#include "messages.h"

void info_message(BitmapFileHeader bmfh, BitmapInfoHeader bmih){

    printf("\n");

    printf("signature: %x (%hu)\n", bmfh.signature, bmfh.signature);
    printf("file size: %x (%u)\n", bmfh.filesize, bmfh.filesize);
    printf("reserved1: %hu\n", bmfh.reserved1);
    printf("reserved2: %hu\n", bmfh.reserved2);
    printf("offset_to_pixels: %x (%u)\n", bmfh.pixelArrOffset, bmfh.pixelArrOffset);

    printf("dib header size: %x (%u)\n", bmih.headerSize, bmih.headerSize);
    printf("image width: %x (%u)\n", bmih.width, bmih.width);
    printf("image height: %x (%u)\n", bmih.height, bmih.height);
    printf("planes: %x (%hu)\n", bmih.planes, bmih.planes);
    printf("bits per pixel: %x (%hu)\n", bmih.bitsPerPixel, bmih.bitsPerPixel);
    printf("compression: %x (%u)\n", bmih.compression, bmih.compression);
    printf("image size: %x (%u)\n", bmih.imageSize, bmih.imageSize);
    printf("x pixels per meter: %x (%u)\n", bmih.xPixelsPerMeter, bmih.xPixelsPerMeter);
    printf("y pixels per meter: %x (%u)\n", bmih.yPixelsPerMeter, bmih.yPixelsPerMeter);
    printf("colors in color table: %x (%u)\n", bmih.colorsInColorTable, bmih.colorsInColorTable);
    printf("important color count: %x (%u)\n", bmih.importantColorCount, bmih.importantColorCount);

    printf("\n");
}
