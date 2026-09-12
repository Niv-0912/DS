#include<stdio.h>
#define N 5

int F = -1;
int R = -1;

int DEQ[N];

void insert_REAR(int y){
    if(R == N-1){
        printf("\nQueue Overflow.");
        return;
    }
    R++;
    DEQ[R] = y;
    if(F == -1)
        F = 0;
}

int delete_FRONT(){
    if(F==-1){
        printf("\nQueue Underflow.");
        return -1;
    }
    else{
        int y = DEQ[F];
        if(F==R)
            F = R = -1;
        else
            F++;
        return y;
    }
}
void insert_FRONT(int y){
    if(F==0){
        printf("\nDouble Ended Queue Overflow.\n");
        return;
    }
    else{
        if(F==-1)
            F = R = 0;
        else
            F--;
    }
    DEQ[F] = y;
}
int delete_REAR(){
    if(R==-1){
        printf("\nDouble Ended Queue Underflow.\n");
        return -1;
    }
    else{
        int y = DEQ[R];
        if(F==R)
            F = R = -1;
        else
            R--;
        return y;
    }
}

void display(){
	int i;
    if(F==-1){
        printf("\nDouble Ended Queue Underflow.\n");
        return;
    }
    for(i=F; i<=R; i++){
        printf("%d\t",DEQ[i]);
    }
}

void main(){
    int choice,num,arr[N],i=0,pop,loop=0;
	
	while(1){
		printf("\nEnter 1 for insert_REAR:\n Enter 2. for  insert_FRONT:\n Enter 3. for delete_REAR :\n ENter 4 delete_FRont :\n ENter 5 display :\n Enter 6 for exit :");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			if(i<N){
				printf("Enter your number:");
				scanf("%d",&arr[i]);
				insert_REAR(arr[i]);
				i++;
				break;
			}
			else{
				printf("Cant enter more numbers: ");
				break;
			}
			
		case 2:
			if(i<N){
				printf("Enter your number:");
				scanf("%d",&arr[i]);
				insert_FRONT(arr[i]);
				i++;
				break;
			}
			else{
				printf("\nCant enter more numbers: ");
				break;
			}
		case 3:
			pop=delete_REAR();
			printf("\n Dequeue number is: %d",pop);
			break;
		case 4:
			pop=delete_FRONT();
			printf("\nDequeue number is: %d ",pop);
			break;
		case 5: 
			display();
			break;
		case 6:
			return;
		default:
			printf("\nEnter vaild choice ");
			break;
		}
	}
}

