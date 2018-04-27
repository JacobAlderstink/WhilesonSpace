#include "chunck.h"
#include <stdlib.h>
#include <iostream>

using namespace std;
int chunck::blocksPerChunck;
chunck* chunck::startChunck;
chunck::chunck(){

}

chunck::chunck(int planetSize, int yLowerBound, int yUpperBound, QGraphicsScene* scenePass, Game* gamePas){
    game = gamePas;
    blocksPerChunck = 30;
    startChunck = this;

    chunck* start = this;
    scene= scenePass;
    start->startingY=game->viewHeight - game->viewWidth/blocksPerChunck;


    for(int i = 0; i < planetSize; i++){
        start->startingX = game->viewWidth*i;

        int value = rand()%yUpperBound;
        start->endingY = value;
        start->endingY += yLowerBound;
        startChunckBlock = new ChunckBlock(start, scene, game);

        int temp = start->endingY;
        start->next = new chunck();
        start = start->next;
        start->startingY = temp;
      }

    start->endingY = startChunck->startingY;
    start->next = startChunck;

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
