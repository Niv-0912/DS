//  WAP to copy a linked list.
#include<stdio.h>
#include<stdlib.h>
struct link_list {
	int info;
	struct link_list *link;
};
struct link_list *first=NULL;
void insert_end_l1(int x){
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
struct link_list2 {
	int info2;
	struct link_list2 *link2;
};
struct link_list2 *first2=NULL;
void insert_end_l2(int x){
	struct link_list2 *new;
    new=(struct link_list2*)malloc(sizeof(struct link_list2));
        new->info2=x;
        new->link2=NULL;
    if(first2==NULL){
        first2=new;
        return;
    }

    else{
        struct link_list2 *temp=first2;
        while(temp->link2!=NULL){
            temp=temp->link2;
        }
        temp->link2=new;
    }
}
void check_link(){
    struct link_list *temp1=first;
	struct link_list2 *temp2=first2;
    int cek;
    while(temp1!=NULL&&temp2!=NULL){
    	if(temp1->info==temp2->info2){
    		cek=0;
		}   
		else{
			cek=1;
			break;
		}
        temp1=temp1->link;
        temp2=temp2->link2;
    }
    if(cek==0){
    	printf("Both link are same:\n");
	}
	else{
		printf("Both are not same:\n");
	}
    
}
void display(){
	struct link_list *temp;
	temp=first;
	while(temp!=NULL){
		printf("%d\t",temp->info);
		temp=temp->link;
	}
	printf("\n");
}
void main(){
	int choice,x,pos;
	while(1){
		printf("1. Insert 1st list\n");
		printf("2. Insert 2nd list\n");
		printf("3. Copy list\n");
        printf("4. Display\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter value to insert: ");
				scanf("%d",&x);
				insert_end_l1(x);
				break;
			case 2:
				printf("Enter value to insert: ");
				scanf("%d",&x);
				insert_end_l2(x);
				break;
			case 3:
				check_link();
				break;
			case 4:
				display();
			case 5:
				exit(0);
				break;
			default:
				printf("Invalid choice\n");
		}
	}
}
				
