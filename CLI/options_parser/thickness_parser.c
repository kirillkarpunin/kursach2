#include "options_parser.h"

void thickness_parser(char* str, int* p_thickness){
    char* end = "\0";

    int thickness = (int)strtol(str, &end, 10);
    if (thickness < 0 || thickness == 0 && strcmp(str, "0") != 0 || strcmp(end, "\0") != 0){
        return;
    }

    *p_thickness = thickness;
}

