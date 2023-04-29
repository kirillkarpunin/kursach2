#pragma once

#include "getopt.h"
#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

#include "structs/CLI_structs.h"
#include "options_parcer/options_parcer.h"
#include "rectangle_parcer/rectangle_parcer.h"

#include "../errors/errors.h"

int function_parser(int argc, char** argv);


