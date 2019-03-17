#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPlainTextEdit>

#include "Character.h"
#include "Command.h"
#include "Item.h"
#include "weapon.h"
#include "Location.h"
#include "ZorkCore.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_playBtn_clicked();
    void on_quitBtn_clicked();

private:
    Ui::MainWindow *ui;
    ZorkCore *game;
};

#endif // MAINWINDOW_H
