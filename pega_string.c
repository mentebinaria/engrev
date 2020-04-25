#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "rb");
    unsigned char byte;

    while (fread(&byte, sizeof(byte), 1, fp)) {
        printf("%c", byte);
    }

    printf("\n");
    fclose(fp);

    return 0;
}
