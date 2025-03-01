#include <stdio.h>
int main() {
int i, j;
int n = 3, temp = 1;
int a[n][n];
for(i = 0; i < n; i++) {
for(j = 0; j < n; j++) {
scanf("%d", &a[i][j]);
}
}
for(i = 0; i < n; i++) {
for(j = 0; j < n; j++) {
if(i != j) {
if(a[i][j] != a[j][i]) {
temp = 0;
break;
}
}
}
if(temp == 0) break;
}
if(temp == 1)
printf("Symmetric\n");
else
printf("Not Symmetric\n");
return 0;
}