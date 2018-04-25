#include "chunck.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
chunck::chunck(){

}

chunck::chunck(int planetSize, int yLowerBound, int yUpperBound, QGraphicsScene* scenePass){
    chunck* source = this;
    chunck* start = this;
    scene= scenePass;
    start->startingY=scene->height() - scene->width()/600;
    for(int i = 0; i < planetSize; i++){
        start->startingX = scene->width()*i;
        int value = rand()%yUpperBound;
        start->endingY = value;
        start->endingY += yLowerBound;
        startChunck = new ChunckBlock(start, scene);

        int temp = start->endingY;
        start->next = new chunck();
        start = start->next;
        start->startingY = temp;
       // startChunck = new ChunckBlock(start, scene);
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
