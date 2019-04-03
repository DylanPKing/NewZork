#include "inventorywindow.h"
#include "ui_inventorywindow.h"

InventoryWindow::InventoryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InventoryWindow)
{
    ui->setupUi(this);
}

InventoryWindow::~InventoryWindow()
{
    delete ui;
}

void InventoryWindow::on_okBtn_clicked()
{
    close();
}

void InventoryWindow::setText(Character &characterBoi)
{
    ui->out->setText(characterBoi.showInventory());
}
