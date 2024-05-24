#ifndef CUSTOM_TYPES_H
#define CUSTOM_TYPES_H

typedef enum {
   OK,
   ERROR
} status_t;


typedef struct {
    int x;
    int y;
} point_t;

typedef struct {
    point_t * points_p;
    size_t capasity;
    size_t total_size;
} points_pool_t;

typedef struct {
    point_t point;
    int count;
} search_point_t;

#endif //#ifndef CUSTOM_TYPES_H
