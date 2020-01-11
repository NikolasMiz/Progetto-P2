#ifndef HOTELINFOWIDGET_H
#define HOTELINFOWIDGET_H

#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>

class HotelInfoWidget : public QGroupBox {

public:
    HotelInfoWidget(QWidget *parent = nullptr);

    QLineEdit *getTaxLineEdit() const;

    QLineEdit *getNameLineEdit() const;

    QComboBox *getStarsCBox() const;

    QString getHotelName() const;

    void setName(QString name) const;

    void setTax(double tax) const;

    void setStars(unsigned int stars);
private:

    QLineEdit *taxLineEdit;
    QLineEdit *nameLineEdit;

    QComboBox *starsCBox;

};


#endif // HOTELINFOWIDGET_H
