#include "basepage.h"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QUuid>
#include <QPushButton>
#include <QFileDialog>
#include "basepage.h"
#include "createbnbwizard.h"
#include <core/allhouse.h>
#include <core/privateroom.h>
#include <core/sharedroom.h>
#include<iostream>

BasePage::BasePage(const BnB *edit, QWidget *parent)
        : QWizardPage(parent) {

    setMinimumHeight(500);

    idLE = new QLineEdit();
    idLE->hide();
    idLE->setText(QUuid::createUuid().toString());

    setTitle(tr("Iniziamo"));


    baseInfo = new BaseInfoWidget();

    roomType = new RoomTypeWidget(this);

    servicesWidget = new ServicesWidget(this);


    filepathLE = new QLineEdit();
    filepathLE->hide();

    QGroupBox *imgBox = new QGroupBox("Immagine");
    QHBoxLayout *imgLayout = new QHBoxLayout();
    imgBox->setLayout(imgLayout);
    QPushButton *imgSelectBtt = new QPushButton("Seleziona immagine");
    imgLayout->addWidget(imgSelectBtt);
    QLabel *imgPrev = new QLabel();
    imgLayout->addWidget(imgPrev);
    imgPrev->hide();

    connect(imgSelectBtt, &QPushButton::clicked, this, [this, imgPrev]() {
        QFileDialog dialog;
        dialog.setFileMode(QFileDialog::ExistingFile);
        dialog.setNameFilter(("Images (*.png *.xpm *.jpg)"));

        if (dialog.exec() == QDialog::Accepted) {
            QString filepath = dialog.selectedFiles().first();
            filepathLE->setText(filepath);

            imgPrev->setPixmap(QPixmap(filepath).scaled(150, 150, Qt::KeepAspectRatio));
            imgPrev->show();


        }
    });


    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(baseInfo);
    layout->addWidget(roomType);
    layout->addWidget(servicesWidget);
    layout->addWidget(imgBox);
    layout->addWidget(idLE);
    layout->addWidget(filepathLE);
    setLayout(layout);

    registerField("name", baseInfo->getBnbNameLineEdit());
    registerField("city", baseInfo->getCityLineEdit());
    registerField("address", baseInfo->getAddressLineEdit());
    registerField("privateType", roomType->getPrivateRadioBtt());
    registerField("shareType", roomType->getShareRadioBtt());
    registerField("allHouseType", roomType->getAllHouseRadioBtt());
    registerField("id", idLE);
    registerField("imgpath", filepathLE);

    if (edit != nullptr) {

        baseInfo->setBnbName(QString::fromStdString(edit->getName()));
        baseInfo->setCity(QString::fromStdString(edit->getCity()));
        baseInfo->setAddress(QString::fromStdString(edit->getAddress()));

        //idLE->setText(QString::fromStdString(edit->getId()));

        auto imgpath = "img/" + QString::fromStdString(edit->getId());

        if(QFile::exists(imgpath)) {
            filepathLE->setText(imgpath);
            imgPrev->setPixmap(QPixmap(imgpath).scaled(150, 150, Qt::KeepAspectRatio));
            imgPrev->show();
        }

        if (dynamic_cast<const PrivateRoom *>(edit) != nullptr) {
            roomType->getPrivateRadioBtt()->setChecked(true);
        } else if (dynamic_cast<const SharedRoom *>(edit) != nullptr) {
            roomType->getShareRadioBtt()->setChecked(true);
        } else if (dynamic_cast<const AllHouse *>(edit) != nullptr) {
            roomType->getAllHouseRadioBtt()->setChecked(true);
        }

        servicesWidget->checkServices(edit->getServices());
    }
}

int BasePage::nextId() const {
    if (roomType->isPrivate()) {
        return CreateBnBWizard::PRIVATE_PAGE;
    } else if (roomType->isShare()) {
        return CreateBnBWizard::SHARE_PARE;
    } else {
        return CreateBnBWizard::ALL_HOUSE_PAGE;
    }
}

QList<Service> BasePage::getServices() const {
    return servicesWidget->getServices();
}



bool BasePage::validatePage() {
    if (!baseInfo->getBnbName().isEmpty() && !baseInfo->getCity().isEmpty() &&
        !baseInfo->getAddress().isEmpty()) {
        if (filepathLE->text().isEmpty()) {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "AirPnP", "La foto non è stata inserita, continuare ugualmente?",
                                          QMessageBox::Yes | QMessageBox::No);
            return reply == QMessageBox::Yes;
        }
        return true;
    } else {

        QMessageBox mex;
        mex.setText("Tutti i campi testuali sono obbligatori");
        mex.setIcon(QMessageBox::Warning);
        mex.exec();
        return false;
    }
}

 const QString& BasePage::getId() const {
    return id;
}

