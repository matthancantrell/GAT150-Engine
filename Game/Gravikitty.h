#pragma once
#include "Framework/Game.h"

class Gravikitty : public Engine::Game
{
public:

	enum class gameState
	{
		title,
		start,
		game,
		death,
		end
	};

	virtual void Initialize() override;
	virtual void Shutdown() override;

	virtual void Update() override;
	virtual void Draw(Engine::Renderer& renderer) override;

protected:

	gameState state_ = gameState::title;
	float stateTimer = 0;
	int lives_ = 9;
};
