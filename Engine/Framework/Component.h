#pragma once
#include "GameObject.h"

namespace Engine
{
	class Component : public GameObject
	{
	public:

		Component() = default;
		~Component() = default;

		friend class Actor;

	protected:

		Actor* owner_ = nullptr;

	};
}