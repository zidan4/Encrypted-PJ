#include <stdio.h>
#include <string.h>

#define KEY 0xAA
#define MAX_ENTRY 512

void encryptDecrypt(char *data) {
    for (int i = 0; i < strlen(data); i++)
        data[i] ^= KEY;
}

int main() {
    FILE *file;
    char entry[MAX_ENTRY];

    printf("Enter your journal entry: ");
    fgets(entry, MAX_ENTRY, stdin);
    encryptDecrypt(entry);

    file = fopen("journal.dat", "ab");
    fwrite(entry, sizeof(char), strlen(entry), file);
    fclose(file);

    printf("Entry saved securely.\n");
    return 0;
}
