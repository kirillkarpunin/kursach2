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

    Image* image = create_image(bmih.width, bmih.height);
    for (int i = (int)bmih.height; i > 0; i--){
        fread(image->matrix[i-1], sizeof(RGB), bmih.width, f);
        fseek(f, count_offset((int)bmih.width), SEEK_CUR);
    }

    fclose(f);

    return image;
}