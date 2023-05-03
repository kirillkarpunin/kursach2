#include "frame.h"

int frame(Color color, int version, int thickness, char* path, char* new_path){
    Image* image = scan_image(path);
    if (image == NULL) {
        return UNABLE_TO_OPEN_FILE;
    }

    Image* copy = create_canvas(image->width + thickness*2, image->height + thickness*2);

    switch (version) {
        case 1: {
            tartan(copy, color);
            break;
        }

        case 2: {
            triangles(copy, color);
            break;
        }

        case 3: {
            hearts(copy, color);
            break;
        }

        default:
            break;
    }

    copy_canvas(image, copy, (Coords){thickness, thickness});

    int code = print_image(copy, path, new_path);

    destroy_canvas(image);
    destroy_canvas(copy);

    if (code != 0) return code;
    return 0;
}


void tartan(Image* image, Color color_bg){

    Color color_prim = {color_bg.r, (color_bg.g + 129) % 255, color_bg.b};
    Color color_sec = {(color_bg.r + 194) % 255, color_bg.g, (color_bg.b + 135) % 255};

    for (int y = 0; y < image->height; y++){

        if (3 < y % TARTAR_SIZE && y % TARTAR_SIZE < 7 || 14 < y % TARTAR_SIZE && y % TARTAR_SIZE < 18)
        {
            for (int x = 0; x < image->width; x++)
            {
                image->matrix[y][x] = (RGB){color_prim.b, color_prim.g, color_prim.r};
            }
        }

        else if (y % TARTAR_SIZE == 10 || y % TARTAR_SIZE == 11)
        {
            for (int x = 0; x < image->width; x++)
            {
                image->matrix[y][x] = (RGB){color_sec.b, color_sec.g, color_sec.r};
            }
        }

        else
        {
            for (int x = 0; x < image->width; x++)
            {
                if (3 < x % TARTAR_SIZE && x % TARTAR_SIZE < 7 || 14 < x % TARTAR_SIZE && x % TARTAR_SIZE < 18)
                {
                    image->matrix[y][x] = (RGB){color_prim.b, color_prim.g, color_prim.r};
                }

                else if (x % TARTAR_SIZE == 10 || x % TARTAR_SIZE == 11)
                {
                    image->matrix[y][x] = (RGB){color_sec.b, color_sec.g, color_sec.r};
                }

                else
                {
                    image->matrix[y][x] = (RGB){color_bg.b, color_bg.g, color_bg.r};
                }
            }
        }
    }
}


void triangles(Image* image, Color color_prim){

    Color color_bg = {255 - color_prim.r, 255 - color_prim.g, 255 - color_prim.b};

    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {

            if (y % TRIANGLES_SIZE < x % TRIANGLES_SIZE)
            {
                image->matrix[y][x] = (RGB){color_bg.b, color_bg.g, color_bg.r};
            }
            else
            {
                image->matrix[y][x] = (RGB){color_prim.b, color_prim.g, color_prim.r};
            }

        }
    }

}


void hearts(Image* image, Color color_prim){

    Color color_bg = {255 - color_prim.r, 255 - color_prim.g, 255 - color_prim.b};

    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            int t_y = y % HEARTS_SIZE;
            int t_x = x % HEARTS_SIZE;

            if (3 < t_y && t_y < 12 && 2 < t_x && t_x < 12 && !(t_x == 7 && t_y == 4))
            {
                if (t_y <= t_x + 4 && t_y <= HEARTS_SIZE - t_x + 3 && t_y >= HEARTS_SIZE - t_x - 7 && t_y >= t_x - 6)
                {
                    image->matrix[y][x] = (RGB){color_prim.b, color_prim.g, color_prim.r};
                }
                else
                {
                    image->matrix[y][x] = (RGB){color_bg.b, color_bg.g, color_bg.r};
                }
            }
            else
            {
                image->matrix[y][x] = (RGB){color_bg.b, color_bg.g, color_bg.r};
            }
        }
    }
}