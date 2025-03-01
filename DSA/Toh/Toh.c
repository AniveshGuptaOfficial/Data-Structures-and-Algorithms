#include<stdio.h>
void Toh(int n,char source,char helper,char destination){
    if (n==1){
        printf("Move disk %d from %c to %c\n",n,source,destination);
    }
    else{
        Toh(n-1,source,destination,helper);
        printf("Move disk %d from %c to %c\n",n,source,destination);
        Toh(n-1,helper,source,destination);
    }
}
int main(){
    int n=3;
    char source='S';
    char helper='H';
    char destination='D';
    Toh(n,source,helper,destination);
    return 0;
}