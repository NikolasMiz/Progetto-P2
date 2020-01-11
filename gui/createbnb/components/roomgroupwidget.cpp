#include <QGroupBox>
#include <QHBoxLayout>
#include <QDoubleValidator>
#include <QFormLayout>
#include "roomgroupwidget.h"

RoomGroupWidget::RoomGroupWidget(QWidget *parent) : QGroupBox(parent) {

    QLabel *nGuestLabel = new QLabel(tr("Persone ospitabili: "));
    nGuestLineEdit = new QLineEdit();
    nGuestLabel->setBuddy(nGuestLineEdit);
    nGuestLineEdit->setValidator(new QIntValidator(0, 100));

    QLabel *priceLabel = new QLabel(tr("Prezzo della camera:"));
    priceLineEdit = new QLineEdit();
    priceLabel->setBuddy(priceLabel);
    auto dVal = new QDoubleValidator(1, 99999, 2, this);
    dVal->setNotation(QDoubleValidator::StandardNotation);
    priceLineEdit->setValidator(dVal);

    QLabel *nRoomLabel = new QLabel(tr("Stanze con queste caratteristiche: "));
    nRoomLineEdit = new QLineEdit();
    nRoomLabel->setBuddy(nRoomLineEdit);
    nRoomLineEdit->setValidator(new QIntValidator(1, 100));

    QFormLayout *layout = new QFormLayout(this);
    layout->addRow(nGuestLabel, nGuestLineEdit);
    layout->addRow(priceLabel, priceLineEdit);
    layout->addRow(nRoomLabel, nRoomLineEdit);

}

unsigned int RoomGroupWidget::getNGuest() const {
    return static_cast<unsigned int>(nGuestLineEdit->text().toInt());
}

unsigned int RoomGroupWidget::getNRooms() const {
    return static_cast<unsigned int>(nRoomLineEdit->text().toInt());
}

double RoomGroupWidget::getPrice() const {
    return priceLineEdit->text().toDouble();
}

void RoomGroupWidget::setNGuest(unsigned int guest) {
    nGuestLineEdit->setText(QString::number(guest));
}

void RoomGroupWidget::setNRooms(unsigned int rooms) {
    nRoomLineEdit->setText(QString::number(rooms));
}

void RoomGroupWidget::setPrice(double price) {
    priceLineEdit->setText(QString::number(price));
}

RoomGroup RoomGroupWidget::getRoomGroup() const {
    return RoomGroup(getNGuest(), getPrice(), getNRooms());
}

bool RoomGroupWidget::isValid() const {
    return getNGuest() > 0 && getNRooms() > 0 && getPrice() > 0;
}
