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
void swap_2_node(){
	struct link_list *a=first,*b=first->link,*prev=NULL,*temp=first;
	while(temp!=NULL&&temp->link!=NULL){
		 b = a->link;
		a->link=b->link;
		b->link=a;
		
		if(prev==NULL){
			temp=b;
		}
		else{
			prev->link=b;
		}
		prev=a;
		temp=a->link;
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
    int k;
    while(1){
        printf("1. Insert node\n");
        printf("2. add GCD\n");
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
            	swap_2_node();
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
