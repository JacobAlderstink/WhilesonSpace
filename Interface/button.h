#ifndef BUTTON_H
#define BUTTON_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QObject>
#include <game.h>

class Button : public QObject, public QGraphicsRectItem
{
Q_OBJECT
public:
    //constructor
    Button(QString name, Game* game, QGraphicsItem* parent = NULL);
    //methods
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();

private:
   QGraphicsTextItem* text;
};


#endif // BUTTON_H
