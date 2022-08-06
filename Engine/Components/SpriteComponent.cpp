#include "SpriteComponent.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"

void Engine::SpriteComponent::Update()
{
}

void Engine::SpriteComponent::Draw(Renderer& renderer)
{
	renderer.Draw(texture_, owner_->transform_);
}
