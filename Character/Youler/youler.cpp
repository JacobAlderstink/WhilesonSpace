#include "youler.h"



Youler::Youler(Game *Chargame): CharacterSuperClass(Chargame)
{
    //setting specific Youler Properties
    mass = 1;
    velocityHor = 1;
    CharWidth = 2/45;
    CharHeight = 4/39;

    setRect( 0, 0, Chargame->getScene()->width()*CharWidth, Chargame->getScene()->height()*CharHeight );

    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveUp()));
    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveDown()));
    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveLeft()));
    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveRight()));
}
