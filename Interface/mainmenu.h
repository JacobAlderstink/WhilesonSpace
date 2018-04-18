#ifndef MAINMENU_H
#define MAINMENU_H
#include <QGraphicsScene>
#include <QObject>
#include "game.h"
class Game;
class MainMenu : public QObject
{
    Q_OBJECT
public:
    explicit MainMenu(Game* game);
    int player;

private:
    Game* MMgame;
   // void displaystart();

signals:
public slots:
   void displayStart();
    void displayOptions();
  void DOption1();
  void DOption2();
  void DOption3();
};

#endif // MAINMENU_H
