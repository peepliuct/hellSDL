#ifndef __Game__
#define __Game__

#include <SDL.h>

class Game {

public:
    Game(void):m_bRunning(true){};

    ~Game(void) {};

    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

    void render(void);

    void update(void);

    void handleEvents(void);

    void clean(void);
   
    bool running(void) { return m_bRunning; }
private:
protected:


//-----------------------------------------------------------

public:
private:
    bool m_bRunning;

	SDL_Window* m_pWindow = NULL;

	SDL_Renderer* m_pRender = NULL;

protected:


};

#endif //__Game__
