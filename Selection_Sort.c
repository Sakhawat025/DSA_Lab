#include<stdio.h>

int i,j,IndxMin,temp;

void Seletion_Sort(int *Arr,int n){
     for (i = 0; i < (n - 1); i++) {
            IndxMin = i;
        for (j = i + 1; j < n; j++) {
                if (Arr[IndxMin] > Arr[j])
                IndxMin= j;
      }
     if (IndxMin!= i) {
         temp = Arr[i];
         Arr[i] = Arr[IndxMin];
         Arr[IndxMin] = temp;
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

    Seletion_Sort(Arr,n);

    return 0;
}