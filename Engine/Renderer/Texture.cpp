#include "Texture.h"
#include "Renderer.h"
#include "Core/Logger.h"
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
		if (surface == nullptr) LOG(SDL_GetError());

		// Create Texture
		texture_ = SDL_CreateTextureFromSurface(renderer.GetRenderer_(), surface);
		if (texture_ == nullptr)
		{
			LOG(SDL_GetError());
			SDL_FreeSurface(surface);
			return false;
		}
		
		return true;
	}

	Engine::Vector2 Texture::GetSize() const
	{
		SDL_Point point;
		SDL_QueryTexture(texture_, nullptr, nullptr, &point.x, &point.y);

		return Vector2{ point.x, point.y };
	}
}