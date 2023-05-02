#include "frame_parser.h"

int frame_parser(int argc, char** argv){

    char* short_ops = "c:v:t:o:n:";
    struct option long_ops[] = {
            {"thickness", required_argument, 0, 't'},
            {"color", required_argument, 0, 'c'},
            {"version", required_argument, 0, 'v'},
            {"new_file", required_argument, 0, 'n'},
            {"origin_file", required_argument, 0, 'o'},
            {0, 0, 0, 0}
    };

    opterr = 0;

    Frame_args args;
    args.new_path = NULL;

    int arg_sum = 0;

    int opt;
    int option_index = 0;
    while ( (opt = getopt_long(argc, argv, short_ops, long_ops, &option_index)) != -1) {
        switch (opt) {
            case 'v': {
                int version;
                if (version_parser(optarg, &version) != 0){
                    error_message(INVALID_VERSION);
                    return 1;
                }
                args.version = version;
                arg_sum |= 1;
                break;
            }

            case 't': {
                int thickness;
                if (thickness_parser(optarg, &thickness) != 0){
                    error_message(INVALID_THICKNESS);
                    return 1;
                }
                args.thickness = thickness;
                arg_sum |= (1 << 1);
                break;
            }
            case 'c': {
                Color color;
                if (color_parser(optarg, &color) != 0){
                    error_message(INVALID_COLOR);
                    return 1;
                }
                args.color = color;
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
                if (strchr("cvotn", optopt) != NULL){
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

    if (arg_sum != FRAME_REQ_ARG_SUM){
        error_message(INVALID_INPUT_NOT_ENOUGH);
        return 1;
    }

    int code = frame(args.color, args.version, args.thickness, args.path, args.new_path);
    if (code != 0) {
        error_message(code);
        return 1;
    }
    return 0;
}