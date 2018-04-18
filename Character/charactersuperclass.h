#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsRectItem>
#include <QObject>
#include "game.h"
#include <QTimer>

class Game;

enum facing {leftDir,rightDir};

class CharacterSuperClass : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    QTimer * TimerGravity;

public:
    CharacterSuperClass();

    Character();
    double GetMass()
    {
        return mass;
    }

protected:
    facing WhichWay;
    double mass;            //should affect terminal velocity
    double velocityHor;
    int timeVarGravity;
    double accGrav;
    bool GravityOn;

public slots:
    void Gravity();

};

#endif // CHARACTER_H


