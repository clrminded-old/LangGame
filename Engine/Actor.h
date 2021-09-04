#pragma once
#include "Graphics.h"
#include <string>

class Actor {
public:

	void DrawActorLeft(Graphics& gfx);
	void DrawActorRight(Graphics& gfx);
	void DrawActorFront(Graphics& gfx);
	void DrawActorBack(Graphics& gfx);
	void ClampToScreen();

	int x = 400;
	int y = 300;

	static constexpr int width = 24;
	static constexpr int height = 24;
};