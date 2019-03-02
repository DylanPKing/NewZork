#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkCore.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createButtons();
    createTextField();
}

MainWindow::~MainWindow()
{
    delete ui;
    foreach (QPushButton *p, directions)
        delete p;
    delete out;
    delete teleport;
}

void MainWindow::createButtons()
{
    const QString dirs[] = {"North", "East", "South", "West", "Teleport"};
    for (int i = 0; i < 5; ++i)
    {
        directions.push_back(new QPushButton(this));
        directions[i]->setText(dirs[i]);
    }
    directions[0]->setGeometry(QRect(QPoint(100, 400), QSize(50, 30)));
    directions[1]->setGeometry(QRect(QPoint(150, 400), QSize(50, 60)));
    directions[2]->setGeometry(QRect(QPoint(100, 430), QSize(50, 30)));
    directions[3]->setGeometry(QRect(QPoint(50, 400), QSize(50, 60)));
    directions[4]->setGeometry(QRect(QPoint(200, 400), QSize(100, 60)));
}

void MainWindow::createTextField()
{
    out = new QPlainTextEdit();

}
