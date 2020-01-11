#ifndef HOTELROOM_H
#define HOTELROOM_H


#include <string>

#include "privateroom.h"

class HotelRoom : public PrivateRoom {

public:
    HotelRoom(const std::string & = "", const std::string & = "", const std::string & = "", const std::string & = "",
              const std::string & = "",
              double = 0.0, unsigned int = 0,
              const std::string & = "");

    double estimatePrice(unsigned int guest) const override;

    unsigned int getStars() const;

    const std::string& getHotelName() const;

    double getTax() const;


protected:
    std::ostream &print(std::ostream &) const override;

private:
    double tax; //tassa applicata dall'hotel A PERSONA
    unsigned int stars;
    std::string hotelName;
};

#endif // HOTELROOM_H
