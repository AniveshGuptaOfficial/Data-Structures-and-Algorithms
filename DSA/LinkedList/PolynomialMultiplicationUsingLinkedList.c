#include <stdio.h>
#include <stdlib.h>
// Node structure containing power and coefficient of variable
struct Node {
    int coeff, power;
    struct Node* next;
};
// Function to add a new node at the end of list
struct Node* addnode(struct Node* start, int coeff, int power)
{
    // Create a new node
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->next = NULL;
    // If linked list is empty
    if (start == NULL) 
        return newnode;
    // If linked list has nodes
    struct Node* ptr = start;
    while (ptr->next != NULL) 
        ptr = ptr->next;
    ptr->next = newnode;
    return start;
}
// Function to display the linked list
void printList(struct Node* ptr)
{
    while (ptr->next != NULL) {
        printf("%dx^%d", ptr->coeff, ptr->power);
        if (ptr->next != NULL && ptr->next->coeff >= 0)
            printf("+");
        ptr = ptr->next;
    }
    printf("%d\n", ptr->coeff);
}
// Function to add coefficients of two elements having the same power
void removeDuplicates(struct Node* start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;
    // Pick elements one by one
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        // Compare the picked element with rest of the elements
        while (ptr2->next != NULL) {
            // If power of two elements are the same
            if (ptr1->power == ptr2->next->power) {
                // Add their coefficients and put it in 1st element
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;               
                // Remove the 2nd element
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
// Function to multiply two polynomial numbers
struct Node* multiply(struct Node* poly1, struct Node* poly2, struct Node* poly3)
{
    // Create two pointers and store the address of 1st and 2nd polynomials
    struct Node *ptr1, *ptr2;
    ptr1 = poly1;
    ptr2 = poly2;
    while (ptr1 != NULL) {
        while (ptr2 != NULL) {
            int coeff, power;
            // Multiply the coefficient of both polynomials and store it in coeff
            coeff = ptr1->coeff * ptr2->coeff;
            // Add the powers of both polynomials and store it in power
            power = ptr1->power + ptr2->power;
            // Invoke addnode function to create a new node by passing three parameters
            poly3 = addnode(poly3, coeff, power);   
            // Move the pointer of 2nd polynomial to get its next term
            ptr2 = ptr2->next;
        }
        // Move the 2nd pointer to the starting point of 2nd polynomial
        ptr2 = poly2;   
        // Move the pointer of 1st polynomial
        ptr1 = ptr1->next;
    }
    // This function will be invoked to add the coefficients of the elements having the same power in the resultant linked list
    removeDuplicates(poly3);   
    return poly3;
}
// Driver code
int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
    // Creation of 1st Polynomial: 3x^2 + 5x^1 + 6
    poly1 = addnode(poly1, 3, 3);
    poly1 = addnode(poly1, 6, 1);
    poly1 = addnode(poly1, -9, 0);
    // Creation of 2nd polynomial: 6x^1 + 8
    poly2 = addnode(poly2, 9, 3);
    poly2 = addnode(poly2, -8, 2);
    poly2 = addnode(poly2, 7, 1);
    poly2 = addnode(poly2, 2, 0);
    // Displaying 1st polynomial
    printf("1st Polynomial:- ");
    printList(poly1);
    // Displaying 2nd polynomial
    printf("2nd Polynomial:- ");
    printList(poly2);
    // Calling multiply function
    poly3 = multiply(poly1, poly2, poly3);
    // Displaying resultant polynomial
    printf("Resultant Polynomial:- ");
    printList(poly3);
    return 0;
}
