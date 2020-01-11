#ifndef PRIVATEPAGE_H
#define PRIVATEPAGE_H

#include <QWizardPage>
#include <QGroupBox>
#include <QLabel>
#include <QList>
#include <QLineEdit>
#include <QComboBox>
#include <qradiobutton.h>
#include <core/bnb.h>
#include<core/roomgroup.h>
#include <gui/createbnb/components/hotelinfowidget.h>
#include <gui/createbnb/components/roomgroupslistwidget.h>
#include <gui/createbnb/components/roomgroupwidget.h>
#include<list>

class PrivatePage : public QWizardPage {
    Q_OBJECT

public:
    PrivatePage(const BnB *edit = nullptr, QWidget *parent = nullptr);

    QList<RoomGroup> getRoomGroups() const;

    int nextId() const override;

    bool validatePage() override;

private:

    QRadioButton *privateRadioBtt;
    QRadioButton *hotelRadioBtt;


    QGroupBox *roomTypeBox;
    QGroupBox *privateBox;

    RoomGroupsListWidget *roomsW;

    HotelInfoWidget *hotelInfo;

};


#endif // PRIVATEPAGE_H
