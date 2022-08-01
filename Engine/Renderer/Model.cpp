#include "Model.h"
#include "../Core/File.h"

#include <iostream>
#include <sstream>

namespace Engine
{

	void Model::Draw(Renderer& renderer, const Vector2& position, float angle, float scale)
	{

		for (int i = 0; i < points_.size() - 1; i++)
		{
			Engine::Vector2 p1 = Vector2::Rotate((points_[i]* scale), angle) + position;
			Engine::Vector2 p2 = Vector2::Rotate((points_[i + 1] * scale), angle) + position;
			renderer.DrawLine(p1, p2, color_);
		}
	}

	void Model::Load(const std::string& filename)
	{
		std::string buffer;

		Engine::ReadFile(filename, buffer);

		// Read Color
		std::istringstream stream(buffer);
		stream >> color_;

		// Read Number of Points
		std::string line;
		std::getline(stream, line);
		size_t numPoints = std::stoi(line);

		//// Read Model Points
		for (size_t i = 0; i < numPoints; i++)
		{
			Vector2 point;

			stream >> point;
			points_.push_back(point);
		}
	}

	float Model::CalculateRadius()
	{
		float radius = 0;

		// Find Largest Length
		for (auto point : points_)
		{
			if (point.Length() > radius) radius = point.Length();
		}

		return radius;
	}
}