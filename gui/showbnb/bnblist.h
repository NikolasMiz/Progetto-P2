#ifndef BNBLIST_H
#define BNBLIST_H

#include "bnbwidget.h"

#include <QWidget>
#include <qboxlayout.h>
#include <qlabel.h>

#include <core/qontainer.h>


class BnBList : public QWidget {
    Q_OBJECT

public:
    BnBList(Qontainer<BnB *> *list, QWidget *parent = nullptr);

    void update(unsigned int guest = 0);

    void readOnly(bool);

private:
    Qontainer<BnB *> *list;
    QList<BnBWidget *> widgets;
    QVBoxLayout *bnblist;
    QLabel *noResultLabel;

    void clearWidgets(QLayout *) const;

    signals:
        void removeBnB(BnB *);
        void editBnB(BnB *);
};

#endif // BNBLIST_H
