#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include "game.h"
Button::Button(QString name, Game* game, QGraphicsItem *parent): QGraphicsRectItem(parent){



    //draw the rect
    setRect(0,0,game->viewWidth/10,game->viewHeight/23);
    //QBrush brush;
    brushLeave.setStyle(Qt::SolidPattern);
    brushEnter.setStyle(Qt::SolidPattern);
    brushLeave.setColor(Qt::darkCyan);
    brushEnter.setColor(Qt::cyan);
    //setBrush(brushLeave);

    //draw text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    //allow it to repsond to hover events
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
 //change color to Cyan
    //QBrush brush;
    //brushEnter.setStyle(Qt::SolidPattern);
    //brushEnter.setColor(Qt::cyan);
    setBrush(brushEnter);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    //QBrush brush;
    //brushLeave.setStyle(Qt::SolidPattern);
    //brushLeave.setColor(Qt::darkCyan);
    setBrush(brushLeave);
}

