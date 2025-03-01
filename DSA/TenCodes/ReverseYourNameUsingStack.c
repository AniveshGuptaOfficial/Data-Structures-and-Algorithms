#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct stack {
char items[MAX];
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
void push(st *s, char newitem) {
if (isfull(s)) {
printf("STACK FULL\n");
} else {
s->top++;
s->items[s->top] = newitem;
}
}
char pop(st *s) {
if (isempty(s)) {
printf("\nSTACK EMPTY\n");
return '\0';
} else {
return s->items[s->top--];
}
}
void printStack(st *s) {
for (int i = 0; i <= s->top; i++) {
printf("%c", s->items[i]);
}
}
int main() {
st *s = (st *)malloc(sizeof(st));
createEmptyStack(s);
char name[] = "Anivesh Gupta";
int length = 0;
while (name[length] != '\0') {
length++;
}
for (int i = 0; i < length; i++) {
push(s, name[i]);
}
printf("Reversed name: ");
for (int i = 0; i < length; i++) {
printf("%c", pop(s));
}
printf("\n");
free(s);
return 0;
}