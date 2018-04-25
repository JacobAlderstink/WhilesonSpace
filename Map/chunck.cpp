#include "chunck.h"
#include <stdlib.h>

chunck::chunck(){

}

chunck::chunck(int planetSize, int yLowerBound, int yUpperBound, QGraphicsScene* scenePass){
    chunck* source = this;
    chunck* start = this;
    scene= scenePass;
    start->startingY=1060;
    for(int i = 0; i < planetSize; i++){
        start->startingX = 1920*i;
        int value = rand()%yUpperBound;
        start->endingY = value;
        start->endingY += yLowerBound;
        startChunck = new ChunckBlock(start, scene);

        start->next = new chunck();
        start = start->next;
        start->startingY = value;

    }

    start->endingY = source->startingY;
    start->next = source;

}

int chunck::getStartingY()
{
   return startingY;
}


int chunck::GetstartingX()
{
   return startingX;
}

int chunck::getEndingY()
{
    return endingY;
}
