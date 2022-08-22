#include "Actor.h"
#include "Components/RenderComponent.h"
#include "Factory.h"

namespace Engine
{
	void Engine::Actor::Draw(Renderer& renderer)
	{
		for (auto& component : components_)
		{
			//component->Update();
			auto renderComponent = dynamic_cast<RenderComponent*>(component.get());
			if (renderComponent)
			{
				renderComponent->Draw(renderer);
			}
		}

		for (auto& child : children_)
		{
			child->Draw(renderer);
		}
	}
	void Actor::AddChild(std::unique_ptr<Actor> child)
	{
		child->parent_ = this;
		child->scene_ = this->scene_;
		children_.push_back(std::move(child));
	}
	void Actor::AddComponent(std::unique_ptr<Component> component)
	{
		// Sets the owner of the component to THIS Actor instance
		component->owner_ = this; 

		// Adds the component to the list of components in this Actor 
		components_.push_back(std::move(component));
	}
	void Engine::Actor::Update()
	{
		for (auto& component : components_)
		{
			component->Update();
		}
		for (auto& child : children_)
		{
			child->Update();
		}
		if (parent_ != nullptr)
		{
			transform_.Update(parent_->transform_.matrix);
		}
		else
		{
			transform_.Update();
		}

		transform_.Update();
	}

	bool Actor::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, tag_);
		READ_DATA(value, name_);

		transform_.Read(value["actors"]);

		if (!(value.HasMember("actors")) || !value["actors"].IsArray())
		{
			for (auto& componentValue : value["components"].GetArray())
			{
				std::string type;
				READ_DATA(componentValue, type);

				auto component = Factory::Instance().Create<Component>(type);
				if (component)
				{
					component->Read(componentValue);
					AddComponent(std::move(component));
				}
			}
		}

		return true;
	}
}
