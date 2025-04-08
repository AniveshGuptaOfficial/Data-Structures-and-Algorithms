#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct stack {
int items[MAX];
int top;
};
typedef struct stack st;
void createEmptyStack(st *s) {
s->top = -1;
}
int isfull(st *s) {
return s->top == MAX - 1;
}
int isempty(st *s) {
return s->top == -1;
}
void push(st *s, int newitem) {
if (isfull(s)) {
printf("STACK FULL\n");
} else {
s->top++;
s->items[s->top] = newitem;
}
}
void pop(st *s) {
if (isempty(s)) {
printf("\nSTACK EMPTY\n");
} else {
printf("Item popped = %d\n", s->items[s->top]);
s->top--;
}
}
void printStack(st *s) {
printf("Stack: ");
for (int i = 0; i <= s->top; i++) {
printf("%d ", s->items[i]);
}
printf("\n");
}
int main() {
st *s = (st *)malloc(sizeof(st));
createEmptyStack(s);
push(s, 1);
push(s, 2);
push(s, 3);
push(s, 4);
printStack(s);
pop(s);
printf("\nAfter popping out\n");
printStack(s);
free(s);
return 0;
}
