#include<stdio.h>
#include<stdlib.h>

#define Max_Size 10

struct node{
    int data;
    struct node*next;
};

struct node*head=NULL;

void insertF(struct node**head,int data){
    struct node*ptr=malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Memory allocate faild\n");
    }
    ptr->data=data;
    ptr->next=*head;
    *head=ptr;
}

void insertEnd(struct node*head,int data){
    struct node* ptr,*temp;
    ptr=head;
    temp=malloc(sizeof(struct node));
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->data=data;
    temp->next=NULL;
}

void addIndex(struct node*head,int pos,int data){
    struct node*ptr,*ptr2;
    ptr=head;
    ptr2=malloc(sizeof(struct node));
    ptr2->data=data;
    ptr2->next=NULL;
    pos--;
    while(pos!=1){
        ptr=ptr->next;
        pos--;
    }
    ptr2->next=ptr->next;
    ptr->next=ptr2;
}

void del_FirstData(struct node**head){
    if(head==NULL){
        printf("The node is empty\n");
    }
    struct node*ptr=*head;
    *head=(*head)->next;
    free(ptr);
    ptr=NULL;

}

void del_Last(struct node*head){
    if(head==NULL){
        printf("The node is empty!\n");
    } else if(head->next==NULL){
        free(head);
        head=NULL;
    }else{
        struct node*ptr2,*ptr3;
        ptr2=head;
        ptr3=head;
        while(ptr2->next!=NULL){
            ptr3=ptr2;
            ptr2=ptr2->next;
        }
        ptr3->next=NULL;
        free(ptr2);
        ptr2=NULL;
    }
}

void del_pos(struct node*head,int pos){
    struct node*current,*privious;
    current=head;
    privious=head;
    if(head==NULL){
        printf("There are no Node!\n");
    }else if(pos==1){
        head=current->next;
        free(current);
        current=NULL;
    } else{
        while(pos!=1){
            privious=current;
            current=current->next;
            pos--;
        }
        privious->next=current->next;
        free(current);
        current=NULL;
    }
}

void reverse(struct Node* head) {
    struct node*ptr;
    ptr=head;
    int i=Max_Size-1;
    int A[Max_Size];
    while(ptr!=NULL){
        A[i]=ptr->data;
        i--;
        ptr=ptr->next;
    }
    for(int j=Max_Size-1;j>=0;j--){
        printf("%d ",A[j]);
    }
    printf("\n");
}



void displayL(struct node*head){
    struct node*temp=head;
    if(temp==NULL){
        printf("NUll\n");
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int choice,data,pos;
    while(1){
        printf("\n1.insertF.\n");
        printf("2.endInsert.\n");
        printf("3.addIndex.\n");
        printf("4.Delete First.\n");
        printf("5.Delete Last.\n");
        printf("6.Delete Index.\n");
        printf("7.Reverse Data.\n");
        printf("8.display: \n");
        printf("9.Exit\n");
        printf("Choice one: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter data: ");
            scanf("%d",&data);
            insertF(&head,data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d",&data);
            insertEnd(head,data);
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d",&pos);
            printf("Enter data: ");
            scanf("%d",&data);
            addIndex(head,pos,data);
            break;
        case 4:
            del_FirstData(&head);
            break;
        case 5:
            del_Last(head);
            break;
        case 6:
            printf("Enter Position: ");
            scanf("%d",&pos);
            del_pos(head,pos);
            break;
        case 7:
            reverse_data(head);
            break;
        case 8:
            displayL(head);
            break;
        case 9:
            exit(0);
        default :
            printf("Wrong choice!!\n");
        }
    }
}
