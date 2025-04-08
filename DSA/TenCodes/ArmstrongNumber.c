#include <stdio.h>
int armstrong1(int a1) {
int a2 = 0;
while (a1 != 0) {
int a3 = a1 % 10;
a2 = a2 + (a3 * a3 * a3);
a1 = a1 / 10;
}
return a2;
}
int main() {
int a;
scanf("%d", &a);
int al = armstrong1(a);
if (a == al) {
printf("Armstrong");
} else {
printf("Not Armstrong");
}
return 0;
}