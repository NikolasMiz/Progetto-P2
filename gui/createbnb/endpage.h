#ifndef ENDPAGE_H
#define ENDPAGE_H

#include <QLabel>
#include <QWizardPage>
#include <QTextEdit>

#include <core/bnb.h>


class EndPage : public QWizardPage {
    Q_OBJECT

public:
    EndPage(const BnB *editBnB = nullptr, QWidget *parent = nullptr);

    QString getDescription() const;

private:

    QTextEdit *descrEdit;
};


#endif // ENDPAGE_H
