#include "TextureManager.h"
#include <SDL_image.h>

bool TextureManager::load(const std::string &filename, const std::string &id, SDL_Renderer* pRenderer){
	SDL_Surface* pTempSurface = IMG_Load(filename.c_str());
    if(pTempSurface == NULL){
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer,pTempSurface);
    SDL_FreeSurface(pTempSurface);

	if(pTexture == NULL){
		return false;
	}

    m_textureMap.insert( std::pair<std::string,SDL_Texture *>(id,pTexture) );
	return true;
}
