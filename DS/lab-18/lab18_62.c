// WAP to implement Stack using singly linked list. 
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int count = 0;
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;
void push(int a){
    count++;
    if(count > MAX){
        printf("Stack Overflow\n");
        return;
    }
    if(top == NULL){
        top = (struct Node*)malloc(sizeof(struct Node));
        top->data = a;
        top->next = NULL;
    }
    else{
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = a;
        temp->next = top;
        top = temp;
    }
}
int pop(){
    if(top == NULL){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        struct Node* temp = top;
        int a = temp->data;
        top = top->next;
        free(temp);
        count--;
        return a;
    }
}
void display(){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
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
        printf("\nEnter 1 for push\n");
        printf("Enter 2 for pop\n");
        printf("Enter 3 for display\n");
        printf("Enter 4 for Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                
                printf("\nEnter number you want to push:");
                scanf("%d",&num);
                push(num);
                break;
            case 2:
                a1=pop();
                printf("\npoped number is %d",a1);
                break;
            case 3:
                display();
                break;
            case 4:
                a=0;
                break;
            default:
                printf("Enter vaild choice:");
                break;
        }   
    }
}
