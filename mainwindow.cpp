#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new ZorkCore();
}

MainWindow::~MainWindow()
{
    delete game;
    delete ui;
}

void MainWindow::on_playBtn_clicked()
{
    game->printWelcome();
    game->show();
    hide();
}

void MainWindow::on_quitBtn_clicked()
{
    close();
}
