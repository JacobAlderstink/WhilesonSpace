#include "chunckblock.h"

ChunckBlock::ChunckBlock(chunck *chunckson, QGraphicsScene *scenepass): QObject(NULL)
{
    int blocksPerChunk = 30;
    scene= scenepass;
    ChunckBlock* curr = this;
    ChunckBlock* prev = curr;
    curr->Y = chunckson->getStartingY();
    curr->setRect(0,0,scene->width()/blocksPerChunk,scene->width()/blocksPerChunk);
    curr->next = new ChunckBlock();
    prev = curr;
    curr = curr->next;
    scene->addItem(prev);
    for(int i = 0; i < blocksPerChunk; i++){
        int ychange = rand()%5-2;
        curr->Y = prev->Y+ychange;
        if(curr->Y > scene->height()-rect().height())
            curr->Y = scene->height()-rect().height();
        curr->setPos(i*scene->width()/blocksPerChunk+chunckson->GetstartingX(),curr->Y);
        scene->addItem(curr);
        curr->next = new ChunckBlock();
        prev = curr;
        curr = curr->next;


        curr->setRect(0,0,scene->width()/blocksPerChunk,scene->width()/blocksPerChunk);

    }

    curr->Y = chunckson->getEndingY();
    curr->setPos(scene->width()+chunckson->GetstartingX(),curr->Y);
    scene->addItem(curr);
}

ChunckBlock::ChunckBlock(){


}
