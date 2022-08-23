#include "Engine.h"
#include "Math/MathUtils.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include <iostream>

using namespace std;
// DEPENDENCIES

int main()
{
	// Initialize Memory and Declare Fi lepath

	Engine::InitializeMemory();
	Engine::SetFilePath("../Assets");

	// Initialize Our Major Systems

	Engine::renderer_g.Initialize();
	Engine::inputSystem_g.Initialize();
	Engine::audioSystem_g.Initialize();
	Engine::resourceManager_g.Initialize();
	Engine::physics_g.Initialize();

	Engine::Engine::Instance().Register();

	// Create A Window And Set Background Color
	Engine::renderer_g.CreateWindow("Engine", 800, 600); // Creates the window with parameters
	Engine::renderer_g.SetClearColor(Engine::Color{ 50, 50, 50, 255 }); // Sets background color within window

	// Scene, Actor, Components
	Engine::Scene scene;

	rapidjson::Document document;
	bool success = Engine::json::Load("Levels/level.txt", document);
	scene.Read(document);
	scene.Initialize();
	
	bool quit = false;
	while (!quit)
	{

		// Update
		Engine::inputSystem_g.Update();
		Engine::audioSystem_g.Update();
		Engine::timer_g.Tick();

		if (Engine::inputSystem_g.GetKeyState(Engine::key_esc) == Engine::InputSystem::KeyState::Pressed) quit = true;

		scene.Update();

		// Render
		Engine::renderer_g.BeginFrame();

		scene.Draw(Engine::renderer_g);

		Engine::renderer_g.EndFrame();
	}

	Engine::inputSystem_g.ShutDown();
	Engine::audioSystem_g.ShutDown();
	Engine::renderer_g.ShutDown();
	Engine::resourceManager_g.ShutDown();
	Engine::physics_g.Shutdown();
}