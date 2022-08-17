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

	rapidjson::Document document;
	bool success = Engine::json::Load("json.txt", document);
	assert(success);

	std::string str;
	Engine::json::Get(document, "string", str);
	std::cout << str << std::endl;

	bool b;
	Engine::json::Get(document, "boolean", b);
	std::cout << b << std::endl;

	int i1;
	Engine::json::Get(document, "integer1", i1);
	std::cout << i1 << std::endl;

	int i2;
	Engine::json::Get(document, "integer2", i2);
	std::cout << i2 << std::endl;

	float f;
	Engine::json::Get(document, "float", f);
	std::cout << f << std::endl;

	Engine::Vector2 v2;
	Engine::json::Get(document, "vector2", v2);
	std::cout << v2 << std::endl;

	Engine::Color color;
	Engine::json::Get(document, "color", color);
	std::cout << color << std::endl;

	// Initialize Our Major Systems

	Engine::renderer_g.Initialize();
	Engine::inputSystem_g.Initialize();
	Engine::audioSystem_g.Initialize();
	Engine::resourceManager_g.Initialize();

	Engine::Engine::Instance().Register();

	// Create A Window And Set Background Color
	Engine::renderer_g.CreateWindow("Engine", 800, 600); // Creates the window with parameters
	Engine::renderer_g.SetClearColor(Engine::Color{ 0, 0, 0, 255 }); // Sets background color within window

	// Scene, Actor, Components
	Engine::Scene scene;
	
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
}