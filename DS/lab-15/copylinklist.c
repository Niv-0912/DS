#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;


void insert(int x) {
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->info = x;
    node->link = NULL;

    if (first == NULL) {
        first = node;
    } else {
        struct node *temp = first;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = node; 
    }
}


void copy() {
    struct node *temp = first;
    struct node *new_first = NULL;
    struct node *new_last = NULL;

    if (temp == NULL) {
        printf("Original list is empty.\n");
        return;
    }

    while (temp != NULL) {
        struct node *new_node = (struct node*)malloc(sizeof(struct node));
        new_node->info = temp->info;
        new_node->link = NULL;

        if (new_first == NULL) {
            new_first = new_node;
            new_last = new_node;
        } else {
            new_last->link = new_node; 
            new_last = new_node;       
        }
        temp = temp->link;
    }

    
    printf("Copied list: ");
    temp = new_first;
    while (temp != NULL) {
        printf("%d \t", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

void display() {
    struct node *temp = first;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Original list: ");
    while (temp != NULL) {
        printf("%d \t", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

 void main() { 
    int choice, x;
    while (1) {
        printf("\n1. Insert at end\n");
        printf("2. Copy list\n");
        printf("3. Display original list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &x);
                insert(x);
                break;
            case 2:
                copy();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
   
}

