#include "options_parser.h"

int thickness_parser(char* str, int* p_thickness){
    char* end = "\0";

    int thickness = (int)strtol(str, &end, 10);
    if (thickness < 0 || strcmp(end, "\0") != 0){
        return 1;
    }

    *p_thickness = thickness;
    return 0;
}

