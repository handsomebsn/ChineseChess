#include "mainwnd.h"
#include <QHBoxLayout>
#include "singlegame.h"
#include "multigame.h"
#include "netgame.h"

MainWnd::MainWnd(int gameType, QWidget *parent) : QWidget(parent)
{
    //游戏类型
    _gameType = gameType;

    //人机游戏
    if(_gameType == 0)
    {
        SingleGame* game = new SingleGame;
        CtrlPanel* panel = new CtrlPanel;

        //水平格式
        QHBoxLayout* hLay = new QHBoxLayout(this);
        //添加game到格式中
        hLay->addWidget(game, 1);
        //添加panel到格式中
        hLay->addWidget(panel);
        //关联悔棋的back按钮
        connect(panel, SIGNAL(sigBack()), game, SLOT(slotBack()));
    }
    else if(_gameType == 1)//人人游戏
    {
        MultiGame* game = new MultiGame;
        CtrlPanel* panel = new CtrlPanel;

        QHBoxLayout* hLay = new QHBoxLayout(this);
        hLay->addWidget(game, 1);
        hLay->addWidget(panel);
        connect(panel, SIGNAL(sigBack()), game, SLOT(slotBack()));
    }
    else if(_gameType == 2)//服务端游戏
    {
        NetGame* game = new NetGame(true);
        CtrlPanel* panel = new CtrlPanel;

        QHBoxLayout* hLay = new QHBoxLayout(this);
        hLay->addWidget(game, 1);
        hLay->addWidget(panel);
        connect(panel, SIGNAL(sigBack()), game, SLOT(slotBack()));
    }
    else if(_gameType == 3)//客户端游戏
    {
        NetGame* game = new NetGame(false);
        CtrlPanel* panel = new CtrlPanel;

        QHBoxLayout* hLay = new QHBoxLayout(this);
        hLay->addWidget(game, 1);
        hLay->addWidget(panel);
        connect(panel, SIGNAL(sigBack()), game, SLOT(slotBack()));
    }
}
