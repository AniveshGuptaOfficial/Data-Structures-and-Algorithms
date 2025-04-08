#include <stdio.h>
int rls(int array[], int size, int ele) {
    if (size == 0)
    return -1;
    if (array[size-1] == ele)
    return size-1;
    return rls(array, size-1, ele);
}
int main(void) {
    int array[] = {1, 4, 7, 9, 16, 56, 70};
    int n = 7;
    int ele = 9;
    int found_index = rls(array, n, ele);
    if(found_index == -1) {
        printf("Element not found in the array ");
    }
    else {
        printf("Element found at index : %d", found_index);
    }
    return 0;
}