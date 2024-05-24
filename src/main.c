
#include <stdlib.h>

#include "input_cheking.h"
#include "custom_types.h"
#include "mem_handlings.h"
#include "file_handlings.h"
#include "search_point.h"

int main(int argc, char *argv[]) {
    status_t status = OK;
    status = check_arguments(argc, argv);
    if (status == OK)
        status = allocate_mem_for_points();
    if (status == OK)
        status = read_points_from_file(argv[1]);
    search_point_t best_point;
    if (status == OK)
        status = find_most_dense_point(&best_point, atoi(argv[2]));

    printf("%d, %d, %d", best_point.point.x, best_point.point.y, best_point.count + 1);

    free_point_pool();

    if (status == OK)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}
