#ifndef INVENTORYWINDOW_H
#define INVENTORYWINDOW_H

#include <QDialog>

#include "Character.h"

namespace Ui {
class InventoryWindow;
}

class InventoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InventoryWindow(QWidget *parent = nullptr);
    ~InventoryWindow();
    void setText(Character&);

private slots:
    void on_okBtn_clicked();

private:
    Ui::InventoryWindow *ui;
};

#endif // INVENTORYWINDOW_H
