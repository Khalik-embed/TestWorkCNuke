
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "input_cheking.h"
#include "error_handlings.h"

#define NUMBER_OF_ARGUMENTS 2
#define FILE_EXTENSION ".txt"

static status_t check_number_arguments(int argc);
static status_t check_extention_file(char * file_name);
static status_t check_open_file(char * file_name);
static status_t check_integer(char * string_number);

status_t check_arguments (int argc, char *argv[]) {
    status_t status = OK;
    if (check_number_arguments(argc) == ERROR) {
        return ERROR;
    }
    if (check_extention_file(argv[1]) == ERROR) {
        return ERROR;
    }
    if (check_open_file(argv[1]) == ERROR) {
        return ERROR;
    }
    if (check_integer(argv[2]) == ERROR) {
        return ERROR;
    }
    return status;
}

static status_t check_number_arguments(int argc) {
    status_t status = OK;
    if (argc != NUMBER_OF_ARGUMENTS + 1) {
        handle_error("Usage: <program> <file name> <radius>\n");
        status = ERROR;
    }
    return status;
}

static status_t check_extention_file(char * file_name) {
    status_t status = OK;
    int file_name_len = strlen(file_name);
    char *extension = FILE_EXTENSION;
    if ((file_name_len < strlen(FILE_EXTENSION))
        || (strcmp(file_name + file_name_len - 4, extension) != 0)) {
        handle_error("File name must have extension .txt\n");
        status = ERROR;
    }
    return status;
}

static status_t check_open_file(char * file_name) {
    status_t status = OK;
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        handle_error("File can't be opened\n");
        status = ERROR;
    }
    fclose(file);
    return status;
}

static status_t check_integer(char * string_number) {
    status_t status = OK;
    if (atoi(string_number) == 0) {
        handle_error("Radius must be integer and more than 0\n");
        status = ERROR;
    }
    return status;
}