#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countVowels(const char *str) {
    int count = 0;

    while (*str) {
        char ch = tolower(*str); // Convert the character to lowercase for easier comparison

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }

        str++; // Move to the next character in the string
    }

    return count;
}

int main() {
    const char *str1 = "Hello, World!";
    const char *str2 = "This is a test string.";
    const char *str3 = "aeiou"; // All vowels

    printf("Vowel count in \"%s\": %d\n", str1, countVowels(str1));
    printf("Vowel count in \"%s\": %d\n", str2, countVowels(str2));
    printf("Vowel count in \"%s\": %d\n", str3, countVowels(str3));

    return 0;
}
