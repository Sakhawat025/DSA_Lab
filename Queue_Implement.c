#include<stdio.h>
#include<stdlib.h>

#define Max_Size 5
int queue[Max_Size];
int front=-1,rear=-1;

void enqueue(int value){
    if(rear==Max_Size-1){
        printf("Queue overFlow!\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    queue[++rear]=value;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow!\n");
        exit(1);
    }
    printf("Dequeued element: %d\n", queue[front++]);
    if (front > rear)
        front = rear = -1;
}

void isEmpty() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue is not empty!\n");
    }
}


void isFull() {
    if (rear == Max_Size - 1) {
        printf("Queue is full!\n");
    } else {
        printf("Queue is not full!\n");
    }
}
void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\nQueue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Queue is Empty\n");
        printf("5. Queue is Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                isFull();
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}