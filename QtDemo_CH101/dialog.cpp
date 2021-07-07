#include "dialog.h"
#include "ui_dialog.h"

const static double PI = 3.141592654;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    bool ok;
    QString tmpStr;
    QString valueStr = ui->radiusLineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt * valueInt * PI;
    ui->areaLabel->setText(tmpStr.setNum(area));
}

void Dialog::on_radiusLineEdit_textChanged(const QString &arg1)
{
    bool ok;
    QString tmpStr;
    int valueInt = arg1.toInt(&ok);
    double area = valueInt * valueInt * PI;
    ui->areaLabel->setText(tmpStr.setNum(area));
}
