//Circular Queue using link list
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int count=0;
struct Node {
    int data;
    int priority;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueue(int a,int priority){
    count++;
    if(count > MAX){
        count--;
        printf("Queue Overflow\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = a;
    newNode->priority = priority;
    newNode->next = NULL;
    if(front == NULL){
        front = rear = newNode;
        rear->next = front; 
    } 
    if(priority < front->priority){
        newNode->next = front;
        front = newNode;
        rear->next = front; 
    } else if(priority >= rear->priority){
        rear->next = newNode;
        rear = newNode;
        rear->next = front; 
    } else {
        struct Node* temp = front;
        while(temp->next != rear && temp->next->priority <= priority){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if(temp == rear){
            rear = newNode;
        }
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
    int num,a1,priority;
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
                printf("Enter the priority: ");
                scanf("%d",&priority);
                enqueue(num,priority);
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