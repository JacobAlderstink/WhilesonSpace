#ifndef CHUNCKLIST_H
#define CHUNCKLIST_H

#include "chunckblock.h"
#include <QGraphicsScene>
class ChunckBlock;

class chunck
{
public:
    chunck(int planetSize, int yLowerBound, int yUpperBound, QGraphicsScene *scenePas);
    int getStartingY();
    int getEndingY();
    int GetstartingX();
private:
    QGraphicsScene* scene;
    int startingX;
    ChunckBlock* startChunck;
    chunck();
    int startingY;
    int endingY;
    chunck* next;

};

#endif // CHUNCKLIST_H
