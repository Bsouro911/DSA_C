#include <stdio.h>
#include <string.h>

void reverseString(char *str, int start, int end) {
    if (start >= end) {
        return; // Base case: the string is reversed
    }

    // Swap the characters at positions start and end
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call with updated start and end positions
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str1[] = "Hello, World!";
    char str2[] = "Testing the recursive function.";
    char str3[] = "12345"; // Numeric string

    printf("Original string 1: %s\n", str1);
    reverseString(str1, 0, strlen(str1) - 1);
    printf("Reversed string 1: %s\n\n", str1);

    printf("Original string 2: %s\n", str2);
    reverseString(str2, 0, strlen(str2) - 1);
    printf("Reversed string 2: %s\n\n", str2);

    printf("Original string 3: %s\n", str3);
    reverseString(str3, 0, strlen(str3) - 1);
    printf("Reversed string 3: %s\n\n", str3);

    return 0;
}
