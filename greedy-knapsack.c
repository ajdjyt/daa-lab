#include<stdio.h>

typedef struct {
    float weight;
    float value;
    float ratio;
} Item;

void sortItemsByRatio(Item items[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

float knapsack(Item items[], int n, int capacity) {
    sortItemsByRatio(items, n);
    float totalValue = 0;
    for(int i = 0; i < n; i++) {
        if(items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((float)capacity / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);
    
    Item items[n];
    
    for(int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i+1);
        scanf("%f %f", &items[i].value, &items[i].weight);
        items[i].ratio = items[i].value / items[i].weight;
    }
    
    float maxValue = knapsack(items, n, capacity);
    printf("Maximum value in knapsack = %.2f\n", maxValue);
    
    return 0;
}
