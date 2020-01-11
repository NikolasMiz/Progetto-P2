#ifndef BASEINFOWIDGET_H
#define BASEINFOWIDGET_H


#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>

class BaseInfoWidget : public QGroupBox {

public:
    BaseInfoWidget(QWidget *parent = nullptr);

    QLineEdit *getBnbNameLineEdit() const;

    QLineEdit *getCityLineEdit() const;

    QLineEdit *getAddressLineEdit() const;

    QString getBnbName() const;

    QString getCity() const;

    QString getAddress() const;

    void setBnbName(const QString &name) const;

    void setCity(const QString &city) const;

    void setAddress(const QString &address) const;

private:

    QLineEdit *bnbNameLineEdit;
    QLineEdit *cityLineEdit;
    QLineEdit *addressLineEdit;

};

#endif // BASEINFOWIDGET_H
