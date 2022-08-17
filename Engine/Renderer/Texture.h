#pragma once
#include "..\Math\Vector2.h"
#include "Resource/Resource.h"
#include <string>

struct SDL_Texture;

namespace Engine
{
	class Renderer;

	class Texture : public Resource
	{
	public:

		Texture() = default;
		~Texture();
		
		bool Create(const std::string filename, ...) override;
		bool Create(Renderer& renderer, const std::string& filename);
		Vector2 GetSize() const;
		SDL_Texture* texture_ = nullptr;

	private:

		
	};
}