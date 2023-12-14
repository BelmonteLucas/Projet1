#include "mastermind.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mastermind w;
    w.show();
    return a.exec();
}
