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
