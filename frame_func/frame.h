#pragma once

#include "../image/image.h"
#include "../CLI/CLI_structs.h"
#include "../geometry/geometry.h"

#define TARTAR_SIZE 22
#define TRIANGLES_SIZE 15
#define HEARTS_SIZE 15

int frame(Color color, int version, int thickness, char* path, char* new_path);

void tartan(Image* image, Color color_bg);

void triangles(Image* image, Color color_prim);

void hearts(Image* image, Color color_bg);