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
struct link_list *create_node(int x){
	struct link_list *new;
	new=(struct link_list*)malloc(sizeof(struct link_list));
	new->info= x;
	new->link=NULL;
	return new;
}

int GCD_node(int a,int b){
	if(b==0){
		return a;
	}
	return GCD_node(b,a%b);
}
void addGCD(){
	struct link_list *temp=first,*node=NULL;
	int gcd=0;
	while(temp->link!=NULL){
		gcd=GCD_node(temp->info,temp->link->info);
		node=create_node(gcd);
		node->link=temp->link;
		temp->link=node;
		temp=node->link;
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
            	addGCD();
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
