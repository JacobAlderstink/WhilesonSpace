#include "chunckblock.h"
int ChunckBlock::blocksPerChunk;
ChunckBlock::ChunckBlock(chunck *chunckson, QGraphicsScene *scenepass, Game *gameTemp): QObject(NULL)
{
    game= gameTemp;
    blocksPerChunk = chunckson->blocksPerChunck;
    scene= scenepass;
    ChunckBlock* curr = this;
    ChunckBlock* prev = curr;

    curr->Y = chunckson->getStartingY();
    curr->setRect(0,0,game->viewWidth/blocksPerChunk,game->viewWidth/blocksPerChunk);
    curr->next = new ChunckBlock();
    prev = curr;
    curr = curr->next;
    setPos(chunckson->GetstartingX(),prev->Y);
    scene->addItem(prev);

    int i;
    for(i = 0; i < blocksPerChunk; i++){
        int ychange = rand()%5-2;
        curr->Y = prev->Y+ychange;
        if(curr->Y > game->viewHeight-rect().height())
            curr->Y = game->viewHeight-rect().height();
        curr->setPos(i*game->viewWidth/blocksPerChunk+chunckson->GetstartingX(),curr->Y);
        scene->addItem(curr);
        curr->next = new ChunckBlock();
        prev = curr;
        curr = curr->next;


        curr->setRect(0,0,game->viewWidth/blocksPerChunk,game->viewWidth/blocksPerChunk);

    }

    int ychange = rand()%5-2;
    curr->Y = prev->Y+ychange;
    if(curr->Y > game->viewHeight-rect().height())
        curr->Y = game->viewHeight-rect().height();
    curr->setPos(i*game->viewWidth/blocksPerChunk+chunckson->GetstartingX(),curr->Y);
    chunckson->endingY = curr->Y;
    scene->addItem(curr);
    scene->setSceneRect(0,0,i*game->viewWidth,game->viewHeight);
}

ChunckBlock::ChunckBlock(){


}
