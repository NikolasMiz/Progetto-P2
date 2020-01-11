#include "sharedinfowidget.h"


#include <QFormLayout>

SharedInfoWidget::SharedInfoWidget(QWidget *parent) : QGroupBox(tr("Informazioni della struttura"), parent) {
    QLabel *nBedsLabel = new QLabel(tr("Numero di letti disponibili"));
    auto iVal = new QIntValidator(0, 998, this);
    nBedsLineEdit = new QLineEdit();
    nBedsLineEdit->setValidator(iVal);
    nBedsLabel->setBuddy(nBedsLineEdit);


    QLabel *pricePerBedLabel = new QLabel(tr("Costo per letto"));
    pricePerBedLineEdit = new QLineEdit();
    auto dVal = new QDoubleValidator(0, 99, 2, this);
    dVal->setNotation(QDoubleValidator::StandardNotation);
    pricePerBedLineEdit->setValidator(dVal);
    pricePerBedLabel->setBuddy(pricePerBedLineEdit);


    QFormLayout *shareLayout = new QFormLayout(this);
    shareLayout->setFormAlignment(Qt::AlignLeft);

    shareLayout->addRow(nBedsLabel, nBedsLineEdit);
    shareLayout->addRow(pricePerBedLabel, pricePerBedLineEdit);

}

QLineEdit *SharedInfoWidget::getNBedsLineEdit() const {
    return nBedsLineEdit;
}

QLineEdit *SharedInfoWidget::getPricePerBedLineEdit() const {
    return pricePerBedLineEdit;
}

void SharedInfoWidget::setNBeds(unsigned int beds) const {
    nBedsLineEdit->setText(QString::number(beds));
}

void SharedInfoWidget::setPrice(double price) const {
    pricePerBedLineEdit->setText(QString::number(price));
}
