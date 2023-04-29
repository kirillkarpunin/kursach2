#include "image.h"

int print_image(Image* image, char* old_file_name, char* new_file_name){
    FILE* f = fopen(old_file_name, "rb");
    if (f == NULL) {
        return UNABLE_TO_OPEN_FILE;
    }

    BitmapFileHeader bmfh;
    BitmapInfoHeader bmih;

    fread(&bmfh, sizeof(bmfh), 1, f);
    fread(&bmih, sizeof(bmih), 1, f);

    fclose(f);

    FILE* fout;
    if (new_file_name) fout = fopen(new_file_name, "wb");
    else fout= fopen(old_file_name, "wb");

    if (fout == NULL) {
        return UNABLE_TO_CREATE_NEW_FILE;
    }

    fwrite(&bmfh, sizeof(bmfh), 1, fout);
    fwrite(&bmih, sizeof(bmih), 1, fout);

    fseek(fout, bmfh.pixelArrOffset, SEEK_SET);

    char* garbage = calloc(count_offset(bmih.width), sizeof(char));
    for (int i = bmih.height; i > 0; i--){
        fwrite(image->matrix[i-1], sizeof(RGB), bmih.width, fout);
        fwrite(garbage, count_offset(bmih.width), sizeof(char), fout);
    }

    fclose(fout);
    free(garbage);
    return 0;
}