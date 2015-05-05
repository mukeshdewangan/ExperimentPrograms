#include <stdio.h>

int main_repeatition()
{

	int Array[]={1,1,1,1,3,3,3,5,5,5,7,7,7,7,8}; 
	int size =15;

	int LastSeen =Array[0];
	int NewSize=0;
	for(int k=1;k<size;k++)
	{
	   if(LastSeen!=Array[k])
	   {		
		   Array[NewSize++]=LastSeen;
		   LastSeen=Array[k];

	   }
	}
	Array[NewSize++]=LastSeen;
	
	
	for(int j=0;j<NewSize;j++)

		printf("   %d  ",Array[j]);
	return 0;
}