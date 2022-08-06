#pragma once
#include "Framework/Component.h"

namespace Engine
{
	class PlayerComponent : public Component
	{
	public:

		PlayerComponent() = default;
		~PlayerComponent() = default;

		void Update() override;
	};
}
