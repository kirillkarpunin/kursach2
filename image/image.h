#pragma once

#include "image_structs.h"
#include "stdio.h"
#include "stdlib.h"
#include "../CLI/CLI_structs.h"
#include "../messages/messages.h"

Image* create_canvas(unsigned int width, unsigned int height);

Image* scan_image(char* file_name);

void copy_canvas(Image* from, Image* to, Coords start);

int print_image(Image* image, char* old_file_name, char* new_file_name);

void destroy_canvas(Image* image);

unsigned int count_offset(int width);

int info(char* path);