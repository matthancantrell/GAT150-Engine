#pragma once
#include "Resource/Resource.h"
#include <string>

struct _TTF_Font;

namespace Engine
{
	class Font : public Resource
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		bool Create(const std::string& filename, int& fontsize);
		bool Create(const std::string filename, ...) override;

		bool Load(const std::string& filename, int fontsize);

		friend class Text;

	private:

		_TTF_Font* ttfFont_ = nullptr;
		
	};
}