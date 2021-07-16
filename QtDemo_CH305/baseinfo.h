#ifndef BASEINFO_H
#define BASEINFO_H

#include <QWidget>

#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>

class BaseInfo : public QWidget
{
    Q_OBJECT
public:
    explicit BaseInfo(QWidget *parent = nullptr);

signals:

public slots:
private:
    QLabel* UserNameLabel;
    QLabel* NameLabel;
    QLabel* SexLabel;
    QLabel* DepartmentLabel;
    QLabel* AgeLabel;
    QLabel* OtherLabel;
    QLineEdit* UserNameLineEdit;
    QLineEdit* NameLineEdit;
    QComboBox* SexComboBox;
    QTextEdit* DepartmentTextEdit;
    QLineEdit* AgeLineEdit;
    QGridLayout* LeftLayout;

    QLabel* HeadLabel;
    QLabel* HeadIconLabel;
    QPushButton* UpdateHeadBtn;
    QHBoxLayout* TopRightLayout;
    QLabel* IntroductionLabel;
    QTextEdit* IntroductionTextEdit;
    QVBoxLayout* RightLayout;

};

#endif // BASEINFO_H
