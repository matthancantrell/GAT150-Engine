#include "PhysicsComponent.h"
#include "Engine.h"

namespace Engine
{
	void PhysicsComponent::Update()
	{
		velocity_ += acceleration_ * timer_g.deltaTime;
		owner_->transform_.position += velocity_ * timer_g.deltaTime;
		velocity_ *= damping;

		acceleration_ = Vector2::Zero;
	}
}

