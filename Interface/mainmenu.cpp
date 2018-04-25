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

    Button* playButton = new Button(QString("Play"),MMgame);
    int btnX = MMgame->getScene()->width()/2 - playButton->boundingRect().width()/2;
    int btnY = MMgame->getScene()->height()/3;
    playButton->setPos(btnX,btnY);
    playButton->setBrush(playButton->brushLeave);

    Button* DisplayOptionsButton = new Button(QString("Display Options"),MMgame);
    btnX = MMgame->getScene()->width()/2 - DisplayOptionsButton->boundingRect().width()/2;
    btnY = 2*MMgame->getScene()->height()/3;
    DisplayOptionsButton->setPos(btnX,btnY);
    DisplayOptionsButton->setBrush(DisplayOptionsButton->brushLeave);

    Button* Close = new Button(QString("X"),MMgame);
    btnX = MMgame->getScene()->width()*11/12 - Close->boundingRect().width()/2;
    btnY = MMgame->getScene()->height()*1/16 - Close->boundingRect().height()/2;
    Close->setPos(btnX,btnY);
    Close->brushLeave.setColor(Qt::red);
    Close->brushEnter.setColor(Qt::darkRed);
    Close->setBrush(Close->brushLeave);

    MMgame->getScene()->addItem(playButton);
    MMgame->getScene()->addItem(DisplayOptionsButton);
    MMgame->getScene()->addItem(Close);

    connect(playButton,SIGNAL(clicked()),MMgame,SLOT(start()));
    connect(DisplayOptionsButton,SIGNAL(clicked()),this,SLOT(displayOptions()));
    connect(Close,SIGNAL(clicked()),MMgame,SLOT(closeGame()));


}

void MainMenu::displayOptions(){
    MMgame->getScene()->clear();

    Button* option1Button = new Button(QString("3840 x 2160"),MMgame);
    option1Button->setBrush(option1Button->brushLeave);
    int btnX = MMgame->getScene()->width()/2 - option1Button->boundingRect().width()/2;
    int btnY = MMgame->getScene()->height()/5;
    option1Button->setPos(btnX,btnY);

    Button* option2Button = new Button(QString("1920 x 1080"),MMgame);
    option2Button->setBrush(option2Button->brushLeave);
    btnX = MMgame->getScene()->width()/2 - option1Button->boundingRect().width()/2;
    btnY = 2*MMgame->getScene()->height()/5;
    option2Button->setPos(btnX,btnY);


    Button* option3Button = new Button(QString("1080 x 720"),MMgame);
    option3Button->setBrush(option3Button->brushLeave);
    btnX = MMgame->getScene()->width()/2 - option1Button->boundingRect().width()/2;
    btnY = 3*MMgame->getScene()->height()/5;
    option3Button->setPos(btnX,btnY);

    Button* option4Button = new Button(QString("back"),MMgame);
    option4Button->setBrush(option4Button->brushLeave);
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
    MMgame->ratioConverter = MMgame->getScene()->width()/2160.0;
    displayOptions();

}

void MainMenu::DOption2(){
    MMgame->getScene()->setSceneRect(0,0,1920,1080);
    MMgame->ratioConverter = MMgame->getScene()->width()/2160.0;
displayOptions();


}

void MainMenu::DOption3(){
    MMgame->getScene()->setSceneRect(0,0,1080,720);
    MMgame->ratioConverter = MMgame->getScene()->width()/2160.0;
displayOptions();


}
