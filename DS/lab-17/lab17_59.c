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
int count=0;
void count_nodes(){
	struct link_list *temp=first;
	while(temp!=NULL){
		count++;
		temp=temp->link;
	}	
}
void switchKth(int k){
	int i=0;
	if(k>count){
		printf("ENter vaild number:");
		return;
	}
	if(2*k-1==count){
		printf("it is middle node it can't swap with its self: ");
	}
	struct link_list *x_prev=NULL,*x=first;
	for(i=1;i<k;i++){
		x_prev=x;
		x=x->link;
	}
	struct link_list *y_prev=NULL,*y=first;
	for(i=1;i<count-k+1;i++){
		y_prev=y;
		y=y->link;
	}
	if(x_prev){
		x_prev->link=y;
	}
	else{
		first=y;
	}
	if(y_prev){
		y_prev->link=x;
	}
	else{
		first=x;
	}
	struct link_list *temp=x->link;
	x->link=y->link;
	y->link=temp;
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
            	count_nodes();
            	printf("ENter Kth position:");
            	scanf("%d",&k);
                switchKth(k);
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
