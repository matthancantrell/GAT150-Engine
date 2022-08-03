#include "Texture.h"
#include "Renderer.h"
#include <SDL.h>
#include <SDL_image.h>

namespace Engine
{
	Texture::~Texture()
	{
		if (texture_ != NULL) SDL_DestroyTexture(texture_);
	}

	bool Texture::Create(Renderer& renderer, const std::string& filename)
	{
		// Load Surface
		SDL_Surface* surface = IMG_Load(filename.c_str());

		// Create Texture
		texture_ = SDL_CreateTextureFromSurface(renderer.GetRenderer_(), surface);
		SDL_FreeSurface(surface);
		return true;
	}

	Engine::Vector2 Texture::GetSize() const
	{
		SDL_Point point;
		SDL_QueryTexture(texture_, nullptr, nullptr, &point.x, &point.y);
		return Vector2{ point.x, point.y };
	}
}