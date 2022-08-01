#include "Actor.h"

namespace Engine
{
	void Engine::Actor::Draw(Renderer& renderer)
	{
		model_.Draw(renderer, transform_.position, transform_.rotation, transform_.scale);
	}
}
