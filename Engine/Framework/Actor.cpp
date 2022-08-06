#include "Actor.h"
#include "Components/RenderComponent.h"

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
	}
}
