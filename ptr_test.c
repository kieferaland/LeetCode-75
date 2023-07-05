#include <stdio.h>

int main() {
    char str[] = "Hello, world!"; // Our string
    char *p = str; // Pointer p points to the beginning of the string
    char *q = str; // Pointer q also points to the beginning of the string

    while(*p != '\0') { // Loop through the string until we hit the null character
        printf("%c", *p); // Print the current character
        p++; // Move to the next character
    }

    printf("\n");

    // q still points to the beginning of the string
    while(*q != '\0') {
        printf("%c", *q);
        q++;
    }

    return 0;
}
