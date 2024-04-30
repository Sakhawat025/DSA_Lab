#include<stdio.h>

int i,j,temp;

void Bubble_Sort(int *Arr,int n){
    for(i=0;i<n-1;++i){
         for(j=0;j<n-i-1;j++){
            if(Arr[j]>Arr[j+1]){
              temp=Arr[j];
              Arr[j]=Arr[j+1];
              Arr[j+1]=temp;
              }
            }
    }
    printf("\n");
    printf("Print The sort Array: ");
    for(i=0;i<n;++i){
        printf("%d ",Arr[i]);
    }

}

int main(){
    int n;
    printf("Enter sizeof Array: ");
    scanf("%d",&n);
    int Arr[n];
    for (i = 0; i < n; ++i) {
        scanf("%d", &Arr[i]);
    }

    Bubble_Sort(Arr,n);

    return 0;
}