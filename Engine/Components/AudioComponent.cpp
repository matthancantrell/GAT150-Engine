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
	bool AudioComponent::Write(const rapidjson::Value& value)const { return true; }
	bool AudioComponent::Read(const rapidjson::Value& value) { return true; }
}
