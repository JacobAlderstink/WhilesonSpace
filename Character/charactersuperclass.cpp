#include "charactersuperclass.h"
#include <QDebug>

void CharacterSuperClass::Gravity()
{
    qDebug() << "Gravity called";
}

CharacterSuperClass::CharacterSuperClass()
{
 setRect( 0, 0, 10, 15 );
 mass = 10;

 TimerGravity =  new QTimer();


 connect(TimerGravity,SIGNAL(timeout()),this,SLOT(Gravity()));

 TimerGravity->start(3);
 timeVarGravity = 0;


}
