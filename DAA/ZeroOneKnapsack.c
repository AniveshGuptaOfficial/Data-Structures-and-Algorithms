#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsack(int values[], int weights[], int n, int capacity) {
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } 
            else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } 
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    printf("Items included: ");
    int w = capacity;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("%d ", i);
            w -= weights[i - 1];
        }
    }
    printf("\n");
    return dp[n][capacity];
}
int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int values[n], weights[n];
    printf("Enter values of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    printf("Enter weights of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);
    int max_value = knapsack(values, weights, n, capacity);
    printf("Maximum value that can be obtained: %d\n", max_value);
    return 0;
}