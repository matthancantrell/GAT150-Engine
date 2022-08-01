#pragma once
#include <string>
#include <map>
namespace FMOD
{
	class System;
	class Sound;
}

namespace Engine
{
	class AudioSystem
	{
	public:

		AudioSystem() = default;
		~AudioSystem() = default;

		void Initialize();
		void ShutDown();

		void Update();

		void AddAudio(const std::string& name, const std::string& filename);
		void PlayAudio(const std::string& name);

	private:

		FMOD::System* fmodSystem_;
		std::map<std::string, FMOD::Sound*> sounds_;
	};
}
