#include "model.h"

#include <core/allhouse.h>
#include <core/hotelroom.h>
#include <core/sharedroom.h>
#include <QFile>
#include <QXmlStreamWriter>
#include <string>
#include <QDomDocument>
#include <QDir>

Model::Model(QString path) : path(path), data(new Qontainer<BnB *>()), filteredResult(new Qontainer<BnB *>()), isEdited(false) {
    load(path);
    resetFilter();
}

Model::~Model()
{
    for (auto it = data->begin(); it != data->end(); ++it) {
        delete *it;
    }
    data->clear();
    filteredResult->clear();

    delete data;
    delete filteredResult;
}

void Model::filter(Query query) const {
    resetFilter();
    filteredResult->clear();
    auto qServ = query.getServices();

    for (auto it = data->begin(); it != data->end(); ++it) {
        if (((query.getName() != "" &&
              QString::fromStdString((*it)->getName()).contains(query.getName(),
                                                                Qt::CaseInsensitive))
             || query.getName().isEmpty()) &&
            ((query.getCity() != "" && QString::fromStdString((*it)->getCity()).contains(query.getCity(),
                                                                Qt::CaseInsensitive))
             || query.getCity().isEmpty())
            && (
                    (query.getHotelRoom() && dynamic_cast<HotelRoom *>(*it) != nullptr)
                    || (query.getPrivateRoom() && dynamic_cast<PrivateRoom *>(*it) != nullptr)
                    || (query.getShareRoom() && dynamic_cast<SharedRoom *>(*it) != nullptr)
                    || (query.getHouseRoom() && dynamic_cast<AllHouse *>(*it) != nullptr))) {

            bool ok = true;
            for (auto is = qServ.begin(); is != qServ.end() && ok; ++is) {
                if (!(*it)->hasService(*is)) {
                    ok = false;
                }
            }

            if (ok) filteredResult->push_front(*it);
        }
    }

}

void Model::resetFilter() const {
    filteredResult->clear();
    for (auto it = data->begin(); it != data->end(); ++it) {
        filteredResult->push_front(*it);
    }
}

Qontainer<BnB *> *Model::getData() const {
    return data;
}

Qontainer<BnB *> *Model::getResult() const {
    return filteredResult;
}

void Model::addItem(BnB *bnb) {
    isEdited = true;
    data->push_front(bnb);
    resetFilter();
}

void Model::deleteItem(BnB *bnb, bool resetFilt)
{
    isEdited = true;
    data->remove(bnb);
    delete bnb;
    if(resetFilt) resetFilter();
}

void Model::save() {
    isEdited = false;
    QFile file(path);
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    QXmlStreamWriter xw(&file);
    xw.setAutoFormatting(true);
    xw.writeStartDocument();
    xw.writeStartElement("BnBs");
    for (auto it = data->begin(); it != data->end(); ++it) {

        BnB *bnb = *it;
        xw.writeStartElement("BnB");


        if (dynamic_cast<SharedRoom *>(bnb) != nullptr) {
            auto shared = static_cast<SharedRoom *>(bnb);

            xw.writeAttribute("type", "SharedRoom");
            xw.writeTextElement("NBeds", QString::number(shared->getNBeds()));
            xw.writeTextElement("PricePerBed", QString::number(shared->getPricePerBed()));

        } else if (dynamic_cast<PrivateRoom *>(bnb)) {
            if (dynamic_cast<HotelRoom *>(bnb)) {
                auto hotel = static_cast<HotelRoom *>(bnb);

                xw.writeAttribute("type", "HotelRoom");
                xw.writeStartElement("HotelInfo");
                xw.writeTextElement("HotelName", QString::fromStdString(hotel->getHotelName()));
                xw.writeTextElement("Tax", QString::number(hotel->getTax()));
                xw.writeTextElement("HotelStar", QString::number(hotel->getStars()));
                xw.writeEndElement();

            } else {
                xw.writeAttribute("type", "PrivateRoom");
            }
            auto privateRoom = static_cast<PrivateRoom *>(bnb);
            xw.writeStartElement("Rooms");

            auto roomlist = privateRoom->getRooms();
            for (auto rit = roomlist.begin(); rit != roomlist.end(); ++rit) {
                xw.writeStartElement("Room");

                xw.writeTextElement("NBeds", QString::number((*rit).getNBeds()));
                xw.writeTextElement("Price", QString::number((*rit).getPrice()));
                xw.writeTextElement("Quantity", QString::number((*rit).getQuantity()));

                xw.writeEndElement();
            }
            xw.writeEndElement();
        } else if (dynamic_cast<AllHouse *>(bnb)) {
            auto allhouse = static_cast<AllHouse *>(bnb);
            xw.writeAttribute("type", "AllHouse");
            xw.writeTextElement("Price", QString::number(allhouse->getPrice()));
            xw.writeTextElement("Mq", QString::number(allhouse->getMq()));
            xw.writeTextElement("Floors", QString::number(allhouse->getNFloors()));
            xw.writeTextElement("NBeds", QString::number(allhouse->getNBeds()));
            xw.writeTextElement("CleaningPrice", QString::number(allhouse->getCleaningPrice()));
            xw.writeTextElement("CanTakeOnCleaning", QString::number(allhouse->getCanGuestTakeOnCleaning()));

        }

        xw.writeStartElement("BaseInfo");
        xw.writeTextElement("Id", QString::fromStdString(bnb->getId()));
        xw.writeTextElement("Name", QString::fromStdString(bnb->getName()));
        xw.writeTextElement("City", QString::fromStdString(bnb->getCity()));
        xw.writeTextElement("Address", QString::fromStdString(bnb->getAddress()));
        xw.writeTextElement("Description", QString::fromStdString(bnb->getDescription()));

        xw.writeStartElement("Services");

        for (auto x = bnb->getServices().begin(); x != bnb->getServices().end(); ++x) {
            xw.writeTextElement("Service", QString::number(*x));
        }
        xw.writeEndElement();

        xw.writeEndElement();

        xw.writeEndElement();


    }
    xw.writeEndElement();
    xw.writeEndDocument();

    file.close();

}

