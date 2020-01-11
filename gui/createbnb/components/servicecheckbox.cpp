#include "servicecheckbox.h"


ServiceCheckBox::ServiceCheckBox(const QString &text, Service s, QWidget *parent)
        : QCheckBox(text, parent), service(s) {

}

Service ServiceCheckBox::getService() const {
    return service;
}

void ServiceCheckBox::check() {
    setChecked(true);
}

ServiceCheckBox::ServiceCheckBox(QWidget *parent)
        : QCheckBox(parent) {

}
