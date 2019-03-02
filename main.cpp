#include <QApplication>

#include "mainwindow.h"

#include "ZorkCore.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //ZorkCore game;
    //game.play();

    w.show();

    return a.exec();

}
