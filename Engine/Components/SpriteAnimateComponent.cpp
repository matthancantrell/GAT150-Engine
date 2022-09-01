#include "SpriteAnimateComponent.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"
#include "Renderer/Texture.h"
#include "Engine.h"

namespace Engine
{
	void SpriteAnimateComponent::Update()
	{
		//update frame
		frameTimer += timer_g.deltaTime;
		if (frameTimer >= 1.0f / sequence_->fps)
		{
			frameTimer = 0;
			frame++;
			if (frame > sequence_->end_frame)
			{
				frame = sequence_->start_frame;
			}
		}
	}

	Rect& SpriteAnimateComponent::GetSource()
	{
		// calculate source rect 
		Vector2 cellSize = sequence_->texture_->GetSize() / Vector2{ sequence_->num_columns, sequence_->num_rows };

		int column = (frame - 1) % sequence_->num_columns;
		int row = (frame - 1) / sequence_->num_columns;

		source.x = (int)(column * cellSize.x);
		source.y = (int)(row * cellSize.y);
		source.w = (int)(cellSize.x);
		source.h = (int)(cellSize.y);

		return source;
	}

	void SpriteAnimateComponent::Draw(Renderer& renderer)
	{
		renderer.Draw(sequence_->texture_, GetSource(), owner_->transform_);
	}

	void SpriteAnimateComponent::SetSequence(const std::string& name)
	{
		// don’t restart sequence if already playing 
		if (sequence_ && sequence_->name == name) return;

		if (sequences_.find(name) != sequences_.end())
		{
			sequence_ = &sequences_[name];

			frame = sequence_->start_frame;
			frameTimer = 0;
		}
	}

	bool SpriteAnimateComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool SpriteAnimateComponent::Read(const rapidjson::Value& value)
	{
		// read in animation sequences 
		if (value.HasMember("sequences") && value["sequences"].IsArray())
		{
			for (auto& sequenceValue : value["sequences"].GetArray())
			{
				Sequence sequence;

				READ_DATA(sequenceValue, sequence.name);
				READ_DATA(sequenceValue, sequence.fps);
				READ_DATA(sequenceValue, sequence.num_columns);
				READ_DATA(sequenceValue, sequence.num_rows);
				READ_DATA(sequenceValue, sequence.start_frame);
				READ_DATA(sequenceValue, sequence.end_frame);

				std::string texture_name;
				READ_DATA(sequenceValue, texture_name);

				sequence.texture_ = resourceManager_g.Get<Texture>(texture_name, renderer_g);

				sequences_[sequence.name] = sequence;
			}
		}

		std::string default_sequence;
		if (!READ_DATA(value, default_sequence))
		{
			// if default sequence not specified, use the first sequence name in the sequences map 
			default_sequence = sequences_.begin()->first;
		}
		SetSequence(default_sequence);

		return true;
	}
}