#include <stdio.h> 
#include <stdlib.h> 
#define MAX 10 // Maximum size of the stack

int count = 0; // Counter to keep track of the number of items in the stack

// Define a stack structure with an array to store items and a top index
struct stack { 
  int items[MAX]; 
  int top; 
}; 
typedef struct stack st; // Create an alias for the stack structure

// Function to initialize an empty stack by setting the top index to -1
void createEmptyStack(st *s) { 
  s->top = -1; 
} 

// Function to check if the stack is full
int isfull(st *s) { 
  return s->top == MAX - 1; 
} 

// Function to check if the stack is empty
int isempty(st *s) { 
  return s->top == -1; 
} 

// Function to push a new item onto the stack
void push(st *s, int newitem) { 
  if (isfull(s)) { // Check if stack is full before pushing
    printf("STACK FULL"); 
  } else { 
    s->top++; // Increment the top index
    s->items[s->top] = newitem; // Add the new item at the top of the stack
  } 
  count++; // Increment the count of items in the stack
} 

// Function to print all items in the stack
void printStack(st *s) { 
  printf("Stack: "); 
  for (int i = 0; i < count; i++) { 
    printf("%d ", s->items[i]); // Print each item in the stack
  } 
  printf("\n"); 
} 

// Function to pop an item from the stack
void pop(st *s) { 
  if (isempty(s)) { // Check if stack is empty before popping
    printf("\n STACK EMPTY \n"); 
  } else { 
    printf("Item popped= %d", s->items[s->top]); // Display the popped item
    s->top--; // Decrement the top index
  } 
  count--; // Decrement the count of items in the stack
  printf("\n"); 
} 

int main() {
  st *s = (st *)malloc(sizeof(st)); // Dynamically allocate memory for the stack
  createEmptyStack(s); // Initialize the stack
  
  // Push items onto the stack
  push(s, 1); 
  push(s, 2); 
  push(s, 3); 
  push(s, 4); 
  
  // Print the current state of the stack
  printStack(s); 
  
  // Pop an item from the stack
  pop(s); 
  printf("\nAfter popping out\n"); 
  
  // Print the stack after popping an item
  printStack(s); 
  
  // Free the allocated memory for the stack
  free(s);
  
  return 0;
}
