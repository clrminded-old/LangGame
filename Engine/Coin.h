#pragma once

#include "Graphics.h"

class Coin
{
public:
	void Update();
	int x;
	int y;
	int vx;
	int vy;
	static constexpr int width = 32;
	static constexpr int height = 32;
	bool isEaten = false;

	void DrawCoin1(Graphics& gfx);
	void DrawCoin2(Graphics& gfx);
	void DrawCoin3(Graphics& gfx);
	void DrawCoin4(Graphics& gfx);
};