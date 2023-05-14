#include "options_parser.h"

int color_parser(char* str, Color* p_color){

    if (count_sep(str) != 2) return 1;

    char* end_r = "\0";
    char* end_g = "\0";
    char* end_b = "\0";

    char* str_r = strtok(str, ",");
    char* str_g = strtok(NULL, ",");
    char* str_b = strtok(NULL, ",");
    char* str_end = strtok(NULL, "");

    if (str_r != NULL && str_g != NULL && str_b != NULL && str_end == NULL){
        int r = (int)strtol(str_r, &end_r, 10);
        int g = (int)strtol(str_g, &end_g, 10);
        int b = (int)strtol(str_b, &end_b, 10);

        if (strcmp(end_r, "\0") == 0 && strcmp(end_g, "\0") == 0 && strcmp(end_b, "\0") == 0){
            if (0 <= r && r <= 255 && 0 <= g && g <= 255 && 0 <= b && b <= 255){
                *p_color = (Color){r, g, b};
                return 0;
            }
            return 1;
        }
        return 1;
    }
    return 1;
}
