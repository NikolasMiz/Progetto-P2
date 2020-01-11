#include <QRadioButton>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QFormLayout>
#include <QScrollArea>
#include <QMessageBox>
#include <gui/createbnb/components/roomgroupslistwidget.h>
#include <core/hotelroom.h>
#include <core/privateroom.h>
#include "createbnbwizard.h"
#include "privatepage.h"
#include <iostream>

PrivatePage::PrivatePage(const BnB *edit, QWidget *parent) : QWizardPage(parent) {
    setTitle(tr("Creazione BnB stanze private"));
    setMinimumWidth(400);
    setMaximumHeight(600);

    roomTypeBox = new QGroupBox(tr("Dove si trovato le stanze?"));
    QHBoxLayout *roomTypeLayout = new QHBoxLayout();

    privateRadioBtt = new QRadioButton(tr("Appartamento"));
    privateRadioBtt->setChecked(true);
    hotelRadioBtt = new QRadioButton(tr("Hotel"));

    roomTypeLayout->addWidget(privateRadioBtt);
    roomTypeLayout->addWidget(hotelRadioBtt);

    roomTypeBox->setLayout(roomTypeLayout);


    privateBox = new QGroupBox(tr("Inserisci le informazioni delle tue camere"));

    QVBoxLayout *pRoom = new QVBoxLayout();
    QScrollArea *scroll = new QScrollArea();
    scroll->setWidgetResizable(true);

    roomsW = new RoomGroupsListWidget();
    scroll->setWidget(roomsW);


    pRoom->addWidget(scroll);

    privateBox->setLayout(pRoom);
    hotelInfo = new HotelInfoWidget();
    hotelInfo->hide();


    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(roomTypeBox);
    layout->addWidget(privateBox);
    layout->addWidget(hotelInfo);

    connect(privateRadioBtt, &QRadioButton::toggled, this, [this](bool toggled) {
        if (toggled)
            hotelInfo->hide();
        else
            hotelInfo->show();
    });


    registerField("isHotel", hotelRadioBtt);
    registerField("hotelName", hotelInfo->getNameLineEdit());
    registerField("hotelStars", hotelInfo->getStarsCBox());
    registerField("hotelTax", hotelInfo->getTaxLineEdit());

    auto privateBnB = dynamic_cast<const PrivateRoom *>(edit);
    if (privateBnB != nullptr) {
        roomsW->setRooms(privateBnB->getRooms());

        auto hotelBnB = dynamic_cast<const HotelRoom *>(edit);
        if (hotelBnB != nullptr) {
            hotelRadioBtt->setChecked(true);
            hotelInfo->setName(QString::fromStdString(hotelBnB->getHotelName()));
            hotelInfo->setTax(hotelBnB->getTax());
            hotelInfo->setStars(hotelBnB->getStars());
        }
    }
}

QList<RoomGroup> PrivatePage::getRoomGroups() const {
    return roomsW->getRoomGroups();
}

int PrivatePage::nextId() const {
    return CreateBnBWizard::END_PAGE;
}

bool PrivatePage::validatePage() {

    bool isHotelOK = (!hotelRadioBtt->isChecked()) || (hotelInfo->getHotelName() != "");
    bool isPrivateOK = roomsW->isValid();

    if (!isPrivateOK) {

        QMessageBox mex;
        mex.setIcon(QMessageBox::Warning);
        mex.setText("Errore nella compilazione delle stanze");
        mex.exec();
        return false;
    }

    if (!isHotelOK) {
        QMessageBox mex;
        mex.setIcon(QMessageBox::Warning);
        mex.setText("Errore informazioni hotel");
        mex.exec();

        return false;
    }

    return true;
}


