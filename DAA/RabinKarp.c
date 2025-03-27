#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int calculateHash(const char* str, int len, int prime) {
    int hashValue = 0;
    for (int i = 0; i < len; i++) {
        hashValue = (hashValue * 26 + (str[i] - 'a')) % prime;
    }
    return hashValue;
}
int* rabinKarp(const char* text, const char* pattern, int* resultSize) {
    int n = strlen(text);
    int m = strlen(pattern);
    int prime = 101;
    int patternHash = calculateHash(pattern, m, prime);
    int textHash = calculateHash(text, m, prime);
    int h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * 26) % prime;
    }
    int* occurrences = (int*)malloc((n - m + 1) * sizeof(int));
    *resultSize = 0;
    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            int match = 1;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                occurrences[*resultSize] = i;
                (*resultSize)++;
            }
        }
        if (i < n - m) {
            textHash = ((textHash - (text[i] - 'a') * h) * 26 + (text[i + m] - 'a')) % prime;
            if (textHash < 0) textHash += prime;
        }
    }
    return occurrences;
}
int main() {
    char text[1000];
    char pattern[100];
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';
    int resultSize;
    int* occurrences = rabinKarp(text, pattern, &resultSize);
    if (resultSize == 0) {
        printf("Pattern not found.\n");
    } else {
        printf("Pattern found at indices: ");
        for (int i = 0; i < resultSize; i++) {
            printf("%d ", occurrences[i]);
        }
        printf("\n");
    }
    free(occurrences);
    return 0;
}
