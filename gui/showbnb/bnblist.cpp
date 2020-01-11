#include "bnblist.h"
#include "bnbwidget.h"
#include "showbnb.h"

#include <QSplitter>
#include <QVBoxLayout>
#include<algorithm>

BnBList::BnBList(Qontainer<BnB *> *list, QWidget *parent) :
        QWidget(parent), list(list) {

    bnblist = new QVBoxLayout();

    QWidget *empty = new QWidget();
    empty->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *master = new QVBoxLayout(this);
    master->addLayout(bnblist);
    master->addWidget(empty);

    update();
}

void BnBList::update(unsigned int guest) {


    widgets.clear();
    clearWidgets(bnblist);


    for (auto it = list->begin(); it != list->end(); ++it) {
        if (!(*it)->canGuestFit(guest)) continue;

        BnBWidget *w = new BnBWidget((*it), guest, this);
        widgets.push_back(w);

        connect(w, &BnBWidget::removeBnB, this, [this](BnB *bnb) {
            emit removeBnB(bnb);
        });

        connect(w, &BnBWidget::editBnB, this, [this](BnB *bnb) {
            emit editBnB(bnb);
        });




    }
    if (widgets.isEmpty() || list->empty()) {
        noResultLabel = new QLabel("Nessun risultato");
        bnblist->addWidget(noResultLabel);
    } else {
       std::sort(widgets.begin(), widgets.end(), [](const BnBWidget* a, const BnBWidget* b){
            auto aCity = QString::fromStdString(a->getBnb()->getCity()).toLower();
            auto bCity = QString::fromStdString(b->getBnb()->getCity()).toLower();

            if(aCity < bCity) {
                return true;
            } else if(aCity == bCity) {
                return QString::fromStdString(a->getBnb()->getName()).toLower() < QString::fromStdString(b->getBnb()->getName()).toLower();
            }
            return false;
        });
        for(auto it = widgets.begin(); it != widgets.end(); ++it) {
            bnblist->addWidget(*it);
            QFrame *line = new QFrame();
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);
            bnblist->addWidget(line);
        }
    }

}

void BnBList::readOnly(bool b) {
    for (auto it = widgets.begin(); it != widgets.end(); ++it) {
        (*it)->readOnly(b);
    }
}

void BnBList::clearWidgets(QLayout *layout) const
{
    if (!layout)
        return;
    while (auto item = layout->takeAt(0)) {
        delete item->widget();
        clearWidgets(item->layout());
    }
}

