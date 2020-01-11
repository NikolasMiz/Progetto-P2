#ifndef BASEPAGE_H
#define BASEPAGE_H


#include <QWizardPage>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QRadioButton>
#include <gui/createbnb/components/baseinfowidget.h>
#include <gui/createbnb/components/roomtypewidget.h>
#include <gui/createbnb/components/serviceswidget.h>
#include <core/bnb.h>


class BasePage : public QWizardPage {
    Q_OBJECT

public:
    BasePage(const BnB *edit = nullptr, QWidget *parent = nullptr);

    int nextId() const override;

    QList <Service> getServices() const;

    bool validatePage() override;

    QString id;

    const QString& getId() const;

private:

    BaseInfoWidget *baseInfo;
    RoomTypeWidget *roomType;
    ServicesWidget *servicesWidget;

    /*HIDDEN FIELD*/
    QLineEdit *idLE;
    QLineEdit *filepathLE;

};


#endif // BASEPAGE_H
