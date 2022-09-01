#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace Engine
{
	void PlayerComponent::Initialize()
	{
		auto component = owner_->GetComponent<CollisionComponent>();
		if (component)
		{
			component->SetCollisionEnter(std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1));
			component->SetCollisionExit(std::bind(&PlayerComponent::OnCollisionExit, this, std::placeholders::_1));
		}
	}
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

		auto component = owner_->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->ApplyForce(direction * speed);
		}
		// Shoot
		if (inputSystem_g.GetKeyState(key_space) == InputSystem::Pressed)
		{
			auto component = owner_->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::Up * 200);
			}
		}

		// Grav Swap
		if (inputSystem_g.GetKeyState(key_shift) == InputSystem::Pressed)
		{
			auto component = owner_->GetComponent<RBPhysicsComponent>();
			if (component)
			{
				component->GravitySwitch();
			}
		}
		// set camera 
		auto camera = owner_->GetScene()->GetActorFromName("Camera");
		if (camera)
		{
			camera->transform_.position = Math::Lerp(camera->transform_.position, owner_->transform_.position, 2 * timer_g.deltaTime);
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
	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		if (other->GetName() == "Coin")
		{
			other->SetDestroy(true);
		}
		std::cout << "Player Enter" << std::endl;
	}
	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		std::cout << "Player Exit" << std::endl;
	}
}
