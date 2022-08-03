#include "Engine.h"
#include <iostream>

using namespace std;
// DEPENDENCIES

int main()
{
	// Initialize Memory and Declare Filepath

	Engine::InitializeMemory();
	Engine::SetFilePath("../Assets");

	// Initialize Our Major Systems

	Engine::renderer_g.Initialize();
	Engine::inputSystem_g.Initialize();
	Engine::audioSystem_g.Initialize();

	Engine::audioSystem_g.AddAudio("laser", "jump.wav");

	// Create A Window And Set Background Color
	Engine::renderer_g.CreateWindow("Engine", 800, 600); // Creates the window with parameters
	Engine::renderer_g.SetClearColor(Engine::Color{ 0, 0, 0, 255 });

	// Create A Texture
	std::shared_ptr<Engine::Texture> texture = std::make_shared<Engine::Texture>();
	texture->Create(Engine::renderer_g, "index.png");

	bool quit = false;
	while (!quit)
	{

		// Update
		Engine::inputSystem_g.Update();
		Engine::audioSystem_g.Update();
		Engine::timer_g.Tick();

		if (Engine::inputSystem_g.onKeyEsc(Engine::InputSystem::KeyState::Pressed)) quit = true;

		// Render
		Engine::renderer_g.BeginFrame();

		Engine::renderer_g.Draw(texture, { 200, 200 }, 0);

		Engine::renderer_g.EndFrame();
	}

	Engine::inputSystem_g.ShutDown();
	Engine::audioSystem_g.ShutDown();
	Engine::renderer_g.ShutDown();
}