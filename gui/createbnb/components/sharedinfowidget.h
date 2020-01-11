#ifndef SHAREINFOWIDGET_H
#define SHAREINFOWIDGET_H

#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>

class SharedInfoWidget : public QGroupBox {

public:
    SharedInfoWidget(QWidget *parent = nullptr);

    QLineEdit *getNBedsLineEdit() const;

    QLineEdit *getPricePerBedLineEdit() const;

    void setNBeds(unsigned int beds) const;

    void setPrice(double price) const;

private:

    QLineEdit *nBedsLineEdit;
    QLineEdit *pricePerBedLineEdit;


};

#endif // SHAREINFOWIDGET_H
