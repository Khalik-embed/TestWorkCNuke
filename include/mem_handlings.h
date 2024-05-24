#ifndef MEM_HANDLINGS_H
#define MEM_HANDLINGS_H

#include <stdio.h>

#include "custom_types.h"

status_t allocate_mem_for_points(void);
status_t get_mem_for_points_pool(points_pool_t * points_pool);
void free_point_pool(void);

status_t write_to_point_pool(int x, int y);
status_t read_from_point_pool(int * x, int * y);

size_t get_total_size(void);
size_t get_capasity_size(void);
size_t get_amount_of_points(void);

#endif //MEM_HANDLINGS_H