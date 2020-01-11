#include "allhouseinfowidget.h"

#include <QFormLayout>

AllHouseInfoWidget::AllHouseInfoWidget(QWidget *parent)
        : QGroupBox("Informazioni della casa", parent) {

    nBedsLabel = new QLabel(tr("Numero di letti a disposizione"), this);
    nBedsLineEdit = new QLineEdit(this);
    auto iVal = new QIntValidator(0, 998, this);
    nBedsLineEdit->setValidator(iVal);
    nBedsLabel->setBuddy(nBedsLineEdit);


    priceLabel = new QLabel(tr("Prezzo affitto giornaliero"), this);
    priceLineEdit = new QLineEdit(this);
    auto dVal = new QDoubleValidator(0, 99998, 2, this);
    dVal->setNotation(QDoubleValidator::StandardNotation);
    priceLineEdit->setValidator(dVal);
    priceLabel->setBuddy(priceLineEdit);


    cleaningLabel = new QLabel(tr("Prezzo pulizie"), this);
    cleaningLineEdit = new QLineEdit(this);
    auto dVal2 = new QDoubleValidator(0, 999, 2, this);
    dVal2->setNotation(QDoubleValidator::StandardNotation);
    cleaningLineEdit->setValidator(dVal2);
    cleaningLabel->setBuddy(cleaningLineEdit);


    nFloorsLabel = new QLabel(tr("Numero di piani"), this);
    nFloorsLineEdit = new QLineEdit(this);
    nFloorsLineEdit->setValidator(iVal);
    nFloorsLabel->setBuddy(nFloorsLineEdit);


    mqLabel = new QLabel(tr("Metri quadrati"), this);
    mqLineEdit = new QLineEdit(this);
    auto dVal3 = new QDoubleValidator(0, 999, 2, this);
    dVal3->setNotation(QDoubleValidator::StandardNotation);
    mqLineEdit->setValidator(dVal3);
    mqLabel->setBuddy(mqLineEdit);


    canTakeOnCleaningLabel = new QLabel(tr("Il cliente si puo' farsi\ncarico delle pulizie?"), this);
    canTakeOnCleaningCBox = new QComboBox(this);
    canTakeOnCleaningCBox->addItem(tr("No"));
    canTakeOnCleaningCBox->addItem(tr("Si"));


    QFormLayout *layout = new QFormLayout(this);
    layout->setFormAlignment(Qt::AlignLeft);
    layout->addRow(nBedsLabel, nBedsLineEdit);
    layout->addRow(priceLabel, priceLineEdit);
    layout->addRow(cleaningLabel, cleaningLineEdit);
    layout->addRow(nFloorsLabel, nFloorsLineEdit);
    layout->addRow(mqLabel, mqLineEdit);
    layout->addRow(canTakeOnCleaningLabel, canTakeOnCleaningCBox);

}

QLineEdit *AllHouseInfoWidget::getNBedsLineEdit() const {
    return nBedsLineEdit;
}

QLineEdit *AllHouseInfoWidget::getPriceLineEdit() const {
    return priceLineEdit;
}

QLineEdit *AllHouseInfoWidget::getCleaningLineEdit() const {
    return cleaningLineEdit;
}

QLineEdit *AllHouseInfoWidget::getMqLineEdit() const {
    return mqLineEdit;
}

QLineEdit *AllHouseInfoWidget::getNFloorsLineEdit() const {
    return nFloorsLineEdit;
}

QComboBox *AllHouseInfoWidget::getCanTakeOnCleaningCBox() const {
    return canTakeOnCleaningCBox;
}

void AllHouseInfoWidget::setNBeds(unsigned int nBeds) const {
    nBedsLineEdit->setText(QString::number(nBeds));
}

void AllHouseInfoWidget::setPrice(double price) const {
    priceLineEdit->setText(QString::number(price));

}

void AllHouseInfoWidget::setCleaning(double cleaning) const {
    cleaningLineEdit->setText(QString::number(cleaning));

}

void AllHouseInfoWidget::setMq(double mq) const {
    mqLineEdit->setText(QString::number(mq));

}

void AllHouseInfoWidget::setNFloors(unsigned int floors) const {
    nFloorsLineEdit->setText(QString::number(floors));

}

void AllHouseInfoWidget::setCanTakeOnCleaning(bool c) const {
    canTakeOnCleaningCBox->setCurrentIndex(!c ? 0 : 1);
}

unsigned int AllHouseInfoWidget::getNBeds() const {
    return static_cast<unsigned int>(nBedsLineEdit->text().toInt());
}

double AllHouseInfoWidget::getPrice() const {
    return priceLineEdit->text().toDouble();

}

double AllHouseInfoWidget::getCleaningPrice() const {
    return cleaningLineEdit->text().toDouble();

}

double AllHouseInfoWidget::getMq() const {
    return mqLineEdit->text().toDouble();

}

unsigned int AllHouseInfoWidget::getNFloors() const {
    return static_cast<unsigned int>(nFloorsLineEdit->text().toInt());

}

bool AllHouseInfoWidget::getCanTakeOnCleaning() const {
    return canTakeOnCleaningCBox->currentIndex() == 1;

}

