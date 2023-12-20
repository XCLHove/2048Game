//
// Created by xclhove on 23-12-20.
//

#ifndef GAME_H
#define GAME_H

#include <array>

const int NCells = 4;

using Pos = std::array<int, 2>;

class Game {
private:
    bool canMoveUp = true;
    bool canMoveDown = true;
    bool canMoveRight = true;
    bool canMoveLeft = true;
public:
    int board[NCells][NCells];
    int total_score = 0;
    bool changed;

    Game();

    void move(bool horizonal, bool reverse);

    /** 重新开始游戏 */
    void restart();

    /**
     * 获取空方块的位置
     * @return
     */
    Pos getEmptyPos();

    bool isFull();

    /**
     * 游戏是否胜利
     * @return
     */
    bool won();

    /**
     * 游戏是否结束
     * @return
     */
    bool over();
};

#endif
