#pragma once

#include "string.h"
#include "stdlib.h"

typedef struct Coords{
    int x;
    int y;
} Coords;

typedef struct Color{
    int r;
    int g;
    int b;
} Color;

typedef struct Rect_args{
    Coords start;
    Coords end;
    int thickness;
    Color color;
    Color fill_color;
    char* path;
    char* new_path;
} Rect_args;

typedef struct Corner_args{
    Coords start;
    Coords end;
    int angle;
    char* path;
    char* new_path;
} Corner_args;