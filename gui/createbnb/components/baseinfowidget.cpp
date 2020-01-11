#include "baseinfowidget.h"
#include <QFormLayout>

BaseInfoWidget::BaseInfoWidget(QWidget *parent) : QGroupBox(tr("Informazioni di base"), parent) {

    QLabel *bnbNameLabel = new QLabel(tr("Nome del BnB: "));
    bnbNameLineEdit = new QLineEdit();
    bnbNameLabel->setBuddy(bnbNameLineEdit);

    QLabel *cityLabel = new QLabel(tr("Città: "));
    cityLineEdit = new QLineEdit();
    cityLabel->setBuddy(cityLineEdit);

    QLabel *addressLabel = new QLabel(tr("Indirizzo: "));
    addressLineEdit = new QLineEdit();
    addressLabel->setBuddy(addressLineEdit);

    QFormLayout *baseLayout = new QFormLayout(this);
    baseLayout->setFormAlignment(Qt::AlignLeft);
    baseLayout->addRow(bnbNameLabel, bnbNameLineEdit);
    baseLayout->addRow(cityLabel, cityLineEdit);
    baseLayout->addRow(addressLabel, addressLineEdit);

    setLayout(baseLayout);
}

QLineEdit *BaseInfoWidget::getBnbNameLineEdit() const {
    return bnbNameLineEdit;
}

QLineEdit *BaseInfoWidget::getCityLineEdit() const {
    return cityLineEdit;
}

QLineEdit *BaseInfoWidget::getAddressLineEdit() const {
    return addressLineEdit;
}

QString BaseInfoWidget::getBnbName() const {
    return bnbNameLineEdit->text();
}

QString BaseInfoWidget::getCity() const {
    return cityLineEdit->text();
}

QString BaseInfoWidget::getAddress() const {
    return addressLineEdit->text();
}

void BaseInfoWidget::setBnbName(const QString &name) const {
    bnbNameLineEdit->setText(name);
}

void BaseInfoWidget::setCity(const QString &city) const {
    cityLineEdit->setText(city);
}

void BaseInfoWidget::setAddress(const QString &address) const {
    addressLineEdit->setText(address);
}
