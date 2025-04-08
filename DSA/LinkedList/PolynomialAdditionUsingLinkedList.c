#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int pow;
    struct Node* next;
};
// Function to create a new node
struct Node* createNode(int c, int p) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = NULL;
    return newNode;
}
// Function to add two polynomials
struct Node* addPolynomial(struct Node* head1, struct Node* head2) {
    struct Node* dummy = createNode(0, 0);
    struct Node* prev = dummy;
    struct Node *curr1 = head1, *curr2 = head2;
    // Traverse both lists
    while (curr1 != NULL && curr2 != NULL) {
        // Compare powers
        if (curr1->pow < curr2->pow) {
            prev->next = curr2;
            prev = curr2;
            curr2 = curr2->next;
        }
        else if (curr1->pow > curr2->pow) {
            prev->next = curr1;
            prev = curr1;
            curr1 = curr1->next;
        }
        else {
            curr1->coeff = curr1->coeff + curr2->coeff;
            prev->next = curr1;
            prev = curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }
    // Append the remaining terms, if any
    if (curr1 != NULL) {
        prev->next = curr1;
    }
    if (curr2 != NULL) {
        prev->next = curr2;
    }
    return dummy->next;
}
// Function to print the polynomial
void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d,%d ", curr->coeff, curr->pow);
        curr = curr->next;
    }
    printf("\n");
}
int main() {
    // 1st polynomial: 5x^2 + 4x^1 + 2x^0
    struct Node* head1 = createNode(5, 2);
    head1->next = createNode(4, 1);
    head1->next->next = createNode(2, 0);
    // 2nd polynomial: -5x^1 - 5x^0
    struct Node* head2 = createNode(-5, 1);
    head2->next = createNode(-5, 0);
    // Add the polynomials
    struct Node* head = addPolynomial(head1, head2);
    // Print the result
    printList(head);
    return 0;
}
