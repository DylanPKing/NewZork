#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkCore.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createDirButtons();
}

MainWindow::~MainWindow()
{
    delete ui;
    foreach (QPushButton *p, directions)
        delete p;
    delete out;
    delete teleport;
}

void MainWindow::createDirButtons()
{
    const QString dirs[4] = {"North", "East", "South", "West"};
    for (int i = 0; i < 4; ++i)
    {
        directions[i] = new QPushButton(this);
        directions[i]->setText((*dirs)[i]);
        directions[i]->setGeometry(QRect(QPoint(0, 0), QSize(100, 50)));
    }
}
