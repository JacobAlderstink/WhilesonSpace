#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "minterface.h"
#include <QTimer>
#include <charactersuperclass.h>
class CharacterSuperClass;
class MInterface;
class Game: public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene * scene;
    MInterface* interface;


public:
    CharacterSuperClass* Character;
    Game();
    QGraphicsScene* getScene();
    QTimer *TimerGravity;
    double ratioConverter;
    int viewWidth;
    int viewHeight;
    void mainMenu();
public slots:
    void start();
    void closeGame();
};
#endif // GAME_H
