#ifndef STONE_H
#define STONE_H

#include <QRect>
#include <QPainter>

class Stone
{
public:
    Stone();
    ~Stone();

    //所有棋子名称
    enum TYPE{CHE, MA, PAO,  BING, JIANG, SHI, XIANG};

    int _row;
    int _col;
    //棋子标示
    int _id;
    //是否死棋
    bool _dead;
    //是否红方
    bool _red;
    //棋子名称
    TYPE _type;

    //初始化
    void init(int id);

    //获得棋子中文名称
    QString name();

    //旋转棋盘
    void rotate();
};

#endif // STONE_H
