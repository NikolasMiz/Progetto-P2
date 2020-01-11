#include "sharedroom.h"

SharedRoom::SharedRoom(const std::string &id, const std::string &name, const std::string &city,
                       const std::string &address,
                       const std::string &descriprion, unsigned int nBeds, double pricePerRoom)
        : BnB(id, name, city, address, descriprion), nBeds(nBeds), pricePerBed(pricePerRoom) {

}

bool SharedRoom::canGuestFit(unsigned int guest) const {
    return nBeds >= guest;
}

std::ostream &SharedRoom::print(std::ostream &stream) const {
    BnB::print(stream);
    stream << "\nVengono messi a disposizione " << nBeds << " posti letto "
           << "per " << pricePerBed << "€/notte";
    return stream;
}

double SharedRoom::estimatePrice(unsigned int guest) const {
    if (!canGuestFit(guest)) return -1;
    return guest * pricePerBed;
}


double SharedRoom::getPricePerBed() const {
    return pricePerBed;
}

unsigned int SharedRoom::getNBeds() const {
    return nBeds;
}
