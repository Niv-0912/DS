#include <stdio.h>
#include <stdlib.h> 

struct node { 
    int info; 
    struct node *link; 
}; 

struct node *first = NULL; 

void insert_node(int x) { 
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
} 

void removeDuplicate() { 
    struct node *temp; 
    struct node *save = first; 

    if (save == NULL) { 
        return; 
    } 
    
    while(save != NULL){
    	
    	temp = save;
    	
    	while(temp->link != NULL){
    		
    		if(save->info == temp->link->info){
    			temp->link = temp->link->link;
			}
			else{
				temp = temp->link;
			}
    		
		}
		
		save = save->link;
    	
	}
} 

void display() { 

    struct node *temp; 
    temp = first; 
    while (temp != NULL) { 
        printf("%d \t", temp->info); 
        temp = temp->link; 
    } 
    printf("\n"); 
} 

void main() { 

    insert_node(50); 
    insert_node(20); 
    insert_node(20); 
    insert_node(30); 
    insert_node(40); 
    insert_node(40); 
    insert_node(50); 
    insert_node(60); 
    
    printf("Original List:\n");
    display(); 
    
    removeDuplicate();
    
    printf("After Removing Duplicates:\n");
    display();

    
}

