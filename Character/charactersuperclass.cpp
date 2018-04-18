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

void CharacterSuperClass::MoveR()
{

}

void CharacterSuperClass::MoveD()
{

}

void CharacterSuperClass::MoveL()
{

}

void CharacterSuperClass::MoveU()
{

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
        MoveU = true;
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
        //Move Up
        MoveU = false;
    }
};
