#include "serviceswidget.h"

ServicesWidget::ServicesWidget(QWidget *parent) : QGroupBox(tr("Servizi"), parent) {
    servicesLayout = new QGridLayout(this);

    addService(tr("Wi-Fi"), Service::WIFI);
    addService(tr("Parcheggio gratuito"), Service::FREE_PARKING);
    addService(tr("Lavatrice"), Service::WASHING_MACHINE);
    addService(tr("Asciugatrice"), Service::DRYER);
    addService(tr("Carte di credito"), Service::POS);
}

void ServicesWidget::addService(const QString &name, Service id) {
    ServiceCheckBox *item = new ServiceCheckBox(name, id, this);
    servicesLayout->addWidget(item, servicesListCheck.length() / 2, servicesListCheck.length() % 2);
    servicesListCheck.push_back(item);

    connect(item, &ServiceCheckBox::stateChanged, this, [item, this](int state) {
        if (state == Qt::Checked)
            emit checkedService(item->getService());
        else
            emit uncheckedService(item->getService());
    });
}

QList <Service> ServicesWidget::getServices() const {
    QList <Service> s;
    for (auto it = servicesListCheck.begin(); it != servicesListCheck.end(); ++it) {
        if ((*it)->isChecked())
            s.push_back((*it)->getService());
    }
    return s;
}


void ServicesWidget::checkServices(const std::list<Service>& l) const {
    for (auto i = l.begin(); i != l.end(); ++i) {
        for (auto t = servicesListCheck.begin(); t != servicesListCheck.end(); ++t) {
            if ((*i) == (*t)->getService()) {
                (*t)->click();
                break;
            }
        }
    }
}

void ServicesWidget::reset() const {
    for (auto it = servicesListCheck.begin(); it != servicesListCheck.end(); ++it) {
        (*it)->setChecked(false);
    }
}

ServicesWidget::~ServicesWidget() {
    qDeleteAll(servicesListCheck.begin(), servicesListCheck.end());
    servicesListCheck.clear();
}


