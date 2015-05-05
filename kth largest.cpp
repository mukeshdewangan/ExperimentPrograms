#include <stdio.h>
#include <malloc.h>
#include <assert.h>
int kth_largest(int AuxArr[],int n, int k);
void SortArray(int Array[],int size);
int main ()
{
	int Array [12]={843,2,523,83,13,63,92,86,237,1289,356,205};
	for(int i=0;i<12;i++)
		printf(" %d ",Array[i]);
	printf("\n");
	SortArray(Array,12);
	int larg = kth_largest(Array,12,6);
	printf("\n6th largest element is %d ",larg);
return 0;
}

void SortArray(int Array[],int size)
{   
	for(int i=0;i<size-1;i++)
	{
	  for(int j=0;j<size-1-i;j++)
	  {
	    if(Array[j+1]<Array[j])
		{
		  int temp =Array[j];
		  Array[j]=Array[j+1];
		  Array[j+1]=temp;
		}
	  }	 
	}
	for(int i=0;i<size;i++)
		printf(" %d ",Array[i]);
}
int kth_largest(int AuxArr[],int n, int k)
{   
	assert (k<n);
    int * larg = (int *)malloc (sizeof (int )*k);
	int i=0;
	larg[i]= AuxArr[i];

	for(int j=0;j<n;j++)
	{
	  if(larg[i]< AuxArr[j])
	  {
	    i=(i+1)%k;
		larg[i]=AuxArr[j];
	  }
	}
	return larg[((i+1)%k)];
}