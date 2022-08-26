#pragma once
#include "Framework/Component.h"
#include "Math/Vector2.h"

namespace Engine
{
	class Actor;

	class PhysicsComponent : public Component
	{
	public:

		PhysicsComponent() = default;

		void Update() override;
		virtual void ApplyForce(const Vector2& force) { acceleration_ += force; }

		virtual void Initialize() override {}

		bool Write(const rapidjson::Value& value) const;
		bool Read(const rapidjson::Value& value);

		Vector2 velocity_;
		Vector2 acceleration_;

		float damping = 1;
	};
}
