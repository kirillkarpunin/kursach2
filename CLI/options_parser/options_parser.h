#pragma once

#include "../structs/CLI_structs.h"
#include "stdlib.h"

void coords_parser(char* str, Coords** p_coords);

void color_parser(char* str, Color** p_color);

void thickness_parser(char* str, int* p_thickness);

void angle_parser(char* str, int* p_angle);