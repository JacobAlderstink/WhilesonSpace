#include "game.h"
#include <Character/charactersuperclass.h>
#include <Youler/youler.h>

Game::Game()
{
/*Main Menu
 * Settings Screen
 * Pause Screen?
 */
    //creating the scene
    scene = new QGraphicsScene();

    scene->setSceneRect(0,0,1920,1080);

    //adding scene to view
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // this will have to be turned off to allow character tracking
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setFixedSize(1920,1500);                              // Will need to be changed to setFixedHeight(HEIGHT)

    showFullScreen();

    TimerGravity =  new QTimer();


}

void Game::start(){
    scene->clear();

    TimerGravity->start(3);

    CharacterSuperClass *Character = new Youler(this);
    Character->setPos(scene->width()/2-Character->rect().width()/2,scene->height()/2-Character->rect().height()/2);
    scene->addItem(Character);
    Character->setFlag(QGraphicsItem::ItemIsFocusable);
    Character->setFocus();



}

void Game::mainMenu(){
  interface = new MInterface(this);


}

QGraphicsScene* Game::getScene(){
  return scene;

}

