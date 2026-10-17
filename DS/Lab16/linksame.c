#include <stdio.h>
#include <stdlib.h> 

struct node { 
    int info; 
    struct node *link; 
}; 

struct node *first = NULL; 
struct node *first1 = NULL;

struct node* insert_node(struct node *first,int x) { 
    struct node *node; 
    if (first == NULL) { 
        node = (struct node*)malloc(sizeof(struct node)); 
        node->info = x; 
        node->link = NULL; 
        first = node; 
    } else { 
        struct node *temp = first; 
        while (temp->link != NULL) { 
            temp = temp->link; 
        } 
        node = (struct node*)malloc(sizeof(struct node)); 
        node->info = x; 
        temp->link = node; 
        node->link = NULL; 
    } 
    return first;
}


int isSame(struct node *first,struct node *first1){
	struct node *temp= first;
	struct node *temp1= first1;
	
	while(temp != NULL && temp1 != NULL){
		
		if(temp->info  != temp1->info){
			return 0;
		}
		
		temp = temp->link;
		temp1 = temp1->link;
	}
	if(temp==NULL && temp1==NULL){
		return 1;
	}
		
}

void main(){
	

	
	first = insert_node(first,10);
	first = insert_node(first,20);
	first = insert_node(first,30);
	
	first1 = insert_node(first1,10);
	first1 = insert_node(first1,20);
	first1 = insert_node(first1,30);

	if(isSame(first,first1)){
		printf("Same");
	}
	else{
		printf("Not same");
	}
		
}
