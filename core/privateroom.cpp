#include "privateroom.h"
#include<sstream>

PrivateRoom::PrivateRoom(const std::string &id, const std::string &name, const std::string &city,
                         const std::string &address,
                         const std::string &description)
        : BnB(id, name, city, address, description) {}

double PrivateRoom::estimatePrice(unsigned int guest) const {
    if (!canGuestFit(guest)) return -1;
    /* copia di std::list<Room> per non avere side effect */
    std::list <RoomGroup> cpRooms(rooms);
    return estimatePriceSwap(guest, cpRooms);
}

double PrivateRoom::estimatePriceSwap(unsigned int guest, std::list <RoomGroup> &cpRooms) const {
    auto it = cpRooms.begin();
    while (it != cpRooms.end() && (*it).getNBeds() >= guest)
        ++it;
    if (it != cpRooms.begin() && it != cpRooms.end()) {
        --it;
    }
    if (it == cpRooms.end()) {
        --it;
        return (*it).getPrice();
    }


    //it e' in una camera che potrebbe contenerli tutti
    if ((*it).getNBeds() >= guest)
        return (*it).getPrice();
    else {
        double price = (*it).getPrice();
        unsigned int remain = guest - (*it).getNBeds();
        cpRooms.erase(it);
        price += estimatePriceSwap(remain, cpRooms);
        return price;
    }

}

bool PrivateRoom::canGuestFit(unsigned int guest) const {
    return getTotBeds() >= guest;
}

void PrivateRoom::addRoom(const RoomGroup &r) {
    rooms.push_back(r);
    rooms.sort([](const RoomGroup &a, const RoomGroup &b) {
        auto aBeds = a.getNBeds();
        auto bBeds = b.getNBeds();

        if (aBeds == bBeds) {
            return a.getPrice() > b.getPrice();
        } else {
            return aBeds > bBeds;
        }

    });

}

std::ostream &PrivateRoom::print(std::ostream &stream) const {
    BnB::print(stream);
    stream << "\nVengono proposte:";
    for (auto it = rooms.begin(); it != rooms.end(); ++it) {


        if((*it).getQuantity() == 1) {
            stream << "\n• una camera da ";
        } else {
               stream << "\n• " << (*it).getQuantity() << " camere da ";
        }

        if((*it).getNBeds()) {
            stream << " un ospite per ";
        } else {
             stream << (*it).getNBeds() << " ospiti per ";
        }

        stream << (*it).getPrice() << " €/notte";
    }

    return stream;
}

const std::list<RoomGroup> &PrivateRoom::getRooms() const {
    return rooms;
}


unsigned int PrivateRoom::getTotBeds() const {
    unsigned int count = 0;
    for (auto it = rooms.begin(); it != rooms.end(); ++it) {
        count += (*it).getNBeds();
    }
    return count;
}
