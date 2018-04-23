#include "youler.h"
#include <QDebug>


Youler::Youler(Game *Chargame): CharacterSuperClass(Chargame)
{
    //setting specific Youler Properties
    mass = 1;
    velocityHor = 1;
    CharWidth = 1.0/45.0;
    CharHeight = 2.0/39.0;
    JumpStrength = (Chargame->getScene()->height())*rationConverter;
    Chargame->getScene()->height();

    //Painting the boy
    QBrush brushBody;
    brushBody.setStyle(Qt::SolidPattern);
    brushBody.setColor(Qt::green);
    setBrush(brushBody);

    setRect( 0, 0, (Chargame->getScene()->width())*CharWidth, (Chargame->getScene()->height())*CharHeight );

    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveUp()));
    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveDown()));
    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveLeft()));
    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveRight()));
}
