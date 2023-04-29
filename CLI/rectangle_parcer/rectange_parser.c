#include "rectangle_parcer.h"

int rectangle_parser(int argc, char** argv){

    char* short_ops = "a:b:c:t:f:n:o:";
    struct option long_ops[] = {
            {"point1", required_argument, 0, 'a'},
            {"point2", required_argument, 0, 'b'},
            {"thickness", required_argument, 0, 't'},
            {"color", required_argument, 0, 'c'},
            {"fill_color", required_argument, 0, 'f'},
            {"new_file", required_argument, 0, 'n'},
            {"origin_file", required_argument, 0, 'o'},
            {0, 0, 0, 0}
    };

    opterr = 0;

    Rect_args* rect_args = (Rect_args*)create_struct(RECT_ARGS);
    *rect_args = (Rect_args){NULL, NULL, -1, NULL, NULL, NULL, NULL};

    int opt;
    int command_index = 0;
    while ( (opt = getopt_long(argc, argv, short_ops, long_ops, &command_index)) != -1) {
        switch (opt) {
            case 'a':
                coords_parser(optarg, &(rect_args->start));
                if (rect_args->start == NULL){
                    error_message(INVALID_COORDS);
                    return 1;
                }
                break;

            case 'b':
                coords_parser(optarg, &(rect_args->end));
                if (rect_args->end == NULL){
                    error_message(INVALID_COORDS);
                    return 1;
                }
                break;

            case 't':
                thickness_parser(optarg, &(rect_args->thickness));
                if (rect_args->thickness == -1){
                    error_message(INVALID_THICKNESS);
                    return 1;
                }
                break;

            case 'c':
                color_parser(optarg, &(rect_args->color));
                if (rect_args->color == NULL){
                    error_message(INVALID_COLOR);
                    return 1;
                }
                break;

            case 'f':
                color_parser(optarg, &(rect_args->fill_color));
                if (rect_args->fill_color == NULL){
                    error_message(INVALID_COLOR);
                    return 1;
                }
                break;

            case 'n':
                rect_args->new_path = optarg;
                break;

            case 'o':
                rect_args->path = optarg;
                break;

            case '?':
                if (strchr("abctfno", optopt) != NULL){
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

    if (rect_args->start == NULL || rect_args->end == NULL || rect_args->color == NULL || rect_args->path == NULL || rect_args->thickness == -1){
        error_message(INVALID_INPUT_NOT_ENOUGH);
        return 1;
    }

    int code = rectangle(rect_args);
    if (code != 0) {
        error_message(code);
    }
    return 0;
}
