#include "intopage.h"
#include <QVBoxLayout>

IntroPage::IntroPage(bool isEdit, QWidget *parent)
        : QWizardPage(parent) {
    setTitle(tr(!isEdit ? "Crea il tuo nuovo annuncio" : "Modifica Annuncio"));

    QLabel *label = new QLabel(tr(!isEdit ? "Benvenuto/a, questa procedura ti aiuterà a creare il tuo nuovo annuncio "
                                    "per il tuo BnB"
                                  : "Benvenuto/a, questa procedura ti guiderà passo passo durante la modifica del "
                                    "tuo annuncio"));
    label->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
}
