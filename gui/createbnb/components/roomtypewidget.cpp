#include "roomtypewidget.h"

#include <QHBoxLayout>
#include "roomtypewidget.h"

RoomTypeWidget::RoomTypeWidget(QWidget *parent) : QGroupBox(tr("Tipo di stanze"), parent) {
    privateRadioBtt = new QRadioButton(tr("Private"));
    shareRadioBtt = new QRadioButton(tr("Condivise"));
    allHouseRadioBtt = new QRadioButton(tr("Intera casa"));

    privateRadioBtt->setChecked(true);

    QHBoxLayout *roomTypeLayout = new QHBoxLayout(this);
    roomTypeLayout->addWidget(privateRadioBtt);
    roomTypeLayout->addWidget(allHouseRadioBtt);
    roomTypeLayout->addWidget(shareRadioBtt);


}

bool RoomTypeWidget::isPrivate() const {
    return privateRadioBtt->isChecked();
}

bool RoomTypeWidget::isShare() const {
    return shareRadioBtt->isChecked();
}

bool RoomTypeWidget::isAllHouse() const {
    return allHouseRadioBtt->isChecked();
}

QRadioButton *RoomTypeWidget::getPrivateRadioBtt() const {
    return privateRadioBtt;
}


QRadioButton *RoomTypeWidget::getShareRadioBtt() const {
    return shareRadioBtt;
}


QRadioButton *RoomTypeWidget::getAllHouseRadioBtt() const {
    return allHouseRadioBtt;
}


