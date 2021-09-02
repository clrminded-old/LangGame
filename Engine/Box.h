#pragma once

#include "Graphics.h"

class Box
{
public:
	void Update();
	void DrawBox(Graphics& gfx);
	int x;
	int y;
	int vx = 1;
	int vy = 1;
	static constexpr int width = 8;
	static constexpr int height = 8;
	bool isEaten = false;
};