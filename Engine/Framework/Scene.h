#pragma once
#include "Actor.h"
#include <list>
#include <memory>

namespace Engine
{

	class Scene : public ISerializable
	{
	public:

		Scene() = default;
		~Scene() = default;

		void Update();
		void Draw(Renderer& renderer);
		void Add(std::unique_ptr<Actor> actor);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

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
