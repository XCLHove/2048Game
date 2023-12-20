#include <QApplication>
#include "gameboard//gameboard.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    srand(time(NULL));
    GameBoard board;
    board.show();
    return app.exec();
}
