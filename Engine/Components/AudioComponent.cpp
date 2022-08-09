#include "AudioComponent.h"
#include "Engine.h"

namespace Engine
{
	void AudioComponent::Update()
	{

	}
	void AudioComponent::Play()
	{
		audioSystem_g.PlayAudio(soundName_, loop_);
	}
	void AudioComponent::Stop()
	{
	}
}
