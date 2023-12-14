#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <QWidget>
#include "clickablelabel.h"

namespace Ui {
    class mastermind;
}

class mastermind : public QWidget {
    Q_OBJECT

public:
    explicit mastermind(QWidget *parent = nullptr);
    ~mastermind();


private:
    Ui::mastermind *ui;
    QVector<ClickableLabel*> listeBoules;

};

#endif // MASTERMIND_H
