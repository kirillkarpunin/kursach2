#include "errors.h"

void error_message(int code){
    switch (code) {
        case UNABLE_TO_OPEN_FILE:
            fprintf(stderr, "\nUnable to open file\n"
                            "Make sure that the path is correct\n"
                            "Requirement for an image:\n"
                            "\t- 40-byte DIB header size\n"
                            "\t- 24-bit color\n"
                            "\t- Without compression\n");
            break;

        case UNABLE_TO_CREATE_NEW_FILE:
            fprintf(stderr, "\nUnable to create new file\nMake sure that the path is correct\n");
            break;

        case UNKNOWN_COMMAND:
            fprintf(stderr, "\nInvalid input: Unknown command\nUse -h or --help to see commands\n");
            break;

        case INVALID_INPUT_REQ_ARG:
            fprintf(stderr, "\nInvalid input: Not all options has arguments\nUse -h or --help to see options\n");
            break;

        case INVALID_INPUT_UNK_OPT:
            fprintf(stderr,"\nInvalid input: Unknown option\nUse -h or --help to see options\n");
            break;

        case INVALID_COORDS:
            fprintf(stderr, "\nInvalid input: Invalid coords\nUse -h or --help to see formats\n");
            break;

        case INVALID_COLOR:
            fprintf(stderr, "\nInvalid input: Invalid colors\nUse -h or --help to see formats\n");
            break;

        case INVALID_THICKNESS:
            fprintf(stderr, "\nInvalid input: Invalid thickness\n");
            break;

        case INVALID_INPUT_NOT_ENOUGH:
            fprintf(stderr, "\nInvalid input: Not all necessary arguments given\n");
            break;

        case INVALID_ANGLE:
            fprintf(stderr, "\nInvalid input: Invalid angle\nUse -h or --help to see formats\n");
            break;

        case INVALID_VERSION:
            fprintf(stderr, "\nInvalid input: Invalid version\nUse -h or --help to see formats\n");
            break;

        default:
            fprintf(stderr, "\nUnknown error\n");
            break;
    }
}
