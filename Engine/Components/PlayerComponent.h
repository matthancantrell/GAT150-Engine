#pragma once
#include "Framework/Component.h"

namespace Engine
{
	class PlayerComponent : public Component
	{
	public:

		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		float speed = 0;
	};
}
