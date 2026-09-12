#include<stdio.h>
#include<stdlib.h>
void  main(){
	int *p_int=(int *)malloc(sizeof(int));
	char *p_char=(char *)malloc(sizeof(char));
	float *p_float=(float *)malloc(sizeof(float));
	
	printf("Enter integer:");
	scanf("%d",p_int);
	
	printf("Enter charcter:");
	scanf("%c",p_char);
	
	printf("Enter float:");
	scanf("%f",p_float);
	
	printf("Integer number is: %d \nCharcter is: %c\n float number is: %f\n",*p_int,*p_char,*p_float);
	
	free(p_int);
	free(p_char);
	free(p_float);
}
