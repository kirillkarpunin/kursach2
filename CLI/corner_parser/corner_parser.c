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
    Corner_args* corner_args = create_struct(CORNER_ARGS);
    if (corner_args == NULL) {
        error_message(MEMORY);
        return 1;
    }
    *corner_args = (Corner_args){NULL, NULL, -1, NULL, NULL};

    int opt;
    int option_index = 0;
    while ( (opt = getopt_long(argc, argv, short_ops, long_ops, &option_index)) != -1) {
        switch (opt) {
            case 'A':
                coords_parser(optarg, &(corner_args->start));
                if (corner_args->start == NULL){
                    error_message(INVALID_COORDS);
                    return 1;
                }
                break;

            case 'B':
                coords_parser(optarg, &(corner_args->end));
                if (corner_args->end == NULL){
                    error_message(INVALID_COORDS);
                    return 1;
                }
                break;

            case 'a':
                angle_parser(optarg, &(corner_args->angle));
                if (corner_args->angle == -1){
                    error_message(INVALID_ANGLE);
                    return 1;
                }
                break;

            case 'n':
                corner_args->new_path = optarg;
                break;

            case 'o':
                corner_args->path = optarg;
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

    if (corner_args->start == NULL || corner_args->end == NULL || corner_args->path == NULL || corner_args->angle == -1){
        error_message(INVALID_INPUT_NOT_ENOUGH);
        return 1;
    }

    int code = corner(corner_args);
    if (code != 0) {
        error_message(code);
        return 1;
    }
    return 0;
}