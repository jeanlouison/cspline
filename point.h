#ifndef POINT_H
#define POINT_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdbool.h>

#include "graphics.h"

#define DEFAULT_POINT_WIDTH 10

typedef struct Point {
	int32_t pos_x, pos_y;
	float width;
	bool is_visible;
	bool is_draggable;
} Point;

Point* create_point(int32_t pos_x, int32_t pos_y);
void draw_point(SDL_Renderer* renderer, Point* point);
void clean_point(Point** point);

#endif // POINT_H