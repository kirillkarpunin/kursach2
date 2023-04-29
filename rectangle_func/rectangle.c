#include "rectangle.h"

int rectangle(Coords start, Coords end, Color color, int thickness, int is_filled, Color fill_color, char* path, char* new_path){

    Image* image = scan_image(path);
    if (image == NULL) {
        return UNABLE_TO_OPEN_FILE;
    }

    if (thickness != 0)
    {
        validate_coord(0, &(start.x), image->width-1);
        validate_coord(0, &(start.y), image->height-1);
        validate_coord(0, &(end.x), image->width-1);
        validate_coord(0, &(end.y), image->height-1);

        if (start.x > end.x) swap(&(start.x), &(end.x));
        if (start.y > end.y) swap(&(start.y), &(end.y));

        recursive_draw(image, start, end, color, thickness);

        if (is_filled && end.x - start.x - 2*(thickness-1) > 1 && end.y - start.y - 2*(thickness-1) > 1){
            start.x += thickness;
            start.y += thickness;
            end.x -= thickness;
            end.y -= thickness;
            recursive_draw(image, start, end, fill_color, -1);
        }
    }


    int code = print_image(image, path, new_path);

    destroy_image(image);

    if (code != 0) return code;
    return 0;
}

void recursive_draw(Image* image, Coords start, Coords end, Color color, int thickness){
    for (int i = start.y; i <= end.y; i++){
        if (i == start.y || i == end.y)
        {
            for (int j = start.x; j <= end.x; j++){
                image->matrix[i][j] = (RGB){color.b, color.g, color.r};
            }
        }

        else
        {
            image->matrix[i][start.x] = (RGB){color.b, color.g, color.r};
            image->matrix[i][end.x] = (RGB){color.b, color.g, color.r};
        }
    }
    thickness--;
    if (thickness && end.x-start.x > 1 && end.y-start.y > 1){
        start.x++;
        start.y++;
        end.x--;
        end.y--;
        recursive_draw(image, start, end, color, thickness);
    }
}