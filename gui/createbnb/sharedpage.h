#ifndef SHAREPAGE_H
#define SHAREPAGE_H

#include <QWizardPage>

#include <gui/createbnb/components/sharedinfowidget.h>

#include <core/bnb.h>

class SharedPage : public QWizardPage {
    Q_OBJECT

public:
    SharedPage(const BnB *edit = nullptr, QWidget *parent = nullptr);

    int nextId() const override;

    bool validatePage() override;

private:
    SharedInfoWidget *roomInfoBox;
};


#endif // SHAREPAGE_H
