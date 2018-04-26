#ifndef PLANETEXAMPLE_H
#define PLANETEXAMPLE_H

#include <QObject>
#include <planetsuperclass.h>
#include <QGraphicsScene>

class PlanetExample : public PlanetSuperClass
{

public:
    PlanetExample(QGraphicsScene* scenePas, Game* game);
};

#endif // PLANETEXAMPLE_H
