#include <stdio.h>
#include <limits.h>
int Midpoint_Crosssum(int A[], int low, int mid, int high, int *start, int *end) {
    int sum = 0, leftsum = INT_MIN, rightsum = INT_MIN;
    int leftIndex = mid, rightIndex = mid + 1;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > leftsum) {
            leftsum = sum;
            leftIndex = i;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += A[i];
        if (sum > rightsum) {
            rightsum = sum;
            rightIndex = i;
        }
    }
    *start = leftIndex;
    *end = rightIndex;
    return leftsum + rightsum;
}
int Left_Right_MaximumSubarray(int A[], int low, int high, int *start, int *end) {
    if (low == high) {
        *start = low;
        *end = high;
        return A[low];
    }
    int mid = (low + high) / 2;
    int leftStart, leftEnd, rightStart, rightEnd, crossStart, crossEnd;
    int leftsum = Left_Right_MaximumSubarray(A, low, mid, &leftStart, &leftEnd);
    int rightsum = Left_Right_MaximumSubarray(A, mid + 1, high, &rightStart, &rightEnd);
    int crosssum = Midpoint_Crosssum(A, low, mid, high, &crossStart, &crossEnd);
    if (leftsum >= rightsum && leftsum >= crosssum) {
        *start = leftStart;
        *end = leftEnd;
        return leftsum;
    } 
    else if (rightsum >= leftsum && rightsum >= crosssum) {
        *start = rightStart;
        *end = rightEnd;
        return rightsum;
    } 
    else {
        *start = crossStart;
        *end = crossEnd;
        return crosssum;
    }
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    int start, end;
    int maxSum = Left_Right_MaximumSubarray(A, 0, n - 1, &start, &end);
    printf("\nMaximum Subarray Sum: %d\n", maxSum);
    printf("Indices of Maximum Subarray: [%d, %d]\n", start, end);
    printf("Elements of Maximum Subarray: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}