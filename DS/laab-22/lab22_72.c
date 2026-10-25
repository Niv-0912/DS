// 72. WAP to find the smallest and largest elements in the Binary Search Tree. 
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
int find_smallest(struct Node* root){
    if(root == NULL){
        printf("Tree is empty\n");
        return -1;
    }
    struct Node* current = root;
    while(current->lptr != NULL){
        current = current->lptr;
    }
    return current->info;
}
int find_largest(struct Node* root){
    if(root == NULL){
        printf("Tree is empty\n");
        return -1;
    }
    struct Node* current = root;
    while(current->rptr != NULL){
        current = current->rptr;
    }
    return current->info;
}
void display_inorder(struct Node* root){
    if(root != NULL){
        display_inorder(root->lptr);
        printf("%d ", root->info);
        display_inorder(root->rptr);
    }
}
void main(){
    int a=1,choice;
    int num,a1;
    while(a){
        printf("\nEnter 1 for insert\n");
        printf("Enter 2 for find smallest\n");
        printf("Enter 3 for find largest\n");
        printf("Enter 4 for inorder display\n");
        printf("Enter 5 to exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d",&num);
                insert_node(num);
                break;
            case 2:
                a1 = find_smallest(root);
                if(a1 != -1){
                    printf("Smallest element: %d\n", a1);
                }
                break;
            case 3:
                a1 = find_largest(root);
                if(a1 != -1){
                    printf("Largest element: %d\n", a1);
                }
                break;
            case 4:
                display_inorder(root);
                printf("\n");
                break;
            case 5:
                a = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}