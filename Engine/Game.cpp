/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"
#include "Graphics.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

void Game::DrawCrosshair(int x, int y)
{
	// this places x and y to the center of the reticle
	gfx.PutPixel(x - 5, y, 255, 255, 255);
	gfx.PutPixel(x - 4, y, 255, 255, 255);
	gfx.PutPixel(x - 3, y, 255, 255, 255);
	gfx.PutPixel(x + 3, y, 255, 255, 255);
	gfx.PutPixel(x + 4, y, 255, 255, 255);
	gfx.PutPixel(x + 5, y, 255, 255, 255);
	gfx.PutPixel(x, y - 5, 255, 255, 255);
	gfx.PutPixel(x, y - 4, 255, 255, 255);
	gfx.PutPixel(x, y - 3, 255, 255, 255);
	gfx.PutPixel(x, y + 3, 255, 255, 255);
	gfx.PutPixel(x, y + 4, 255, 255, 255);
	gfx.PutPixel(x, y + 5, 255, 255, 255);
}

void Game::DrawBox(int x, int y)
{
	// top
	gfx.PutPixel(x, y, 255, 255, 255);
	gfx.PutPixel(x + 1, y, 255, 255, 255);
	gfx.PutPixel(x + 2, y, 255, 255, 255);
	gfx.PutPixel(x + 6, y, 255, 255, 255);
	gfx.PutPixel(x + 7, y, 255, 255, 255);
	gfx.PutPixel(x + 8, y, 255, 255, 255);

	// right
	gfx.PutPixel(x + 8, y, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 1, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 6, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 7, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 8, 255, 255, 255);

	// bottom
	gfx.PutPixel(x, y + 8, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 8, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 8, 255, 255, 255);
	gfx.PutPixel(x + 6, y + 8, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 8, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 8, 255, 255, 255);

	// left
	gfx.PutPixel(x, y, 255, 255, 255);
	gfx.PutPixel(x, y + 1, 255, 255, 255);
	gfx.PutPixel(x, y + 2, 255, 255, 255);
	gfx.PutPixel(x, y + 6, 255, 255, 255);
	gfx.PutPixel(x, y + 7, 255, 255, 255);
	gfx.PutPixel(x, y + 8, 255, 255, 255);

}

