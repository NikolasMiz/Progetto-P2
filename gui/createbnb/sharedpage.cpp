#include "createbnbwizard.h"
#include "sharedpage.h"

#include <QMessageBox>
#include <QVBoxLayout>

#include <gui/createbnb/components/sharedinfowidget.h>

#include <core/sharedroom.h>

SharedPage::SharedPage(const BnB *edit, QWidget *parent)
        : QWizardPage(parent) {
    setTitle(tr(edit == nullptr ? "Creazione BnB stanze condivise" : "Modifica le stanze condivise"));
    QVBoxLayout *layout = new QVBoxLayout(this);
    roomInfoBox = new SharedInfoWidget();

    layout->addWidget(roomInfoBox);


    registerField("sharePricePerBed", roomInfoBox->getPricePerBedLineEdit());
    registerField("shareNBeds", roomInfoBox->getNBedsLineEdit());


    auto *shareRoom = dynamic_cast<const SharedRoom *>(edit);
    if (shareRoom != nullptr) {
        roomInfoBox->setNBeds(shareRoom->getNBeds());
        roomInfoBox->setPrice(shareRoom->getPricePerBed());
    }
}

int SharedPage::nextId() const {
    return CreateBnBWizard::END_PAGE;
}

bool SharedPage::validatePage() {
    if (!roomInfoBox->getNBedsLineEdit()->text().isEmpty() && !roomInfoBox->getPricePerBedLineEdit()->text().isEmpty()) {
        return true;
    } else {

        QMessageBox mex;
        mex.setIcon(QMessageBox::Warning);
        mex.setText("Tutti i campi sono obbligatori");
        mex.exec();

        return false;
    }
}


