#include "query.h"

Query::Query(QString name, QString city, bool privateRoom, bool shareRoom, bool hotelRoom, bool houseRoom,
             QList <Service> s)
        : name(name), city(city),
          privateRoom((privateRoom || shareRoom || hotelRoom || houseRoom) == false ? true : privateRoom),
          shareRoom((privateRoom || shareRoom || hotelRoom || houseRoom) == false ? true : shareRoom),
          hotelRoom((privateRoom || shareRoom || hotelRoom || houseRoom) == false ? true : hotelRoom),
          houseRoom((privateRoom || shareRoom || hotelRoom || houseRoom) == false ? true : houseRoom),
          services(s) {

}

QString Query::getName() const {
    return name;
}

QString Query::getCity() const {
    return city;
}

QList <Service> Query::getServices() const {
    return services;
}

bool Query::getPrivateRoom() const {
    return privateRoom;
}

bool Query::getShareRoom() const {
    return shareRoom;
}

bool Query::getHotelRoom() const {
    return hotelRoom;
}

bool Query::getHouseRoom() const {
    return houseRoom;
}
