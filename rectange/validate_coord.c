#include "rectangle.h"

void validate_coord(int down_border, int* coord, int up_border){
    if (*coord < down_border){
        *coord = down_border;
        return;
    }

    if (*coord > up_border){
        *coord = up_border;
        return;
    }
}
