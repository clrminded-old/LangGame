/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Coin.h"
#include "Actor.h"
#include "BrickBoarder.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
	
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	
	bool IsColliding(int x0, int y0, int width0, int height0, int x1, int y1, int width1, int height1);
	int ClampScreenX(int x, int width);
	int ClampScreenY(int y, int height);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	// myBox is the one that I control the movement of
	Actor myBox;

	Coin coin0;
	Coin coin1;
	Coin coin2;
	
	BrickBoarder brick;

	std::vector<std::string> directions = { "left", "right", "up", "down" };
	std::string direction;

	bool coin0IsCollected = false;
	bool coin1IsCollected = false;
	bool coin2IsCollected = false;
	/********************************/
};