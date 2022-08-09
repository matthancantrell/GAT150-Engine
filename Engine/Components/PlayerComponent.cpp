#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace Engine
{
	void PlayerComponent::Update()
	{
		// Movement
		if (inputSystem_g.GetKeyState(key_left) == InputSystem::Held)
		{
			owner_->transform_.rotation -= 180 * timer_g.deltaTime;
		}
		if (inputSystem_g.GetKeyState(key_right) == InputSystem::Held)
		{
			owner_->transform_.rotation += +180 * timer_g.deltaTime;
		}

		float thrust = 0;
		if (inputSystem_g.GetKeyState(key_up) == InputSystem::Held)
		{
			thrust = 100;
		}


		auto component = owner_->GetComponent<PhysicsComponent>();
		if (component)
		{
			// Thrust Force
			Vector2 force = Vector2::Rotate({ 1, 0 }, Math::DegToRad(owner_->transform_.rotation)) * thrust;
			component->ApplyForce(force);

			// Gravity
			force = (Vector2{ 400,300 } - owner_->transform_.position).Normalized() * 60.0;
			component->ApplyForce(force);
		}
		// Shoot
		if (inputSystem_g.GetKeyState(key_space) == InputSystem::Held)
		{
			auto component = owner_->GetComponent<AudioComponent>();
			if (component) component->Play();
		}
	}
}
