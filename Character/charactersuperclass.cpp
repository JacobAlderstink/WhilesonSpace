#include "charactersuperclass.h"

void CharacterSuperClass::Gravity()
{
    if(GravityOn == true)
    {
        if(accGrav*timeVarGravity < 1)      //terminal velocty control
        {
            timeVarGravity++;
        }
        setPos(x(),y()+accGrav*timeVarGravity);
    }
}

CharacterSuperClass::CharacterSuperClass()
{
 setRect( 0, 0, 10, 15 );
 mass = 10;
 timeVarGravity = 0;
 accGrav = 0.01;        //totally changeable, essentially the rate of falling caused by gravity
 GravityOn = true;

 TimerGravity =  new QTimer();


 connect(TimerGravity,SIGNAL(timeout()),this,SLOT(Gravity()));

 TimerGravity->start(3);



};
