#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue(int x) {
    if (rear == N - 1) {
        printf("Queue Full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}
void display() {
    if (front == -1 && rear == -1) {
        printf("Queue Empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int peek() {
    if (front == -1 && rear == -1) {
        printf("Queue Empty\n");
    } else {
        printf("%d",queue[front]);
    }
}
void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue Empty\n");
    } else if (front == rear) {
        printf("Dequeued %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Dequeued %d\n", queue[front]);
        front++;
    }
}
int main() {
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    peek();
    display();
    return 0;
}
