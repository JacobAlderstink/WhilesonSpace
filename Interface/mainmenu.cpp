#include "mainmenu.h"
#include "button.h"
#include <QDebug>

MainMenu::MainMenu(Game* game)
{
    MMgame = game;
    displayStart();
}

void MainMenu::displayStart(){
    MMgame->getScene()->clear();
    Button* playButton = new Button(QString("Play"));
    int btnX = MMgame->getScene()->width()/2 - playButton->boundingRect().width()/2;
    int btnY = MMgame->getScene()->height()/3;
    playButton->setPos(btnX,btnY);
    MMgame->getScene()->addItem(playButton);
    connect(playButton,SIGNAL(clicked()),MMgame,SLOT(start()));
    Button* DisplayOptionsButton = new Button(QString("Display Options"));
    btnX = MMgame->getScene()->width()/2 - DisplayOptionsButton->boundingRect().width()/2;
    btnY = 2*MMgame->getScene()->height()/3;
    DisplayOptionsButton->setPos(btnX,btnY);
    MMgame->getScene()->addItem(DisplayOptionsButton);
    connect(DisplayOptionsButton,SIGNAL(clicked()),this,SLOT(displayOptions()));

}

void MainMenu::displayOptions(){
    MMgame->getScene()->clear();

    Button* option1Button = new Button(QString("3840 x 2160"));
    int btnX = MMgame->getScene()->width()/2 - option1Button->boundingRect().width()/2;
    int btnY = MMgame->getScene()->height()/5;
    option1Button->setPos(btnX,btnY);

    Button* option2Button = new Button(QString("1920 x 1080"));
    btnX = MMgame->getScene()->width()/2 - option1Button->boundingRect().width()/2;
    btnY = 2*MMgame->getScene()->height()/5;
    option2Button->setPos(btnX,btnY);


    Button* option3Button = new Button(QString("1080 x 720"));
    btnX = MMgame->getScene()->width()/2 - option1Button->boundingRect().width()/2;
    btnY = 3*MMgame->getScene()->height()/5;
    option3Button->setPos(btnX,btnY);

    Button* option4Button = new Button(QString("back"));
    btnX = MMgame->getScene()->width()/2 - option4Button->boundingRect().width()/2;
    btnY = 4*MMgame->getScene()->height()/5;
    option4Button->setPos(btnX,btnY);


    MMgame->getScene()->addItem(option4Button);
    MMgame->getScene()->addItem(option1Button);
    MMgame->getScene()->addItem(option2Button);
    MMgame->getScene()->addItem(option3Button);
    connect(option4Button, SIGNAL(clicked()),this,SLOT(displayStart()));
    connect(option1Button, SIGNAL(clicked()),this,SLOT(DOption1()));
    connect(option2Button, SIGNAL(clicked()),this,SLOT(DOption2()));
    connect(option3Button, SIGNAL(clicked()),this,SLOT(DOption3()));

}


void MainMenu::DOption1(){
    MMgame->getScene()->setSceneRect(0,0,3840,2160);
    displayOptions();

}

void MainMenu::DOption2(){
    MMgame->getScene()->setSceneRect(0,0,1920,1080);
displayOptions();


}

void MainMenu::DOption3(){
    MMgame->getScene()->setSceneRect(0,0,1080,720);
displayOptions();


}
