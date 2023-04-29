#include "rectangle.h"

int rectangle(Rect_args* rect_args){

    Image* image = scan_image(rect_args->path);
    if (image == NULL) {
        return UNABLE_TO_OPEN_FILE;
    }

    if (rect_args->thickness != 0)
    {
        validate_coord(0, &(rect_args->start->x), image->width-1);
        validate_coord(0, &(rect_args->start->y), image->height-1);
        validate_coord(0, &(rect_args->end->x), image->width-1);
        validate_coord(0, &(rect_args->end->y), image->height-1);

        if (rect_args->start->x > rect_args->end->x) swap_coords(&(rect_args->start->x), &(rect_args->end->x));
        if (rect_args->start->y > rect_args->end->y) swap_coords(&(rect_args->start->y), &(rect_args->end->y));

        recursive_draw(image, rect_args->start, rect_args->end, rect_args->color, rect_args->thickness);

        if (rect_args->fill_color && (rect_args->end->x) - (rect_args->start->x) - 2*(rect_args->thickness-1) > 1 &&
            (rect_args->end->y) - (rect_args->start->y) - 2*(rect_args->thickness-1) > 1){
            (rect_args->start->x)++;
            (rect_args->start->y)++;
            (rect_args->end->x)--;
            (rect_args->end->y)--;
            recursive_draw(image, rect_args->start, rect_args->end, rect_args->fill_color, -1);
        }
    }


    int code = print_image(image, rect_args->path, rect_args->new_path);

    destroy_struct(rect_args->start);
    destroy_struct(rect_args->end);
    destroy_struct(rect_args->color);
    if (rect_args->fill_color)destroy_struct(rect_args->fill_color);
    destroy_struct(rect_args);

    destroy_image(image);

    if (code != 0) return code;
    return 0;
}

void recursive_draw(Image* image, Coords* start, Coords* end, Color* color, int thickness){
    for (int i = start->y; i <= end->y; i++){
        if (i == start->y || i == end->y)
        {
            for (int j = start->x; j <= end->x; j++){
                image->matrix[i][j] = (RGB){color->b, color->g, color->r};
            }
        }

        else
        {
            image->matrix[i][start->x] = (RGB){color->b, color->g, color->r};
            image->matrix[i][end->x] = (RGB){color->b, color->g, color->r};
        }
    }
    thickness--;
    if (thickness && end->x-start->x > 1 && end->y-start->y > 1){
        (start->x)++;
        (start->y)++;
        (end->x)--;
        (end->y)--;
        recursive_draw(image, start, end, color, thickness);
    }
}