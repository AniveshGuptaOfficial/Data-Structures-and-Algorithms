#include <stdio.h>
int main() {
int i, j, k;
int n = 3;
int a[n][n], b[n][n], c[n][n];
for(i = 0; i < n; i++) {
for(j = 0; j < n; j++) {
scanf("%d", &a[i][j]);
}
}
for(i = 0; i < n; i++) {
for(j = 0; j < n; j++) {
scanf("%d", &b[i][j]);
}
}
for(i = 0; i < n; i++) {
for(j = 0; j < n; j++) {
c[i][j] = 0;
for(k = 0; k < n; k++) {
c[i][j] += a[i][k] * b[k][j];
}
}
}
for(i = 0; i < n; i++) {
for(j = 0; j < n; j++) {
printf("%d\t", c[i][j]);
}
printf("\n");
}
return 0;
}