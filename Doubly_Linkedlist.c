#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next,*prev;
};

struct node *head = NULL;

void insertStart(int item) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = item;
    ptr->next = head;
    ptr->prev = NULL;
    if (head != NULL)
        head->prev = ptr;
    head = ptr;
    printf("\nNode inserted at the Start.");
}

void insertEnd(int item) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    ptr->data = item;
    ptr->next = NULL;
    if (head == NULL) {
        ptr->prev = NULL;
        head = ptr;
        printf("\nNode inserted at the end");
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = ptr;
    ptr->prev = temp;
    printf("\nNode inserted at the end");
}

void insertPosition(int item, int index) {
    if (index == 1) {
        insertStart(item);
        return;
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    int i = 1;
    while (i < index - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("\nIndex Out");
        return;
    }
    ptr->data = item;
    ptr->next = temp->next;
    ptr->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = ptr;
    temp->next = ptr;
    printf("\nNode inserted at index %d", index);
}

void deleteStart() {
    if (head == NULL) {
        printf("\nList is empty");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    printf("\nNode deleted from the Start.");
}

void deleteEnd() {
    if (head == NULL) {
        printf("\nList is empty");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp == head) {
        head = NULL;
        free(temp);
    } else {
        temp->prev->next = NULL;
        free(temp);
    }
    printf("\nNode deleted from the end");
}

void deletePosition(int index) {
    if (head == NULL) {
        printf("\nList is empty");
        return;
    }
    if (index == 1) {
        deleteStart(index);
        return;
    }
    struct node *temp = head;
    int i = 1;
    while (i < index && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("\nIndex out");
        return;
    }
    if (temp->next == NULL) {
        temp->prev->next = NULL;
        free(temp);
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    printf("\nNode deleted from index %d", index);
}

void reversdisplay(){
    struct node*temp;
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    printf("Reverse data values : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

void display() {
    struct node *ptr = head;
    printf("\nPrinting values: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    int choice,item,index;
    while(1){
        printf("choice Number: ");
        printf("\n1. Insert in beginning\n");
        printf("2. Insert in end\n");
        printf("3. Insert in Position\n");
        printf("4. delete in start\n");
        printf("5. delete in end\n");
        printf("6. delete in Position\n");
        printf("7.reverse Order\n");
        printf("8. Display\n");
        printf("Exit program\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            scanf("%d",&item);
            insertStart(item);
            break;
        case 2:
            scanf("%d",&item);
            insertEnd(item);
            break;
        case 3:
            printf("Enter the Item: ");
            scanf("%d",&item);
            printf("Enter the Position: ");
            scanf("%d",&index);
            insertPosition(item,index);
            break;
        case 4:
            deleteStart();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            printf("Enter the Position: ");
            scanf("%d",&index);
            deletePosition(index);
            break;
            case 7:
            reversdisplay(head);
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            printf("Please enter valid choice!");
        }
    }
}