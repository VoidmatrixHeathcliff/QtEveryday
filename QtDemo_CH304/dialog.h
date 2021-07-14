#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QLabel>
#include <QPushButton>
#include <QFrame>
#include <QPixmap>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    QLabel* UserNameLabe;
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

    QPushButton* OkBtn;
    QPushButton* CancelBtn;
    QHBoxLayout* ButtomLayout;
};

#endif // DIALOG_H
