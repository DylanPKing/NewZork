#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPlainTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void createButtons();
    void createTextField();

    QVector<QPushButton*> directions;
    QPushButton *teleport;
    QPlainTextEdit *out;
};

#endif // MAINWINDOW_H
