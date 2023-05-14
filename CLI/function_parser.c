#include "CLI.h"

int function_parser(int argc, char** argv){

    if (argc == 1){
        help_message();
        return 0;
    }

    char* short_ops = "hrfc";
    static struct option long_ops[] = {
            {"help", no_argument, 0, 'h'},
            {"rectangle", no_argument, 0, 'r'},
            {"frame", no_argument, 0, 'f'},
            {"corner", no_argument, 0, 'c'},
            {0, 0, 0, 0}
    };

    opterr = 0;

    int option_index = 0;
    int opt = getopt_long(argc, argv, short_ops, long_ops, &option_index);

    switch (opt) {
        case 'h':
            help_message();
            return 0;
        case 'r':
            return rectangle_parser(argc, argv);
        case 'f':
            return frame_parser(argc, argv);
        case 'c':
            return corner_parser(argc, argv);
        default:
            error_message(UNKNOWN_COMMAND);
            return 1;
    }
}
