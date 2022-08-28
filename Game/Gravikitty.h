#pragma once
#include "Framework/Game.h"

class Gravikitty : public Engine::Game
{
public:
	virtual void Initialize() override;
	virtual void Shutdown() override;

	virtual void Update() override;
	virtual void Draw(Engine::Renderer& renderer) override;
};
