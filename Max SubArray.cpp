#include <stdio.h>
#define SIZE 5
#define max(A,B)  ((A) < (B) ? (B) : (A) )
int main_MaxSubArray ()
{
	int Array [SIZE] ={8,-2,3,-5,-7}  ;
	int max_so_far =0, max_ending=0;
	for(int i=0;i<SIZE ;i++)
	{
		max_ending=max(0,max_ending+Array[i]);
		max_so_far=max(max_so_far,max_ending);	  
	}

	printf("MaxSubArray   %d \n",max_so_far );

	return 0;
}