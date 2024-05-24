
#include <stdlib.h>

#include "mem_handlings.h"
#include "error_handlings.h"

#define STEP_OF_ALLOCATE_POINTS 256

static points_pool_t points_pool_mem;


status_t allocate_mem_for_points(void){
    status_t status = OK;
    points_pool_mem.capasity = STEP_OF_ALLOCATE_POINTS;
    points_pool_mem.total_size = STEP_OF_ALLOCATE_POINTS;
    points_pool_mem.points_p = (point_t *) malloc(STEP_OF_ALLOCATE_POINTS * sizeof(point_t));
    if (points_pool_mem.points_p == NULL) {
        handle_error("Error: Unable to allocate memory.");
        status = ERROR;
    }
    return status;
}

status_t get_mem_for_points_pool(points_pool_t * points_pool){
    status_t status = OK;
    if(points_pool_mem.points_p != NULL){
        points_pool->points_p = points_pool_mem.points_p;
        points_pool->capasity = points_pool_mem.capasity;
        points_pool->total_size = points_pool_mem.total_size;
    } else {
        handle_error("Error: Unable to get memory adress.");
        status = ERROR;
        points_pool = NULL;
    }
    return status;
}

status_t reallocate_mem_for_points(void){
    status_t status = OK;
    point_t *new_points_p = (point_t *)realloc(points_pool_mem.points_p, STEP_OF_ALLOCATE_POINTS * sizeof(point_t));
    if (new_points_p == NULL){
        free(points_pool_mem.points_p);
        handle_error("Error: Unable to allocate memory.");
        status = ERROR;
    } else {
        points_pool_mem.capasity += STEP_OF_ALLOCATE_POINTS;
        points_pool_mem.total_size += STEP_OF_ALLOCATE_POINTS;
        points_pool_mem.points_p = new_points_p;
    }
    return status;
}

void free_point_pool(void) {
    if (points_pool_mem.points_p != NULL) {
        free(points_pool_mem.points_p);
    }
}

status_t write_to_point_pool(int x, int y){
    status_t status = OK;
    if (points_pool_mem.capasity == 0){
        if (reallocate_mem_for_points() ==  ERROR) {
            status = ERROR;
            return status;
        }
    }
    points_pool_mem.points_p[get_amount_of_points()].x = x;
    points_pool_mem.points_p[get_amount_of_points()].y = y;
    points_pool_mem.capasity --;
    return status;
}

status_t read_from_point_pool(int * x, int * y){
    status_t status = OK;
    if (get_amount_of_points() > 0){
        *x = points_pool_mem.points_p[get_amount_of_points()].x;
        *y = points_pool_mem.points_p[get_amount_of_points()].y;
        points_pool_mem.capasity ++;
    } else {
        handle_error("Error: Memory is empty.");
        status = ERROR;
    }
    return status;
}

size_t get_total_size(void){
    return points_pool_mem.total_size;
}

size_t get_capasity_size(void){
    return points_pool_mem.capasity;
}

size_t get_amount_of_points(void){
    return points_pool_mem.total_size - points_pool_mem.capasity;
}