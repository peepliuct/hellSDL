#include "Game.h"
#include <SDL_image.h>


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

	SDL_RenderCopy(m_pRender, m_pTexture, &m_srcRectangle, &m_destRectangle);

    // show the window
    SDL_RenderPresent(m_pRender);
}

void Game::update(void){
	m_srcRectangle.x  = ((( SDL_GetTicks() >> 7) % 6) << 7);
}

void Game::handleEvents(void){
	SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
	  case SDL_QUIT:{
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
	SDL_Surface* pTempSurface = IMG_Load("assets/lion.png");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRender,pTempSurface);
    SDL_FreeSurface(pTempSurface);

	//SDL_QueryTexture(m_pTexture, NULL, NULL, &m_srcRectangle.w, &m_srcRectangle.h);
    m_destRectangle.x = m_srcRectangle.x = 0;
    m_destRectangle.y = m_srcRectangle.y = 0;
    m_destRectangle.w = m_srcRectangle.w = 128;
    m_destRectangle.h = m_srcRectangle.h = 82;
}
