#include "graphics.h"

void draw_circle(SDL_Renderer* renderer, int32_t pos_x, int32_t pos_y, int32_t radius)
{
	const int32_t diameter = (radius * 2);
	int32_t x = (radius - 1);
	int32_t y = 0;
	int32_t tx = 1;
	int32_t ty = 1;
	int32_t error = (tx - diameter);
	
	while (x >= y)
	{
		//Each of the following renders an octant of the circle
		SDL_RenderDrawPoint(renderer, pos_x + x, pos_y - y);
		SDL_RenderDrawPoint(renderer, pos_x + x, pos_y + y);
		SDL_RenderDrawPoint(renderer, pos_x - x, pos_y - y);
		SDL_RenderDrawPoint(renderer, pos_x - x, pos_y + y);
		SDL_RenderDrawPoint(renderer, pos_x + y, pos_y - x);
		SDL_RenderDrawPoint(renderer, pos_x + y, pos_y + x);
		SDL_RenderDrawPoint(renderer, pos_x - y, pos_y - x);
		SDL_RenderDrawPoint(renderer, pos_x - y, pos_y + x);
		
		if (error <= 0)
		{
			++y;
			error += ty;
			ty += 2;
		}
		
		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}