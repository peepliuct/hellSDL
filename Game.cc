#include "Game.h"


bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags){
    // initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        // if the initialization failed, exit.
        return false;
    }

    // if succeeded create the first window
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width,height,flags);

    // if failed, exit
    if(m_pWindow == NULL){
		return false;
    }


    m_pRender = SDL_CreateRenderer(m_pWindow, -1, 0);
    // if failed, exit
    if(m_pRender == NULL){
        return false;
    }

	return true;
}

void Game::render(void){
    // everything is OK, let's draw the window
    SDL_SetRenderDrawColor(m_pRender,0,0,0,255); 
 

    // clear the window to black
    SDL_RenderClear(m_pRender);


    // show the window
    SDL_RenderPresent(m_pRender);


    // delay 5s before the window shuts down
    SDL_Delay(5000);
}

void Game::update(void){
	;
}

void Game::handleEvents(void){
	;
}

void Game::clean(void){
    if(m_pRender != NULL){
	   SDL_DestroyRenderer(m_pRender);	
	}

	if(m_pWindow != NULL){
		SDL_DestroyWindow(m_pWindow);
	}

    SDL_Quit();
}
