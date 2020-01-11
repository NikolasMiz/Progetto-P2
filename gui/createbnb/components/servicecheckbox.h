#ifndef SERVICECHECKBOX_H
#define SERVICECHECKBOX_H


#include <QCheckBox>
#include <core/service.h>

class ServiceCheckBox : public QCheckBox {
public:
    ServiceCheckBox(QWidget *parent = nullptr);

    ServiceCheckBox(const QString &text = "", Service s = Service::WIFI, QWidget *parent = nullptr);

    Service getService() const;

    void check();

private:
    Service service;
};


#endif // SERVICECHECKBOX_H
