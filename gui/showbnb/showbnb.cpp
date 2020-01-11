#include "showbnb.h"

#include <QVBoxLayout>
#include <QLabel>
#include<sstream>
#include<core/service.h>
#include<QFile>

ShowBnB::ShowBnB(const BnB *bnb, QWidget *parent) : QWidget(parent), bnb(bnb) {
    setMinimumWidth(600);

    QLabel *title = new QLabel(QString::fromStdString(bnb->getName()));
    QFont f = title->font();
    f.setBold(true);
    f.setPointSize(22);
    title->setFont(f);


    std::stringstream ss;
    ss << *bnb;
    QLabel *content = new QLabel(QString::fromStdString(ss.str()));
    content->setWordWrap(true);

    QLabel *descr = new QLabel(QString::fromStdString(bnb->getDescription()));

    QFont descrFont = descr->font();
    descrFont.setPointSize(14);
    descr->setFont(descrFont);
    descr->setWordWrap(true);

    QVBoxLayout *master = new QVBoxLayout(this);
    master->addWidget(title);
    master->addWidget(content);
    master->addWidget(descr);

    if (bnb->getServices().size() > 0) {
        QString services = "<hr>Servizi offerti:<ul>";
        for (auto it = bnb->getServices().begin(); it != bnb->getServices().end(); ++it) {
            services = services + "<li>";
            QString s = "";

            switch (*it) {
                case Service::WIFI:
                    s = "WIFI incluso";
                    break;
                case Service::POS:
                    s = "Pagamento con carte di credito";
                    break;
                case Service::FREE_PARKING:
                    s = "Parcheggio gratuito";
                    break;
                case Service::BREAKFAST_IN_BNB:
                    s = "Colazione";
                    break;
                case Service::WASHING_MACHINE:
                    s = "Lavatrice";
                    break;
                case Service::DRYER:
                    s = "Asciugatrice";
                    break;
            }
            services = services + s + "</li>";
        }

        services += "</ul>";
        QLabel *servicesLabel = new QLabel(services);
        master->addWidget(servicesLabel);


    }


    auto path = "img/" + QString::fromStdString(bnb->getId());
    if (QFile::exists(path)) {
        QLabel *img = new QLabel();
        img->setPixmap(QPixmap(path).scaled(500, 500, Qt::KeepAspectRatio));
        img->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        master->addWidget(img);
    }

}

