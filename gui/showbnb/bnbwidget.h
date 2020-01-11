#ifndef BNBWIDGET_H
#define BNBWIDGET_H

#include "showbnb.h"

#include <QWidget>
#include <qpushbutton.h>

#include <core/bnb.h>


class BnBWidget : public QWidget {
    Q_OBJECT
public:
    BnBWidget(BnB *bnb, unsigned int guest = 0, QWidget *parent = nullptr);

    void readOnly(bool);

    BnB *getBnb() const;

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    BnB *bnb;
    unsigned int guest;
    ShowBnB *showWidget;
    QPushButton *del;
    QPushButton *edit;

    signals:
        void removeBnB(BnB*);
        void editBnB(BnB *);
};

#endif // BNBWIDGET_H
