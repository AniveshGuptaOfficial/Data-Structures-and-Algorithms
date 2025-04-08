#include<stdio.h>
int rbs(int a[],int first,int last,int find){
    if(last>=find){
        int mid = (last+first)/2;
        if(a[mid]==find){
            return mid;
        }
        if(a[mid]>find){
            return rbs(a,first,mid-1,find);
        }
        return rbs(a,mid+1,last,find);
    }
    return -1;
}
int main(){
    int a[] = {1, 4, 7, 9, 16, 56, 70};
    int n = sizeof(a)/sizeof(a[0]);
    int ele = 8;
    int xyz = rbs(a, 0, n-1, ele);
    if(xyz == -1 ) {
        printf("Element not found in the array ");
    }
    else {
        printf("Element found at index : %d",xyz);
    }
    return 0;
}