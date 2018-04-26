#ifndef PLANETSUPERCLASS_H
#define PLANETSUPERCLASS_H

#include <QObject>
#include "chunck.h"
#include <QGraphicsScene>
#include "game.h"

class PlanetSuperClass: public QObject
{
Q_OBJECT
public:
  PlanetSuperClass(QGraphicsScene* scenePass, Game* game);
protected:
    qreal gravity;
    QGraphicsScene* scene;
    chunck* Source;
    Game* gameObj;
    int finalSceneWidth;
};

#endif // PLANETSUPERCLASS_H
