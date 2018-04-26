#include "planetsuperclass.h"

PlanetSuperClass::PlanetSuperClass(QGraphicsScene* scenePass, Game* game)
{
    scene= scenePass;
    gravity = 5;
    gameObj = game;
}
