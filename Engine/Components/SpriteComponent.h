#pragma once
#include "RenderComponent.h"

namespace Engine
{
	class Texture;

	class SpriteComponent : public RenderComponent
	{
	public:

		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		std::shared_ptr<Texture> texture_;
	};
}