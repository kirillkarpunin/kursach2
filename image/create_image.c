#include "image.h"

Image* create_image(unsigned int width, unsigned int height){

    RGB** matrix = malloc(height*sizeof(RGB*));
    if (matrix == NULL) return NULL;

    for (int i = (int)height; i > 0; i--){
        matrix[i-1] = malloc(width* sizeof(RGB));
        if (matrix[i-1] == NULL) return NULL;
    }

    Image* image = malloc(sizeof(Image));
    if (image == NULL) return NULL;

    *image = (Image){width, height, matrix};
    return image;
}
