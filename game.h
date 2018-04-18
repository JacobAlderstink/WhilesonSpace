#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "minterface.h"

class MInterface;
class Game: public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene * scene;
    MInterface* interface;

public:
    Game();
    QGraphicsScene* getScene();


    void mainMenu();

public slots:
    void start();
};
#endif // GAME_H
