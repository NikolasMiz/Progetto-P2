#ifndef ROOMSWIDGET_H
#define ROOMSWIDGET_H

#include "roomgroupwidget.h"

#include <QList>
#include <QVBoxLayout>

#include <core/roomgroup.h>


class RoomGroupsListWidget : public QWidget {
public:
    RoomGroupsListWidget(QWidget *parent = nullptr);

    ~RoomGroupsListWidget();


    QList<RoomGroup> getRoomGroups() const;

    QLineEdit *getNRoomLineEdit() const;

    void setRooms(const std::list <RoomGroup> &rooms);

    bool isValid() const;

private:
    QList<RoomGroupWidget *> *roomWidgets;

    QLineEdit *nRoomLineEdit;
    QVBoxLayout *pRoom;
    QWidget *empty;

    void updateNumber(int newNum) const;

};

#endif // ROOMSWIDGET_H
