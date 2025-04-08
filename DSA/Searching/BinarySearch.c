#include <stdio.h>
int rbs(char array[], int f, int l, char ele){
    if (l >= f){
        int middle = (f + l)/2;
        if (array[middle] == ele)
        return middle;
        if (array[middle] > ele)
        return rbs(array, f, middle-1, ele);
        return rbs(array, middle+1, l, ele);
    }
    return -1;
}
int main(void){
    char array[] = {'g','a','v','f','d'}; //{1, 4, 7, 9, 16, 56, 70};
    int n = sizeof(array)/sizeof(array[0]);
    char ele = 'v';
    int found_index = rbs(array, 0, n-1, ele);
    if(found_index == -1 ) {
        printf("Element not found in the array ");
    }
    else {
        printf("Element found at index : %d",found_index);
    }
    return 0;
}