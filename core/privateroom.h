#ifndef PRIVATEROOM_H
#define PRIVATEROOM_H

#include <list>

#include "bnb.h"
#include "roomgroup.h"

class PrivateRoom : public BnB {

public:
    PrivateRoom(const std::string & = "", const std::string & = "", const std::string & = "", const std::string & = "",
                const std::string & = "");

    double estimatePrice(unsigned int guest) const override;

    void addRoom(const RoomGroup &);

    const std::list<RoomGroup>& getRooms() const;

    bool canGuestFit(unsigned int guest) const override;

protected:
    std::ostream &print(std::ostream &) const override;

private:
    std::list<RoomGroup> rooms;
    double estimatePriceSwap(unsigned int,
                             std::list <RoomGroup> &) const; //swap per il metodo ricorsivo, permette il passaggio di parametri
    unsigned int getTotBeds() const;
};


#endif // PRIVATEROOM_H
