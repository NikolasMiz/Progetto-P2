#ifndef ROOMGROUP_H
#define ROOMGROUP_H

/* rappresenta una o più stanze di un BnB Privato con le stesse caratteristiche */
class RoomGroup {
public:
    RoomGroup(unsigned int nBeds = 0, double price = 0.0, unsigned int quantity = 0);

    unsigned int getNBeds() const;

    double getPrice() const;

    void setNBeds(unsigned int);

    void setPrice(double);

    unsigned int getQuantity() const;

private:
    unsigned int nBeds;
    double price;
    unsigned int quantity;
};

#endif // ROOMGROUP_H
