#include <stdio.h>
#include <stdlib.h>

#include "error_handlings.h"

void handle_error(const char *message) {
    fprintf(stderr, "%s\n", message);
}