#include<stdio.h>

int i,j,temp;

void Insertion_Sort(int *Arr,int n){
     for(i=1; i<n; i++){
        temp=Arr[i];
        j=i-1;
        while(j>=0 && Arr[j]> temp){
            Arr[j+1]=Arr[j];
            j--;

        }
        Arr[j+1]=temp;
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

    Insertion_Sort(Arr,n);

    return 0;
}