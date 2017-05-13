#ifndef BOARD_H
#define BOARD_H

#include <QFrame>
#include "stone.h"
#include "step.h"
#include <QVector>

class Board : public QFrame
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);
    ~Board();

    //游戏数据
    Stone _s[32]; //32颗棋子
    int _r; //棋子的半径
    QPoint _off; //偏移量
    bool _bSide; //哪一方

    QVector<Step*> _steps;

    //游戏状态
    int _selectId; //被选择棋子的id
    bool _bRedTurn; //是否红棋走
    void init(bool bRedSide);

    //绘图
    void paintEvent(QPaintEvent *);
    void drawPlate(QPainter& p);
    void drawPlace(QPainter& p);
    void drawInitPosition(QPainter& p);
    void drawInitPosition(QPainter& p, int row, int col);
    void drawStone(QPainter& p);
    void drawStone(QPainter& p, int id);

    //返回象棋棋盘行列对应的像素坐标
    QPoint center(int row, int col);
    QPoint center(int id);
    QPoint topLeft(int row, int col);
    QPoint topLeft(int id);
    QRect cell(int row, int col);
    QRect cell(int id);

    bool getClickRowCol(QPoint pt, int &row, int &col);

    // 帮助
    QString name(int id);
    bool red(int id);
    bool sameColor(int id1, int id2);
    int getStoneId(int row, int col);
    void killStone(int id);
    void reliveStone(int id);
    void moveStone(int moveId, int row, int col);
    bool isDead(int id);

    //移动棋子
    void mouseReleaseEvent(QMouseEvent *);
    void click(QPoint pt);
    virtual void click(int id, int row, int col);
    void trySelectStone(int id);
    void tryMoveStone(int killId, int row, int col);
    void moveStone(int moveId, int killId,int row, int col);
    void saveStep(int moveId, int killId, int row, int col, QVector<Step*>& steps);
    void backOne();
    void back(Step* step);
    virtual void back();

    // 规则
    bool canMove(int moveId, int killId, int row, int col);
    bool canMoveJiang(int moveId, int killId, int row, int col);
    bool canMoveShi(int moveId, int killId, int row, int col);
    bool canMoveXiang(int moveId, int killId, int row, int col);
    bool canMoveMa(int moveId, int killId, int row, int col);
    bool canMoveChe(int moveId, int killId, int row, int col);
    bool canMovePao(int moveId, int killId, int row, int col);
    bool canMoveBing(int moveId, int killId, int row, int col);

    bool canSelect(int id);

    //帮助规则执行
    int getStoneCountAtLine(int row1, int col1, int row2, int col2);
    int relation(int row1, int col1, int row, int col);
    bool isBottomSide(int id);

signals:

public slots:
    void slotBack();
};

#endif // BOARD_H
