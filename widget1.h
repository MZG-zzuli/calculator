
#ifndef WIDGET1_H
#define WIDGET1_H


#include <QWidget>
#include<QPushButton>
#include<QTextEdit>
#include<QStack>
class widget1 : public QWidget
{
    Q_OBJECT
public:
    explicit widget1(QWidget *parent = nullptr);

private:
    QTextEdit* txt;
    QPushButton* but0;
    QPushButton* but1;
    QPushButton* but2;
    QPushButton* but3;
    QPushButton* but4;
    QPushButton* but5;
    QPushButton* but6;
    QPushButton* but7;
    QPushButton* but8;
    QPushButton* but9;
    QPushButton* butDeng;
    QPushButton* butLeftKuo;
    QPushButton* butRightKuo;
    QPushButton* butJia;
    QPushButton* butJian;
    QPushButton* butCheng;
    QPushButton* butChu;
    QPushButton* butBack;
    QString s;
    QStack<int> num;
    QStack<QChar> op;
    void eval();
    long long Deng();
    void funC();
    void funDeng();
    bool lastIsOp=true;
    int left=0;
    int right=0;
    bool trueOrFlase=true;
    bool pressDeng=false;
signals:
public slots:
    void funChar();

};

#endif // WIDGET1_H
