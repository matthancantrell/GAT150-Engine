#pragma once
#include "RenderComponent.h"

namespace Engine
{
	class Model;

	class ModelComponent : public RenderComponent
	{
	public:

		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		std::shared_ptr<Model> model_;
	};
}