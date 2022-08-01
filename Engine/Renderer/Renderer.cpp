#include "Renderer.h"
#include <SDL.h>
#include <SDL_ttf.h>

namespace Engine
{
	void Renderer::Initialize()
	{
		SDL_Init(SDL_INIT_VIDEO);
		TTF_Init();
	}
	void Renderer::ShutDown() // Shutdown is often in opposite order of initialization
	{
		SDL_DestroyRenderer(renderer_);
		SDL_DestroyWindow(window_);
		TTF_Quit();
	}
	void Renderer::CreateWindow(const char* title, int width, int height)
	{
		width_ = width;
		height_ = height;

		window_ = SDL_CreateWindow(title, 100, 100, width_, height_, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	}
	void Renderer::BeginFrame()
	{
		SDL_SetRenderDrawColor(renderer_, clearColor_.r, clearColor_.g, clearColor_.b, clearColor_.a);
		SDL_RenderClear(renderer_);
	}
	void Renderer::EndFrame()
	{
		SDL_RenderPresent(renderer_);
	}
	void Renderer::DrawLine(float x1, float y1, float x2, float y2)
	{
		SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
		SDL_RenderDrawLineF(renderer_, x1, y1, x2, y2);
	}
	void Renderer::DrawPoint(float x, float y)
	{
		SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0);
		SDL_RenderDrawPointF(renderer_, x, y);
	}
	void Renderer::DrawLine(const Vector2& v1, const Vector2& v2, const Color& color)
	{
		SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
		SDL_RenderDrawLineF(renderer_, v1.x, v1.y, v2.x, v2.y);
	}
	void Renderer::DrawPoint(const Vector2& v, const Color& color)
	{
		SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
		SDL_RenderDrawPointF(renderer_, v.x, v.y);
	}
}