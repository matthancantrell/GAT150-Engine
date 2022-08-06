#pragma once
#include "GameObject.h"
#include "Component.h"
#include <vector>

namespace Engine
{
	class Scene;
	class Renderer;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Transform& transform) : transform_{ transform } {}

		virtual void Update() override;
		virtual void Draw(Renderer& renderer);

		void AddComponent(std::unique_ptr<Component> component);

		virtual void OnCollision(Actor* other) {}
		float GetRadius() { return 0; } // model_.GetRadius()* std::max(transform_.scale.x, transform_.scale.y);
	
		std::string& GetTag() { return tag_; }
		
		friend class Scene;

		// State
		bool destroy_ = false;

		Transform transform_;

	protected:

		std::string tag_;

		// Physics
		Vector2 velocity_;
		float damping_ = 1;

		// Object
		Scene* scene_ = nullptr;

		std::vector<std::unique_ptr<Component>> components_;

	};
}