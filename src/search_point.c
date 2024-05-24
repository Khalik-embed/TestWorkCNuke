#include <stdlib.h>
#include <math.h>

#include "search_point.h"
#include "custom_types.h"
#include "mem_handlings.h"

#define MAX_WIDTH 100
#define MAX_HIGHT 100

static double distance(point_t a, point_t b);

status_t find_most_dense_point(search_point_t * best_point, int radius){
    status_t status = OK;

    int num_points = get_amount_of_points();
    points_pool_t points_pool;

    status = get_mem_for_points_pool(&points_pool);
    if (status == ERROR)
        return status;

    int x_start = radius / 2;
    int y_start = radius / 2;
    int x_end = MAX_WIDTH - radius / 2;
    int y_end = MAX_HIGHT - radius / 2;

    search_point_t search_point_current;
    point_t *estimated_point;

    best_point->point.x = 0;
    best_point->point.y = 0;
    best_point->count = 0;

    for (size_t i = x_start; i < x_end; i++) {
        for (size_t j = y_start; j < y_end; j++) {

            search_point_current.point.x = i;
            search_point_current.point.y = j;
            search_point_current.count = 0;

            int rude_estimate_x_min = search_point_current.point.x  - radius;
            int rude_estimate_x_max = search_point_current.point.x + radius;
            int rude_estimate_y_min = search_point_current.point.y - radius;
            int rude_estimate_y_max = search_point_current.point.y + radius;

            for (size_t k = 0; k < num_points; k++){

                estimated_point = points_pool.points_p + k;
                if ((estimated_point->x >= rude_estimate_x_min)
                    && (estimated_point->x <= rude_estimate_x_max)
                    && (estimated_point->y >= rude_estimate_y_min)
                    && (estimated_point->y <= rude_estimate_y_max)) {

                    if (distance(*estimated_point, search_point_current.point) <= radius) {
                        search_point_current.count += 1;
                    }

                }

            }
            if (best_point->count < search_point_current.count){
                best_point->point.x = search_point_current.point.x;
                best_point->point.y = search_point_current.point.y;
                best_point->count = search_point_current.count;
            }
        }
    }
    return status;
}

static double distance(point_t a, point_t b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}