void DrawCeeplusplus(int x, int y) {
    // layer 0 x
    gfx.PutPixel(x +  4, y, 0, 0, 0);
    gfx.PutPixel(x +  5, y, 0, 0, 0);
    gfx.PutPixel(x +  6, y, 0, 0, 0);
    gfx.PutPixel(x +  7, y, 0, 0, 0);
    gfx.PutPixel(x +  8, y, 0, 0, 0);
    gfx.PutPixel(x +  9, y, 0, 0, 0);
    gfx.PutPixel(x + 10, y, 0, 0, 0);
    gfx.PutPixel(x + 11, y, 0, 0, 0);
    
    
    // layer 1
    gfx.PutPixel(x +  0, y + 1, 0, 0, 0);
    gfx.PutPixel(x +  1, y + 1, 0, 0, 0);
    gfx.PutPixel(x +  2, y + 1, 0, 0, 0);
    gfx.PutPixel(x +  3, y + 1, 0, 0, 0);
    gfx.PutPixel(x +  4, y + 1, 0, 0, 0);
    gfx.PutPixel(x +  5, y + 1, 0, 0, 0);
    gfx.PutPixel(x +  6, y + 1, 0, 0, 0);
    gfx.PutPixel(x +  7, y + 1, 0, 0, 0);
    gfx.PutPixel(x +  8, y + 1, 0, 0, 0);
    gfx.PutPixel(x +  9, y + 1, 0, 0, 0);
    gfx.PutPixel(x + 10, y + 1, 0, 0, 0);
    gfx.PutPixel(x + 11, y + 1, 0, 0, 0);
    gfx.PutPixel(x + 12, y + 1, 0, 0, 0);
    gfx.PutPixel(x + 13, y + 1, 0, 0, 0);
    gfx.PutPixel(x + 14, y + 1, 0, 0, 0);
    gfx.PutPixel(x + 15, y + 1, 0, 0, 0);
    
    // layer 2
    gfx.PutPixel(x +  0, y + 2, 0, 0, 0);
    gfx.PutPixel(x +  1, y + 2, 0, 0, 0);
    gfx.PutPixel(x +  2, y + 2, 0, 0, 0);
    gfx.PutPixel(x +  3, y + 2, 0, 0, 0);
    gfx.PutPixel(x +  4, y + 2, 0, 0, 0);
    gfx.PutPixel(x +  5, y + 2, 0, 0, 0);
    gfx.PutPixel(x +  6, y + 2, 0, 0, 0);
    gfx.PutPixel(x +  7, y + 2, 0, 0, 0);
    gfx.PutPixel(x +  8, y + 2, 0, 0, 0);
    gfx.PutPixel(x +  9, y + 2, 0, 0, 0);
    gfx.PutPixel(x + 10, y + 2, 0, 0, 0);
    gfx.PutPixel(x + 11, y + 2, 0, 0, 0);
    gfx.PutPixel(x + 12, y + 2, 0, 0, 0);
    gfx.PutPixel(x + 13, y + 2, 0, 0, 0);
    gfx.PutPixel(x + 14, y + 2, 0, 0, 0);
    gfx.PutPixel(x + 15, y + 2, 0, 0, 0);
    
    // layer 3
    gfx.PutPixel(x +  0, y + 3, 0, 0, 0);
    gfx.PutPixel(x +  1, y + 3, 0, 0, 0);
    gfx.PutPixel(x +  2, y + 3, 0, 0, 0);
    gfx.PutPixel(x +  3, y + 3, 0, 0, 0);
    gfx.PutPixel(x +  4, y + 3, 0, 0, 0);
    gfx.PutPixel(x +  5, y + 3, 0, 0, 0);
    gfx.PutPixel(x +  6, y + 3, 0, 0, 0);
    gfx.PutPixel(x +  7, y + 3, 0, 0, 0);
    gfx.PutPixel(x +  8, y + 3, 0, 0, 0);
    gfx.PutPixel(x +  9, y + 3, 0, 0, 0);
    gfx.PutPixel(x + 10, y + 3, 0, 0, 0);
    gfx.PutPixel(x + 11, y + 3, 0, 0, 0);
    gfx.PutPixel(x + 12, y + 3, 0, 0, 0);
    gfx.PutPixel(x + 13, y + 3, 0, 0, 0);
    gfx.PutPixel(x + 14, y + 3, 0, 0, 0);
    gfx.PutPixel(x + 15, y + 3, 0, 0, 0);
    
    // layer 4
    gfx.PutPixel(x +  0, y, 0, 0, 0);
    gfx.PutPixel(x +  1, y, 0, 0, 0);
    gfx.PutPixel(x +  2, y, 0, 0, 0);
    gfx.PutPixel(x +  3, y, 0, 0, 0);
    gfx.PutPixel(x +  4, y, 0, 0, 0);
    gfx.PutPixel(x +  5, y, 0, 0, 0);
    gfx.PutPixel(x +  6, y, 0, 0, 0);
    gfx.PutPixel(x +  7, y, 0, 0, 0);
    gfx.PutPixel(x +  8, y, 0, 0, 0);
    gfx.PutPixel(x +  9, y, 0, 0, 0);
    gfx.PutPixel(x + 10, y, 0, 0, 0);
    gfx.PutPixel(x + 11, y, 0, 0, 0);
    gfx.PutPixel(x + 12, y, 0, 0, 0);
    gfx.PutPixel(x + 13, y, 0, 0, 0);
    gfx.PutPixel(x + 14, y, 0, 0, 0);
    gfx.PutPixel(x + 15, y, 0, 0, 0);
    
    // layer 5
    gfx.PutPixel(x +  0, y, 0, 0, 0);
    gfx.PutPixel(x +  1, y, 0, 0, 0);
    gfx.PutPixel(x +  2, y, 0, 0, 0);
    gfx.PutPixel(x +  3, y, 0, 0, 0);
    gfx.PutPixel(x +  4, y, 0, 0, 0);
    gfx.PutPixel(x +  5, y, 0, 0, 0);
    gfx.PutPixel(x +  6, y, 0, 0, 0);
    gfx.PutPixel(x +  7, y, 0, 0, 0);
    gfx.PutPixel(x +  8, y, 0, 0, 0);
    gfx.PutPixel(x +  9, y, 0, 0, 0);
    gfx.PutPixel(x + 10, y, 0, 0, 0);
    gfx.PutPixel(x + 11, y, 0, 0, 0);
    gfx.PutPixel(x + 12, y, 0, 0, 0);
    gfx.PutPixel(x + 13, y, 0, 0, 0);
    gfx.PutPixel(x + 14, y, 0, 0, 0);
    gfx.PutPixel(x + 15, y, 0, 0, 0);
    
    // layer 6
    gfx.PutPixel(x +  0, y, 0, 0, 0);
    gfx.PutPixel(x +  1, y, 0, 0, 0);
    gfx.PutPixel(x +  2, y, 0, 0, 0);
    gfx.PutPixel(x +  3, y, 0, 0, 0);
    gfx.PutPixel(x +  4, y, 0, 0, 0);
    gfx.PutPixel(x +  5, y, 0, 0, 0);
    gfx.PutPixel(x +  6, y, 0, 0, 0);
    gfx.PutPixel(x +  7, y, 0, 0, 0);
    gfx.PutPixel(x +  8, y, 0, 0, 0);
    gfx.PutPixel(x +  9, y, 0, 0, 0);
    gfx.PutPixel(x + 10, y, 0, 0, 0);
    gfx.PutPixel(x + 11, y, 0, 0, 0);
    gfx.PutPixel(x + 12, y, 0, 0, 0);
    gfx.PutPixel(x + 13, y, 0, 0, 0);
    gfx.PutPixel(x + 14, y, 0, 0, 0);
    gfx.PutPixel(x + 15, y, 0, 0, 0);
    
    // layer 7
    gfx.PutPixel(x +  0, y, 0, 0, 0);
    gfx.PutPixel(x +  1, y, 0, 0, 0);
    gfx.PutPixel(x +  2, y, 0, 0, 0);
    gfx.PutPixel(x +  3, y, 0, 0, 0);
    gfx.PutPixel(x +  4, y, 0, 0, 0);
    gfx.PutPixel(x +  5, y, 0, 0, 0);
    gfx.PutPixel(x +  6, y, 0, 0, 0);
    gfx.PutPixel(x +  7, y, 0, 0, 0);
    gfx.PutPixel(x +  8, y, 0, 0, 0);
    gfx.PutPixel(x +  9, y, 0, 0, 0);
    gfx.PutPixel(x + 10, y, 0, 0, 0);
    gfx.PutPixel(x + 11, y, 0, 0, 0);
    gfx.PutPixel(x + 12, y, 0, 0, 0);
    gfx.PutPixel(x + 13, y, 0, 0, 0);
    gfx.PutPixel(x + 14, y, 0, 0, 0);
    gfx.PutPixel(x + 15, y, 0, 0, 0);
    
    // layer 8
    gfx.PutPixel(x +  0, y, 0, 0, 0);
    gfx.PutPixel(x +  1, y, 0, 0, 0);
    gfx.PutPixel(x +  2, y, 0, 0, 0);
    gfx.PutPixel(x +  3, y, 0, 0, 0);
    gfx.PutPixel(x +  4, y, 0, 0, 0);
    gfx.PutPixel(x +  5, y, 0, 0, 0);
    gfx.PutPixel(x +  6, y, 0, 0, 0);
    gfx.PutPixel(x +  7, y, 0, 0, 0);
    gfx.PutPixel(x +  8, y, 0, 0, 0);
    gfx.PutPixel(x +  9, y, 0, 0, 0);
    gfx.PutPixel(x + 10, y, 0, 0, 0);
    gfx.PutPixel(x + 11, y, 0, 0, 0);
    gfx.PutPixel(x + 12, y, 0, 0, 0);
    gfx.PutPixel(x + 13, y, 0, 0, 0);
    gfx.PutPixel(x + 14, y, 0, 0, 0);
    gfx.PutPixel(x + 15, y, 0, 0, 0);
    
    // layer 9
    gfx.PutPixel(x +  0, y, 0, 0, 0);
    gfx.PutPixel(x +  1, y, 0, 0, 0);
    gfx.PutPixel(x +  2, y, 0, 0, 0);
    gfx.PutPixel(x +  3, y, 0, 0, 0);
    gfx.PutPixel(x +  4, y, 0, 0, 0);
    gfx.PutPixel(x +  5, y, 0, 0, 0);
    gfx.PutPixel(x +  6, y, 0, 0, 0);
    gfx.PutPixel(x +  7, y, 0, 0, 0);
    gfx.PutPixel(x +  8, y, 0, 0, 0);
    gfx.PutPixel(x +  9, y, 0, 0, 0);
    gfx.PutPixel(x + 10, y, 0, 0, 0);
    gfx.PutPixel(x + 11, y, 0, 0, 0);
    gfx.PutPixel(x + 12, y, 0, 0, 0);
    gfx.PutPixel(x + 13, y, 0, 0, 0);
    gfx.PutPixel(x + 14, y, 0, 0, 0);
    gfx.PutPixel(x + 15, y, 0, 0, 0);
    
    // layer 10
    gfx.PutPixel(x +  0, y, 0, 0, 0);
    gfx.PutPixel(x +  1, y, 0, 0, 0);
    gfx.PutPixel(x +  2, y, 0, 0, 0);
    gfx.PutPixel(x +  3, y, 0, 0, 0);
    gfx.PutPixel(x +  4, y, 0, 0, 0);
    gfx.PutPixel(x +  5, y, 0, 0, 0);
    gfx.PutPixel(x +  6, y, 0, 0, 0);
    gfx.PutPixel(x +  7, y, 0, 0, 0);
    gfx.PutPixel(x +  8, y, 0, 0, 0);
    gfx.PutPixel(x +  9, y, 0, 0, 0);
    gfx.PutPixel(x + 10, y, 0, 0, 0);
    gfx.PutPixel(x + 11, y, 0, 0, 0);
    gfx.PutPixel(x + 12, y, 0, 0, 0);
    gfx.PutPixel(x + 13, y, 0, 0, 0);
    gfx.PutPixel(x + 14, y, 0, 0, 0);
    gfx.PutPixel(x + 15, y, 0, 0, 0);
    
    // layer 11
    gfx.PutPixel(x +  0, y, 0, 0, 0);
    gfx.PutPixel(x +  1, y, 0, 0, 0);
    gfx.PutPixel(x +  2, y, 0, 0, 0);
    gfx.PutPixel(x +  3, y, 0, 0, 0);
    gfx.PutPixel(x +  4, y, 0, 0, 0);
    gfx.PutPixel(x +  5, y, 0, 0, 0);
    gfx.PutPixel(x +  6, y, 0, 0, 0);
    gfx.PutPixel(x +  7, y, 0, 0, 0);
    gfx.PutPixel(x +  8, y, 0, 0, 0);
    gfx.PutPixel(x +  9, y, 0, 0, 0);
    gfx.PutPixel(x + 10, y, 0, 0, 0);
    gfx.PutPixel(x + 11, y, 0, 0, 0);
    gfx.PutPixel(x + 12, y, 0, 0, 0);
    gfx.PutPixel(x + 13, y, 0, 0, 0);
    gfx.PutPixel(x + 14, y, 0, 0, 0);
    gfx.PutPixel(x + 15, y, 0, 0, 0);
    
    // layer 12
    gfx.PutPixel(x +  0, y, 0, 0, 0);
    gfx.PutPixel(x +  1, y, 0, 0, 0);
    gfx.PutPixel(x +  2, y, 0, 0, 0);
    gfx.PutPixel(x +  3, y, 0, 0, 0);
    gfx.PutPixel(x +  4, y, 0, 0, 0);
    gfx.PutPixel(x +  5, y, 0, 0, 0);
    gfx.PutPixel(x +  6, y, 0, 0, 0);
    gfx.PutPixel(x +  7, y, 0, 0, 0);
    gfx.PutPixel(x +  8, y, 0, 0, 0);
    gfx.PutPixel(x +  9, y, 0, 0, 0);
    gfx.PutPixel(x + 10, y, 0, 0, 0);
    gfx.PutPixel(x + 11, y, 0, 0, 0);
    gfx.PutPixel(x + 12, y, 0, 0, 0);
    gfx.PutPixel(x + 13, y, 0, 0, 0);
    gfx.PutPixel(x + 14, y, 0, 0, 0);
    gfx.PutPixel(x + 15, y, 0, 0, 0);
    
    // layer 13
    gfx.PutPixel(x +  0, y, 0, 0, 0);
    gfx.PutPixel(x +  1, y, 0, 0, 0);
    gfx.PutPixel(x +  2, y, 0, 0, 0);
    gfx.PutPixel(x +  3, y, 0, 0, 0);
    gfx.PutPixel(x +  4, y, 0, 0, 0);
    gfx.PutPixel(x +  5, y, 0, 0, 0);
    gfx.PutPixel(x +  6, y, 0, 0, 0);
    gfx.PutPixel(x +  7, y, 0, 0, 0);
    gfx.PutPixel(x +  8, y, 0, 0, 0);
    gfx.PutPixel(x +  9, y, 0, 0, 0);
    gfx.PutPixel(x + 10, y, 0, 0, 0);
    gfx.PutPixel(x + 11, y, 0, 0, 0);
    gfx.PutPixel(x + 12, y, 0, 0, 0);
    gfx.PutPixel(x + 13, y, 0, 0, 0);
    gfx.PutPixel(x + 14, y, 0, 0, 0);
    gfx.PutPixel(x + 15, y, 0, 0, 0);
    
    // layer 14
    gfx.PutPixel(x +  0, y, 0, 0, 0);
    gfx.PutPixel(x +  1, y, 0, 0, 0);
    gfx.PutPixel(x +  2, y, 0, 0, 0);
    gfx.PutPixel(x +  3, y, 0, 0, 0);
    gfx.PutPixel(x +  4, y, 0, 0, 0);
    gfx.PutPixel(x +  5, y, 0, 0, 0);
    gfx.PutPixel(x +  6, y, 0, 0, 0);
    gfx.PutPixel(x +  7, y, 0, 0, 0);
    gfx.PutPixel(x +  8, y, 0, 0, 0);
    gfx.PutPixel(x +  9, y, 0, 0, 0);
    gfx.PutPixel(x + 10, y, 0, 0, 0);
    gfx.PutPixel(x + 11, y, 0, 0, 0);
    gfx.PutPixel(x + 12, y, 0, 0, 0);
    gfx.PutPixel(x + 13, y, 0, 0, 0);
    gfx.PutPixel(x + 14, y, 0, 0, 0);
    gfx.PutPixel(x + 15, y, 0, 0, 0);
    
    // layer 15
    gfx.PutPixel(x +  0, y, 0, 0, 0);
    gfx.PutPixel(x +  1, y, 0, 0, 0);
    gfx.PutPixel(x +  2, y, 0, 0, 0);
    gfx.PutPixel(x +  3, y, 0, 0, 0);
    gfx.PutPixel(x +  4, y, 0, 0, 0);
    gfx.PutPixel(x +  5, y, 0, 0, 0);
    gfx.PutPixel(x +  6, y, 0, 0, 0);
    gfx.PutPixel(x +  7, y, 0, 0, 0);
    gfx.PutPixel(x +  8, y, 0, 0, 0);
    gfx.PutPixel(x +  9, y, 0, 0, 0);
    gfx.PutPixel(x + 10, y, 0, 0, 0);
    gfx.PutPixel(x + 11, y, 0, 0, 0);
    gfx.PutPixel(x + 12, y, 0, 0, 0);
    gfx.PutPixel(x + 13, y, 0, 0, 0);
    gfx.PutPixel(x + 14, y, 0, 0, 0);
    gfx.PutPixel(x + 15, y, 0, 0, 0);
    
    
}

/**
* So the very first thing that we learn is that we have the power to control the pixels on the screen with PutPixel.
* PutPixel is a method from the gfx class. We included the "Graphics.h" at the top that gives us the ability to use it.
* The parameters are the x and y coordinates and the last 3 params are the rbg values that we get the color.
* Easiest and most common way we will see PutPixels will be using variables x and y with operations to move. 
* (This will be greatly improved in the future)
*/
void Game::ComposeFrame()
{
	const int x = 400;
	const int y = 100;

	// made some functions that use the keyboard output and change the drawn images
	// The hope is to start drawing different images.

	if (wnd.kbd.KeyIsPressed(VK_CONTROL)) {
		DrawCrosshair(x, y);
	} 
	else {
		DrawBox(x, y);
	}
	
	


}
