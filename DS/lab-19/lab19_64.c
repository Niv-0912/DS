// 64. Write a menu driven program to implement following operations on the circular 
// linked list. 
// • Insert a node at the front of the list. 
// • Insert a node at the end of the list. 
// • Delete the first node of the list. 
// • Delete the last node of the list. 
// • Delete a node from specified position of the list. 
// • Display all nodes. 
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int info;
    struct Node *next;
};
struct Node *head = NULL;
void insert_front(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = data;
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}
void insert_end(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = data;
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
int delete_front(){
    if(head == NULL){
        printf("List is empty\n");
        return -1;
    }
    struct Node* temp = head;
    int data = temp->info;
    if(head->next == head){
        head = NULL;
    } else {
        struct Node* last = head;
        while(last->next != head){
            last = last->next;
        }
        head = head->next;
        last->next = head;
    }
    free(temp);
    return data;
}
int delete_end(){
    if(head == NULL){
        printf("List is empty\n");
        return -1;
    }
    struct Node* temp = head;
    int data;
    if(head->next == head){
        data = head->info;
        head = NULL;
    } else {
        while(temp->next->next != head){
            temp = temp->next;
        }
        data = temp->next->info;
        free(temp->next);
        temp->next = head;
    }
    return data;
}
int delete_position(int pos){
    if(head == NULL){
        printf("List is empty\n");
        return -1;
    }
    struct Node* temp = head;
    int data;
    if(pos == 1){
        data = delete_front();
        return data;
    }
    for(int i=1; i<pos-1; i++){
        temp = temp->next;
        if(temp == head){
            printf("Position out of range\n");
            return -1;
        }
    }
    struct Node* delNode = temp->next;
    data = delNode->info;
    temp->next = delNode->next;
    free(delNode);
    return data;
}
void display(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do{
        printf("%d ", temp->info);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
}
void main(){
    int a=1,choice;
    int num,a1,pos;
    while(a){
        printf("\nEnter 1 for insert at front\n");
        printf("Enter 2 for insert at end\n");
        printf("Enter 3 for delete from front\n");
        printf("Enter 4 for delete from end\n");
        printf("Enter 5 for delete from position\n");
        printf("Enter 6 for display\n");
        printf("Enter 7 to exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the number to insert at front: ");
                scanf("%d",&num);
                insert_front(num);
                break;
            case 2:
                printf("Enter the number to insert at end: ");
                scanf("%d",&num);
                insert_end(num);
                break;
            case 3:
                a1 = delete_front();
                if(a1 != -1) {
                    printf("Deleted from front: %d\n", a1);
                }
                break;
            case 4:
                a1 = delete_end();
                if(a1 != -1) {
                    printf("Deleted from end: %d\n", a1);
                }
                break;
            case 5:
                printf("Enter the position to delete: ");
                scanf("%d",&pos);
                a1 = delete_position(pos);
                if(a1 != -1) {
                    printf("Deleted from position %d: %d\n", pos, a1);
                }
                break;
            case 6:
                display();
                break;
            case 7:
                a = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}