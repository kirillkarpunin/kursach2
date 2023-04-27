#include "CLI.h"

void coords_parser(char* str, Coords** p_coords){
    Coords* coords = (Coords*) create_struct(COORDS);
    if (coords == NULL) return;

    char* end = "\0";

    str = strtok(str, " \t,");
    if (str == NULL) return;
    int coord = (int)strtol(str, &end, 10);
    if (coord == 0 && strcmp(str, "0") != 0 || strcmp(end, "\0") != 0){
        return;
    }
    coords->x = coord;

    str = strtok(NULL, " \t");
    if (str == NULL) return;
    coord = (int)strtol(str, &end, 10);
    if (coord == 0 && strcmp(str, "0") != 0 || strcmp(end, "\0") != 0){
        return;
    }
    coords->y = coord;

    str = strtok(NULL, "");
    if (str != NULL){
        return;
    }

    *p_coords = coords;
}
