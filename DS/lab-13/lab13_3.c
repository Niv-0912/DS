#include<stdio.h>
void main(){
	int a[100],n,i,*p,sum=0;
	printf("Enter value of n:");
	scanf("%d",&n);
	p=a;
	for(i=0;i<n;i++){
		printf("Enter %d number:",i+1);
		scanf("%d",p+i);
		sum=sum+*(p+i);
	}
	printf("sum of %d  number is: %d",n,sum);
	
}
