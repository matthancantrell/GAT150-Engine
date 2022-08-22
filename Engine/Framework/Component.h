#pragma once
#include "GameObject.h"
#include "Serialization/Serialization.h"

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