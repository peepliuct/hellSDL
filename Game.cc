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

  initSpirit();

  m_textureManager.load("assets/lions.png","spirit_001",m_pRender);
	
  m_bRunning = true;

  return true;
}

void Game::render(void){
  SDL_Rect srcRectangle{0,0,0,0};
  SDL_Rect destRectangle{0,0,128,82};
  // everything is OK, let's draw the window
  // clear the window to black
  SDL_RenderClear(m_pRender);

  Rect rect = m_pSpirit->getCurrentFrameRect();
  rect.convertToSDLRect(srcRectangle);

  SDL_Texture *pTexture = m_textureManager.fetch_texture(m_pSpirit->getSpiritID());

  SDL_RenderCopy(m_pRender,pTexture, &srcRectangle , &destRectangle);

  // show the window
  SDL_RenderPresent(m_pRender); 
}

void Game::update(void){
  if(m_pSpirit != NULL){
    m_pSpirit->update(SDL_GetTicks());
  }
}

void Game::handleEvents(void){
  SDL_Event event;
  if(SDL_PollEvent(&event) == 1){
    switch(event.type){
    case SDL_QUIT:{
      m_bRunning = false;
    }break;
    default:
      break;
    }
  }
}

void Game::clean(void){
  if(m_pRender != NULL){
    SDL_DestroyRenderer(m_pRender);	
  }

  if(m_pWindow != NULL){
    SDL_DestroyWindow(m_pWindow);
  }

  if(m_pSpirit != NULL) {
    delete m_pSpirit;
  }

  SDL_Quit();
}

void Game::initSpirit(void){
  Rect orign_rect(0,0,128,82);
  std::vector<Rect> spiritRects;
  for(int i = 0; i < 6; i++){
    spiritRects.push_back(orign_rect);
    orign_rect.increase_left(128);
  }
  m_pSpirit = new Spirit("spirit_001", spiritRects, 6);
}
