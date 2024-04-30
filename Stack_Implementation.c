#include<stdio.h>
#include<stdlib.h>

#define Max_Size 3

int stack[Max_Size];
int top=-1;

void push(int value){
    if(top==Max_Size-1){
        printf("Stack OverFlow!\n");
        return;
    }
    stack[++top]=value;
}

void pop(){
    if(top==-1){
        printf("Stack undeflow!!\n");
        exit(1);
    }
    top--;
}

void isEmpty(){
    if(top==-1){
        printf("Stack is Empty!\n");
    }else{
        printf("Stack is Not Empty!\n");
    }
}

void isFull() {
    if (top == Max_Size - 1) {
        printf("Stack is full!\n");
    } else {
        printf("Stack is not full!\n");
    }
}

void display(){
    if(top==-1){
        printf("Stack is Empty!\n");
        return;
    }
    printf("Stack elements: ");
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(){
    int choice,value;
    while(1){
        printf("\nChoice One: ");
        printf("\n1.Push\n");
        printf("2.pop\n");
        printf("3.isEmpty?\n");
        printf("4.isFULL\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter Your choice: ");
        scanf("%d",&choice);
        
        switch (choice){
            case 1:
            printf("Enter value to push: ");
            scanf("%d",&value);
            push(value);
            break;
            case 2:
            pop();
            break;
            case 3:
            isEmpty();
            break;
            case 4:
            isFull();
            break;
            case 5:
            display();
            break;;
            case 6:
            printf("Exiting program.\n");
            exit(0);
            default :
            printf("Wrong choice!!\nTry Agian\n");
        }
    }
    return 0;
}