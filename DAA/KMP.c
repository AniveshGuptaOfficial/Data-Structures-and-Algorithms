#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void computeLPSArray(const char* P, int m, int* lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (P[i] == P[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void printLPSArray(const int* lps, int m) {
    printf("LPS array: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", lps[i]);
    }
    printf("\n");
}
void KMPSearch(const char* T, int n, const char* P, int m) {
    int* lps = (int*)malloc(m * sizeof(int));
    computeLPSArray(P, m, lps);
    printLPSArray(lps, m);
    int i = 0;
    int j = 0;
    while (i < n) {
        if (P[j] == T[i]) {
            i++;
            j++;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && P[j] != T[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    free(lps);
}
int main() {
    char T[1000];
    char P[100];
    printf("Enter the text: ");
    fgets(T, sizeof(T), stdin);
    T[strcspn(T, "\n")] = '\0';
    printf("Enter the pattern: ");
    fgets(P, sizeof(P), stdin);
    P[strcspn(P, "\n")] = '\0';
    int n = strlen(T);
    int m = strlen(P);
    KMPSearch(T, n, P, m);
    return 0;
}
