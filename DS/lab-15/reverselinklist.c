#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;

void insert_node(int x) {
	
    struct node *node = (struct node *)malloc(sizeof(struct node));
    
    node->info = x;
    node->link = NULL;

    if (first == NULL) {
        first = node;
    }
	else {
        struct node *temp = first;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = node;
    }
}

void reverse_list() {
    struct node *prev = NULL, *current = first, *next = NULL;
    
    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    
    first = prev;
    printf("List reversed successfully.\n");
}

void display() {
	
    struct node *temp = first;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d \t", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

void main() {
    int choice, x;
    while (1) {
        printf("1. Insert at end\n");
        printf("2. Reverse link list\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &x);
                insert_node(x);
                break;
            case 2:
                reverse_list();
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

