#pragma once
#include "../Math/Transform.h";

namespace Engine
{
	class GameObject
	{
	public:

		GameObject() = default;

		virtual void Update() = 0;
	};
}