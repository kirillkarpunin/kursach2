#include "CLI_structs.h"

void* create_struct(int key){
    void* mem;
    switch (key) {
        case COORDS:
            mem = (Coords*)malloc(sizeof(Coords));
            return mem;

        case COLOR:
            mem = (Color*)malloc(sizeof(Color));
            return mem;

        case RECT_ARGS:
            mem = (Rect_args*)malloc(sizeof(Rect_args));
            return mem;

        case CORNER_ARGS:
            mem = (Corner_args*)malloc(sizeof(Corner_args));
            return mem;

        default:
            return NULL;
    }
}
