#include "mastermind.h"
#include "ui_mastermind.h"

mastermind::mastermind(QWidget *parent) : QWidget(parent), ui(new Ui::mastermind) {
    ui->setupUi(this);

    ClickableLabel* BouleN = new ClickableLabel("C:\\Users\\BELMONTE\\Pictures\\noire.png", "C:\\Users\\BELMONTE\\Pictures\\noireAp.png",this);
    BouleN->setGeometry(20,400, 80, 80);
    listeBoules.push_back(BouleN);

    ClickableLabel* BouleB = new ClickableLabel("C:\\Users\\BELMONTE\\Pictures\\bleu.png", "C:\\Users\\belmonte\\Pictures\\bleuAp.png", this);
    BouleB->setGeometry(100,400, 80, 80);
    listeBoules.push_back(BouleB);

    ClickableLabel* BouleR = new ClickableLabel("C:\\Users\\BELMONTE\\Pictures\\rouge.png", "C:\\Users\\BELMONTE\\Pictures\\rougeAp.png", this);
    BouleR->setGeometry(180,400, 80, 80);
    listeBoules.push_back(BouleR);

    ClickableLabel* BouleJ = new ClickableLabel("C:\\Users\\BELMONTE\\Pictures\\jaune.png", "C:\\Users\\BELMONTE\\Pictures\\jauneAp.png", this);
    BouleJ->setGeometry(260,400, 80, 80);
    listeBoules.push_back(BouleJ);

    ClickableLabel* BouleV = new ClickableLabel("C:\\Users\\BELMONTE\\Pictures\\vert.png", "C:\\Users\\BELMONTE\\Pictures\\vertAp.png", this);
    BouleV->setGeometry(340,400, 80, 80);
    listeBoules.push_back(BouleV);

    ClickableLabel* BouleO = new ClickableLabel("C:\\Users\\BELMONTE\\Pictures\\orange.png", "C:\\Users\\BELMONTE\\Pictures\\orangeAp.png", this);
    BouleO->setGeometry(420,400, 80, 80);
    listeBoules.push_back(BouleO);

}

mastermind::~mastermind() {
    delete ui;
}


