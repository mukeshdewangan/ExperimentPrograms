#include <stdio.h>
#include <string.h>
#define SIZE 7
int main/*_test*/ ()
{
	int A[SIZE] = {5,9,3,1,6,8,4};
	int imin = 0;
	int imax = SIZE-1;
	for (int i = 0; i < SIZE/2; i++) 
	{
		if (A[imin] < A[imax]) 
		{
			break;
		}
		imin ++;
		imax --;
	}
	printf("Max %d ",imin);
	printf("Min %d ",imax);

  /*char firstStr[]="start";
  char * seconfStr = "End";
  strcpy(firstStr,seconfStr);
  printf("first %s\n",firstStr);*/
	int a=89;
	int *p ;
	p=(int  *)&a;
	printf("hello Error %d",*p);
	
	return 0 ;
	

}

