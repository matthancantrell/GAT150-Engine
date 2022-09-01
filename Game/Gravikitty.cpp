#include "Gravikitty.h"
#include "Engine.h"
#include <iostream>

void Gravikitty::Initialize()
{
	scene_ = std::make_unique<Engine::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "Text-Models/Prefab.txt", "Levels/level.txt", "Text-Models/Tilemap.txt"};

	for (auto sceneName : sceneNames)
	{
		bool success = Engine::json::Load(sceneName, document);
		if (!success)
		{
			LOG("error could not load scene %s", sceneName.c_str());
			continue;
		}

		scene_->Read(document);
	}
	scene_->Initialize();
}

void Gravikitty::Shutdown()
{
	scene_->RemoveAll();
}

void Gravikitty::Update()
{

	scene_->Update();
}

void Gravikitty::Draw(Engine::Renderer& renderer)
{
	scene_->Draw(renderer);
}