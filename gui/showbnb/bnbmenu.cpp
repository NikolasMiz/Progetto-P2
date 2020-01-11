#include "bnbmenu.h"
#include "searchwidget.h"

#include <gui/createbnb/createbnbwizard.h>

#include <core/hotelroom.h>

#include <QAction>
#include <QFile>
#include <QMessageBox>
#include <QScrollArea>
#include <QShortcut>
#include <QInputDialog>

BnBMenu::BnBMenu(Model *model, QWidget *parent) : QWidget(parent), tmp(nullptr), wizard(nullptr), model(model),
    isReadOnly(false){

    setMinimumHeight(600);
    setMinimumWidth(1200);

    QHBoxLayout *masterLayout = new QHBoxLayout(this);


    /************************LEFT SIDE*******************************************/
    list = new BnBList(model->getResult());
    createBtt = new QPushButton("Nuovo");
    deleteAllBtt = new QPushButton("Rimuovi tutti i risultati");

    QLabel *hint = new QLabel("Clicca su un BnB per ulteriori informazioni");
    auto hintFont = hint->font();
    hintFont.setItalic(true);
    hintFont.setPixelSize(10);
    hint->setFont(hintFont);
    QVBoxLayout *bnbLayout = new QVBoxLayout();
    bnbLayout->addWidget(createBtt);
    bnbLayout->addWidget(deleteAllBtt);
    bnbLayout->addWidget(hint);

    QScrollArea *scroll = new QScrollArea();
    scroll->setWidgetResizable(true);
    scroll->setWidget(list);
    bnbLayout->addWidget(scroll);



    /************************SEARCH MENU********************************/

    searchMenu = new SearchWidget();

    QWidget *listMenu = new QWidget();
    listMenu->setLayout(bnbLayout);
    masterLayout->addWidget(searchMenu);

    masterLayout->addWidget(listMenu);

    QAction *adminAction = new QAction(this);
    adminAction->setShortcut(Qt::Key_Q | Qt::CTRL);
    this->addAction(adminAction);
    connect(adminAction, SIGNAL(triggered()), this, SLOT(switchAdmin()));


    connect(list, &BnBList::removeBnB, this, &BnBMenu::deleteBnB);

    connect(list, &BnBList::editBnB, this, &BnBMenu::editBnB);

    connect(createBtt, &QPushButton::clicked, this, &BnBMenu::createBnB);

    connect(deleteAllBtt, &QPushButton::clicked, this, &BnBMenu::deleteAllResults);

    connect(searchMenu->getSearchBtt(), &QPushButton::clicked, this, &BnBMenu::applyFilter);

    connect(searchMenu->getClearBtt(), &QPushButton::clicked, this, &BnBMenu::resetFilter);
}

void BnBMenu::deleteUselessImages(bool save)
{
    if(save)
        for (auto it = deleted.begin(); it != deleted.end(); ++it) {
            auto path = "img/" + (*it);
            if(QFile::exists(path))
                QFile::remove(path);
        }
    deleted.clear();
    if(!save) {
        for (auto it = created.begin(); it != created.end(); ++it) {
            auto path = "img/" + (*it);
            if(QFile::exists(path))
                QFile::remove(path);
        }
    }
    created.clear();
}


void BnBMenu::clearFilter() const {
  searchMenu->clearFilter();
}

void BnBMenu::enableAdmin() {

    bool ok;
    QString text = QInputDialog::getText(nullptr, "AirPnP",
                                         "Per abilitare i controlli admin viene richiesta una password: (pass1234)", QLineEdit::Password,
                                         "", &ok);
    if(!ok || text != "pass1234") {
        return;
    }

    createBtt->show();
    deleteAllBtt->show();
    deleteAllBtt->show();
    isReadOnly = false;
    list->readOnly(false);

}

void BnBMenu::disableAdmin() {
    createBtt->hide();
    deleteAllBtt->hide();
    isReadOnly = true;
    list->readOnly(true);
}

void BnBMenu::switchAdmin() {
    if (!isReadOnly)
        disableAdmin();
    else {
        enableAdmin();
    }
}

void BnBMenu::applyFilter()
{
    Query q(searchMenu->getName(), searchMenu->getCity(), searchMenu->isPrivate(),
            searchMenu->isShared(),
            searchMenu->isHotel(), searchMenu->isAllHouse(), searchMenu->getServices());
    this->model->filter(q);
    if (searchMenu->getGuests() == 0)
        list->update();
    else {
        list->update(searchMenu->getGuests());
    }
    list->readOnly(isReadOnly);
}

void BnBMenu::resetFilter()
{
    this->model->resetFilter();
    this->clearFilter();
    list->update();
    list->readOnly(isReadOnly);
}

void BnBMenu::createBnB()
{
    delete wizard;
    wizard = new CreateBnBWizard(nullptr, this);
    connect(wizard, &CreateBnBWizard::finished, this, [this]() {
        tmp = wizard->res;
        created.push_back(QString::fromStdString(tmp->getId()));
        this->model->addItem(tmp);

        this->resetFilter();
    });

    wizard->show();
}

void BnBMenu::editBnB(BnB* bnb)
{
    delete wizard;
    wizard = new CreateBnBWizard(bnb, this);
    connect(wizard, &CreateBnBWizard::finished, this, [this, bnb]() {
        deleted.push_back(QString::fromStdString(bnb->getId()));

        this->model->deleteItem(bnb);
        tmp = wizard->res;
        this->model->addItem(tmp);

        created.push_back(QString::fromStdString(tmp->getId()));

        resetFilter();
    });

    wizard->show();
}

void BnBMenu::deleteBnB(BnB *bnb)
{
    deleted.push_back(QString::fromStdString(bnb->getId()));
    this->model->deleteItem(bnb);
    list->update();
}

void BnBMenu::deleteAllResults()
{

    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "AirPnP", "Sei sicuro di voler eliminare tutti i seguenti BnB?",
                                    QMessageBox::Yes|QMessageBox::No);

      if (reply == QMessageBox::Yes) {
          auto removeList = this->model->getResult();
          for(auto it = removeList->begin(); it != removeList->end(); ++it) {
              deleted.push_back(QString::fromStdString((*it)->getId()));
              this->model->deleteItem(*it, false);
          }
          model->resetFilter();
          list->update();
          QString res = "I BnB selezionati sono stati eliminati, tornerai alla lista completa";
          QMessageBox success;
          success.setText(res);
          success.exec();
      }


}
