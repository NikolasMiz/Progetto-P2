#ifndef CREATEBNBWIZARD_H
#define CREATEBNBWIZARD_H


#include "allhousepage.h"
#include "basepage.h"
#include "endpage.h"
#include "privatepage.h"
#include "sharedpage.h"

#include <QWizard>
#include <core/bnb.h>
#include <core/service.h>

class CreateBnBWizard : public QWizard {
    Q_OBJECT

public:
    CreateBnBWizard(const BnB *editBnB = nullptr, QWidget *parent = nullptr);

    void accept() override;

    enum {
        INTRO_PAGE, BASE_PAGE, PRIVATE_PAGE, SHARE_PARE, ALL_HOUSE_PAGE, END_PAGE
    };
    const BnB *editBnB;
    BnB *res;


    signals:
        void finished();

private:
    BasePage *basePage;
    PrivatePage *privatePage;
    SharedPage *sharePage;
    AllHousePage *allHousePage;
    EndPage *endPage;

};

#endif // CREATEBNBWIZARD_H
