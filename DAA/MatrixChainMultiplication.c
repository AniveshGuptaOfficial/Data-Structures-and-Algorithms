#include <stdio.h>
#include <limits.h>
void printParenthesis(int i, int j, int n, int s[n][n], char *name) {
    if (i == j) {
        printf("%c", (*name)++);
        return;
    }
    printf("(");
    printParenthesis(i, s[i][j], n, s, name);
    printParenthesis(s[i][j] + 1, j, n, s, name);
    printf(")");
}
void matrixChainOrder(int p[], int n) {
    int m[n][n], s[n][n];
    for (int i = 1; i < n; i++) m[i][i] = 0;
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("\nMinimum number of multiplications: %d\n", m[1][n - 1]);
    printf("Optimal Parenthesization: ");
    char name = 'A';
    printParenthesis(1, n - 1, n, s, &name);
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int p[n + 1];
    printf("Enter the dimensions: ");
    for (int i = 0; i <= n; i++) scanf("%d", &p[i]);
    matrixChainOrder(p, n + 1);
    return 0;
}