#ifndef QUERY_H
#define QUERY_H

#include <QList>
#include <core/service.h>
#include<string>

class Query {
public:
    Query(QString name, QString city, bool privateRoom, bool shareRoom, bool hotelRoom, bool houseRoom,
          QList <Service> s);

    QString getName() const;

    QString getCity() const;

    bool getPrivateRoom() const;

    bool getShareRoom() const;

    bool getHotelRoom() const;

    bool getHouseRoom() const;

    QList <Service> getServices() const;

private:
    QString name;
    QString city;
    bool privateRoom;
    bool shareRoom;
    bool hotelRoom;
    bool houseRoom;
    QList <Service> services;
};

#endif // QUERY_H
