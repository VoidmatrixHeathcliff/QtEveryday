#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
    connect(ui->treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(treeItemChanged(QTreeWidgetItem*, int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    ui->treeWidget->clear();
    ui->treeWidget->setHeaderLabel("树状视图");
    // 第一个分组
    QTreeWidgetItem *group1 = new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0, "group1");
    group1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    group1->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *subItem1 = new QTreeWidgetItem(group1);
    subItem1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem1->setText(0, "subItem1");
    subItem1->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *subItem2 = new QTreeWidgetItem(group1);
    subItem2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem2->setText(0, "subItem2");
    subItem2->setCheckState(0, Qt::Unchecked);

    // 第二个分组
    QTreeWidgetItem *group2 = new QTreeWidgetItem(ui->treeWidget);
    group2->setText(0, "group2");
    group2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    group2->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *subItem3 = new QTreeWidgetItem(group2);
    subItem3->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem3->setText(0, "subItem3");
    subItem3->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *subItem4 = new QTreeWidgetItem(group2);
    subItem4->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem4->setText(0, "subItem4");
    subItem4->setCheckState(0, Qt::Unchecked);
}

void Widget::treeItemChanged(QTreeWidgetItem *item, int column)
{
    if (Qt::Checked == item->checkState(column))
    {
        int count = item->childCount();
        if(count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                item->child(i)->setCheckState(column, Qt::Checked);
            }
        }
        else
        {
            updateParaentItem(item);
        }
    }
    else if (Qt::Unchecked == item->checkState(column)) {
        int count = item->childCount();
        if(count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                item->child(i)->setCheckState(column, Qt::Unchecked);
            }
        }
        else
        {
            updateParaentItem(item);
        }
    }
}

void Widget::updateParaentItem(QTreeWidgetItem *item)
{
    QTreeWidgetItem *parent = item->parent();
    if (parent == nullptr)
    {
        return;
    }
    // 选中的子节点个数
    int selectedCount = 0;
    int childCound = parent->childCount();
    for (int i = 0; i < childCound; i++)
    {
        QTreeWidgetItem *childItem = parent->child(i);
        if (childItem->checkState(0) == Qt::Checked)
        {
            selectedCount++;
        }
    }
    if (selectedCount <= 0)
    {
        // 未选中状态
        parent->setCheckState(0, Qt::Unchecked);
    }
    else if (selectedCount > 0 && selectedCount < childCound) {
        // 部分选中状态
        parent->setCheckState(0, Qt::PartiallyChecked);
    }
    else if (selectedCount == childCound)
    {
        // 选中状态
        parent->setCheckState(0, Qt::Checked);
    }
}
