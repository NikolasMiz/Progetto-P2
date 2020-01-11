#include "roomgroup.h"

RoomGroup::RoomGroup(unsigned int nBeds, double price, unsigned int quantity) : nBeds(nBeds), price(price), quantity(quantity) {

}

unsigned int RoomGroup::getNBeds() const {
    return nBeds;
}

void RoomGroup::setNBeds(unsigned int beds) {
    nBeds = beds;
}

double RoomGroup::getPrice() const {
    return price;
}

void RoomGroup::setPrice(double price) {
    this->price = price;
}

unsigned int RoomGroup::getQuantity() const {
    return quantity;
}



