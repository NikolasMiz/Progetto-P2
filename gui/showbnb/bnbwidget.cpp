#include "bnbwidget.h"
#include "showbnb.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include<sstream>
#include<QFile>
#include<QMessageBox>

BnBWidget::BnBWidget(BnB *bnb, unsigned int guest, QWidget *parent) :
        QWidget(parent), bnb(bnb), guest(guest) {
    QHBoxLayout *master = new QHBoxLayout();
    QVBoxLayout *layout = new QVBoxLayout();


    showWidget = new ShowBnB(bnb);
    auto path = "img/" + QString::fromStdString(bnb->getId());

    if (!QFile::exists(path)) {
        path = ":/gui/img/bnb";
    }
    QLabel *img = new QLabel();
    img->setPixmap(QPixmap(path).scaled(200, 100, Qt::KeepAspectRatio));
    img->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    img->setMaximumWidth(200);
    master->addWidget(img);

    QLabel *title = new QLabel(QString::fromStdString(bnb->getName()));
    QFont f = title->font();
    f.setBold(true);
    f.setPointSize(16);
    title->setFont(f);

    layout->addWidget(title);


    std::stringstream ss;
    ss << *bnb;
    QLabel *content = new QLabel(QString::fromStdString(ss.str()));
    layout->addWidget(content);
    content->setWordWrap(true);

    master->addLayout(layout);

    if (guest > 0) {
        QLabel *price = new QLabel(QString::number(bnb->estimatePrice(guest)).append("€/notte"));

        QFont f2 = title->font();
        f2.setBold(true);
        f2.setPointSize(22);
        price->setFont(f2);
        master->addWidget(price);
    }

    del = new QPushButton("X");
    del->setFixedSize(20, 20);
    edit = new QPushButton("✎");
    edit->setFixedSize(20, 20);

    master->addWidget(del);
    master->addWidget(edit);

    setLayout(master);

    connect(del, &QPushButton::clicked, this, [this]() {

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "AirPnP", "Eliminare il BnB?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            emit removeBnB(this->bnb);
        }

    });
    connect(edit, &QPushButton::clicked, this, [this]() {
        emit editBnB(this->bnb);
    });
}

void BnBWidget::readOnly(bool b) {
    del->setVisible(!b);
    edit->setVisible(!b);
}

void BnBWidget::mousePressEvent(QMouseEvent *event) {
    showWidget->show();
    QWidget::mousePressEvent(event);
}

BnB *BnBWidget::getBnb() const
{
    return bnb;
}



