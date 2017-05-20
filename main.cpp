#include <QApplication>
#include "mainwindow.h"
#include "Style/SStyle.h"

//重载QApplication，使用其消息分发处理;
class SApplication : public QApplication
{
public:
    SApplication(int &argc, char **argv):QApplication(argc,argv)
    {
    }

protected:
    //消息投递;
    virtual bool notify(QObject *object, QEvent *event)
    {
        return QApplication::notify(object,event);
    }

};

//程序入口;
int main(int argc, char *argv[])
{
    SApplication a(argc, argv);
    //设置应用系统的字体，如切换字体;
    a.setFont(QFont("msyh"));
    //皮肤样式类;
    SStyle style;
    a.setStyleSheet(style.GetStyle());
    //显示主界面;
    MainWindow w;
    w.show();

    return a.exec();
}
