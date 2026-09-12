// Write a menu driven program to implement following operations on the singly 
// linked list.  
// • Insert a node at the front of the linked list. 
// • Insert a node at the end of the linked list. 
// • Insert a node by preserving the order of the data of the linked list. (Ordered 
// insertion) 
// • Display all nodes. 
// • Delete the first node of the linked list. 
// • Delete the last node of the linked list. 
// • Delete a node from specified position of the list. 
// • Count the no. of nodes in the linked list. 
#include<stdio.h>
#include<stdlib.h>
# define n 5
struct link_list {
	int info;
	int link;
};
struct link_list *first=NULL;
void insert(int x){
	struct link_list *node;
	node=(struct link_list*)malloc(sizeof(struct link_list));
	node->info=x;
	node->link=first;
	first=node;
}
void insert_end(int x){
	struct link_list *node,*temp;
	node=(struct link_list*)malloc(sizeof(struct link_list));
	node->info=x;
	node->link=NULL;
	if(first==NULL)
		first=node;
	else{
		temp=first;
		while(temp->link!=NULL)
			temp=temp->link;
		temp->link=node;
	}
}
void insert_order(int x){
	struct link_list *node,*temp,*prev;
	node=(struct link_list*)malloc(sizeof(struct link_list));
	node->info=x;
	if(first==NULL || first->info>=x){
		node->link=first;
		first=node;
	}
	else{
		temp=first;
		while(temp!=NULL && temp->info<x){
			prev=temp;
			temp=temp->link;
		}
		prev->link=node;
		node->link=temp;
	}
}
int delete_first(){
	struct link_list *temp;
	int x;
	if(first==NULL)
		return -1;
	else{
		temp=first;
		x=temp->info;
		first=first->link;
		free(temp);
		return x;
	}
}
int delete_last(){
	struct link_list *temp,*prev;
	int x;
	if(first==NULL)
		return -1;
	else if(first->link==NULL){
		x=first->info;
		free(first);
		first=NULL;
		return x;
	}
	else{
		temp=first;
		while(temp->link!=NULL){
			prev=temp;
			temp=temp->link;
		}
		x=temp->info;
		prev->link=NULL;
		free(temp);
		return x;
	}
}
int delete_pos(int pos){
	struct link_list *temp,*prev;
	int x,i;
	if(first==NULL)
		return -1;
	else if(pos==1){
		x=first->info;
		temp=first;
		first=first->link;
		free(temp);
		return x;
	}
	else{
		temp=first;
		for(i=1;i<pos && temp!=NULL;i++){
			prev=temp;
			temp=temp->link;
		}
		if(temp==NULL)
			return -1;
		else{
			x=temp->info;
			prev->link=temp->link;
			free(temp);
			return x;
		}
	}
}
int count(){
	struct link_list *temp;
	int c=0;
	temp=first;
	while(temp!=NULL){
		c++;
		temp=temp->link;
	}
	return c;
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
	int choice,x,pos;
	while(1){
		printf("1. Insert at front\n");
		printf("2. Insert at end\n");
		printf("3. Insert in order\n");
		printf("4. Display\n");
		printf("5. Delete first\n");
		printf("6. Delete last\n");
		printf("7. Delete at position\n");
		printf("8. Count nodes\n");
		printf("9. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter value to insert: ");
				scanf("%d",&x);
				insert(x);
				break;
			case 2:
				printf("Enter value to insert: ");
				scanf("%d",&x);
				insert_end(x);
				break;
			case 3:
				printf("Enter value to insert: ");
				scanf("%d",&x);
				insert_order(x);
				break;
			case 4:
				display();
				break;
			case 5:
				x=delete_first();
				if(x==-1)
					printf("List is empty\n");
				else
					printf("Deleted value: %d\n",x);
				break;
			case 6:
				x=delete_last();
				if(x==-1)
					printf("List is empty\n");
				else
					printf("Deleted value: %d\n",x);
				break;
			case 7:
				printf("Enter position to delete: ");
				scanf("%d",&pos);
				x=delete_pos(pos);
				if(x==-1)
					printf("Invalid position or list is empty\n");
				else
					printf("Deleted value: %d\n",x);
				break;
			case 8:
				x=count();
				printf("Number of nodes: %d\n",x);
				break;
			case 9:
				exit(0);
			default:
				printf("Invalid choice\n");
		}
	}
}