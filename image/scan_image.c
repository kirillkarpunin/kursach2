#include "image.h"

Image* scan_image(char* file_name){
    BitmapFileHeader bmfh;
    BitmapInfoHeader bmih;

    FILE* f = fopen(file_name, "rb");
    if (f == NULL) return NULL;

    fread(&bmfh, sizeof(bmfh), 1, f);
    fread(&bmih, sizeof(bmih), 1, f);
    if (bmih.headerSize != 40 || bmih.bitsPerPixel != 24 || bmih.compression != 0)
//        return NULL;

    fseek(f, bmfh.pixelArrOffset, SEEK_SET);

    RGB** matrix = malloc(bmih.height * sizeof(RGB*));
    for (int i = bmih.height; i > 0; i--){
        matrix[i-1] = malloc(bmih.width * sizeof(RGB));
        fread(matrix[i-1], sizeof(RGB), bmih.width, f);
        fseek(f, count_offset(bmih.width), SEEK_CUR);
    }

    fclose(f);

    Image* image = malloc(sizeof(Image));
    *image = (Image){bmih.width, bmih.height, matrix};

    return image;
}