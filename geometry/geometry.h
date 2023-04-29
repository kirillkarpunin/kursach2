#pragma once

#include "../CLI/CLI_structs.h"

void validate_coord(int down_border, int* coord, int up_border);

void swap(int* a, int* b);

void matrix_mul(Coords* p_coords, int angle);
