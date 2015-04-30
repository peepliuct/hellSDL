#include "Game.h"
#include <iostream>


bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    // initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        // if the initialization failed, exit.
        return false;
    }

	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

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

    SDL_SetRenderDrawColor(m_pRender,0,0,0,255); 

	loadAssets();
	
	m_bRunning = true;

	return true;
}

void Game::render(void){
    // everything is OK, let's draw the window
    // clear the window to black
    SDL_RenderClear(m_pRender);


    // show the window
    SDL_RenderPresent(m_pRender);


    // delay 5s before the window shuts down
    //SDL_Delay(5000);
}

void Game::update(void){
	;
}

void Game::handleEvents(void){
	SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
	  case SDL_QUIT:{
		std::cout << "m_bRunning = false " << std::endl;
		m_bRunning = false;
	  }break;
	  default:
		break;
     }
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


void Game::loadAssets(void){
	SDL_Surface* pTempSurface = SDL_LoadBMP("assets/fishtitle.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRender,pTempSurface);
    SDL_FreeSurface(pTempSurface);
}
