#include "corner.h"

int corner(Corner_args* corner_args){
    Image* image = scan_image(corner_args->path);
    if (image == NULL) {
        return UNABLE_TO_OPEN_FILE;
    }

    if (corner_args->angle != 0) {
        validate_coord(0, &(corner_args->start->x), image->width - 1);
        validate_coord(0, &(corner_args->start->y), image->height - 1);
        validate_coord(0, &(corner_args->end->x), image->width - 1);
        validate_coord(0, &(corner_args->end->y), image->height - 1);

        if (corner_args->start->x > corner_args->end->x) swap_coords(&(corner_args->start->x), &(corner_args->end->x));
        if (corner_args->start->y > corner_args->end->y) swap_coords(&(corner_args->start->y), &(corner_args->end->y));

        int center_x = (corner_args->end->x + corner_args->start->x)/2;
        int center_y = (corner_args->end->y + corner_args->start->y)/2;

    }


}
