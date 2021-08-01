#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdbool.h>
#include "point.h"

void draw_circle(SDL_Renderer* renderer, int32_t pos_x, int32_t pos_y, int32_t radius);

#endif // GRAPHICS_H