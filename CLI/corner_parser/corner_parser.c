#include "corner_parser.h"

int corner_parser(int argc, char** argv){

    char* short_ops = "A:B:a:o:n:";
    struct option long_ops[] = {
            {"point1", required_argument, 0, 'A'},
            {"point2", required_argument, 0, 'B'},
            {"angle", required_argument, 0, 'a'},
            {"new_file", required_argument, 0, 'n'},
            {"origin_file", required_argument, 0, 'o'},
            {0, 0, 0, 0}
    };

    opterr = 0;

    Corner_args args;
    args.new_path = NULL;

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

            case 'a': {
                int angle;
                if (angle_parser(optarg, &angle) != 0){
                    error_message(INVALID_ANGLE);
                    return 1;
                }
                args.angle = angle;
                arg_sum |= (1 << 2);
                break;
            }

            case 'n':
                args.new_path = optarg;
                break;

            case 'o':
                args.path = optarg;
                arg_sum |= (1 << 3);
                break;

            case '?':
                if (strchr("ABano", optopt) != NULL){
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

    if (arg_sum != CORNER_REQ_ARG_SUM){
        error_message(INVALID_INPUT_NOT_ENOUGH);
        return 1;
    }

    int code = corner(args.start, args.end, args.angle, args.path, args.new_path);
    if (code != 0) {
        error_message(code);
        return 1;
    }
    return 0;
}