#include "allhouse.h"

bool AllHouse::canGuestFit(unsigned int guest) const {
    return nBeds >= guest;
}

std::ostream &AllHouse::print(std::ostream &stream) const {
    BnB::print(stream);
    stream << "\nLa struttura offre " << nBeds << " posti letto su " << nFloors << " piani ";
    stream << "su una superficie di " << mq << " mq\n";
    stream << "Costo affitto giornaliero €" << price << " e un contributo per le pulizie di €" << cleaningPrice;
    if (canGuestTakeOnCleaning) {
        stream << "\nSe gli ospiti lo desiderano possono provvedere alle pulizie di base per non pagare il contributo";
    }
    return stream;
}


AllHouse::AllHouse(const std::string &id, const std::string &name, const std::string &city, const std::string &address,
                   const std::string &description,
                   double price, unsigned int nBeds, double cleaningPrice, bool canGuestTakeOnCleaning, double mq,
                   unsigned int nFloors)
        : BnB(id, name, city, address, description), price(price), nBeds(nBeds), cleaningPrice(cleaningPrice),
          canGuestTakeOnCleaning(canGuestTakeOnCleaning),
          mq(mq), nFloors(nFloors) {}

double AllHouse::estimatePrice(unsigned int guest) const {
    if (canGuestFit(guest)) {
        return price +
               cleaningPrice; //il cliente decidera' poi con il proprietario come fare se vuole fare le pulizie (se vuole)
    }
    return -1;
}


double AllHouse::getCleaningPrice() const {
    return cleaningPrice;
}

double AllHouse::getPrice() const {
    return price;
}

bool AllHouse::getCanGuestTakeOnCleaning() const {
    return canGuestTakeOnCleaning;
}

double AllHouse::getMq() const {
    return mq;
}


unsigned int AllHouse::getNFloors() const {
    return nFloors;
}


unsigned int AllHouse::getNBeds() const {
    return nBeds;
}

