#include "ModelComponent.h"
#include "Renderer/Model.h"
#include "Framework/Actor.h"

namespace Engine
{
	void ModelComponent::Update() {}

	void ModelComponent::Draw(Renderer& renderer)
	{
		model_->Draw(renderer, owner_->transform_);
	}
}