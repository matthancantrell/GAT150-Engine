#include "Engine.h"

namespace Engine
{
	InputSystem inputSystem_g;
	Renderer renderer_g;
	Time timer_g;
	AudioSystem audioSystem_g;
	ResourceManager resourceManager_g;

	void Engine::Register()
	{
		Factory::Instance().Register<Actor>("Actor");
	}
}