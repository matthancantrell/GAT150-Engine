#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

void Engine::PlayerComponent::Update()
{
	if (Engine::inputSystem_g.GetKeyState(key_left) == Engine::InputSystem::Held)
	{
		owner_->transform_.position += {-10, 0 };
	}

	if (Engine::inputSystem_g.GetKeyState(key_right) == Engine::InputSystem::Held)
	{
		owner_->transform_.position += { 10, 0 };
	}

	if (Engine::inputSystem_g.GetKeyState(key_up) == Engine::InputSystem::Held)
	{
		owner_->transform_.position += { 0,-10 };
	}

	if (Engine::inputSystem_g.GetKeyState(key_down) == Engine::InputSystem::Held)
	{
		owner_->transform_.position += { 0,10 };
	}
}
