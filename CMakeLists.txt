cmake_minimum_required(VERSION 3.23)
project(cw2 C)

set(CMAKE_C_STANDARD 99)

add_executable(cw2 main.c image/scan_image.c image/image.h image/image_structs.h image/print_image.c image/count_offset.c errors/error_message.c errors/errors.h rectangle_func/rectangle.c rectangle_func/rectangle.h geometry/validate_coord.c geometry/swap_coords.c CLI/function_parser.c CLI/CLI.h CLI/rectangle_parser/rectange_parser.c CLI/options_parser/coords_parser.c CLI/structs/CLI_structs.h CLI/options_parser/color_parser.c CLI/options_parser/thickness_parser.c CLI/structs/create_struct.c CLI/structs/destroy_struct.c image/destroy_image.c geometry/geometry.h CLI/options_parser/options_parser.h CLI/rectangle_parser/rectangle_parser.h CLI/corner_parser/corner_parser.c CLI/corner_parser/corner_parser.h corner_func/corner.c corner_func/corner.h CLI/options_parser/angle_parser.c image/create_image.c)
