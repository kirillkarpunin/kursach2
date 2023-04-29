#include "options_parser.h"

void angle_parser(char* str, int* p_angle){
    char* end = "\0";

    int angle = (int)strtol(str, &end, 10);
    if (angle == 0 && strcmp(str, "0") != 0 || strcmp(end, "\0") != 0){
        return;
    }

    angle = angle % 360;
    if (angle < 0) angle = 360 + angle;

    if (angle != 0 && angle != 90 && angle != 180 && angle != 270){
        return;
    }

    *p_angle = angle;
}