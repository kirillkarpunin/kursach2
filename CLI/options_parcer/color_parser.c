#include "options_parcer.h"

void color_parser(char* str, Color** p_color){
    Color* color = (Color*)malloc(sizeof(Color));
    if (color == NULL) return;

    char* end = "\0";

    str = strtok(str, " \t,");
    if (str == NULL) return;
    int r = (int)strtol(str, &end, 10);
    if (r < 0 || r > 255 || r == 0 && strcmp(str, "0") != 0 || strcmp(end, "\0") != 0){
        return;
    }
    color->r = r;

    str = strtok(NULL, " \t,");
    if (str == NULL) return;
    int g = (int)strtol(str, &end, 10);
    if (g < 0 || g > 255 || g == 0 && strcmp(str, "0") != 0 || strcmp(end, "\0") != 0){
        return;
    }
    color->g = g;

    str = strtok(NULL, " \t");
    if (str == NULL) return;
    int b = (int)strtol(str, &end, 10);
    if (b < 0 || b > 255 || b == 0 && strcmp(str, "0") != 0 || strcmp(end, "\0") != 0){
        return;
    }
    color->b = b;

    str = strtok(NULL, "");
    if (str != NULL) {
        return;
    }

    *p_color = color;
}
