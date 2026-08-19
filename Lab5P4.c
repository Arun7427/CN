#include <stdio.h>
#include <string.h>

int main() {
    char stuffed[100], destuffed[100];
    int i, j = 0;

    printf("Enter stuffed data: ");
    scanf("%s", stuffed);

    for (i = 0; stuffed[i] != '\0'; i++) {
        
        if (stuffed[i] == 'E') {  
            i++;
        }
        destuffed[j++] = stuffed[i];
    }

    destuffed[j] = '\0';

    printf("Destuffed Data: %s\n", destuffed);

    return 0;
}
