#include "AudioSystem.h"
#include <fmod.hpp>

void Engine::AudioSystem::Initialize()
{
	FMOD::System_Create(&fmodSystem_);

	void* extradriverdata = nullptr;
	fmodSystem_->init(32, FMOD_INIT_NORMAL, extradriverdata);
}

void Engine::AudioSystem::ShutDown()
{
	for (auto sound : sounds_)
	{
		sound.second->release();
	}

	sounds_.clear();
	fmodSystem_->close();
	fmodSystem_->release();
}

void Engine::AudioSystem::Update()
{
	fmodSystem_->update();
}

void Engine::AudioSystem::AddAudio(const std::string& name, const std::string& filename)
{
	auto it = sounds_.find(name);
	if (it == sounds_.end())
	{
		FMOD::Sound* sound = nullptr;
		fmodSystem_->createSound(filename.c_str(), FMOD_DEFAULT, 0, &sound);
		sounds_[name] = sound;
	}
}

void Engine::AudioSystem::PlayAudio(const std::string& name)
{
	auto it = sounds_.find(name);
	if (it != sounds_.end())
	{
		FMOD::Sound* sound = it->second;
		sound->setMode(FMOD_LOOP_OFF);

		FMOD::Channel* channel;
		fmodSystem_->playSound(sound, 0, false, &channel);
	}
}
