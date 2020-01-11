#ifndef INTOPAGE_H
#define INTOPAGE_H

#include <QWizardPage>
#include <QLabel>

class IntroPage : public QWizardPage {
    Q_OBJECT

public:
    IntroPage(bool isEdit = false, QWidget *parent = nullptr);
};


#endif // INTOPAGE_H
