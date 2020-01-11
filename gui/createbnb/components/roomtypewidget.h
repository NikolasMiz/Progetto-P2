#ifndef ROOMTYPEWIDGET_H
#define ROOMTYPEWIDGET_H

#include <QGroupBox>
#include <QRadioButton>

class RoomTypeWidget : public QGroupBox {

public:
    RoomTypeWidget(QWidget *parent = nullptr);

    bool isPrivate() const;

    bool isShare() const;

    bool isAllHouse() const;


    QRadioButton *getPrivateRadioBtt() const;

    QRadioButton *getShareRadioBtt() const;

    QRadioButton *getAllHouseRadioBtt() const;

private:
    QRadioButton *privateRadioBtt;
    QRadioButton *shareRadioBtt;
    QRadioButton *allHouseRadioBtt;


};

#endif // ROOMTYPEWIDGET_H
