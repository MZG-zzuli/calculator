#include<QApplication>
#include"widget1.h"
int main(int argc,char** argv){
    QApplication app(argc,argv);
    widget1 * wid=new widget1;
    wid->show();

    return app.exec();
}
