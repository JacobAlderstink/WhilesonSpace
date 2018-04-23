#include "youler.h"
#include <QDebug>


Youler::Youler(Game *Chargame): CharacterSuperClass(Chargame)
{
    //setting specific Youler Properties
    mass = 1;
    velocityHor = 1*ratioConverter;
    CharWidth = 40*ratioConverter;
    CharHeight = 80*ratioConverter;
    JumpStrength = 7*ratioConverter;
    Chargame->getScene()->height();

    //Painting the boy
    QBrush brushBody;
    brushBody.setStyle(Qt::SolidPattern);
    brushBody.setColor(Qt::green);
    setBrush(brushBody);

    setRect( 0, 0, CharWidth, CharHeight );

    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveUp()));
    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveDown()));
    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveLeft()));
    connect(Chargame->TimerGravity,SIGNAL(timeout()),this,SLOT(MoveRight()));
}
