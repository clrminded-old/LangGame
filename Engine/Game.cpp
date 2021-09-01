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

/**
* This is the spot where the game logic goes!
* The logic is in update, the drawing code is in ComposeFrame!
* Like MVC. The way everything should be done!
* 
* Main takeaway:
* If we put functions and variables inside the scope of the function, it can not be "remembered"
* The way to be remembered is put that stuff in the header and make it a member variable instead.
* 
* Velocity vs Position
* Easy shit to know what the difference is. 
* Now we have 3 solid ways of moving around a cursor.... we can left the code freely move it with velocity...
* we can inhibit the controls of the movement to control how it moved based on whether the key is held down or not...
* or we can just simply move the position and not deal with velocity. Alot of newly found power.
* These kind of movements can give us alot of insight of how we move forward with different games. with packman moving just the position
* with astroids maybe something along the lines of using an inhibitor.
* and with cases with moving enemies, the free flowing velocity might come into play.
* I wonder if I can get it moving in a circle???? probably have to do something with the math library and use sin(-) and cos(-)?
* 
*/
void Game::UpdateModel()
{
    if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
        // x = x + 100;
        // x = x + 2;
        // vx = vx + 1; move into inhibitor conditional
        if (inhibitRight) {
            // do nothing
        }
        else {
            vx = vx + 1;
            inhibitRight = true;
        }
    }
    else {
        inhibitRight = false;
    }
    if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
        // x = x - 100;
        // x = x - 2;
        //vx = vx - 1;
        if (inhibitLeft) {
            // do nothing
        }
        else {
            vx = vx - 1;
            inhibitLeft = true;
        }
    }
    else {
        inhibitLeft = false;
    }
    if (wnd.kbd.KeyIsPressed(VK_UP)) {
        // y = y - 100;
        // y = y - 2;
        // vy = vy - 1;
        if (inhibitUp) {
            // do nothing
        }
        else {
            vy = vy - 1;
            inhibitUp = true;
        }
    }
    else {
        inhibitUp = false;
    }
    if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
        // y = y + 100;
        // y = y + 2;
        // vy = vy + 1;
        if (inhibitDown) {
            // do nothing
        }
        else {
            vy = vy + 1;
            inhibitDown = true;
        }
    }
    else {
        inhibitDown = false;
    }

    // without this shit dont move!
    x = x + vx;
    y = y + vy;

    // these will bound the reticle inside the bounds of the screen
    if (x <= 0) {
        x = 0;
        vx = 0;
    }
    // You can do this...
    //if (x + 5 >= 800) {
    //    x = 794;
    //    vx = 0;
    //}
    // But a much more sexier way is like this
    if (x + 9 >= gfx.ScreenWidth) {
        x = gfx.ScreenWidth - 9 - 1;
        vx = 0;
    }
    if (y < 0) {
        y = 0;
        vy = 0;
    }
    // Same sexiness here...
    // if (y + 5 >= 600) {
    //     y = 594;
    //     vy = 0;
    // }
    if (y + 9 >= gfx.ScreenHeight) {
        y = gfx.ScreenHeight - 9 - 1;
        vy = 0;
    }

    // controls the change in color of the reticle
    if (wnd.kbd.KeyIsPressed(VK_CONTROL)) {
        gb = 0;
    }
    else {
        gb = 255;
    }

    // changes the shape
    shapeIsChanged = (wnd.kbd.KeyIsPressed(VK_SHIFT));
}

void Game::DrawCrosshair(int x, int y, int r, int g, int b)
{
	// this places x and y to the center of the reticle
	gfx.PutPixel(x - 5, y, r, g, b);
	gfx.PutPixel(x - 4, y, r, g, b);
	gfx.PutPixel(x - 3, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);
	gfx.PutPixel(x + 5, y, r, g, b);
	gfx.PutPixel(x, y - 5, r, g, b);
	gfx.PutPixel(x, y - 4, r, g, b);
	gfx.PutPixel(x, y - 3, r, g, b);
	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x, y + 5, r, g, b);
}

