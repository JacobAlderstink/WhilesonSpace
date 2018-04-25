#ifndef PLANETSUPERCLASS_H
#define PLANETSUPERCLASS_H

#include <QObject>
#include "chuncklist.h"
#include <QGraphicsScene>

class PlanetSuperClass: public QObject
{
Q_OBJECT
public:
  PlanetSuperClass(QGraphicsScene* scenePass);
protected:
    qreal gravity;
    QGraphicsScene* scene;
    chunck* Source;

};

#endif // PLANETSUPERCLASS_H
