#include "allhousepage.h"

#include <QHBoxLayout>
#include <QMessageBox>

#include <core/allhouse.h>
#include <core/hotelroom.h>

AllHousePage::AllHousePage(const BnB *edit, QWidget *parent)
        : QWizardPage(parent) {
    QHBoxLayout *master = new QHBoxLayout(this);
    info = new AllHouseInfoWidget();

    master->addWidget(info);

    registerField("allHousePrice", info->getPriceLineEdit());
    registerField("allHouseCleaning", info->getCleaningLineEdit());
    registerField("allHouseCanTakeOnCleaning", info->getCanTakeOnCleaningCBox());
    registerField("allHouseNBeds", info->getNBedsLineEdit());
    registerField("allHouseMq", info->getMqLineEdit());
    registerField("allHouseNFloors", info->getNFloorsLineEdit());


    auto allHouse = dynamic_cast<const AllHouse *>(edit);

    if (allHouse != nullptr) {
        info->setCleaning(allHouse->getCleaningPrice());
        info->setNBeds(allHouse->getNBeds());
        info->setMq(allHouse->getMq());
        info->setNFloors(allHouse->getNFloors());
        info->setPrice(allHouse->getPrice());
        info->setCanTakeOnCleaning(allHouse->getCanGuestTakeOnCleaning());
    }

}

bool AllHousePage::validatePage() {
    if (info->getNBeds() > 0 && info->getMq() > 0 && info->getNFloors() > 0 && info->getPrice() > 0) {
        return true;
    } else {
        QMessageBox mex;
        mex.setIcon(QMessageBox::Warning);
        mex.setText("Tutti i campi sono obbligatori");
        mex.exec();
        return false;
    }
}

