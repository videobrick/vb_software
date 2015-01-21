#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
    int width, height;
    int bufsize;

    uint8_t * inbuf;
    uint8_t * outbuf;
    uint8_t * tempbuf;
    uint8_t * ybuf;
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
    tempbuf = outbuf = malloc(bufsize);

    f = fopen(argv[1], "r");
    fread(inbuf, bufsize, 1, f);
    fclose(f);

    ybuf = inbuf;
    ubuf = inbuf + width * height;
    vbuf = inbuf + width * height + 1;

    for (i=0; i < width * height / 2; i++) {
        *tempbuf++ = *ybuf++;
        *tempbuf++ = *ubuf; ubuf+=2;
        *tempbuf++ = *ybuf++;
        *tempbuf++ = *vbuf; vbuf+=2;
    }

    f = fopen(argv[2], "w");
    fwrite(outbuf, bufsize, 1, f);
    fclose(f);

    free(outbuf);
    free(inbuf);

    return 0;
}
