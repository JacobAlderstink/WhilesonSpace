#include "mainmenu.h"
#include "button.h"
#include <QDebug>

MainMenu::MainMenu(Game* game)
{
    MMgame = game;
    Button* player1Button = new Button(QString("Play"));
    int btnX = MMgame->getScene()->width()/2 - player1Button->boundingRect().width()/2;
    int btnY = MMgame->getScene()->height()/2;
    player1Button->setPos(btnX,btnY);
    MMgame->getScene()->addItem(player1Button);
    connect(player1Button,SIGNAL(clicked()),MMgame,SLOT(start()));

}

/*
void MainMenu::displaystart(){
    srand(time(NULL));
    int btnX = rand() % 800;
    int btnY = rand() % 600;
    qDebug() << player << " was the player chosen!";
    Button* playButton = new Button(QString("Start"));
    //int btnX = MMgame->getScene()->width()/2 - playButton->boundingRect().width()/2;
    //int btnY = 500;
    playButton->setPos(btnX,btnY);
    connect(playButton, SIGNAL(clicked()),MMgame,SLOT(start()));
    MMgame->getScene()->addItem(playButton);

}
*/
