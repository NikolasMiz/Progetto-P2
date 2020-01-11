#include "endpage.h"
#include <QTextEdit>
#include <QVBoxLayout>

EndPage::EndPage(const BnB *editBnB, QWidget *parent)
        : QWizardPage(parent) {
    setTitle("Abbiamo quasi finito");

    QLabel *label = new QLabel("Se desideri aggiungere informazioni aggiuntive puoi farlo qui sotto");
    label->setWordWrap(true);

    descrEdit = new QTextEdit();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(descrEdit);

    if (editBnB) {
        descrEdit->setText(QString::fromStdString(editBnB->getDescription()));
    }

}

QString EndPage::getDescription() const {
    return descrEdit->toPlainText();
}
