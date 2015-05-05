//asd
#include <stdio.h>

int compact(int  Array[], int size)
{
  int current, insert = 0;

  for(current=0;current<size;current++)
  {
    if(Array[insert]!= Array[current])
	{
		Array[++insert]=Array[current];
	}	 	
  }
  Array[++insert]=Array[current];
  return insert;
}



int main_check ()
{
	int Array[]={1,1,2,2,3,3,3,4,5,5,5,6,7,8,8};
	int size =15;
	size=compact(Array,size);
	for(int i=0;i<size;i++)
	  printf(" %d ",Array[i]);
 return 0;
}