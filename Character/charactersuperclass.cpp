#include "charactersuperclass.h"

void CharacterSuperClass::Gravity()
{
    if(GravityOn == true)
    {
        if(accGrav*timeVarGravity < 1)      //terminal velocty control
        {
            timeVarGravity++;
        }
        setPos(x(),y()+mass*accGrav*timeVarGravity);
    }
}

CharacterSuperClass::CharacterSuperClass(Game *game)
{
 setRect( 0, 0, 10, 15 );
 mass = 10;
 timeVarGravity = 0;
 accGrav = 0.01;        //totally changeable, essentially the rate of falling caused by gravity
 GravityOn = true;

 Chargame = game;



    connect(game->TimerGravity,SIGNAL(timeout()),this,SLOT(Gravity()));


    MoveR = false;
    MoveD = false;
    MoveL = false;
    MoveU = false;




}

void CharacterSuperClass::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_D)
    {
        //move Right
        setPos(x(),y());
    }
    if(event->key() == Qt::Key_S)
    {
        //move down
        setPos(x(),y());
    }
    if(event->key() == Qt::Key_A)
    {
        //move right
        setPos(x(),y());
    }
    if(event->key() == Qt::Key_W)
    {
        //Move Up
        setPos(x(),y());
    }
}

void CharacterSuperClass::keyReleaseEvent(QKeyEvent *event)
{

};
