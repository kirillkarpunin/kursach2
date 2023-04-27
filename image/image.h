#pragma once

#include "image_structs.h"
#include "stdio.h"
#include "stdlib.h"
#include "../errors/errors.h"

Image* scan_image(char* file_name);

int print_image(Image* image, char* old_file_name, char* new_file_name);

void destroy_image(Image* image);

unsigned int count_offset(int width);