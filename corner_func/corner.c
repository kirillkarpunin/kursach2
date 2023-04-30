#include "corner.h"

int corner(Coords start, Coords end, int angle, char* path, char* new_path){
    Image* image = scan_image(path);
    if (image == NULL) {
        return UNABLE_TO_OPEN_FILE;
    }

    Image* copy = create_canvas(image->width, image->height);
    copy_canvas(image, copy);


    if (angle != 0) {
        validate_coord(0, &(start.x), (int)image->width-1);
        validate_coord(0, &(start.y), (int)image->height-1);
        validate_coord(0, &(end.x), (int)image->width-1);
        validate_coord(0, &(end.y), (int)image->height-1);

        if (start.x > end.x) swap(&(start.x), &(end.x));
        if (start.y > end.y) swap(&(start.y), &(end.y));

        Coords center = {(end.x + start.x) / 2, (end.y + start.y) / 2};

        for (int y = start.y; y <= end.y; y++){
            for (int x = start.x; x <= end.x; x++){

                Coords coords = {x, y};
                Coords new_coords = {coords.x - center.x, coords.y - center.y};

                matrix_mul(&new_coords, angle);

                new_coords.x += center.x;
                new_coords.y += center.y;

                validate_coord(0, &(new_coords.x), (int)image->width-1);
                validate_coord(0, &(new_coords.y), (int)image->height-1);

                copy->matrix[new_coords.y][new_coords.x] = image->matrix[coords.y][coords.x];
            }
        }
    }

    int code = print_image(copy, path, new_path);

    destroy_canvas(image);
    destroy_canvas(copy);

    if (code != 0) return code;
    return 0;
}
