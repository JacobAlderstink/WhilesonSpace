#include "game.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game* newGame = new Game();
    newGame->mainMenu();
    return a.exec();
}
