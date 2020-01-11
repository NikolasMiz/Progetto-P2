#ifndef ALLHOUSE_H
#define ALLHOUSE_H


#include "bnb.h"

class AllHouse : public BnB {

public:

    AllHouse(const std::string & = "", const std::string & = "", const std::string & = "", const std::string & = "",
             const std::string & = "", double = 0.0, unsigned int = 0, double = 0.0, bool = false,
             double = 0.0, unsigned int = 0);

    double estimatePrice(unsigned int guest) const override;


    double getCleaningPrice() const;

    double getPrice() const;

    bool getCanGuestTakeOnCleaning() const;

    double getMq() const;

    unsigned int getNFloors() const;

    unsigned int getNBeds() const;

    bool canGuestFit(unsigned int guest) const override;

protected:

    std::ostream &print(std::ostream &) const override;

private:
    double price; //prezzo per la casa
    unsigned int nBeds;
    double cleaningPrice; //prezzo delle pulizie della casa (applicate una volta per tutto il soggiorno)
    bool canGuestTakeOnCleaning; //se l'ospite pu' farsi carico delle pulizie per non pagare il supplemento
    double mq; //metri quadrati
    unsigned int nFloors;
};

#endif // ALLHOUSE_H
