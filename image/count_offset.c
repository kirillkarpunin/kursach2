#include "image.h"

unsigned int count_offset(int width){
    int rem = width * sizeof(RGB) % 4;
    int offset = rem ? 4 - rem : 0;
    return offset;
}