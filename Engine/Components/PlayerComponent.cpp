#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace Engine
{
	void PlayerComponent::Update()
	{
		// Movement
		Vector2 direction = Vector2::Zero;
		if (inputSystem_g.GetKeyState(key_left) == InputSystem::Held)
		{
			direction = Vector2::Left;
		}
		if (inputSystem_g.GetKeyState(key_right) == InputSystem::Held)
		{
			direction = Vector2::Right;
		}

		float thrust = 0;
		if (inputSystem_g.GetKeyState(key_up) == InputSystem::Held)
		{
			thrust = 100;
		}


		auto component = owner_->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->ApplyForce(direction * speed);
		}
		// Shoot
		if (inputSystem_g.GetKeyState(key_space) == InputSystem::Held)
		{
			auto component = owner_->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::Up * 30);
			}
		}
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, speed);

		return true;
	}
}
