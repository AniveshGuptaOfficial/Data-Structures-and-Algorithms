#include <stdio.h>
#include <string.h>
int dp[100][100];
char seq1[100], seq2[100], direction[100][100];
void printLCS(int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (direction[i][j] == 'c') {
        printLCS(i - 1, j - 1);
        printf("%c", seq1[i - 1]);
    } 
    else if (direction[i][j] == 'u')
        printLCS(i - 1, j);
    else
        printLCS(i, j - 1);
}
void longestCommonSubsequence(int m, int n) {
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                direction[i][j] = 'c';
            } 
            else if (dp[i - 1][j] >= dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                direction[i][j] = 'u';
            } 
            else {
                dp[i][j] = dp[i][j - 1];
                direction[i][j] = 'l';
            }
        }
    }
}
int main() {
    printf("Enter the 1st sequence: ");
    scanf("%s", seq1);
    printf("Enter the 2nd sequence: ");
    scanf("%s", seq2);
    int m = strlen(seq1);
    int n = strlen(seq2);
    longestCommonSubsequence(m, n);
    printf("\nThe Longest Common Subsequence is ");
    printLCS(m, n);
    printf("\nLength of LCS: %d\n", dp[m][n]);
    return 0;
}