#pragma once
#include "Singleton.h"
#include <memory>
#include <string>
#include <map>

namespace Engine
{
	class GameObject;
	class CreatorBase
	{
	public:

		virtual std::unique_ptr<GameObject> Create() = 0;
	};

	template <typename T>
	class Creator: public CreatorBase
	{

		virtual std::unique_ptr<GameObject> Create() override
		{
			return std::make_unique<T>();
		}
	};

	class Factory: public Singleton<Factory>
	{
	public:
		template <typename T>
		void Register(const std::string& key);

		template <typename T>
		std::unique_ptr<T> Create(const std::string& key);

	private:

		std::map<std::string, std::unique_ptr<CreatorBase>> registry_;
	};

	template<typename T>
	inline void Factory::Register(const std::string& key)
	{
		registry_[key] = std::make_unique<Creator<T>>();
	}

	template<typename T>
	inline std::unique_ptr<T> Factory::Create(const std::string& key)
	{
		auto iter = registry_.find(key);
		if (iter != registry_.end())
		{
			return std::unique_ptr<T>(dynamic_cast<T*>(iter->second->Create().release()));
		}

		return std::unique_ptr<T>();
	}
}