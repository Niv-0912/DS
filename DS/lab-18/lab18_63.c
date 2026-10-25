//  WAP to implement Simple Queue,  using singly linked list.

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int count = 0;
struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueue(int a){
    count++;
    if(count > MAX){
        printf("Queue Overflow\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = a;
    newNode->next = NULL;

    if(rear == NULL){
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}   
int dequeue(){
    if(front == NULL){
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node* temp = front;
    int a = temp->data;
    front = front->next;
    if(front == NULL) {
        rear = NULL; 
    }
    free(temp);
    count--;
    return a;
}
void display(){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
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
                if(a1 != -1) {
                    printf("Dequeued: %d\n", a1);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                a = 0; 
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
