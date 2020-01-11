#ifndef ALLHOUSEINFOWIDGET_H
#define ALLHOUSEINFOWIDGET_H

#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>


class AllHouseInfoWidget : public QGroupBox {
public:
    AllHouseInfoWidget(QWidget *parent = nullptr);

    QLineEdit *getNBedsLineEdit() const;

    QLineEdit *getPriceLineEdit() const;

    QLineEdit *getCleaningLineEdit() const;

    QLineEdit *getMqLineEdit() const;

    QLineEdit *getNFloorsLineEdit() const;

    QComboBox *getCanTakeOnCleaningCBox() const;

    void setNBeds(unsigned int nBeds) const;

    void setPrice(double price) const;

    void setCleaning(double cleaning) const;

    void setMq(double mq) const;

    void setNFloors(unsigned int floors) const;

    void setCanTakeOnCleaning(bool c) const;

    unsigned int getNBeds() const;

    double getPrice() const;

    double getCleaningPrice() const;

    double getMq() const;

    unsigned int getNFloors() const;

    bool getCanTakeOnCleaning() const;

private:
    QLabel *priceLabel;
    QLabel *canTakeOnCleaningLabel;
    QLabel *nBedsLabel;
    QLabel *cleaningLabel;
    QLabel *mqLabel;
    QLabel *nFloorsLabel;

    QLineEdit *nBedsLineEdit;
    QLineEdit *priceLineEdit;
    QLineEdit *cleaningLineEdit;
    QLineEdit *mqLineEdit;
    QLineEdit *nFloorsLineEdit;

    QComboBox *canTakeOnCleaningCBox;

};

#endif // ALLHOUSEINFOWIDGET_H
