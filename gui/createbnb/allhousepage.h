#ifndef ALLHOUSEPAGE_H
#define ALLHOUSEPAGE_H

#include <QWizard>

#include <gui/createbnb/components/allhouseinfowidget.h>

#include <core/bnb.h>


class AllHousePage : public QWizardPage {
public:
    AllHousePage(const BnB *edit = nullptr, QWidget *parent = nullptr);

    bool validatePage() override;

private:
    AllHouseInfoWidget *info;
};

#endif // ALLHOUSEPAGE_H
