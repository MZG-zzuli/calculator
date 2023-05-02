
#include "widget1.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QDebug>
#include<QFont>
#include<QMap>

widget1::widget1(QWidget *parent)
    : QWidget{parent}
{
    txt=new QTextEdit;
    txt->setReadOnly(true);
    QGridLayout *mainLayout=new QGridLayout;
    mainLayout->addWidget(txt,0,0,4,4);//添加输入框
    QFont font("黑体",45);
    txt->setFont(font);
    butBack=new QPushButton("C");
    butBack->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(butBack,SIGNAL(clicked(bool)),SLOT(funChar()));

    butLeftKuo=new QPushButton("(");
    butLeftKuo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(butLeftKuo,SIGNAL(clicked(bool)),SLOT(funChar()));

    butRightKuo=new QPushButton(")");
    butRightKuo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(butRightKuo,SIGNAL(clicked(bool)),SLOT(funChar()));

    butDeng=new QPushButton("=");
    butDeng->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(butDeng,SIGNAL(clicked(bool)),SLOT(funChar()));

    but0=new QPushButton("0");
    but0->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(but0,SIGNAL(clicked(bool)),SLOT(funChar()));

    but1=new QPushButton("1");
    but1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(but1,SIGNAL(clicked(bool)),SLOT(funChar()));

    but2=new QPushButton("2");
    but2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(but2,SIGNAL(clicked(bool)),SLOT(funChar()));

    but3=new QPushButton("3");
    but3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(but3,SIGNAL(clicked(bool)),SLOT(funChar()));

    but4=new QPushButton("4");
    but4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(but4,SIGNAL(clicked(bool)),SLOT(funChar()));
    but5=new QPushButton("5");
    but5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(but5,SIGNAL(clicked(bool)),SLOT(funChar()));
    but6=new QPushButton("6");
    but6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(but6,SIGNAL(clicked(bool)),SLOT(funChar()));
    but7=new QPushButton("7");
    but7->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(but7,SIGNAL(clicked(bool)),SLOT(funChar()));
    but8=new QPushButton("8");
    but8->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(but8,SIGNAL(clicked(bool)),SLOT(funChar()));
    but9=new QPushButton("9");
    but9->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(but9,SIGNAL(clicked(bool)),SLOT(funChar()));
    butJia=new QPushButton("+");
    butJia->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(butJia,SIGNAL(clicked(bool)),SLOT(funChar()));
    butJian=new QPushButton("-");
    butJian->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(butJian,SIGNAL(clicked(bool)),SLOT(funChar()));

    butCheng=new QPushButton("*");
    butCheng->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(butCheng,SIGNAL(clicked(bool)),SLOT(funChar()));
    butChu=new QPushButton("/");
    butChu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(butChu,SIGNAL(clicked(bool)),SLOT(funChar()));


    QGridLayout* glayout=new QGridLayout;
    glayout->addWidget(butBack,0,0,1,1);
    glayout->addWidget(butLeftKuo,0,1,1,1);
    glayout->addWidget(butRightKuo,0,2,1,1);
    glayout->addWidget(butDeng,0,3,1,1);

    glayout->addWidget(but0,1,0,1,1);
    glayout->addWidget(but1,1,1,1,1);
    glayout->addWidget(but2,1,2,1,1);
    glayout->addWidget(but3,1,3,1,1);

    glayout->addWidget(but4,2,0,1,1);
    glayout->addWidget(but5,2,1,1,1);
    glayout->addWidget(but6,2,2,1,1);
    glayout->addWidget(but7,2,3,1,1);

    glayout->addWidget(but8,3,0,1,1);
    glayout->addWidget(but9,3,1,1,1);
    glayout->addWidget(butJia,3,2,1,1);
    glayout->addWidget(butJian,3,3,1,1);

    glayout->addWidget(butCheng,4,0,1,2);
    glayout->addWidget(butChu,4,2,1,2);

    mainLayout->addLayout(glayout,4,0,4,4);

    setLayout(mainLayout);
}

void widget1::eval()
{
    int b=num.top();
    num.pop();
    int a=num.top();
    num.pop();
    QChar c=op.top();
    op.pop();
    if(c=='+'){
        num.push(a+b);
    }else if(c=='-'){
        num.push(a-b);
    }else if(c=='*'){
        num.push(a*b);
    }else{
        num.push(a/b);
    }
}


long long widget1::Deng(){
    QMap<QChar,int> mp={{'+',1},{'-',1},{'*',2},{'/',2}};
    int i,j,x;
    std::string ss=s.toStdString();
    for(i=0;i<ss.size();i++){
        if(isdigit(ss[i])){
            j=i,x=0;
            while(isdigit(ss[j])){
                x=x*10+ss[j]-'0';
                j++;
            }
            i=j-1;
            num.push(x);
        }else if(ss[i]=='('){
            op.push(ss[i]);
        }else if(ss[i]==')'){
            while(op.top()!='('&&mp[op.top()]>=mp[s[i]]){       //保证上一个运算可以直接进行计算时，对其计算
                eval();
            }
            op.pop();
        }else{
            while(op.size()!=0&&mp[op.top()]>=mp[ss[i]])eval();
            op.push(s[i]);
        }
    }
    while(op.size()!=0&&mp[op.top()]>=mp[ss[i]])eval();
    return num.top();
}

void widget1::funChar()
{
    QPushButton* button=qobject_cast<QPushButton*>(sender());
    QString c=button->text();
    if(c=="="){
        pressDeng=true;
        if(left!=right){
            trueOrFlase=false;
            //错误
        }
        funDeng();
        return;
    }else if(c=="C"){
        funC();
        return;
    }
    if(c[0]>='0'&&c[0]<='9'){
        lastIsOp=false;
    }else if(c[0]==')'){
        if(left<=right){
            trueOrFlase=false;
            //表达式错误
        }
        right++;
    }else if(c[0]=='('){
        left++;
    }else{
        if(lastIsOp){
            trueOrFlase=false;
            //错误
        }
        lastIsOp=true;
    }
    s+=c;
    qDebug()<<s;
    txt->setText(s);
}

void widget1::funC()
{
    if(pressDeng){
        s="";
        pressDeng=false;
    }
    int n=s.size();
    s.remove(n-1,1);
    txt->setText(s);
}

void widget1::funDeng()
{
    QString ss="";
    if(trueOrFlase){
        ss=QString(std::to_string(Deng()).data());
    }else{
        ss="表达式错误";
    }

    s=s+"=\n"+ss;

    txt->setText(s);

}





