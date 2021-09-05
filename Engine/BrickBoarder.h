#pragma once

#include "Graphics.h"

class BrickBoarder
{
public:
	int x = 0;
	int y = 0;
	static constexpr int width = 32;
	static constexpr int height = 32;
	void DrawBrick(Graphics& gfx, int x, int y);
	void DrawBrickDown(Graphics& gfx, int x, int y);
};
