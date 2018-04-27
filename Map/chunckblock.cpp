#include "chunckblock.h"
#include <QTimer>
#include <iostream>
using namespace std;

int ChunckBlock::blocksPerChunk;


ChunckBlock::ChunckBlock(chunck *chunckson, QGraphicsScene *scenepass, Game *gameTemp): QObject(NULL)
{
    startingBlock = this;
    Checker = fals;
    ParentChunck= chunckson;
    game= gameTemp;
    blocksPerChunk = ParentChunck->blocksPerChunck;
    scene= scenepass;
    ParentChunck->startChunckBlock = this;

    ChunckBlock* curr = this;
    ChunckBlock* prev = curr;

    curr->Y = ParentChunck->getStartingY();
    curr->setRect(0,0,game->viewWidth/blocksPerChunk,game->viewWidth/blocksPerChunk);
    curr->next = new ChunckBlock();
    prev = curr;
    curr = curr->next;
    setPos(ParentChunck->GetstartingX(),prev->Y);
    //scene->addItem(prev);

    int i;
    for(i = 0; i < blocksPerChunk; i++){
        int ychange = rand()%5-2;
        curr->Y = prev->Y+ychange;
        if(curr->Y > game->viewHeight-rect().height())
            curr->Y = game->viewHeight-rect().height();
        curr->setPos(i*game->viewWidth/blocksPerChunk+ParentChunck->GetstartingX(),curr->Y);
     //   scene->addItem(curr);
        curr->next = new ChunckBlock();
        prev = curr;
        curr = curr->next;


        curr->setRect(0,0,game->viewWidth/blocksPerChunk,game->viewWidth/blocksPerChunk);

    }

    int ychange = rand()%5-2;
    curr->Y = prev->Y+ychange;
    if(curr->Y > game->viewHeight-rect().height())
        curr->Y = game->viewHeight-rect().height();
    curr->setPos(blocksPerChunk-1*game->viewWidth/blocksPerChunk+ParentChunck->GetstartingX(),curr->Y);
    ParentChunck->endingY = curr->Y;

    scene->setSceneRect(0,0,i*game->viewWidth,game->viewHeight);
    QTimer *ChunckUpdater  = new QTimer;
    ChunckUpdater->start(10);
    connect(ChunckUpdater,SIGNAL(timeout()),this,SLOT(ChunckSceneUpdater()));


}

ChunckBlock::ChunckBlock(){


}

void ChunckBlock::ChunckSceneUpdater(){

 //   static tribool Checker= fals;
   if((( ParentChunck->GetstartingX() >= game->Character->pos().x()-game->viewWidth/2 ) && ( ParentChunck->GetstartingX() <= game->Character->pos().x()+game->viewWidth/2 )) && (Checker == fals))
    {
        ChunckBlock* temp = ParentChunck->startChunckBlock;
        for(int i = 0; i <= blocksPerChunk; i++){
          scene->addItem(temp);
          temp = temp->next;
        }
        Checker = tru;
        cout << "chucnk added" << endl;

    }
   else if((( ParentChunck->GetstartingX()+game->viewWidth >= game->Character->pos().x()-game->viewWidth/2 ) && ( ParentChunck->GetstartingX()+game->viewWidth <= game->Character->pos().x()+game->viewWidth/2 )) && (Checker == fals)){
       ChunckBlock* temp = ParentChunck->startChunckBlock;
       for(int i = 0; i <= blocksPerChunk; i++){
         scene->addItem(temp);
         temp = temp->next;
       }
       Checker = tru;
       cout << "chucnk added" << endl;
}
    else if(( ParentChunck->GetstartingX()+game->viewWidth < game->Character->pos().x()-game->viewWidth/2) || (ParentChunck->GetstartingX() > game->Character->pos().x()+game->viewWidth/2) && (Checker == tru))
    {
        ChunckBlock* temp = ParentChunck->startChunckBlock;
        for(int i = 0; i <= blocksPerChunk; i++){
          scene->removeItem(temp);
          temp = temp->next;
        }
        cout << "chucnk removed" << endl;
        Checker = fals;
    }
/*
    scene->width();
    scene->height();
*/
}