void Game::DrawBox(int x, int y, int r, int g, int b)
{
	// top
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 6, y, r, g, b);
	gfx.PutPixel(x + 7, y, r, g, b);
	gfx.PutPixel(x + 8, y, r, g, b);

	// right
	gfx.PutPixel(x + 8, y, r, g, b);
	gfx.PutPixel(x + 8, y + 1, r, g, b);
	gfx.PutPixel(x + 8, y + 2, r, g, b);
	gfx.PutPixel(x + 8, y + 6, r, g, b);
	gfx.PutPixel(x + 8, y + 7, r, g, b);
	gfx.PutPixel(x + 8, y + 8, r, g, b);

	// bottom
	gfx.PutPixel(x, y + 8, r, g, b);
	gfx.PutPixel(x + 1, y + 8, r, g, b);
	gfx.PutPixel(x + 2, y + 8, r, g, b);
	gfx.PutPixel(x + 6, y + 8, r, g, b);
	gfx.PutPixel(x + 7, y + 8, r, g, b);
	gfx.PutPixel(x + 8, y + 8, r, g, b);

	// left
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x, y + 6, r, g, b);
	gfx.PutPixel(x, y + 7, r, g, b);
	gfx.PutPixel(x, y + 8, r, g, b);

}

void Game::ComposeFrame()
{
    if (x > 100 && x < 200) {
        DrawCrosshair(x, y, 255, 255, 255);
    }
    else {
        DrawBox(x, y, 255, 255, 255);
    }
    
}

/**
* Video 1 stuff
* So the very first thing that we learn is that we have the power to control the pixels on the screen with PutPixel.
* PutPixel is a method from the gfx class. We included the "Graphics.h" at the top that gives us the ability to use it.
* The parameters are the x and y coordinates and the last 3 params are the rbg values that we get the color.
* Easiest and most common way we will see PutPixels will be using variables x and y with operations to move.
* (This will be greatly improved in the future)
*/

/**
* Video 2 stuff
* See those x and y variables that are in the ComposeFrame? yeah thats what is preventing the movement to be smooth.
* Its the scope of the variables of x and y!
* Oh SHIT, this is the easiest shit! NOTE: 100 pixels per second is way to much, moved down to 2 pixels per second.
* This is what animation is all about!
*/

/**
* VIdeo 3 stuff
* This conditional will be checking for if the shift key is being pressed or not, this is to determine shape
* The shape of the radical is more important than the color that the radical is
* so if shift is being pressed we will draw the box, if shift is not being pressed than the crosshair will be the shape of the radical
* this is the default shape.
*
* My initial solution:
* Inside the shape then we have a nested conditional to check whether or not the control key is being pressed
* this is to determine the color of the radical.
* 
* if (wnd.kbd.KeyIsPressed(VK_CONTROL)) {
*   DrawBox(x, y, 255, gb, gb);
* }
* else {
*   DrawBox(x, y, 255, 0, 0);
* }
* 
* if (wnd.kbd.KeyIsPressed(VK_CONTROL)) {
*   DrawCrosshair(x, y, 255, gb, gb);
* }
* else {
*   DrawCrosshair(x, y, 255, 0, 0);
* }
*
* Chilis solution:
* Since gb has an already declared value, and this is the value that we want to change when the control key is getting pressed
* simply change the value of gb, this is a MUCH better solution as you can see.
*/

/**
* Video 4 stuff
* This shit goes inside the Game.h to become a member variable and not a instance variable.
* int x = 400;
* int y = 300;
* made some functions that use the keyboard output and change the drawn images
* The hope is to start drawing different images.
* 
* The game logic is anything that is not drawing anything to the screen.
* This stuff goes in the UpdateModel function.
* This is the spot where the game logic goes!
* The logic is in update, the drawing code is in ComposeFrame!
* Like MVC. The way everything should be done!
*/