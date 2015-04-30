#include <iostream>
#include "Game.h"

Game* g_game = NULL;

int main(int argc, char* args[]){
	g_game = new Game() ;
    g_game->init("Game1", 100, 100, 640,480,false);
 
    while (g_game->running()){
		std::cout << "starting handling the event" << std::endl;
		g_game->handleEvents();
		std::cout << "finishing handling the event" << std::endl;
        g_game->update();
        g_game->render();
    }

	g_game->clean();
    return 0;
}
