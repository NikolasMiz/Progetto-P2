#include "bnb.h"

BnB::BnB(const std::string &id, const std::string &name, const std::string &city, const std::string &address,
         const std::string &description)
        : id(id), name(name), city(city), address(address), description(description) {

}


void BnB::addService(Service s) {

    auto it = find(services.begin(), services.end(), s);
    if (it == services.end()) //non e' gia' nella lista
        services.push_back(s);
}

void BnB::removeService(Service s) {
    auto it = find(services.begin(), services.end(), s);
    if (it != services.end()) //e' nella lista
        services.erase(it);
}

std::ostream& BnB::print(std::ostream &stream) const {
    stream << name + '\n';
    stream << address << ", " << city;
    return stream;
}

bool BnB::hasService(Service s) const {
    return std::find(services.begin(), services.end(), s) != services.end();
}

std::ostream &operator<<(std::ostream &stream, const BnB &b) {
    return b.print(stream);
}

/**GETTER AND SETTER**/


const std::string& BnB::getDescription() const {
    return description;
}


const std::string& BnB::getId() const {
    return id;
}

const std::list<Service>& BnB::getServices() const {
    return services;
}


const std::string &BnB::getName() const {
    return name;
}

const std::string &BnB::getCity() const {
    return city;
}

const std::string &BnB::getAddress() const {
    return address;
}


