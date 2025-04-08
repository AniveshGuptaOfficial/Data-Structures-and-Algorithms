#include <stdio.h>
typedef struct {
    char name[20];
    float weight;
    float profit;
    float ratio;
} Item;
void greedyKnapsack(int n, Item items[], float capacity) {
    int i, j;
    float totalProfit = 0, totalWeight = 0, fraction;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    printf("\nSelected items:\n");
    printf("Name\tWeight\tProfit\tFraction\tEarned Profit\n");
    for (i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            fraction = 1.0;
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
            totalWeight += items[i].weight;
        } else {
            fraction = capacity / items[i].weight;
            totalProfit += fraction * items[i].profit;
            totalWeight += fraction * items[i].weight;
            capacity = 0;
        }
        printf("%s\t%.2f\t%.2f\t%.2f\t\t%.2f\n", items[i].name, items[i].weight, items[i].profit, fraction, fraction * items[i].profit);
        if (capacity == 0) break;
    }
    printf("\nTotal weight: %.2f\n", totalWeight);
    printf("Total profit: %.2f\n", totalProfit);
}
int main() {
    int n, i;
    float capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item items[n];
    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);
    for (i = 0; i < n; i++) {
        printf("Enter name, weight and profit of item %d: ", i + 1);
        scanf("%s %f %f", items[i].name, &items[i].weight, &items[i].profit);
        items[i].ratio = items[i].profit / items[i].weight;
    }
    greedyKnapsack(n, items, capacity);
    return 0;
}