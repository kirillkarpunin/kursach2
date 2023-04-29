#pragma once

#include "string.h"
#include "stdlib.h"

#define COORDS 1
typedef struct Coords{
    int x;
    int y;
} Coords;

#define COLOR 2
typedef struct Color{
    int r;
    int g;
    int b;
} Color;

#define RECT_ARGS 3
typedef struct Rect_args{
    Coords* start;
    Coords* end;
    int thickness;
    Color* color;
    Color* fill_color;
    char* path;
    char* new_path;
} Rect_args;

#define CORNER_ARGS 4
typedef struct Corner_args{
    Coords* start;
    Coords* end;
    int angle;
    char* path;
    char* new_path;
} Corner_args;

void* create_struct(int key);

void destroy_struct(void* ptr);
