#pragma once

#include "../image/image.h"
#include "../CLI/CLI_structs.h"
#include "../geometry/geometry.h"

int rectangle(Coords start, Coords end, Color color, int thickness, int is_filled, Color fill_color, char* path, char* new_path);

void recursive_draw(Image* image, Coords start, Coords end, Color color, int thickness);