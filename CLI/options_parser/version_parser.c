#include "options_parser.h"

int version_parser(char* str, int* p_version){
    char* end = "\0";

    int version = (int)strtol(str, &end, 10);
    if (strcmp(end, "\0") != 0){
        return 1;
    }

    if (version < 1 || version > 3){
        return 1;
    }

    *p_version = version;
    return 0;
}
