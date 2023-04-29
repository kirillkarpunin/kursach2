cmake_minimum_required(VERSION 3.23)
project(cw2 C)

set(CMAKE_C_STANDARD 99)

add_executable(cw2 main.c image/scan_image.c image/image.h image/image_structs.h image/print_image.c image/count_offset.c errors/error_message.c errors/errors.h rectangle_func/rectangle.c rectangle_func/rectangle.h geometry/validate_coord.c geometry/swap_coords.c CLI/function_parser.c CLI/CLI.h CLI/rectangle_parcer/rectange_parser.c CLI/options_parcer/coords_parser.c CLI/structs/CLI_structs.h CLI/options_parcer/color_parser.c CLI/options_parcer/thickness_parser.c CLI/structs/create_struct.c CLI/structs/destroy_struct.c image/destroy_image.c geometry/geometry.h CLI/options_parcer/options_parcer.h CLI/rectangle_parcer/rectangle_parcer.h)
