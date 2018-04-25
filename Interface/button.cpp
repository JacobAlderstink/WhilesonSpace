#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include "game.h"
Button::Button(QString name, Game* game, QGraphicsItem *parent): QGraphicsRectItem(parent){

    //draw the rect
    setRect(0,0,game->getScene()->width()/10,game->getScene()->height()/23);
    brushLeave.setStyle(Qt::SolidPattern);
    brushEnter.setStyle(Qt::SolidPattern);
    brushLeave.setColor(Qt::darkCyan);
    brushEnter.setColor(Qt::cyan);

    //Change pen

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
    setBrush(brushEnter);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setBrush(brushLeave);
}

