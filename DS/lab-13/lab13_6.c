#include<stdio.h>
#include<string.h>
void main(){
	int i,sum=0,j,flag=0;
	char a[100],*p;
	printf("Enter string :");
	scanf("%s",a);
	p=a;
	int len=0;
	for(i=0;*(p+i)!='\0';i++){
		len++;
	}
	len--;
	for(i=0,j=len;i<len/2,j>len/2;i++,j--){
		if(*(p+i)!=*(p+j)){
			flag++;
			break;
		}	
	}
	if(flag == 0){
		printf("String pointer is pelindrome:");
	}
	else{
		printf("String pointer is not pelindrome:");
	}
	
}
