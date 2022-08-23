#pragma once
#include "Framework/Component.h"

namespace Engine
{
	class AudioComponent : public Component
	{
	public:

		AudioComponent() = default;
		void Update() override;

		void Play();
		void Stop();

		virtual void Initialize() override {}

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		std::string soundName_;
		float volume_ { 1 };
		float pitch_ { 1 };
		bool playOnAwake_ { false };
		bool loop_ { false };
	};
}