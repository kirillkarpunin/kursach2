#include "image.h"

void copy_canvas(Image* from, Image* to, Coords start){
    for (int y = 0; y < from->height; y++){
        for (int x = 0; x < from->width; x++){
            to->matrix[y+start.y][x+start.x] = from->matrix[y][x];
        }
    }
}
