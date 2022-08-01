#pragma once
#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Framework/Scene.h"
#include "Framework/Game.h"

#include <memory>
#include <vector>
#include <list>


namespace Engine
{
	extern InputSystem inputSystem_g;
	extern Renderer renderer_g;
	extern Time timer_g;
	extern AudioSystem audioSystem_g;
}
