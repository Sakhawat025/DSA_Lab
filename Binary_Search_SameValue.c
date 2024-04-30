#include<stdio.h>
int main()
{
    int A[]={2,5,5,8,9,11,12,17,50,77,77};
    int n=10;
    int i,Target=-1,Mid,low=0,High=n-1,key;

    printf("Enter search key: ");
    scanf("%d",&key);
    for(i=0;i<n;++i){
        Mid=(low+High)/2;
        if(key==A[Mid]){
            Target=Mid;
            break;
        }
        if(key>A[Mid]){
            low=Mid+1;
        }
        else {
            High=Mid-1;
        }
    }
    while(A[Mid]==key){
        Mid--;
    }
    printf("First Searching Index %d",Target);

    if(High<low){
        printf("The Value Index is Not Found!");
    }

    return;
}