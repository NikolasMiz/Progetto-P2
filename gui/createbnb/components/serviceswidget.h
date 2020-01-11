#ifndef SERVICESWIDGET_H
#define SERVICESWIDGET_H


#include "servicecheckbox.h"

#include <QGroupBox>
#include <QGridLayout>

class ServicesWidget : public QGroupBox {

    Q_OBJECT

public:
    ServicesWidget(QWidget *parent = nullptr);

    void addService(const QString &name, Service id);

    QList <Service> getServices() const;

    void checkServices(const std::list <Service>&) const;

    void reset() const;

    ~ServicesWidget();

    signals:
        void uncheckedService(Service s);
        void checkedService(Service s);

private:
    QGridLayout *servicesLayout;
    QList<ServiceCheckBox *> servicesListCheck;

};

#endif // SERVICESWIDGET_H
