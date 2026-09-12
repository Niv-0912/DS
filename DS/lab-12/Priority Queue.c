#include <stdio.h>
#define N 5
int f=-1;
int r=-1;
struct  Priority_Queue{
	int data;
	int priority;
};
struct Priority_Queue pq[N];
void enqueue(int x,int y){
	if(f==-1){
		printf("overflow");
		return;
	
	}
	pq[++r].data=x;
	pq[++r].priority=y;
	if(f==-1){
		f=0;
	}
}
int dequeue(){
	if(r==-1&&f==-1){
		printf("Underflow");
	}
	else{
		if(f==r){
		printf("Deleted data:%d || Priority is : %d",pq[r].data,pq[r].priority);
		r=f=-1;
	}
	else{
		int max_index = f,i;
		for(i=f+1;i<r;i++){
			if(pq[i].priority>pq[max_index].priority){
				max_index=i;
			}
		}
		printf("Deleted data:%d || Priority is : %d",pq[max_index].data,pq[max_index].priority);
		for(i=max_index;i<r;i++){
			pq[i]=pq[i+1];
		}
		r--;
	}	
}
	
	
	
}
void display(){
	int i;
	if(f==-1){
		printf("Underflow");
		return;
	}
	printf("\n priority queue is:"); 
	for(i=f;i<r;i++){
		printf("{%d  %d}  ",pq[i].data,pq[i].priority);
	}
}
void main(){
	int choice,num,x,y,i=0,pop,loop=0;
	
	while(1){
		printf("\nEnter 1 for Enqueue: \n Enter 2. for  dequeue: \n Enter 3 for . display : \n ENter 4 exit :");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			if(i<N){
				printf("Enter your data:");
				scanf("%d",&x);
				printf("Enter your priority");
				scanf("%d",&y);
				enqueue(x,y);
				break;
			}
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			return;	
		default:
			printf("Enter vaild choice ");
			break;
		}
	}
	
} 
