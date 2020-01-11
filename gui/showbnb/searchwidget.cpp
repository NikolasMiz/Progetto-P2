#include "searchwidget.h"

#include <QIntValidator>
#include <QLabel>
#include <QPushButton>

SearchWidget::SearchWidget(QWidget *parent) : QWidget (parent)
{
    setMaximumWidth(500);
    QVBoxLayout *masterSearch = new QVBoxLayout(this);


    QHBoxLayout *searchLayoutA = new QHBoxLayout();
    QLabel *searchNameLbl = new QLabel("Nome: ");
    searchName = new QLineEdit();

    searchLayoutA->addWidget(searchNameLbl);
    searchLayoutA->addWidget(searchName);


    QLabel *searchCityLbl = new QLabel("Città: ");
    searchCity = new QLineEdit();

    searchLayoutA->addWidget(searchCityLbl);
    searchLayoutA->addWidget(searchCity);

    masterSearch->addLayout(searchLayoutA);

    QGroupBox *typeGroup = new QGroupBox("Tipo di camera");
    QHBoxLayout *typeLayout = new QHBoxLayout();
    privateRoom = new QCheckBox("Privata");
    sharedRoom = new QCheckBox("Condivisa");
    hotelRoom = new QCheckBox("Camera di Hotel");
    houseRoom = new QCheckBox("Intera Casa");
    typeLayout->addWidget(privateRoom);
    typeLayout->addWidget(hotelRoom);
    typeLayout->addWidget(sharedRoom);
    typeLayout->addWidget(houseRoom);
    typeGroup->setLayout(typeLayout);

    masterSearch->addWidget(typeGroup);


    QHBoxLayout *guestLayout = new QHBoxLayout();
    QLabel *guestLbl = new QLabel("Numero di ospiti: ");
    guests = new QLineEdit();

    QIntValidator *intVal = new QIntValidator(0, 999, this);
    guests->setValidator(intVal);
    guestLayout->addWidget(guestLbl);
    guestLayout->addWidget(guests);
    masterSearch->addLayout(guestLayout);

    servicesWidget = new ServicesWidget();
    masterSearch->addWidget(servicesWidget);

    QHBoxLayout *bttSearchLayout = new QHBoxLayout();

    searchBtt = new QPushButton("Cerca");
    clearBtt = new QPushButton("Reset");

    bttSearchLayout->addWidget(searchBtt);
    bttSearchLayout->addWidget(clearBtt);
    masterSearch->addLayout(bttSearchLayout);



    QWidget *empty = new QWidget();
    empty->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    masterSearch->addWidget(empty);


}

void SearchWidget::clearFilter() const
{
    searchName->setText("");
    searchCity->setText("");
    privateRoom->setCheckState(Qt::CheckState::Unchecked);
    hotelRoom->setCheckState(Qt::CheckState::Unchecked);
    sharedRoom->setCheckState(Qt::CheckState::Unchecked);
    houseRoom->setCheckState(Qt::CheckState::Unchecked);
    servicesWidget->reset();
    guests->setText("");
}

QString SearchWidget::getName() const
{
    return searchName->text();
}

QString SearchWidget::getCity() const
{
    return searchCity->text();
}

unsigned int SearchWidget::getGuests() const
{
    return static_cast<unsigned int>(guests->text().toInt());
}

bool SearchWidget::isPrivate() const
{
    return privateRoom->isChecked();
}

bool SearchWidget::isAllHouse() const
{
    return houseRoom->isChecked();
}

bool SearchWidget::isShared() const
{
    return sharedRoom->isChecked();
}

bool SearchWidget::isHotel() const
{
    return hotelRoom->isChecked();
}

QList<Service> SearchWidget::getServices() const
{
    return servicesWidget->getServices();
}


QPushButton *SearchWidget::getSearchBtt() const
{
    return searchBtt;
}

QPushButton *SearchWidget::getClearBtt() const
{
    return clearBtt;
}
