#include "planetexample.h"
#include <QGraphicsScene>

PlanetExample::PlanetExample(QGraphicsScene* scenePas, Game* game) : PlanetSuperClass(scenePas, game)
{
    gravity = 5;
    Source = new chunck(10,game->viewWidth,game->viewWidth-300, scenePas, game);


}
