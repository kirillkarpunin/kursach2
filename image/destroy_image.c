#include "image.h"

void destroy_canvas(Image* image){
    for (int i = image->height; i > 0; i--){
        free(image->matrix[i-1]);
    }
    free(image->matrix);
    free(image);
}
