#ifndef PLANETSUPERCLASS_H
#define PLANETSUPERCLASS_H
#include <QObject>
class PlanetSuperClass: public QObject
{
Q_OBJECT
public:
  PlanetSuperClass();

protected:
    qreal gravity;

};

#endif // PLANETSUPERCLASS_H
