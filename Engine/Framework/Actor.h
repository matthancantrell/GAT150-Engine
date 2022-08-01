#pragma once
#include "GameObject.h"
#include "../Renderer/Model.h"
#include "Game.h"

namespace Engine
{
	class Scene;
	class Game;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Model& model,const Transform& transform) : GameObject{ transform }, model_{ model }  {}

		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);

		virtual void OnCollision(Actor* other) {}
		float GetRadius() { return model_.GetRadius() * transform_.scale; }
		std::string& GetTag() { return tag_; }
		
		friend class Scene;

		// State
		bool destroy_ = false;

	protected:

		std::string tag_;

		// Physics
		Vector2 velocity_;
		float damping_ = 1;

		// Object
		Scene* scene_ = nullptr;
		Model model_;

	};
}