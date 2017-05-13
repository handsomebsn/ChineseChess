#ifndef MULTIGAME_H
#define MULTIGAME_H

#include "board.h"

class MultiGame : public Board
{
    Q_OBJECT

public:
    explicit MultiGame(QWidget *parent = 0);
    ~MultiGame();

signals:

public slots:

};

#endif // MULTIGAME_H
