#include "planetexample.h"
#include <QGraphicsScene>
PlanetExample::PlanetExample(QGraphicsScene* scenePas) : PlanetSuperClass(scenePas)
{
    gravity = 5;
    Source = new chunck(10,scenePas->height(),scenePas->height()-300, scenePas);

}
