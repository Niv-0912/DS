// 71. WAP to check whether the given two trees are same or not. 

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
struct Node2{
    int info;
    struct Node2 *lptr;
    struct Node2 *rptr;
};
struct Node2 *root2 = NULL;

void insert_node2(int data){
    struct Node2* newNode = (struct Node2*)malloc(sizeof(struct Node2));
    if(root2==NULL){
        newNode->info = data;
        newNode->lptr = NULL;
        newNode->rptr = NULL;
        root2 = newNode;
    } 
    else {
        struct Node2* current = root2;
        struct Node2* parent = NULL;
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
int compare_trees(struct Node* root1, struct Node2* root2){
    if(root1 == NULL && root2 == NULL){
        return 1;
    }
    if(root1 != NULL && root2 != NULL){
        return (root1->info == root2->info) && compare_trees(root1->lptr, root2->lptr) && compare_trees(root1->rptr, root2->rptr);
    }
    return 0;
}

void main(){
    int a=1,choice;
    int num,a1;
    while(a){
        printf("\nEnter 1 for tree 1 insert\n");
        printf("Enter 2 for tree 2 insert\n");
        printf("Enter 3 to compare trees\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d",&num);
                insert_node(num);
                break;
            case 2:
                printf("Enter the number to insert: ");
                scanf("%d",&num);
                insert_node2(num);
                break;
            case 3:
                if(compare_trees(root, root2)){
                    printf("The trees are the same\n");
                } else {
                    printf("The trees are not the same\n");
                }
                break;
            case 4:
                a = 0;
        }
    }
}