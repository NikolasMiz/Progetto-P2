#include "roomgroupslistwidget.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QIntValidator>
#include <QScrollArea>
#include <QVBoxLayout>
#include <qmessagebox.h>

RoomGroupsListWidget::RoomGroupsListWidget(QWidget *parent) : QWidget(parent) {
    roomWidgets = new QList<RoomGroupWidget *>();

    QLabel *nRoomLabel = new QLabel(tr("Numero di tipi di stanze: "));
    nRoomLineEdit = new QLineEdit();
    nRoomLabel->setBuddy(nRoomLineEdit);
    nRoomLineEdit->setValidator(new QIntValidator(1, 20));
    QFormLayout *nRoomLayout = new QFormLayout();
    nRoomLayout->addRow(nRoomLabel, nRoomLineEdit);

    empty = new QWidget();
    empty->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    pRoom = new QVBoxLayout(this);
    pRoom->addLayout(nRoomLayout);
    pRoom->addWidget(empty);

    connect(nRoomLineEdit, &QLineEdit::textChanged, this, [=](const QString &text) {
        updateNumber(text.toInt());
    });


}

RoomGroupsListWidget::~RoomGroupsListWidget() {
    qDeleteAll(roomWidgets->begin(), roomWidgets->end());
    roomWidgets->clear();
    delete roomWidgets;
}

void RoomGroupsListWidget::updateNumber(int newNum) const {
    int oldNum = roomWidgets->size();

    if (newNum > oldNum) {
        int diff = newNum - oldNum;
        for (int i = 0; i < diff; i++) {
            pRoom->removeWidget(empty);
            RoomGroupWidget *r = new RoomGroupWidget();
            pRoom->addWidget(r);
            pRoom->addWidget(empty);
            roomWidgets->push_back(r);
        }
    } else {
        int diff = oldNum - newNum;
        auto it = roomWidgets->end();
        it--;
        for (int i = 0; i < diff; i++) {
            pRoom->removeWidget(*it);
            roomWidgets->erase(it);
            delete *it;
            it--;
        }

    }
}

QList<RoomGroup> RoomGroupsListWidget::getRoomGroups() const {
    QList <RoomGroup> list;

    for (auto it = roomWidgets->begin(); it != roomWidgets->end(); it++) {
        list.push_back((*it)->getRoomGroup());
    }
    return list;
}

QLineEdit *RoomGroupsListWidget::getNRoomLineEdit() const {
    return nRoomLineEdit;
}

void RoomGroupsListWidget::setRooms(const std::list <RoomGroup> &rooms) {
    nRoomLineEdit->setText(QString::number(rooms.size()));

    auto ifrom = rooms.begin();
    auto ito = roomWidgets->begin();

    while (ifrom != rooms.end()) {

        (*ito)->setNRooms((*ifrom).getQuantity());
        (*ito)->setPrice((*ifrom).getPrice());
        (*ito)->setNGuest((*ifrom).getNBeds());

        ++ifrom;
        ++ito;
    }
}

bool RoomGroupsListWidget::isValid() const {
    bool ok = true;
    if (roomWidgets->count() > 0) {

        for (auto it = roomWidgets->begin(); it != roomWidgets->end() && ok; ++it) {
            ok = ok && (*it)->isValid();
        }

    } else {
        ok = false;
    }
    return ok;
}

