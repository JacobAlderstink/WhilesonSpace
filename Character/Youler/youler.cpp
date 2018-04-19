#include "youler.h"



Youler::Youler(Game *Chargame): CharacterSuperClass(Chargame)
{
    //setting specific Youler Properties
    mass = 1;
    velocityHor = 1;
    CharWidth = 2/45;
    CharHeight = 4/39;



    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveUp()));
    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveDown()));
    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveLeft()));
    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveRight()));
}
