#pragma once
#include "GameObject.h"
#include "Serialization/Serialization.h"
#include "Actor.h"

namespace Engine
{
	class Component : public GameObject, public ISerializable
	{
	public:

		Component() = default;
		~Component() = default;

		friend class Actor;

	protected:

		Actor* owner_ = nullptr;

	};
}