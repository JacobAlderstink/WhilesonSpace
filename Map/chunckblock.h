#ifndef CHUNCKBLOCK_H
#define CHUNCKBLOCK_H

#include <QObject>
#include <QGraphicsRectItem>
#include "chunck.h"
#include <QGraphicsScene>
#include "game.h"

class chunck;
enum tribool {tru,fals,unin};

class ChunckBlock : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    ChunckBlock(chunck* chunckson, QGraphicsScene* scenepas, Game* gameTemp);
    int getStartingY(){
        return Y;
    }
    int getStartingX(){
        return X;
    }
    static int blocksPerChunk;
     ChunckBlock* startingBlock;
private:
    Game* game;
    tribool Checker;
    QGraphicsScene* scene;
    chunck *ParentChunck;
    ChunckBlock* next;
    //ChunckBlock* startingBlock;
    int Y;
    int X;

    ChunckBlock();
signals:

public slots:
    void ChunckSceneUpdater();
};

#endif // CHUNCKBLOCK_H
