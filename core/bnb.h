#ifndef BNB_H
#define BNB_H

#include <string>
#include <list>
#include <algorithm>
#include "core/service.h"
#include<ostream>

class BnB {

public:
    BnB(const std::string & = "", const std::string & = "", const std::string & = "", const std::string & = "",
        const std::string & = "");

    virtual ~BnB() = default;

    virtual double estimatePrice(unsigned int guest) const = 0;

    void addService(Service s);

    void removeService(Service s);

    const std::string &getId() const;

    const std::string& getName() const;

    const std::string& getCity() const;

    const std::string& getAddress() const;

    const std::string& getDescription() const;

    friend std::ostream& operator<<(std::ostream &stream, const BnB &);

    const std::list<Service>& getServices() const;

    virtual bool canGuestFit(unsigned int guest) const = 0; //se c'e' posto in struttura per n persone

    bool hasService(Service s) const;

protected:
    /* metodo polimormo che permette l'output polimormo */
    virtual std::ostream &print(std::ostream &) const;


private:
    std::string id; //unique ID
    std::string name;
    std::string city;
    std::string address;
    std::string description;

    std::list<Service> services;
};

std::ostream &operator<<(std::ostream &stream, const BnB &);

#endif // BNB_H
