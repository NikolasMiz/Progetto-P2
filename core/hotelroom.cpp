#include "hotelroom.h"

HotelRoom::HotelRoom(const std::string &id, const std::string &name, const std::string &city,
                     const std::string &address,
                     const std::string &description, double tax, unsigned int stars,
                     const std::string &hotelName) : PrivateRoom(id, name, city, address, description), tax(tax),
                                                     stars(stars),
                                                     hotelName(hotelName) {}

double HotelRoom::estimatePrice(unsigned int guest) const {
    if (!canGuestFit(guest)) return -1;
    return PrivateRoom::estimatePrice(guest) + tax * guest;
}


std::ostream &HotelRoom::print(std::ostream &stream) const {
    PrivateRoom::print(stream);
    return stream << "\nCollocato all'interno dell'hotel " << stars << " stelle " << hotelName
                  << "\nTassa di soggiorno a persona: " << tax << "€";

}


/**GETTER AND SETTER**/

unsigned int HotelRoom::getStars() const {
    return stars;
}


const std::string &HotelRoom::getHotelName() const {
    return hotelName;
}

double HotelRoom::getTax() const {
    return tax;
}



