#include "image.h"

Image* create_canvas(unsigned int width, unsigned int height){

    RGB** matrix = malloc(height*sizeof(RGB*));

    for (int i = (int)height; i > 0; i--){
        matrix[i-1] = calloc(width,sizeof(RGB));
    }

    Image* image = malloc(sizeof(Image));

    *image = (Image){width, height, matrix};
    return image;
}
