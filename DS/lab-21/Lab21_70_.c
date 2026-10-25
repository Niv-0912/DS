// 70. Write a menu driven program to implement Binary Search Tree (BST) & perform 
// following operations:  
// • Insert a node 
// • Delete a node 
// • Search a node 
// • Preorder Traversal 
// • Postorder Traversal 
// • Inorder Traversal 
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int info;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node *root = NULL;
void insert_node(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(root==NULL){
        newNode->info = data;
        newNode->lptr = NULL;
        newNode->rptr = NULL;
        root = newNode;
    } 
    else {
        struct Node* current = root;
        struct Node* parent = NULL;
        while(current != NULL){
            
            parent = current;
            if(data < current->info){
                current = current->lptr;
            } else {
                current = current->rptr;
            }
        }
        newNode->info = data;
        newNode->lptr = NULL;
        newNode->rptr = NULL;
        if(data < parent->info){
            parent->lptr = newNode;
        } else {
            parent->rptr = newNode;
        }
    }
}

void display_inorder(struct Node* root){
    if(root != NULL){
        display_inorder(root->lptr);
        printf("%d ", root->info);
        display_inorder(root->rptr);
    }
}

void display_preorder(struct Node* root){
    if(root != NULL){
        printf("%d ", root->info);
        display_preorder(root->lptr);
        display_preorder(root->rptr);
    }
}

void display_postorder(struct Node* root){
    if(root != NULL){
        display_postorder(root->lptr);
        display_postorder(root->rptr);
        printf("%d ", root->info);
    }
}

int delete_node(int key){
    struct Node* current = root;
    struct Node* parent = NULL;
    while(current != NULL && current->info != key &&key != current->info){
        parent = current;
        if(key < current->info){
            current = current->lptr;
        } else {
            current = current->rptr;
        }
    }
    if(current == NULL){
        printf("Node not found\n");
        return -1;
    }
    else{
        free(current);
        if(parent == NULL){
            root = NULL;
        } else if(parent->lptr == current){
            parent->lptr = NULL;
        } else {
            parent->rptr = NULL;
        }
    } 
    return 0;
}

int search_node(int key){
    struct Node* current = root;
    while(current != NULL && current->info != key&& key == current->info){
        if(key < current->info){
            current = current->lptr;
        } else {
            current = current->rptr;
        }
    }
    if(current == NULL){
        printf("Node not found\n");
        return -1;
    } else {
        printf("Node found: %d\n", current->info);
        return 0;
    }
    
}

void main(){
    int a=1,choice;
    int num,a1;
    while(a){
        printf("\nEnter 1 for insert\n");
        printf("Enter 2 for delete\n");
        printf("Enter 3 for search\n");
        printf("Enter 4 for inorder display\n");
        printf("Enter 5 for preorder display\n");
        printf("Enter 6 for postorder display\n");
        printf("Enter 7 to exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d",&num);
                insert_node(num);
                break;
            case 2:
                printf("Enter the number to delete: ");
                scanf("%d",&num);
                delete_node(num);
                break;
            case 3:
                printf("Enter the number to search: ");
                scanf("%d",&num);
                search_node(num);
                break;
            case 4:
                display_inorder(root);
                break;
            case 5:
                display_preorder(root);
                break;
            case 6:
                display_postorder(root);
                break;
            case 7:
                a = 0;
        }
    }
}