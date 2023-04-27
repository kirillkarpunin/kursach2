#pragma once

#include "getopt.h"
#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "rectangle_structs.h"
#include "../errors/errors.h"
#include "../rectange/rectangle.h"

int function_parser(int argc, char** argv);

int rectangle_parser(int argc, char** argv);

void coords_parser(char* str, Coords** p_coords);

void color_parser(char* str, Color** p_color);

void thickness_parser(char* str, int* p_thickness);
