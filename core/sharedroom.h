#ifndef SHAREDROOM_H
#define SHAREDROOM_H


#include "bnb.h"

class SharedRoom : public BnB {
    /*in stanza si potrebbe soggiornare con persone che fanno parte di altre prenotazioni
    piu' economico perche', a differenza della privata, pago esattamente a seconda di quante persone sono nella pronotazione
     (nella privata pagavo a seconda di quante camere prenotavo)*/

public:

    SharedRoom(const std::string & = "", const std::string & = "", const std::string & = "", const std::string & = "",
               const std::string & = "", unsigned int = 0, double = 0.0);

    double estimatePrice(unsigned int guest) const override;

    unsigned int getNBeds() const;

    double getPricePerBed() const;

    bool canGuestFit(unsigned int guest) const override;

protected:
    std::ostream &print(std::ostream &) const override;

private:

    unsigned int nBeds;
    double pricePerBed;

};


#endif // SHAREDROOM_H
