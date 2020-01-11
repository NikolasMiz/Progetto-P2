#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include <gui/createbnb/components/serviceswidget.h>

class SearchWidget : public QWidget
{
public:
    SearchWidget(QWidget * = nullptr);

    void clearFilter() const;

    QString getName() const;

    QString getCity() const;

    unsigned int getGuests() const;

    bool isPrivate() const;

    bool isAllHouse() const;

    bool isShared() const;

    bool isHotel() const;

    QList<Service> getServices() const;

    QPushButton *getSearchBtt() const;

    QPushButton *getClearBtt() const;

private:

    QLineEdit *searchName;
    QLineEdit *searchCity;
    QCheckBox *privateRoom;
    QCheckBox *sharedRoom;
    QCheckBox *hotelRoom;
    QCheckBox *houseRoom;
    QLineEdit *guests;
    ServicesWidget *servicesWidget;

    QPushButton *searchBtt;
    QPushButton *clearBtt;
};

#endif // SEARCHWIDGET_H
