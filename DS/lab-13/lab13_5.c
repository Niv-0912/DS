#include<stdio.h>
void main(){
	int a[100],n,i,*p,j,temp;
	printf("Enter value of n:");
	scanf("%d",&n);
	p=a;
	for(i=0;i<n;i++){
		printf("Enter %d number:",i+1);
		scanf("%d",p+i);
	}
	printf("\nBefore sort Array is:\n");
	for(i=0;i<n;i++){
		printf("%d\t",*(p+i));
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(*(p+i)>*(p+j)){
				temp=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=temp;
			}
		}
	}
	
	printf("\nAfter sort Array is:\n");
	for(i=0;i<n;i++){
		printf("%d\t",*(p+i));
	}
	
}
