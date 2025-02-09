#include <stdio.h>

int main() {
    unsigned char hex_values[] = {0x66, 0x34, 0x6b, 0x6d, 0x6d, 0x36, 0x70, 0x7c,
                                  0x3d, 0x82, 0x7f, 0x70, 0x82, 0x6e, 0x83, 0x82,
                                  0x44, 0x42, 0x83, 0x44, 0x75, 0x7b, 0x7f, 0x8c, 0x89};
    int size = 25;
    for (int i = 0; i < size; i++) {
        printf("%c", hex_values[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%c", hex_values[i] + i);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%c", hex_values[i] - i);
    }
    printf("\n");
    return 0;
}