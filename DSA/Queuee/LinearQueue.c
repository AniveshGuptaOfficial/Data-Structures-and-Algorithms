// C program for array implementation of queue
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a queue
struct Queue {
    int front, rear, size; // front and rear indicate the queue's current ends, size indicates current size
    unsigned capacity;      // maximum capacity of the queue
    int* array;             // dynamic array to store queue elements
};

// Function to create a queue of given capacity
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue)); // allocate memory for queue structure
    queue->capacity = capacity;
    queue->front = queue->size = 0;     // initialize front and size to 0
    queue->rear = capacity - 1;         // initialize rear to last index (for circular nature of the queue)
    queue->array = (int*)malloc(queue->capacity * sizeof(int)); // allocate memory for the queue's array
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity); // checks if the queue has reached its capacity
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue) {
    return (queue->size == 0); // checks if the queue has no elements
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) // if the queue is full, no addition can be made
        return;
    queue->rear = (queue->rear + 1) % queue->capacity; // increment rear index circularly
    queue->array[queue->rear] = item;                  // add new item at the rear
    queue->size = queue->size + 1;                     // increment size of the queue
    printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) // if the queue is empty, no element to remove
        return INT_MIN;
    int item = queue->array[queue->front];             // store the item at the front
    queue->front = (queue->front + 1) % queue->capacity; // increment front index circularly
    queue->size = queue->size - 1;                     // decrement size of the queue
    return item;
}

// Function to get front of queue without removing it
int front(struct Queue* queue) {
    if (isEmpty(queue)) // if the queue is empty, no front element
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get rear of queue without removing it
int rear(struct Queue* queue) {
    if (isEmpty(queue)) // if the queue is empty, no rear element
        return INT_MIN;
    return queue->array[queue->rear];
}

// Driver program to test above functions
int main() {
    struct Queue* queue = createQueue(1000); // create a queue with a capacity of 1000

    enqueue(queue, 10); // add 10 to the queue
    enqueue(queue, 20); // add 20 to the queue
    enqueue(queue, 30); // add 30 to the queue
    enqueue(queue, 40); // add 40 to the queue

    printf("%d dequeued from queue\n\n", dequeue(queue)); // remove and print the front item

    printf("Front item is %d\n", front(queue)); // get and print the front item
    printf("Rear item is %d\n", rear(queue));   // get and print the rear item

    return 0;
}
