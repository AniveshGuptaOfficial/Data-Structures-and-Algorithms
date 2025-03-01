#include <stdio.h>
int main() {
    int n, i, flag = 0;
    // Take an integer input from the user
    scanf("%d", &n);
    // Check if the number is less than or equal to 1
    // Numbers 0 and 1 are not considered prime
    if (n <= 1) {
        printf("%d is not a prime number.\n", n);
        return 0;
    }
    // Loop from 2 to n/2 to check for factors
    // If n is divisible by any number in this range, it is not prime
    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            flag = 1; // A divisor is found, mark flag as 1
            break;    // Exit the loop early if a divisor is found
        }
    }
    // If flag is still 0, n is prime
    if (flag == 0)
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);
    return 0;
}
