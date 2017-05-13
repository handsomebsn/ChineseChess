#include "ctrlpanel.h"
#include <QGridLayout>
#include <QVBoxLayout>

CtrlPanel::CtrlPanel(QWidget *parent) : QWidget(parent)
{
    //网格
    QGridLayout *grid = new QGridLayout(this);
    //垂直格式
    QVBoxLayout *vLay = new QVBoxLayout;

    grid->setColumnStretch(0, 1);
    grid->setColumnStretch(2, 1);
    grid->setRowStretch(0, 1);
    grid->setRowStretch(2, 1);
    grid->addLayout(vLay, 1, 1);

    //创建并添加悔棋按钮
    vLay->addWidget(this->_back = new QPushButton("back"));
    //关联悔棋按钮点击事件
    connect(this->_back, SIGNAL(clicked(bool)), this, SIGNAL(sigBack()));
}
