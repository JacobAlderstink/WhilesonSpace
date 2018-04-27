#include "charactersuperclass.h"
#include <QDebug>
#include "chunckblock.h"

void CharacterSuperClass::Gravity()
{

    //checking for collisions
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(ChunckBlock))
        {
            if(GravityOn == true)
            {
                GravityOn = false;
                MoveU = false;
            }
        }
    }
    if(GravityOn == true)
    {
        if(MoveU == true && accGrav*timeVarGravity < JumpStrength+TerminalVelo)
        {
            timeVarGravity++;
        }
        else if(accGrav*timeVarGravity < 3)      //terminal velocty control
        {
            timeVarGravity++;
        }
        setPos(x(),y()+mass*accGrav*timeVarGravity);
    }
}

void CharacterSuperClass::MoveRight()
{
    Chargame->centerOn(this);
    if(MoveR == true)
        setPos(x()+velocityHor,y());
}

void CharacterSuperClass::MoveDown()
{
    setPos(x(),y());
}

void CharacterSuperClass::MoveLeft()
{
    if(MoveL == true)
        setPos(x()-velocityHor,y());
}

void CharacterSuperClass::MoveUp()
{
    if(MoveU == true)
    {
        GravityOn = true;
        setPos(x(),y()-JumpStrength);
    }
}

CharacterSuperClass::CharacterSuperClass(Game *game)
{
    setRect( 0, 0, game->getScene()->width()*2/45, game->getScene()->height()*4/39 );


    Chargame = game;

    ratioConverter = Chargame->getScene()->width()/2160.0;
    mass = 10;
    timeVarGravity = 0;
    accGrav = 0.1*ratioConverter;        //totally changeable, essentially the rate of falling caused by gravity
    GravityOn = true;
    JumpStrength = 5*ratioConverter;
    TerminalVelo = 3*ratioConverter;


    JumpCount = 0;

    MoveR = false;
    MoveD = false;
    MoveL = false;
    MoveU = false;

    connect(game->TimerGravity,SIGNAL(timeout()),this,SLOT(Gravity()));

}

void CharacterSuperClass::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_D)
    {
        //move Right
        MoveR = true;

    }
    if(event->key() == Qt::Key_S)
    {
        //move down
        MoveD = true;
    }
    if(event->key() == Qt::Key_A)
    {
        //move Left
        MoveL = true;
    }
    if(event->key() == Qt::Key_W)
    {
        //Move Up
        if(JumpCount < 400)
        {
            MoveU = true;
            timeVarGravity = 0;
            JumpCount++;
        }
    }
    if(event->key() == Qt::Key_Space)
    {
        //Chargame->getScene()->setSceneRect();
        Chargame->mainMenu();
    }
}

void CharacterSuperClass::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_D)
    {
        //move Right
        MoveR = false;
    }
    if(event->key() == Qt::Key_S)
    {
        //move down
        MoveD = false;
    }
    if(event->key() == Qt::Key_A)
    {
        //move Left
        MoveL = false;
    }
    if(event->key() == Qt::Key_W)
    {
    }
};
