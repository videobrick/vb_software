#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
    int width, height;
    int bufsize;

    uint8_t * inbuf;
    uint8_t * tmpbuf;
    uint8_t * outbuf;
    uint8_t * ubuf;
    uint8_t * vbuf;

    int i;

    FILE * f;

    if (argc < 4) {
        printf("Usage: %s <infile> <outfile> <width> <height>\n", argv[0]);
        return 1;
    }

    width = atoi(argv[3]);
    height = atoi(argv[4]);
    bufsize = width * height * 2;

    inbuf = malloc(bufsize);
    outbuf = malloc(bufsize);

    f = fopen(argv[1], "r");
    fread(inbuf, bufsize, 1, f);
    fclose(f);

    // Y Plane
    memcpy(outbuf, inbuf, width * height);

    tmpbuf = inbuf + width * height;
    ubuf = outbuf + width * height;
    vbuf = outbuf + (3 * width * height) / 2;

    // U and V plane
    for (i=0; i < width * height / 2; i++) {
        *ubuf++ = *tmpbuf++;
        *vbuf++ = *tmpbuf++;
    }

    f = fopen(argv[2], "w");
    fwrite(outbuf, bufsize, 1, f);
    fclose(f);

    free(outbuf);
    free(inbuf);

    return 0;
}
