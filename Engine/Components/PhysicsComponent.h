#pragma once
#include "Framework/Component.h"
#include "Math/Vector2.h"

namespace Engine
{
	class PhysicsComponent : public Component
	{
	public:

		PhysicsComponent() = default;

		void Update() override;
		void ApplyForce(const Vector2& force) { acceleration_ += force; }

		Vector2 velocity_;
		Vector2 acceleration_;

		float damping = 1;
	};
}
