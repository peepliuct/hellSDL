#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__

#include <string>
#include <SDL.h>
#include "Rect.h"
#include <map>


class TextureManager {

public:
    TextureManager(void){}

    ~TextureManager(void){}

	bool load(const std::string &filename, const std::string &id,SDL_Renderer* pRenderer);

	SDL_Texture *fetch_texture(const std::string &id){ return m_textureMap[id];}

private:
protected:

//-------------------------------------

public:
   std::map<std::string, SDL_Texture*> m_textureMap;
private:
protected:


};


#endif //__TEXTURE_MANAGER_H___
