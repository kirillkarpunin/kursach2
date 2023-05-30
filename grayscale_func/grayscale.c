#include "grayscale.h"

int grayscale(char* path, char* new_path){
    Image* image = scan_image(path);
    if (image == NULL) {
        return UNABLE_TO_OPEN_FILE;
    }

    for (int y = 0; y < image->height; y++){
        for (int x = 0; x < image->width; x++){
            int gray = (int)( ((image->matrix[y][x].b)*0.11) + ((image->matrix[y][x].g)*0.59) + ((image->matrix[y][x].r)*0.30) );
            image->matrix[y][x] = (RGB){gray, gray, gray};
        }
    }

    int code = print_image(image, path, new_path);

    destroy_canvas(image);

    if (code != 0) return code;
    return 0;
}
