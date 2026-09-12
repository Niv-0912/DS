#include<stdio.h>
void main(){
	int a[100],n,i,*p;
	printf("Enter value of n:");
	scanf("%d",&n);
	p=a;
	for(i=0;i<n;i++){
		printf("Enter %d number:",i+1);
		scanf("%d",p+i);
	}
	i=0;
	int max=*(p+i);
	for(i=1;i<n;i++){
		if(max<*(p+i)){
			max=*(p+i);
		}
	}
	printf("maximum number of array is: %d",max);
	
}
