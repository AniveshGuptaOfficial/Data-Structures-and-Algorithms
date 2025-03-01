#include<stdio.h>
typedef struct{
    char name[20];
    float weight;
    float profit;
    float ratio;
}Item;
void gk(int n, Item items[], float capacity){
    float totalprofit = 0,totalweight = 0,fraction;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(items[j].ratio<items[j+1].ratio){
                Item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;         
            }
        }
    }
    printf("\nSelected item:\n");
    printf("Name\tWeight\tProfit\tFraction\tEarned Profit\n");
    for(int i=0;i<n;i++){
        if(items[i].weight<=capacity){
            fraction =1.0;
            capacity -= items[i].weight;
            totalprofit += items[i].profit;
            totalweight += items[i].weight;
        }
        else{
            fraction = capacity/items[i].weight;
            totalprofit += fraction*items[i].profit;
            totalweight += fraction*items[i].weight;
            capacity = 0;
        }
        printf("%s\t%.2f\t%.2f\t%.2f\t%.2f\n",items[i].name,items[i]
    }
}
int main(){
    int n;
    float capacity;
    printf("Enter the number of items: ");
    scanf("%d",&n);
    Item items[n];
    printf("Enter the capacity of the knapsack: ");
    scanf("%f",&capacity);
    for(int i=0;i<n;i++){
        printf("Enter name, weight and profit of item %d: ",i+1);
        scanf("%s %f %f", items[i].name, &items[i].weight, &items[i].profit);
        items[i].ratio = items[i].profit/items[i].weight;
    }
    gk(n,items,capacity);
    return 0;
}