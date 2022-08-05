#include "Engine.h"
#include "Math/MathUtils.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include <iostream>

#define NAME "Matthan"
#define YES

using namespace std;
// DEPENDENCIES

int add(int a, int b)
{
	return a + b;
}

constexpr int add_c(int a, int b)
{
	return a + b;
}

int main()
{
	cout << NAME << endl;
	cout << __FILE__ << endl;
	cout << __LINE__ << endl;
	cout << __FUNCTION__ << endl;

#ifdef YES
	cout << "Yes!" << endl;
#endif


	// Initialize Memory and Declare Filepath

	Engine::InitializeMemory();
	Engine::SetFilePath("../Assets");

	// Initialize Our Major Systems

	Engine::renderer_g.Initialize();
	Engine::inputSystem_g.Initialize();
	Engine::audioSystem_g.Initialize();

	Engine::audioSystem_g.AddAudio("laser", "laser.wav");

	// Create A Window And Set Background Color
	Engine::renderer_g.CreateWindow("Engine", 800, 600); // Creates the window with parameters
	Engine::renderer_g.SetClearColor(Engine::Color{ 0, 0, 0, 255 });

	// Create A Texture
	std::shared_ptr<Engine::Texture> texture = std::make_shared<Engine::Texture>();
	texture->Create(Engine::renderer_g, "index.png");

	float angle = 0;

	bool quit = false;
	while (!quit)
	{

		// Update
		Engine::inputSystem_g.Update();
		Engine::audioSystem_g.Update();
		Engine::timer_g.Tick();

		if (Engine::inputSystem_g.GetKeyState(Engine::key_esc) == Engine::InputSystem::KeyState::Pressed) quit = true;

		angle += 360.0f * Engine::timer_g.deltaTime;

		// Render
		Engine::renderer_g.BeginFrame();

		Engine::renderer_g.Draw(texture, { 400, 300 }, angle, { 1, 1 }, { 0.5f, 0.5f });

		Engine::renderer_g.EndFrame();
	}

	Engine::inputSystem_g.ShutDown();
	Engine::audioSystem_g.ShutDown();
	Engine::renderer_g.ShutDown();
}