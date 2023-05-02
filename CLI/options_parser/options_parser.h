#pragma once

#include "../CLI_structs.h"
#include "stdlib.h"

int coords_parser(char* str, Coords* p_coords);

int color_parser(char* str, Color* p_color);

int thickness_parser(char* str, int* p_thickness);

int angle_parser(char* str, int* p_angle);

int version_parser(char* str, int* p_version);