#include <stdio.h>
template <typename  T>
void swap (T &a,T &b)
{
	T temp ;
	temp=a;
	a=b;
	b=temp;
}
int Intersection (int First[] ,int size1, int Second[],int size2 ,int Intersect[] )
{
	int count1 = 0,count2 =0;
	int size=0;
	while(count1 <size1 && count2 <size2)
	{
	  if(First[count1] < Second[count2])
		  count1++;
	  else if(First[count1] > Second[count2])
		  count2++;
	  else 
	  {
		  Intersect[size++]=First[count1++];
		  count2++;
	  }
	}
	return size;
}

int Union (int First[] ,int size1, int Second[],int size2 ,int unian[] )
{
 int count1 = 0,count2 =0;
	int size=0;
	while(count1 <size1 || count2 <size2)
	{ if(First[count1] < Second[count2])
		   unian[size++]=First[count1++];
	  else if(First[count1] > Second[count2])
		   unian[size++]=Second[count2++];
	  //if(First[count1] == Second[count2])
	  else
	  {		  
	   unian[size++]=First[count1++];
	   count2++;
	  }
	 
	 
	}
	if(count1==size1)
	{
	    while(count2<size2)
		  unian[size++]=Second[count2++];
	}
	if(count2==size2)
	{
		  while (count1<size1)
		  unian[size++]=First[count1++];
	}
	return size;	
}
int DifferenceA_B (int First[] ,int size1, int Second[],int size2 ,int Diff[])
{
	int count1 = 0,count2 =0;
	int size=0;
	while(count1 <size1 )
	{
	  if(First[count1] < Second[count2])
		   Diff[size++]=First[count1++];
	  else if(First[count1] > Second[count2])
	      {		count2++;		   }
	  else
	     {		count1++;   count2++;	  }	 	 
	}
	
	if(count2==size2)
	{
		  while (count1<size1)
		  Diff[size++]=First[count1++];
	}
	return size;
}
int main_setOperation ()
{
	int Array[]={2,4,5,7,8};
	int Array2 [] ={2,3,6,7,8};
	int size1 =5, size2 = 5, sizeresult=0 ;
	int intersect [7]={0}; 
	printf("\nIntersection \n");
	sizeresult= Intersection(Array,size1, Array2,size2,intersect );
	for(int i=0;i<sizeresult;i++)
			printf("  %d",intersect[i]);

	int Unian[12]={0}; 
	sizeresult= Union(Array,size1, Array2,size2,Unian );
	printf("\nUnion \n");
	for(int i=0;i<sizeresult;i++)
			printf("  %d",Unian[i]);

	int Differ[5]={0}; 
	sizeresult= DifferenceA_B(Array,size1, Array2,size2,Differ );
	printf("\nDiffernce A - B  \n");	
	for(int i=0;i<sizeresult;i++)
			printf("  %d",Differ[i]);

    return 0;
}