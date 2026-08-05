#include <stdio.h>

int main() {
    int data[100], div[20], temp[100];
    int datalen = 0, divlen = 0;
    int i, j;
    char ch;

    printf("Enter the data (binary): ");

    while ((ch = getchar()) != '\n') {
        if (ch == '0' || ch == '1') {
            data[datalen++] = ch - '0';
        }
    }

    printf("Enter the divisor (generator polynomial): ");

    while ((ch = getchar()) != '\n') {
        if (ch == '0' || ch == '1') {
            div[divlen++] = ch - '0';
        }
    }

    
    for (i = 0; i < datalen; i++) {
        temp[i] = data[i];
    }

    
    for (i = datalen; i < datalen + divlen - 1; i++) {
        temp[i] = 0;
    }

    int total = datalen + divlen - 1;


    for (i = 0; i < datalen; i++) {
        if (temp[i] == 1) {
            for (j = 0; j < divlen; j++) {
                temp[i + j] ^= div[j];
            }
        }
    }

    printf("\nCRC Remainder: ");
    for (i = datalen; i < total; i++) {
        printf("%d", temp[i]);
    }

    printf("\nTransmitted Codeword: ");
    for (i = 0; i < datalen; i++) {
        printf("%d", data[i]);
    }
    for (i = datalen; i < total; i++) {
        printf("%d", temp[i]);
    }

    printf("\n");

    return 0;
}
