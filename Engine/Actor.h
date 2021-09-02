#pragma once
#include "Graphics.h"

class Actor {
public:
	void DrawBox(Graphics& gfx);
	void ClampToScreen();

	int x = 400;
	int y = 300;

	static constexpr int width = 8;
	static constexpr int height = 8;
};