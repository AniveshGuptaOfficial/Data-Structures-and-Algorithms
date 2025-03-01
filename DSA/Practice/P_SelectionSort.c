#include<stdio.h>
void xyz(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+i;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp = a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
}
int main(){
    int a[] = {2,6,1,3,0,7};
    int n = sizeof(a)/sizeof(a[0]);
    xyz(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}