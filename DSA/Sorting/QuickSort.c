#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[], int start, int stop) {
    for (int i = start; i <= stop; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int partition(int arr[], int low, int high) {
    printArray(arr, low, high);
    int pivot = arr[low];
    int start = low;
    int end = high;
    int k = high;
    for (int i = high; i > low; i--) {
        if (arr[i] >= pivot)
            swap(&arr[i], &arr[k--]);
    }
    swap(&arr[low], &arr[k]);
    return k;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int idx = partition(arr, low, high);
        quickSort(arr, low, idx - 1);
        quickSort(arr, idx + 1, high);
    }
}
int main() {
    int arr[] = {4, 3, 6, 9, 2, 4, 3, 1, 2, 1, 8, 9, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, 0, n - 1);
    return 0;
}