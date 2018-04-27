#ifndef CHUNCKLIST_H
#define CHUNCKLIST_H

#include "chunckblock.h"
#include <QGraphicsScene>
#include "game.h"

class ChunckBlock;

class chunck
{
public:
    chunck(int planetSize, int yLowerBound, int yUpperBound, QGraphicsScene *scenePas, Game* gamePas);
    int getStartingY();
    int getEndingY();
    int GetstartingX();
    int endingY;
    static int blocksPerChunck;
    ChunckBlock* startChunckBlock;
private:
    static chunck* startChunck;
    Game* game;
    QGraphicsScene* scene;
    int startingX;
    chunck();
    int startingY;
    chunck* next;

};

#endif // CHUNCKLIST_H
