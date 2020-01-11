#ifndef ROOMWIDGET_H
#define ROOMWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QGroupBox>
#include <core/roomgroup.h>

class RoomGroupWidget : public QGroupBox {

public:

    RoomGroupWidget(QWidget *parent = nullptr);

    unsigned int getNGuest() const;

    unsigned int getNRooms() const;

    double getPrice() const;


    void setNGuest(unsigned int guest);

    void setNRooms(unsigned int rooms);

    void setPrice(double price);


    RoomGroup getRoomGroup() const;

    bool isValid() const;

private:
    QLineEdit *nGuestLineEdit;
    QLineEdit *nRoomLineEdit;
    QLineEdit *priceLineEdit;
};


#endif // ROOMWIDGET_H
