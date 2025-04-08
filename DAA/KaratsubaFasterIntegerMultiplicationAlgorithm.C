#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int nextPowerOfTwo(int n) {
    int power = 1;
    while (power < n)
        power *= 2;
    return power;
}
void padZeros(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1 > len2 ? len1 : len2;
    int newLen = nextPowerOfTwo(maxLen);
    while (strlen(num1) < newLen) {
        memmove(num1 + 1, num1, strlen(num1) + 1);
        num1[0] = '0';
    }
    while (strlen(num2) < newLen) {
        memmove(num2 + 1, num2, strlen(num2) + 1);
        num2[0] = '0';
    }
}
long long stringToLL(const char *str) {
    long long result = 0;
    while (*str) {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}
long long karatsuba(char *num1, char *num2) {
    int n = strlen(num1);
    if (n == 1)
        return (num1[0] - '0') * (num2[0] - '0');
    int half = n / 2;
    char XH[half + 1], XL[half + 1], YH[half + 1], YL[half + 1];
    strncpy(XH, num1, half);
    XH[half] = '\0';
    strcpy(XL, num1 + half);
    strncpy(YH, num2, half);
    YH[half] = '\0';
    strcpy(YL, num2 + half);
    long long a = karatsuba(XH, YH);
    long long d = karatsuba(XL, YL);
    char sumX[half + 20], sumY[half + 20];
    sprintf(sumX, "%lld", stringToLL(XH) + stringToLL(XL));
    sprintf(sumY, "%lld", stringToLL(YH) + stringToLL(YL));
    long long e = karatsuba(sumX, sumY) - a - d;
    long long result = a * pow(10, n) + e * pow(10, n / 2) + d;
    return result;
}
int main() {
    char num1[100], num2[100];
    printf("Enter the first integer: ");
    scanf("%s", num1);
    printf("Enter the second integer: ");
    scanf("%s", num2);
    padZeros(num1, num2);
    printf("\nNumbers after padding (if needed):\n");
    printf("Number 1: %s\n", num1);
    printf("Number 2: %s\n", num2);
    int len = strlen(num1);
    if ((len & (len - 1)) == 0)
        printf("The length of the numbers is already a power of 2.\n");
    else
        printf("The numbers have been padded to make their length a power of 2.\n");
    long long product = karatsuba(num1, num2);
    printf("\nProduct of the numbers: %lld\n", product);
    return 0;
}