#include <stdio.h>
#include <stdlib.h>
struct link_list {
    int info;
    struct link_list *link;
};
struct link_list *first=NULL;

void insert_end(int x){
	struct link_list *new;
    new=(struct link_list*)malloc(sizeof(struct link_list));
        new->info=x;
        new->link=NULL;
    if(first==NULL){
        first=new;
        return;
    }

    else{
        struct link_list *temp=first;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=new;
    }
}

void remove_duplicates(){
    struct link_list *current=first,*next_node;
    if(first==NULL){
        return;
    }
    while(current->link!=NULL){
        if(current->info==current->link->info){
            current->link=current->link->link;
        }
        else{
            current=current->link;
        }
    }
}
void display(){
    struct link_list *temp;
    temp=first;
    while(temp!=NULL){
        printf("%d \t",temp->info);
        temp=temp->link;
    }
    printf("\n");
}

void main(){
    int choice,x;
    while(1){
        printf("1. Insert node\n");
        printf("2. Remove duplicates\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d",&x);
                insert_end(x);
                break;
            case 2:
                remove_duplicates();
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
