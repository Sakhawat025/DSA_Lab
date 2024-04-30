#include<stdio.h>
int main(){
    int n,i,Key,count=0;
    printf("Enter The Size of Array: ");
    scanf("%d",&n);
    int Arr[n];

    for(i=0;i<n;++i){
        scanf("%d",&Arr[i]);
    }
    printf("Enter Key Value: ");
    scanf("%d",&Key);
    
    for(i=0;i<n;++i){
        if(Arr[i]==Key){
            printf("The key value position %d \n",i);
            count++;
        }
    }
    if(count==0){
        printf("Invilad!\n");
    }

    return 0;
}