void Model::load(QString path) const {
    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QDomDocument r;
    r.setContent(&file);

    QDomNodeList bnbs = r.elementsByTagName("BnB");
    for (int i = 0; i < bnbs.size(); i++) {
        BnB *res = nullptr;
        QDomNode bnbNode = bnbs.item(i);
        QDomElement bnbElem = bnbNode.toElement();

        QDomNode baseInfo = bnbNode.firstChildElement("BaseInfo");

        QDomElement idElem = baseInfo.firstChildElement("Id");
        QDomElement nameElem = baseInfo.firstChildElement("Name");
        QDomElement cityElem = baseInfo.firstChildElement("City");
        QDomElement addressElem = baseInfo.firstChildElement("Address");
        QDomElement descrElem = baseInfo.firstChildElement("Description");

        std::string id = idElem.text().toStdString();
        std::string name = nameElem.text().toStdString();
        std::string city = cityElem.text().toStdString();
        std::string address = addressElem.text().toStdString();
        std::string description = descrElem.text().toStdString();


        auto elemType = bnbElem.attribute("type");
        if (elemType == "SharedRoom") {
            QDomElement nBedsElem = bnbElem.firstChildElement("NBeds");
            QDomElement pricePerBedElem = bnbElem.firstChildElement("PricePerBed");
            unsigned int nBeds = static_cast<unsigned int>(nBedsElem.text().toInt());
            double pricePerBed = pricePerBedElem.text().toDouble();
            res = new SharedRoom(id, name, city, address, description, nBeds, pricePerBed);
        } else if (elemType == "AllHouse") {
            QDomElement mqElem = bnbElem.firstChildElement("Mq");
            QDomElement priceElem = bnbElem.firstChildElement("Price");
            QDomElement floorsElem = bnbElem.firstChildElement("Floors");
            QDomElement cleaningPriceElem = bnbElem.firstChildElement("CleaningPrice");
            QDomElement nBedsElem = bnbElem.firstChildElement("NBeds");
            QDomElement canTakeOnElem = bnbElem.firstChildElement("CanTakeOnCleaning");

            double mq = mqElem.text().toDouble();
            double price = priceElem.text().toDouble();
            unsigned int nFloors = static_cast<unsigned int>(floorsElem.text().toInt());
            unsigned int nBeds = static_cast<unsigned int>(nBedsElem.text().toInt());
            double cleaningPrice = cleaningPriceElem.text().toDouble();
            bool canTakeOn = canTakeOnElem.text().toInt() == 1;
            res = new AllHouse(id, name, city, address, description, price, nBeds, cleaningPrice, canTakeOn, mq,
                               nFloors);

        } else if (elemType == "HotelRoom" || elemType == "PrivateRoom") {


            if (elemType == "HotelRoom") {

                QDomNode hotelInfo = bnbNode.firstChildElement("HotelInfo");
                QDomElement hotelNameElem = hotelInfo.firstChildElement("HotelName");
                QDomElement taxElem = hotelInfo.firstChildElement("Tax");
                QDomElement hotelStarElem = hotelInfo.firstChildElement("HotelStar");

                std::string hotelName = hotelNameElem.text().toStdString();
                double tax = taxElem.text().toDouble();
                unsigned int hotelStar = static_cast<unsigned int>(hotelStarElem.text().toInt());
                res = new HotelRoom(id, name, city, address, description, tax, hotelStar, hotelName);
            }
            if (res == nullptr) res = new PrivateRoom(id, name, city, address);
            QDomNodeList roomsNode = bnbNode.toElement().firstChildElement("Rooms").elementsByTagName("Room");
            auto privateRoom = static_cast<PrivateRoom *>(res);

            for (int i = 0; i < roomsNode.size(); ++i) {
                QDomElement nBedsElem = roomsNode.at(i).firstChildElement("NBeds");
                QDomElement priceElem = roomsNode.at(i).firstChildElement("Price");
                QDomElement quantityElem = roomsNode.at(i).firstChildElement("Quantity");
                unsigned int nBeds = static_cast<unsigned int>(nBedsElem.text().toInt());
                unsigned int quantity = static_cast<unsigned int>(quantityElem.text().toInt());
                double price = priceElem.text().toDouble();

                RoomGroup r(nBeds, price, quantity);
                privateRoom->addRoom(r);
            }


        } else {
            continue;
        }

        QDomNodeList servicesNode = baseInfo.toElement().firstChildElement("Services").elementsByTagName("Service");

        for (int p = 0; p < servicesNode.size(); ++p) {
            res->addService(Service(servicesNode.at(p).toElement().text().toInt()));
        }

        data->push_front(res);
    }

}

bool Model::getIsEdited() const
{
    return isEdited;
}
