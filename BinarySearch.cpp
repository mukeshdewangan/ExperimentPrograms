#include <stdio.h>
int RotationPivot(int Array[],int size )
{
	int Low =0,High =size-1;
  while(Low < High)
  {
	int Mid= (Low +( High))/2;
	//First half is sorted 
    if(Array[Low] <= Array[Mid])
	{
		  Low=Mid+1;	 
	}
	else //second half is sorted 
	{
	   High=Mid;
	}
  }
  return Low;
}
int BinarySearchRotated(int Array[],int size , int key)
{
  int Low =0,High =size-1;
  while(Low <=High)
  {
	int Mid= (Low + High)/2;
	if(Array[Mid]==key)
	{
	 return Mid;
	}
	//First half is sorted 
    if(Array[Low] <= Array[Mid])
	{
	  if(Array[Low]<=key && key <=Array[Mid])
	  {
	    High=Mid-1;
	  }
	  else 
		  Low=Mid+1;
	}
	else //second half is sorted 
	{
	    if(Array[Mid]<=key && key <=Array[High])
		{
		 Low= Mid+1;
		}
		else 
		{
		 High=Mid-1;
		}
	}
  }
  return -1;
}

int main_binarySearch()
{
	const int size =10;
	int Array [size]={9,11,15,17,2,3,4,5,6,8};
	int enter=0;
	puts("Enter the search key ");
	scanf("%d",&enter);
	int search =BinarySearchRotated(Array,size,enter);
	printf("\n pos of %d in array  is  %d ",enter ,search);
	printf("pivot index of rotation is %d ",RotationPivot(Array,size));
 return  0;
}