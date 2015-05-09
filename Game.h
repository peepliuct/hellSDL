#ifndef __Game__
#define __Game__

#include <SDL.h>
#include "TextureManager.h"
#include "Spirit.h"

class Game {

public:
    Game(void):m_bRunning(false),m_pWindow(NULL),m_pRender(NULL),m_pSpirit(NULL){};

    ~Game(void) {};

    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void render(void);

    void update(void);

    void handleEvents(void);

    void clean(void);
   
    bool running(void) { return m_bRunning; }
private:

	void initSpirit(void);
protected:


//-----------------------------------------------------------

public:
private:
    bool m_bRunning;

	SDL_Window* m_pWindow;

	SDL_Renderer* m_pRender;

	Spirit* m_pSpirit;

	TextureManager m_textureManager;

protected:


};

#endif //__Game__
