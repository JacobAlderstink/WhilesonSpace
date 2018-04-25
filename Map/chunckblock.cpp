#include "chunckblock.h"

ChunckBlock::ChunckBlock(chunck *chunckson, QGraphicsScene *scenepass): QObject(NULL)
{
    int blocksPerChunk = 600;
    scene= scenepass;
    ChunckBlock* curr = this;
    ChunckBlock* prev = curr;
    curr->Y = chunckson->getStartingY();
    curr->setRect(0,0,scene->width()/blocksPerChunk,scene->width()/blocksPerChunk+10);
    curr->next = new ChunckBlock();
    prev = curr;
    curr = curr->next;

    for(int i = 0; i < blocksPerChunk; i++){


        int ychange = rand()%5-2;
        curr->Y = prev->Y+ychange;
        if(curr->Y > 1080-rect().height())
            curr->Y = 1080-rect().height();
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
