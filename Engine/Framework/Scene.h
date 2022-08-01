#pragma once
#include "Actor.h"
#include <list>
#include <memory>

namespace Engine
{
	class Actor;
	class Renderer;

	class Scene
	{
	public:

		Scene() = default;
		~Scene() = default;

		void Update();
		void Draw(Renderer& renderer);
		void Add(std::unique_ptr<Actor> actor);

		template<typename T>
		T* GetActor();

	private:

		std::list<std::unique_ptr<Actor>> actors_;

	};

	template<typename T>
	inline T* Scene::GetActor()
	{
		for (auto& actor : actors_)
		{
			T* result = dynamic_cast<T*>(actor.get());
			if (result) return result;
		}
		return nullptr;
	}

}
