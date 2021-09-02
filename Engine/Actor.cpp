#include "Actor.h"
#include "Graphics.h"

void Actor::DrawBox(Graphics& gfx)
{
	// top
	gfx.PutPixel(x, y, 255, 255, 255);
	gfx.PutPixel(x + 1, y, 255, 255, 255);
	gfx.PutPixel(x + 2, y, 255, 255, 255);
	gfx.PutPixel(x + 5, y, 255, 255, 255);
	gfx.PutPixel(x + 6, y, 255, 255, 255);
	gfx.PutPixel(x + 7, y, 255, 255, 255);

	// right
	gfx.PutPixel(x + 7, y, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 1, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 5, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 6, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 7, 255, 255, 255);

	// bottom
	gfx.PutPixel(x, y + 7, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 7, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 7, 255, 255, 255);
	gfx.PutPixel(x + 5, y + 7, 255, 255, 255);
	gfx.PutPixel(x + 6, y + 7, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 7, 255, 255, 255);

	// left
	gfx.PutPixel(x, y, 255, 255, 255);
	gfx.PutPixel(x, y + 1, 255, 255, 255);
	gfx.PutPixel(x, y + 2, 255, 255, 255);
	gfx.PutPixel(x, y + 5, 255, 255, 255);
	gfx.PutPixel(x, y + 6, 255, 255, 255);
	gfx.PutPixel(x, y + 7, 255, 255, 255);
}

void Actor::ClampToScreen()
{
    const int right = x + width;
    if (x < 0) {
        x = 0;
    }
    else if (right >= Graphics::ScreenWidth) {
        x =  Graphics::ScreenWidth - width;
    }
    const int bottom = y + height;
    if (y < 0) {
        y = 0;
    }
    else if (bottom >= Graphics::ScreenHeight) {
        y =  Graphics::ScreenHeight - height;
    }
}
