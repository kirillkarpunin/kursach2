#include "options_parser.h"

int count_sep(char* str){
    int ret_val = 0;
    for (int i = 0; str[i]; i++){
        if (str[i] == ',') ret_val++;
    }
    return ret_val;
}
