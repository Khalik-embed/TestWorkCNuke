#include <stdio.h>

#include "file_handlings.h"
#include "mem_handlings.h"
#include "error_handlings.h"

#define COUNT_OF_VARIABLES_IN_ONE_LINE 2

status_t read_points_from_file(const char *filename) {
    status_t status = OK;
    FILE *file = fopen(filename, "r");
    points_pool_t points_pool;

    if (get_mem_for_points_pool(&points_pool) == ERROR) {
        fclose(file);
        status = ERROR;
        return status;
    }

    int x, y;
    int scan_result = fscanf(file, "%d,%d", &x, &y);

    while (scan_result == COUNT_OF_VARIABLES_IN_ONE_LINE ) {
        if (write_to_point_pool(x, y) == ERROR) {
            fclose(file);
            status = ERROR;
            return status;
        }
        scan_result = fscanf(file, "%d,%d", &x, &y);
    }

    if ((scan_result != EOF) && (scan_result != COUNT_OF_VARIABLES_IN_ONE_LINE)) {
        handle_error("Error: File has uncorrect data");
        fclose(file);
        status = ERROR;
        return status;
    }
    if (get_amount_of_points() == 0) {
        handle_error("Error: File is empty");
        fclose(file);
        status = ERROR;
        return status;
    }
    fclose(file);
    return status;
}