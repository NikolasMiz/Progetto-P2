#include "hotelinfowidget.h"

#include <QFormLayout>

HotelInfoWidget::HotelInfoWidget(QWidget *parent) : QGroupBox(tr("Informazioni hotel"), parent) {

    QLabel *nameLabel = new QLabel(tr("Nome dell'hotel"));
    nameLineEdit = new QLineEdit();
    nameLabel->setBuddy(nameLineEdit);

    QLabel *taxLabel = new QLabel(tr("Tassa di soggiorno (a persona)"), this);
    taxLineEdit = new QLineEdit();
    auto dVal = new QDoubleValidator(0, 99, 2, this);
    dVal->setNotation(QDoubleValidator::StandardNotation);
    taxLineEdit->setValidator(dVal);
    taxLabel->setBuddy(taxLineEdit);

    QLabel *starsLabel = new QLabel(tr("Stelle dell'hotel"));
    starsCBox = new QComboBox();
    starsCBox->addItem(tr("2"));
    starsCBox->addItem(tr("3"));
    starsCBox->addItem(tr("4"));
    starsCBox->addItem(tr("5"));

    QFormLayout *hotelLayout = new QFormLayout(this);
    hotelLayout->setFormAlignment(Qt::AlignLeft);
    hotelLayout->addRow(nameLabel, nameLineEdit);
    hotelLayout->addRow(taxLabel, taxLineEdit);
    hotelLayout->addRow(starsLabel, starsCBox);

}

QLineEdit *HotelInfoWidget::getTaxLineEdit() const {
    return taxLineEdit;
}

QLineEdit *HotelInfoWidget::getNameLineEdit() const {
    return nameLineEdit;
}

QComboBox *HotelInfoWidget::getStarsCBox() const {
    return starsCBox;
}

QString HotelInfoWidget::getHotelName() const {
    return nameLineEdit->text();
}

void HotelInfoWidget::setName(QString name) const
{
    nameLineEdit->setText(name);
}

void HotelInfoWidget::setTax(double tax) const
{
    taxLineEdit->setText(QString::number(tax));
}

void HotelInfoWidget::setStars(unsigned int stars)
{
    starsCBox->setCurrentIndex(starsCBox->findText(QString::number(stars)));
}
