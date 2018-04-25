#include "planetexample.h"

PlanetExample::PlanetExample(QGraphicsScene* scenePas) : PlanetSuperClass(scenePas)
{
    gravity = 5;
    Source = new chunck(10,8,2);

}
