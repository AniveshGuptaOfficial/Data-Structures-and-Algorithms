#include <stdio.h> 
#include <string.h> 
void computeLPSArray(char *pattern, int m, int *lps){ 
    int len = 0; 
    lps[0] = 0; 
    int i = 1; 
    while (i < m){ 
        if (pattern[i] == pattern[len]){ 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else{ 
            if (len != 0){ 
                len = lps[len - 1]; 
            } 
            else { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}
void KMPSearch(char *text, char *pattern){ 
    int n = strlen(text); 
    int m = strlen(pattern); 
    int lps[m]; 
    computeLPSArray(pattern, m, lps); 
    int i = 0; 
    int j = 0; 
    int found = 0; 
    while (i < n){ 
        if (pattern[j] == text[i]){ 
            i++; 
            j++; 
        } 
        if (j == m){ 
            printf("Pattern found at shift %d\n", i - j); 
            j = lps[j - 1]; 
            found = 1; 
        } 
        else if (i < n && pattern[j] != text[i]){ 
            if (j != 0) 
                j = lps[j - 1]; 
            else 
                i++; 
        } 
    } 
    if (!found) 
        printf("Pattern not found\n"); 
} 
int main(){ 
    char text[1000], pattern[100]; 
    printf("Enter the text: "); 
    scanf("%s", text); 
    printf("Enter the pattern: "); 
    scanf("%s", pattern); 
    KMPSearch(text, pattern); 
    return 0; 
}