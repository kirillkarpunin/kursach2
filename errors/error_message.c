#include "errors.h"

void error_message(int code){
    switch (code) {
        case UNABLE_TO_OPEN_FILE:
            fprintf(stderr, "Unable to open file\n"
                            "Requirement for an image:\n"
                            "\t- 40-byte DIB header size\n"
                            "\t- 24-bit color\n"
                            "\t- Without compression\n");
            break;

        case UNABLE_TO_CREATE_NEW_FILE:
            fprintf(stderr, "Unable to create new file\n");
            break;

        case UNKNOWN_COMMAND:
            fprintf(stderr, "Invalid input: Unknown command\nUse -h or --help to see commands\n");
            break;

        case INVALID_INPUT_REQ_ARG:
            fprintf(stderr, "Invalid input: Not all options has arguments\nUse -h or --help to see options\n");
            break;

        case INVALID_INPUT_UNK_OPT:
            fprintf(stderr,"Invalid input: Unknown option\nUse -h or --help to see options\n");
            break;

        case INVALID_COORDS:
            fprintf(stderr, "Invalid input: Invalid coords\nUse -h or --help to see formats\n");
            break;

        case INVALID_COLOR:
            fprintf(stderr, "Invalid input: Invalid colors\nUse -h or --help to see formats\n");
            break;

        case INVALID_THICKNESS:
            fprintf(stderr, "Invalid input: Invalid thickness\n");
            break;

        case INVALID_INPUT_NOT_ENOUGH:
            fprintf(stderr, "Invalid input: Not all necessary arguments given\n");
            break;

        case INVALID_ANGLE:
            fprintf(stderr, "Invalid input: Invalid angle\nUse -h or --help to see formats\n");
            break;

        default:
            break;
    }
}
