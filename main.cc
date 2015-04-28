#include <unistd.h>
#include "Game.h"

Game* g_game = NULL;

int main(int argc, char* args[]){
	g_game = new Game() ;
    g_game->init("Game1", 100, 100, 640,480,0);
 
    while (g_game->running()){
		g_game->handleEvents();
        g_game->update();
        g_game->render();
		sleep(10000);
    }

	g_game->clean();
    return 0;
}