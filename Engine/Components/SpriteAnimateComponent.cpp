#include "SpriteAnimateComponent.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"
#include "Engine.h"

namespace Engine
{
	void SpriteAnimateComponent::Update()
	{
		//update frame
		frameTimer += timer_g.deltaTime;
		if (frameTimer >= 1.0f / fps)
		{
			frameTimer = 0;
			frame++;
			if (frame > end_frame)
			{
				frame = start_frame;
			}
		}

		//calculate source rect
		Vector2 cellSize = texture_->GetSize() / Vector2{ num_columns, num_rows };

		int column = (frame - 1) % num_columns;
		int row = (frame - 1) / num_columns;

		source.x = (int)(column * cellSize.x);
		source.y = (int)(row * cellSize.y);
		source.w = (int)(cellSize.x);
		source.h = (int)(cellSize.y);
	}

	void SpriteAnimateComponent::Draw(Renderer& renderer)
	{
		renderer.Draw(texture_, source, owner_->transform_);
	}

	bool SpriteAnimateComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool SpriteAnimateComponent::Read(const rapidjson::Value& value)
	{
		std::string texture_name;
		READ_DATA(value, texture_name);

		texture_ = resourceManager_g.Get<Texture>(texture_name, renderer_g);

		READ_DATA(value, fps);
		READ_DATA(value, num_columns);
		READ_DATA(value, num_rows);
		READ_DATA(value, start_frame);
		READ_DATA(value, end_frame);

		return true;
	}
}