#include <stdio.h>


int main_Find ()
{
	int Array [10]={1,2,3,4,5,6,7,8,9,2};
	int sum=0;
	for(int i=0;i<10;i++)
		sum+=Array[i];

	int missing = sum -((9*(9+1))/2) ;
	printf("  %d  ",missing);
	return 0;
}