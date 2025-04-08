#include <stdio.h>
int main() {
int t1 = 0, t2 = 1;
int nextTerm = t1 + t2;
printf("Fibonacci series: %d, %d, ", t1, t2);
while (nextTerm <= 100) {
printf("%d, ", nextTerm);
t1 = t2;
t2 = nextTerm;
nextTerm = t1 + t2;
}
return 0;
}