#ifndef SHOWBNB_H
#define SHOWBNB_H

#include <QWidget>

#include <core/bnb.h>


class ShowBnB : public QWidget {
public:
    ShowBnB(const BnB *bnb, QWidget *parent = nullptr);

private:
    const BnB *bnb;
};

#endif // SHOWBNB_H
