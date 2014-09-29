#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabel("Header");
    QTreeWidgetItem *item1 = new QTreeWidgetItem(ui->treeWidget);
    item1->setText(0, "NewItem");

    QTreeWidgetItem *item2 = new QTreeWidgetItem(ui->treeWidget);
    item2->setText(0, "NewItem");
    QTreeWidgetItem *item21 = new QTreeWidgetItem(item2, QStringList() << "New Sub Item");
    QTreeWidgetItem *item22 = new QTreeWidgetItem(item2, QStringList() << "New Item");
    QTreeWidgetItem *item221 = new QTreeWidgetItem(item22, QStringList() << "New Sub Item");
    QTreeWidgetItem *item2211 = new QTreeWidgetItem(item221, QStringList() << "New Sub Item");
    QTreeWidgetItem *item2212 = new QTreeWidgetItem(item221, QStringList() << "New Sub Item");
    QTreeWidgetItem *item23 = new QTreeWidgetItem(item2, QStringList() <<"New Item");

    QTreeWidgetItem *item3 = new QTreeWidgetItem(ui->treeWidget, QStringList() << "New Item");
    QTreeWidgetItem *item31 = new QTreeWidgetItem(item3, QStringList() << "");

    QTreeWidgetItem *item4 = new QTreeWidgetItem(ui->treeWidget, QStringList() << "New Item");

    ui->treeWidget->expandAll();
    item3->setExpanded(false);
    item4->setExpanded(false);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_treeWidget_itemExpanded(QTreeWidgetItem *item)
{
    if (item->childCount() > 0) {
        if (item->child(0)->text(0).isEmpty()) {
            item->setExpanded(false);
        }
    }
}
