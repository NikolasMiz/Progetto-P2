#include "maincontroller.h"

#include <QAction>
#include <QApplication>
#include <QCloseEvent>
#include <QDir>
#include<QMessageBox>
#include <QToolBar>

MainController::MainController(QWidget *parent) : QWidget(parent), model(new Model("data.xml")) {
    move(0, 0);
    QVBoxLayout *layout = new QVBoxLayout(this);


    bnbMenu = new BnBMenu(model);
    if (!QDir("img").exists()) {
        QDir().mkdir("img");
    }
    layout->addWidget(bnbMenu);


    QAction *saveAction = new QAction(this);
    saveAction->setShortcut(Qt::Key_S | Qt::CTRL);
    this->addAction(saveAction);

    connect(saveAction, &QAction::triggered, this, [this](){
        this->model->save();
        bnbMenu->deleteUselessImages(true);
    });

}

MainController::~MainController()
{
    delete model;
}

void MainController::closeEvent(QCloseEvent *) {

    bool save = false;
    if (!model->getIsEdited() ||
            QMessageBox::question(this, "AirPnP","Desideri salvare le modifiche?",QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        model->save();
        save = true;
    }
    bnbMenu->deleteUselessImages(save);
    QApplication::quit();

}
