#ifndef CHUNCKBLOCK_H
#define CHUNCKBLOCK_H

#include <QObject>
#include <QGraphicsRectItem>
#include "chunck.h"
#include <QGraphicsScene>
#include "game.h"

class chunck;

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
private:
    Game* game;
    QGraphicsScene* scene;
    ChunckBlock* next;
    int Y;
    int X;

    ChunckBlock();
signals:

public slots:
};

#endif // CHUNCKBLOCK_H
