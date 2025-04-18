#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
    struct Item* next;
};

struct Item* head = NULL;

void addItem() {
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
    printf("Enter Item ID: ");
    scanf("%d", &newItem->id);
    printf("Enter Item Name: ");
    scanf(" %[^\n]s", newItem->name);
    printf("Enter Quantity: ");
    scanf("%d", &newItem->quantity);
    printf("Enter Price: ");
    scanf("%f", &newItem->price);
    newItem->next = head;
    head = newItem;
    printf("Item added successfully!\n");
}

void searchItem() {
    int id;
    printf("Enter Item ID to search: ");
    scanf("%d", &id);
    struct Item* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Item Found: ID: %d, Name: %s, Quantity: %d, Price: $%.2f\n",
                   temp->id, temp->name, temp->quantity, temp->price);
            return;
        }
        temp = temp->next;
    }
    printf("Item not found!\n");
}

void displayInventory() {
    struct Item* temp = head;
    if (temp == NULL) {
        printf("Inventory is empty!\n");
        return;
    }
    printf("\nInventory:\n");
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: $%.2f\n",
               temp->id, temp->name, temp->quantity, temp->price);
        if (temp->quantity < 10) {
            printf("** Low Stock Alert for %s **\n", temp->name);
        }
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Search Item\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                searchItem();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
