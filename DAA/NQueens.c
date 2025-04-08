#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void addSolution(int*** ans, int** board, int* solutionCount, int n) {
    (*solutionCount)++;
    *ans = (int**) realloc(*ans, (*solutionCount) * sizeof(int*));
    (*ans)[*solutionCount - 1] = (int*) malloc(n * n * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*ans)[*solutionCount - 1][i * n + j] = board[i][j];
        }
    }
}
bool isSafe(int row, int col, int** board, int n) {
    int x = row, y = col;
    while (y >= 0) {
        if (board[x][y] == 1)
            return false;
        y--;
    }
    x = row, y = col;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }
    x = row, y = col;
    while (x < n && y >= 0) {
        if (board[x][y] == 1)
            return false;
        x++;
        y--;
    }
    return true;
}
void solve(int col, int*** ans, int** board, int* solutionCount, int n) {
    if (col == n) {
        addSolution(ans, board, solutionCount, n);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col + 1, ans, board, solutionCount, n);
            board[row][col] = 0;
        }
    }
}
void printSolutions(int** solutions, int solutionCount, int n) {
    for (int k = 0; k < solutionCount; k++) {
        printf("Solution %d:\n", k + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c ", solutions[k][i * n + j] == 1 ? 'Q' : '.');
            }
            printf("\n");
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    int** board = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        board[i] = (int*) calloc(n, sizeof(int));
    }
    int** solutions = NULL;
    int solutionCount = 0;
    solve(0, &solutions, board, &solutionCount, n);
    if (solutionCount == 0) {
        printf("No solutions exist for N = %d.\n", n);
    }
    else {
        printf("Total solutions for N = %d: %d\n\n", n, solutionCount);
        printSolutions(solutions, solutionCount, n);
    }
    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);
    for (int i = 0; i < solutionCount; i++) {
        free(solutions[i]);
    }
    free(solutions);
    return 0;
}