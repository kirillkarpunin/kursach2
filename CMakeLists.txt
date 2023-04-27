cmake_minimum_required(VERSION 3.23)
project(cw2 C)

set(CMAKE_C_STANDARD 99)

add_executable(cw2 main.c image/scan_image.c image/image.h image/image_structs.h image/print_image.c image/count_offset.c errors/error_message.c errors/errors.h rectange/rectangle.c rectange/rectangle.h rectange/validate_coord.c rectange/swap_coords.c CLI/function_parser.c CLI/CLI.h CLI/rectange_parser.c CLI/coords_parser.c CLI/rectangle_structs.h CLI/color_parser.c CLI/thickness_parser.c CLI/create_struct.c CLI/destroy_struct.c image/destroy_image.c)
