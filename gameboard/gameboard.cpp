//
// Created by xclhove on 23-12-20.
//

#include "gameboard.h"
#include <QKeyEvent>
#include <QMessageBox>


GameBoard::GameBoard(QWidget *parent) : QWidget(parent) {
    resize(650, 450); // set default size
    mainLayout = new QVBoxLayout(); // create the main layout
    setLayout(mainLayout);

    boardLayout = new QGridLayout(); // create the board layout
    drawBoard(); // 绘制小方块
    mainLayout->insertLayout(0, boardLayout);

    // create the score widget and add it to the board
    score = new QLabel(QString("SCORE: %1").arg(0));
    score->setStyleSheet("QLabel { color: rgb(235,224,214); font: 16pt; }");
    score->setFixedHeight(50);
    mainLayout->insertWidget(1, score, 0, Qt::AlignRight);

    setStyleSheet("GameBoard { background-color: rgb(187,173,160) }"); // style sheet of the board
}

void GameBoard::drawBoard() {
    delete boardLayout;
    boardLayout = new QGridLayout();
    for (int i = 0; i < NCells; ++i) {
        for (int j = 0; j < NCells; ++j) {
            delete cells[i][j];
            cells[i][j] = new Cell(game.board[i][j]);
            boardLayout->addWidget(cells[i][j], i, j);
            cells[i][j]->draw();
        }
    }
    mainLayout->insertLayout(0, boardLayout);
}

void GameBoard::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Up:
            game.move(false, false);
            break;
        case Qt::Key_Down:
            game.move(false, true);
            break;
        case Qt::Key_Left:
            game.move(true, false);
            break;
        case Qt::Key_Right:
            game.move(true, true);
            break;
        case Qt::Key_Tab:
            game.restart();
            break;
        case Qt::Key_Any:
            break;
    }

    if (game.over()) {
        QMessageBox::warning(this, "游戏结束", "你输了！你的分数：" + score->text(), "确定");
        game.restart();
        drawBoard();
        return;
    }

    if (game.won()) {
        QMessageBox::information(this, "游戏胜利", "你赢了！你的分数：" + score->text(), "确定");
        game.restart();
        drawBoard();
        return;
    }

    if (!game.changed) return;

    if (game.isFull()) return;
    auto pos = game.getEmptyPos();
    game.board[pos[0]][pos[1]] = 2;
    score->setText(QString("SCORE: %1").arg(game.total_score));
    drawBoard();
}