#ifndef BNBMENU_H
#define BNBMENU_H

#include "bnblist.h"
#include "searchwidget.h"

#include <QPushButton>
#include <QWidget>
#include "model.h"

#include <gui/createbnb/createbnbwizard.h>

#include <core/qontainer.h>

class BnBMenu : public QWidget {
    Q_OBJECT

public:
    BnBMenu(Model *, QWidget *parent = nullptr);
    void deleteUselessImages(bool save);

private:
    QPushButton *createBtt;
    QPushButton *deleteAllBtt;

    BnBList *bnbList;
    BnB *tmp;
    CreateBnBWizard *wizard;
    BnBList *list;
    Model *model;
    QList<QString> deleted; // deleted and not saved id
    QList<QString> created; // created and not saved id
    bool isReadOnly = false;

    void clearFilter() const;

    void enableAdmin();

    void disableAdmin();

private:
    SearchWidget *searchMenu ;
private
    slots:
       void switchAdmin();
       void applyFilter();
       void resetFilter();
       void createBnB();
       void editBnB(BnB *);
       void deleteBnB(BnB*);
       void deleteAllResults();

};

#endif // BNBMENU_H
