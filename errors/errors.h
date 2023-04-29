#pragma once

#include "stdio.h"

#define UNABLE_TO_OPEN_FILE 1
#define UNABLE_TO_CREATE_NEW_FILE 2
#define UNKNOWN_COMMAND 3

#define INVALID_INPUT_REQ_ARG 4
#define INVALID_INPUT_UNK_OPT 5
#define INVALID_COORDS 6
#define INVALID_COLOR 7
#define INVALID_THICKNESS 8
#define INVALID_ANGLE 9
#define INVALID_INPUT_NOT_ENOUGH 10

#define MEMORY 11

void error_message(int code);
