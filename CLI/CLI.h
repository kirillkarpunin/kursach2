#pragma once

#include "getopt.h"
#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

#include "CLI_structs.h"
#include "options_parser/options_parser.h"
#include "rectangle_parser/rectangle_parser.h"
#include "corner_parser/corner_parser.h"
#include "frame_parser/frame_parser.h"

#include "../messages/messages.h"

int function_parser(int argc, char** argv);


