#include "minterface.h"
#include "mainmenu.h"

MInterface::MInterface(Game* pasGame)
{
game = pasGame;
menu = new MainMenu(game);


}
