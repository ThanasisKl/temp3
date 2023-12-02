#include <stdio.h>
#include <string.h>

// Function to break a string into all possible combinations of
// non-overlapping substrings enclosed within curly braces
void recur(char* s, int i, char* result) {
    int n = strlen(s);
    if (i == n) {
        printf("%s\n", result);
        return;
    }

    // Consider each substring s[i, j]
    for (int j = n - 1; j >= i; j--) {
        // Create a substring {s[i, j]}
        char substr[j - i + 1];
        sprintf(substr, "%.*s|", j - i + 1, s + i);
        // Append the substring to the result and recur with an index
        // of the next character to be processed and the result string
        char temp[strlen(result) + strlen(substr) + 1];
        strcpy(temp, result);
        strcat(temp, substr);
        recur(s, j + 1, temp);
    }
}

int main() {
    // Input string
    char s[] = "1234";

    int starting_index = 0;
    char empty_string[1] = ""; // Empty string

    recur(s, starting_index, empty_string);

    return 0;
}
