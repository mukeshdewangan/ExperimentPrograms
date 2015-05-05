#include <stdio.h>
void BucketSort(int Array[],int size);
void SortBinary (int Array [], int size);
int main_sortBinary ()
{
	int Array[12]={1,0,0,0,1,0,1,0,1,0,1,1};
	int size =12;


	SortBinary(Array,size);
  return 0;
}

void BucketSort(int Array[],int size)
{
  
}
void  SortBinary (int Array [], int size)
{
	int ON =0,OFF =0;
  for(int i=0;i<size;i++ )
  {
    if(Array[i])
		OFF++;
  }


  for(int i=0;i<OFF;i++) 
	  Array[i]=0;
  for(int i=OFF;i<size;i++)
	  Array[i]=1;

	for(int i=0;i<size;i++) 
		printf("%d ",Array[i]);
  
}