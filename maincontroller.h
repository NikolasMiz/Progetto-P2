#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "model.h"

#include <QWidget>

#include <gui/showbnb/bnbmenu.h>

class MainController : public QWidget {
    Q_OBJECT
public:
    MainController(QWidget *parent = nullptr);
    ~MainController();
protected:
    void closeEvent(QCloseEvent *) override;

private:
    Model *model;

    BnBMenu *bnbMenu;

};

#endif // MAINCONTROLLER_H
