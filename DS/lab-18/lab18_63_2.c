//Circular Queue using link list
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueue(int a){
    
    if(rear->next == front){
        printf("Queue Overflow\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = a;
    newNode->next = NULL;
    if(rear == NULL){
        front = rear = newNode;
        rear->next = front; 
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; 
    }
}
int dequeue(){
    if(front == NULL){
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node* temp = front;
    int a = temp->data;
    if(front == rear){
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; 
    }
    free(temp);
    return a;
}
void display(){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != front);
    printf("\n");
}
void main(){
    int a=1,choice;
    int num,a1;
    while(a){
        printf("\nEnter 1 for enqueue\n");
        printf("Enter 2 for dequeue\n");
        printf("Enter 3 for display\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the number to enqueue: ");
                scanf("%d",&num);
                enqueue(num);
                break;
            case 2:
                a1 = dequeue();
                if(a1 != -1)
                    printf("Dequeued: %d\n", a1);
                break;
            case 3:
                display();
                break;
            case 4:
                a = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}