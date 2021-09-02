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
#include "Box.h"
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
    // random_device -> random number generator -> uniform_int_distribution for x and y values with ranges.
    std::random_device rd; // seed with a different value each time
    std::mt19937 rng( rd() ); // random number generator
    std::uniform_int_distribution<int> xDist(0, 770); // the random x values between 0 and 770 (account for width w/o going off screen)
    std::uniform_int_distribution<int> yDist(0, 570); // the random y values between 0 and 570 (account for the height w/o going off screen)

    // setting the random positions
    box0.x = xDist(rng);
    box0.y = yDist(rng);
    box1.x = xDist(rng);
    box1.y = yDist(rng);
    box2.x = xDist(rng);
    box2.y = yDist(rng);

    // setting the initial velocities for the boxes
    // right-down
    box0.vx = 1;
    box0.vy = 1;
    // left-down
    box1.vx = -1;
    box1.vy = 1;
    // left-up
    box2.vx = -1;
    box2.vy = -1;

    // myBox is the one that I control the movement of
    myBox.x = 400;
    myBox.y = 300;
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
*/
void Game::UpdateModel()
{
    

    if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
        myBox.x = myBox.x + 2;
    }
    
    if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
       myBox.x = myBox.x - 2;
    }
    
    if (wnd.kbd.KeyIsPressed(VK_UP)) {
        myBox.y = myBox.y - 2;
    }
   
    if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
        myBox.y = myBox.y + 2;
    }

    // these will bound the reticle inside the bounds of the screen
    //myBox.x = ClampScreenX(myBox.x, myBox.width);
    //myBox.y = ClampScreenY(myBox.y, myBox.height);
    myBox.ClampToScreen();

    box0.x += box0.vx;
    box0.y += box0.vy;
    box1.x += box1.vx;
    box1.y += box1.vy;
    box2.x += box2.vx;
    box2.y += box2.vy;

    // stub
    {
        const int box0Xold = box0.x;
        const int box0Yold = box0.y;

        box0.x = ClampScreenX(box0.x, box0.width);
        if (box0.x != box0Xold) {
            box0.vx = -box0.vx;
        }

        box0.y = ClampScreenY(box0.y, box0.height);
        if (box0.y != box0Yold) {
            box0.vy = -box0.vy;
        }
    }
    // stub
    {
        const int box1Xold = box1.x;
        const int box1Yold = box1.y;

        box1.x = ClampScreenX(box1.x, box1.width);
        if (box1.x != box1Xold) {
            box1.vx = -box1.vx;
        }

        box1.y = ClampScreenY(box1.y, box1.height);
        if (box1.y != box1Yold) {
            box1.vy = -box1.vy;
        }
    }
    // stub
    {
        const int box2Xold = box2.x;
        const int box2Yold = box2.y;

        box2.x = ClampScreenX(box2.x, box2.width);
        if (box2.x != box2Xold) {
            box2.vx = -box2.vx;
        }

        box2.y = ClampScreenY(box2.y, box2.height);
        if (box2.y != box2Yold) {
            box2.vy = -box2.vy;
        }
    }

    if (IsColliding(myBox.x, myBox.y, myBox.width, myBox.height, box0.x, box0.y, box0.width, box0.height)) {
        isEaten = true;
    }
    if (IsColliding(myBox.x, myBox.y, myBox.width, myBox.height, box1.x, box1.y, box1.width, box1.height)) {
        isEaten = true;
    }
    if (IsColliding(myBox.x, myBox.y, myBox.width, myBox.height, box2.x, box2.y, box2.width, box2.height)) {
        isEaten = true;
    }
}

bool Game::IsColliding(int x0, int y0, int width0, int height0, int x1, int y1, int width1, int height1)
{
    const int right0 = x0 + width0;
    const int bottom0 = y0 + height0;
    const int right1 = x1 + width1;
    const int bottom1 = y1 + height1;

    return right0 >= x1 && 
        x0 <= right1 &&
        bottom0 >= y1 &&
        y0 <= bottom1;
}

int Game::ClampScreenX(int x, int width) {
    const int right = x + width;
    if (x < 0) {
        return 0;
    }
    else if (right >= gfx.ScreenWidth) {
        return (gfx.ScreenWidth - 1) - width;
    }
    return x;
    
}

int Game::ClampScreenY(int y, int height) {
    const int bottom = y + height;
    if (y < 0) {
        return 0;
    }
    else if (bottom >= gfx.ScreenHeight) {
        return (gfx.ScreenHeight - 1) - height;
    }
    return y;
}

void Game::ComposeFrame()
{
    

    if (isEaten) {
    }
    else {
        box0.DrawBox(gfx);
        box1.DrawBox(gfx);
        box2.DrawBox(gfx);
    }
    myBox.DrawBox(gfx);
    
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

/* moving with constant speed and increasing per key press
* you just have to do this with all the VK_LEFT, RIGHT, UP, DOWN
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
*/

// without this shit dont move!
// x = x + vx;
// y = y + vy;

/*
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