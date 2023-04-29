#include "../image/image.h"
#include "../CLI/CLI.h"
#include "../geometry/geometry.h"

int rectangle(Rect_args* rect_args);

void recursive_draw(Image* image, Coords* start, Coords* end, Color* color, int thickness);