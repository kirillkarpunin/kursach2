#include "../image/image.h"
#include "../CLI/CLI.h"

int rectangle(Rect_args* rect_args);

void recursive_draw(Image* image, Coords* start, Coords* end, Color* color, int thickness);

void validate_coord(int down_border, int* coord, int up_border);

void swap_coords(int* a, int* b);