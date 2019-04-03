#include <QApplication>

#include "mainwindow.h"

/*
 * Win condition: pick up sword, breastplate, and helmet, and drop in room j
 * Lose condition: enter room f
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();

}
