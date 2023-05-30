#include "grayscale_parser.h"

int grayscale_parser(int argc, char** argv){
    char* short_ops = "o:n:";
    struct option long_ops[] = {
            {"new_file", required_argument, 0, 'n'},
            {"origin_file", required_argument, 0, 'o'},
            {0, 0, 0, 0}
    };

    opterr = 0;

    Gray_args args;
    args.new_path = NULL;

    int arg_sum = 0;

    int opt;
    int option_index = 0;
    while ( (opt = getopt_long(argc, argv, short_ops, long_ops, &option_index)) != -1) {
        switch (opt) {
            case 'n':
                args.new_path = optarg;
                break;

            case 'o':
                args.path = optarg;
                arg_sum |= 1;
                break;

            case '?':
                if (strchr("on", optopt) != NULL){
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

    if (arg_sum != GRAY_REQ_ARG_SUM){
        error_message(INVALID_INPUT_NOT_ENOUGH);
        return 1;
    }

    int code = grayscale(args.path, args.new_path);
    if (code != 0) {
        error_message(code);
        return 1;
    }
    return 0;
}
