#include "basepage.h"
#include "createbnbwizard.h"
#include "privatepage.h"
#include<iostream>
#include "allhousepage.h"
#include "endpage.h"
#include "intopage.h"
#include "sharedpage.h"
#include<typeinfo>
#include <core/allhouse.h>
#include <core/hotelroom.h>
#include <core/sharedroom.h>
#include<iostream>
#include<QFile>
#include<QDir>

CreateBnBWizard::CreateBnBWizard(const BnB *editBnB, QWidget *parent)
        : QWizard(parent), editBnB(editBnB), res(nullptr) {

    setWindowTitle(tr(editBnB == nullptr ? "Creazione di un nuovo BnB" : "Modifica BnB"));

    QPixmap img;
    img.load(":/gui/img/logo.png");

    setPixmap(QWizard::WatermarkPixmap, img.scaled(260, 1000, Qt::KeepAspectRatio));

    setPage(INTRO_PAGE, new IntroPage(editBnB != nullptr, this));
    basePage = new BasePage(editBnB, this);
    setPage(BASE_PAGE, basePage);
    privatePage = new PrivatePage(editBnB, this);
    setPage(PRIVATE_PAGE, privatePage);


    sharePage = new SharedPage(editBnB, this);
    setPage(SHARE_PARE, sharePage);

    allHousePage = new AllHousePage(editBnB, this);
    setPage(ALL_HOUSE_PAGE, allHousePage);

    endPage = new EndPage(editBnB, this);
    setPage(END_PAGE, endPage);


}

void CreateBnBWizard::accept() {

    std::string name = field("name").value<QString>().toStdString();
    std::string city = field("city").value<QString>().toStdString();
    std::string address = field("address").value<QString>().toStdString();
    std::string id = field("id").value<QString>().toStdString();
    std::string description = endPage->getDescription().toStdString();


    QString imgpath = field("imgpath").value<QString>();

    QString targetpath = "img/" + QString::fromStdString(id);

    if(QFile::exists(imgpath))
        QFile::copy(imgpath, targetpath);


    if (field("privateType").value<bool>()) {

        if (field("isHotel").value<bool>()) {
            double tax = field("hotelTax").value<double>();
            unsigned int stars = field("hotelStars").value<unsigned int>() + 2;
            std::string hotelName = field("hotelName").value<QString>().toStdString();

            res = new HotelRoom(id, name, city, address, description, tax, stars, hotelName);
        } else {
            res = new PrivateRoom(id, name, city, address, description);
        }

        PrivateRoom *p = static_cast<PrivateRoom *>(res);
        auto rooms = privatePage->getRoomGroups();
        for (auto it = rooms.begin(); it != rooms.end(); ++it) {
            p->addRoom(*it);
        }

    } else if (field("shareType").value<bool>()) {
        unsigned int nBeds = field("shareNBeds").value<unsigned int>();
        double pricePerBed = field("sharePricePerBed").value<double>();

        res = new SharedRoom(id, name, city, address, description, nBeds, pricePerBed);
    } else {
        double price = field("allHousePrice").value<double>();
        double cleaningPrice = field("allHouseCleaning").value<double>();
        bool canTakeOnCleaning = field("allHouseCanTakeOnCleaning").value<bool>();
        unsigned int nBeds = field("allHouseNBeds").value<unsigned int>();
        double mq = field("allHouseMq").value<double>();
        unsigned int nFloors = field("allHouseNFloors").value<unsigned int>();
        res = new AllHouse(id, name, city, address, description, price, nBeds, cleaningPrice, canTakeOnCleaning, mq,
                           nFloors);
    }
    auto services = basePage->getServices();

    for (auto it = services.begin(); it != services.end(); it++) {
        res->addService((*it));
    }

    QDialog::accept();
    emit finished();

}



