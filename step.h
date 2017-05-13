#ifndef STEP_H
#define STEP_H

#include <QObject>

class Step : public QObject
{
    Q_OBJECT

public:
    explicit Step(QObject *parent = 0);
    ~Step();

    //移动棋子的标记
    int _moveId;
    //杀死棋子的标记
    int _killId;
    //起点
    int _rowFrom;
    int _colFrom;
    //终点
    int _rowTo;
    int _colTo;
};

#endif // STEP_H
