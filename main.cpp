#include <QApplication>
#include "choosedlg.h"
#include "mainwnd.h"
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //获取当前时间
    QTime t = QTime::currentTime();
    //将当前秒转化成毫秒，加上当前毫秒数，以此为基数产生随机数
    qsrand(t.msec() + t.second() * 1000);

    ChooseDlg dlg;
    //打开选择对话框，等待按钮点击事件
    if(dlg.exec() != QDialog::Accepted){
        return 0;
    }

    //创建主窗口，接受选择对话框传来的_selected参数
    MainWnd wnd(dlg._selected);
    //显示主窗口
    wnd.show();

    return app.exec();
}
