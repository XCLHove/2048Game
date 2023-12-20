//
// Created by xclhove on 23-12-20.
//

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include "../game/game.h"
#include "../cell/cell.h"

class GameBoard : public QWidget
{
Q_OBJECT
public:
    explicit GameBoard(QWidget *parent = 0);

private:
    Game game; // main game logic
    Cell* cells[NCells][NCells] {};
    QVBoxLayout *mainLayout; // main layout
    QGridLayout *boardLayout; // grid layout of board
    QLabel *score; // score widget

    void drawBoard(); // 绘制小方块

protected:
    void keyPressEvent(QKeyEvent *event); //键盘按键事件
};

#endif
