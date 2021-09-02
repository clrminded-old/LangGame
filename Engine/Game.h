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
#include "Box.h"

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
	
	bool overlapTest(int x0, int y0, int x1, int y1);

	int ClampScreenX(int x, int width);
	int ClampScreenY(int y, int height);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Box box0;
	Box myBox;

	int vx = 0;
	int vy = 0;

	int gb = 255;
	bool controlIsPressed = false;
	bool shapeIsChanged = false; // used to be called ShiftIsPressed
	bool inhibitUp = false; // checking to see if we have handled the keypress before?
	bool inhibitDown = false;
	bool inhibitLeft = false;
	bool inhibitRight = false;
	bool isEaten = false;
	/********************************/
};