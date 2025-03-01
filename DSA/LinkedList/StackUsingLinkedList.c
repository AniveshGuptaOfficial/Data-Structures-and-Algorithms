#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
void push(int val) {
    // Create new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    // Make the new node point to the head node
    newNode->next = head;
    // Make the new node the head node
    head = newNode;
}
void pop() {
    struct node *temp;
    if (head == NULL)
        printf("Stack is Empty\n");
    else {
        printf("Popped element = %d\n", head->data);
        // Backup the head node
        temp = head;
        // Move head to the next node
        head = head->next;
        // Free the popped element's memory
        free(temp);
    }
}
// Print the linked list
void printList() {
    struct node *temp = head;
    // Iterate through the entire linked list and print data
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    push(10);
    push(20);
    push(30);
    printf("Linked List\n");
    printList();
    pop();
    printf("After the pop, the new linked list\n");
    printList();
    pop();
    printf("After the pop, the new linked list\n");
    printList();
    return 0;
}
