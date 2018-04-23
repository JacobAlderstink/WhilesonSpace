#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsRectItem>
#include <QObject>
#include "game.h"
#include <QTimer>
#include <QKeyEvent>

class Game;

enum facing {leftDir,rightDir};

class CharacterSuperClass : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:


public:
    CharacterSuperClass(Game *);

    double GetMass()
    {
        return mass;
    }
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

protected:
    facing WhichWay;
    Game * Chargame;

    bool GravityOn;

    int timeVarGravity;
    int JumpCount;
    int JumpStrength;
    int TerminalVelo;

    double ratioConverter;
    double accGrav;
    double mass;            //should affect terminal velocity
    double velocityHor;



    //character dimensions
    qreal CharWidth;
    qreal CharHeight;

    //bool for movement
    bool MoveR;
    bool MoveD;
    bool MoveL;
    bool MoveU;

public slots:
    void Gravity();

    void MoveRight();
    void MoveDown();
    void MoveLeft();
    void MoveUp();      //Jump

};

#endif // CHARACTER_H


