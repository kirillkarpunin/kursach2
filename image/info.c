#include "../messages/messages.h"

int info(char* path){
    BitmapFileHeader bmfh;
    BitmapInfoHeader bmih;

    FILE* f = fopen(path, "rb");
    if (f == NULL) {
        error_message(UNABLE_TO_OPEN_FILE);
        return 1;
    }

    fread(&bmfh, sizeof(bmfh), 1, f);
    fread(&bmih, sizeof(bmih), 1, f);

    fclose(f);

    info_message(bmfh, bmih);

    return 0;
}
