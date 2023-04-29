#include "options_parser.h"

int coords_parser(char* str, Coords* p_coords){

    char* end_x = "\0";
    char* end_y = "\0";

    char* str_x = strtok(str, ",");
    char* str_y = strtok(NULL, ",");
    char* str_end = strtok(NULL, "");

    if (str_x != NULL && str_y != NULL && str_end == NULL){
        int x = (int)strtol(str_x, &end_x, 10);
        int y = (int)strtol(str_y, &end_y, 10);

        if (strcmp(end_x, "\0") == 0 && strcmp(end_y, "\0") == 0){
            *p_coords = (Coords){x,y};
            return 0;
        }
        return 1;
    }
    return 1;
}
