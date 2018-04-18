#ifndef MINTERFACE_H
#define MINTERFACE_H

#include <QObject>
#include <QGraphicsRectItem>
#include "game.h"
#include "mainmenu.h"
class Game;
class MainMenu;
class MInterface : public QObject
{
    Q_OBJECT
public:
    MainMenu* menu;
    MInterface(Game *pasGame);
    Game* game;
signals:

public slots:

};

#endif // MINTERFACE_H
