#include "rectangle_parser.h"

int rectangle_parser(int argc, char** argv){

    char* short_ops = "A:B:c:t:f:n:o:";
    struct option long_ops[] = {
            {"point1", required_argument, 0, 'A'},
            {"point2", required_argument, 0, 'B'},
            {"thickness", required_argument, 0, 't'},
            {"color", required_argument, 0, 'c'},
            {"fill_color", required_argument, 0, 'f'},
            {"new_file", required_argument, 0, 'n'},
            {"origin_file", required_argument, 0, 'o'},
            {0, 0, 0, 0}
    };

    opterr = 0;

    Rect_args args;
    args.new_path = NULL;

    int is_filled = 0;
    int arg_sum = 0;

    int opt;
    int option_index = 0;
    while ( (opt = getopt_long(argc, argv, short_ops, long_ops, &option_index)) != -1) {
        switch (opt) {

            case 'A': {
                Coords coords;
                if (coords_parser(optarg, &coords) != 0){
                    error_message(INVALID_COORDS);
                    return 1;
                }
                args.start = coords;
                arg_sum |= 1;
                break;
            }

            case 'B': {
                Coords coords;
                if (coords_parser(optarg, &coords) != 0){
                    error_message(INVALID_COORDS);
                    return 1;
                }
                args.end = coords;
                arg_sum |= (1 << 1);
                break;
            }

            case 't': {
                int thickness;
                if (thickness_parser(optarg, &thickness) != 0){
                    error_message(INVALID_THICKNESS);
                    return 1;
                }
                args.thickness = thickness;
                arg_sum |= (1 << 2);
                break;
            }

            case 'c': {
                Color color;
                if (color_parser(optarg, &color) != 0){
                    error_message(INVALID_COLOR);
                    return 1;
                }
                args.color = color;
                arg_sum |= (1 << 3);
                break;
            }

            case 'f': {
                Color color;
                if (color_parser(optarg, &color) != 0){
                    error_message(INVALID_COLOR);
                    return 1;
                }
                args.fill_color = color;
                is_filled = 1;
                break;
            }

            case 'n':
                args.new_path = optarg;
                break;

            case 'o':
                args.path = optarg;
                arg_sum |= (1 << 4);
                break;

            case '?':
                if (strchr("ABctfno", optopt) != NULL){
                    error_message(INVALID_INPUT_REQ_ARG);
                    return 1;
                } else {
                    error_message(INVALID_INPUT_UNK_OPT);
                    return 1;
                }
            default:
                break;
        }
    }

    if (arg_sum != RECT_REQ_ARG_SUM){
        error_message(INVALID_INPUT_NOT_ENOUGH);
        return 1;
    }

    int code = rectangle(args.start, args.end, args.color, args.thickness, is_filled, args.fill_color, args.path, args.new_path);
    if (code != 0) {
        error_message(code);
        return 1;
    }
    return 0;
}
