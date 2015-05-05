#include <stdio.h>
#include "string operation.cpp"
int main_External ()
{
 char p[]="have a nice day!!!";
 swap(p,3,6) ;
 puts(p);
 int arra[2][3][2]={0};
 int *ptr;
 ptr =  & arra[0][0][0];
 arra[1][1][1]=9;
 printf(" %d ",*(((ptr+1)+1)+1));
 return 0;
}

#include <stdio.h>
#include <string.h>
typedef union {
int a;
char b[10];
float c;
}Union;
int main_experiement ()
{
    printf(" %d ",8,6);
	char arr[19]={'\0'};
	int i=0;
	//scanf("%d",&i);
	sprintf(arr,"Hi every %d ",i);
	//puts(arr);
	char ch1 ='f';
	char ch2 ='k';
	char ch3 ='p';
	const char  *  p1 ;
	p1 =&ch1;
	*p1++;
	char * const  p2 =&ch3;
	//p2=&ch2;
	(*p2)++;
	printf("p1 = %c p2 =%c  ",*p1,*p2);
 return 0;
}