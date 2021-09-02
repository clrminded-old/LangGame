#pragma once

#include "Graphics.h"

class Box
{
public:
	void Update();
	void DrawBox(Graphics& gfx);
	int x;
	int y;
	int vx;
	int vy;
	static constexpr int width = 8;
	static constexpr int height = 8;
	bool isEaten = false;
};