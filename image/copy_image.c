#include "image.h"

void copy_image(Image* from, Image* to){
    for (int y = 0; y < from->height; y++){
        for (int x = 0; x < from->width; x++){
            to->matrix[y][x] = from->matrix[y][x];
        }
    }
}
