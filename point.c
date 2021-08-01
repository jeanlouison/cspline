#include "point.h"

/**
 * Create a point with its positions.
 * 
 * \param pos_x position X
 * \param pos_y position Y
 * \return a new point.
*/
Point* create_point(int32_t pos_x, int32_t pos_y) 
{
    Point* point = malloc(sizeof(Point));
    if (point == NULL)
        return NULL;
    point->pos_x = pos_x;
    point->pos_y = pos_y;
    point->width = DEFAULT_POINT_WIDTH;
    point->is_visible = true;
    point->is_draggable = true;
    return point;
}

/**
 * 
 *
*/
void draw_point(SDL_Renderer* renderer, Point* point)
{
	draw_circle(renderer, point->pos_x, point->pos_y, DEFAULT_POINT_WIDTH);
}


/**
 * Properly clean a point.
 * 
 * \param point * to be cleaned.
*/
void clean_point(Point** point) 
{
    free((*point));
    *point = NULL;
}