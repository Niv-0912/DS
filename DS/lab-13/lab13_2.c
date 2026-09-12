#include<stdio.h>
void main(){
	int a[100],n,i,*p;
	printf("Enter value of n:");
	scanf("%d",&n);
	p=a;
	for(i=0;i<n;i++){
		printf("Enter %d element:",i+1);
		scanf("%d",p+i);
	}
	printf("Array is:");
	for(i=0;i<n;i++){
		printf("%d\t",*(p+i));
	}
}
