#include <stdio.h>
#include <assert.h>

int MergeSortedArrayRepeatable(int Array1[],int Array2[],int size1 ,int size2 ,int Result[] );
int MergeSortedArrayNONRepeatable(int Array1[],int Array2[],int size1 ,int size2 ,int Result[] );
int RemoveDuplicateSortedArray(int Array[],int size);
int SortedArrayRotation(int Array[] ,unsigned short int  size,unsigned short int rotation )
{
	int i,k,temp;
  for(i=0;i<rotation;i++)
   {	
	 temp = Array[size-1];
     for(k=size-1;k>0;k--)
	 {
		 Array[k]=Array[k-1];
	 }
	 Array[k]=temp;
   }
  return rotation;
}

int MergeSortedArrayNONRepeatable(int Array1[],int Array2[],int size1 ,int size2 ,int Result[] )
{
	int  resultSize=0;
	assert(size1>0||size2>0);

	if(size1==0)
	{
	 Result=Array2;return size2;
	}
	if(size2==0)
	{
	 Result=Array1;return size1;
	}
	int first =0, second =0; 
	while(first <size1 && second <size2)
	{
		if(Array1[first]<Array2[second])
		{
			Result[resultSize++]=Array1[first++];
		}
		else if(Array1[first]>Array2[second])
		{
			Result[resultSize++]=Array2[second++];
		}
		else 
		{first++;second++;}
	}

	if(first==size1)
	{
		for(int j=second;j<size2;j++)
			Result[resultSize++]=Array2[second++];
	}
	if(second==size2)
	{
		for(int j=first;j<size1;j++)
			Result[resultSize++]=Array1[first++];
	}

	return resultSize;
}


int MergeSortedArrayRepeatable(int Array1[],int Array2[],int size1 ,int size2 ,int Result[] )
{
	int  resultSize=0;

	assert(size1>0||size2>0);


	if(size1==0)
	{
	 Result=Array2;return size2;
	}
	if(size2==0)
	{
	 Result=Array1;return size1;
	}
	int first =0, second =0; 
	while(first <size1 && second <size2)
	{
		if(Array1[first]<=Array2[second])
		{
			Result[resultSize++]=Array1[first++];
		}
		else
		{
			Result[resultSize++]=Array2[second++];
		}
	}

	if(first==size1)
	{
		for(int j=second;j<size2;j++)
			Result[resultSize++]=Array2[second++];
	}
	if(second==size2)
	{
		for(int j=first;j<size1;j++)
			Result[resultSize++]=Array1[first++];
	}

	return resultSize;
}

int RemoveDuplicateSortedArray(int Array[],int size/*,int Result[]*/)
{ 
	assert(size>0);
	int resultSize =0;
	
	int LastSeen = Array[0];
	for( int i=1;i<size;i++)
	{
	 if(LastSeen!=Array[i])
	 {
	  Array[resultSize++]=LastSeen;
	  LastSeen=Array[i];
	 }
	}
	Array[resultSize++]=Array[size-1];
	 return resultSize;  
}

int main_removeDuplicate ()
{
	int Arr1 [] ={1,4,6,8,12,13,16,19};
	int Arr2 [] ={1,4,5,8,9,12,15};
	int Arr3 [] ={2,2,2,2,2,2,3,3,3,3,3,3,5};
	
	unsigned int size =7;
	unsigned int rotate =3;
	int size1=8 , size2=7 ;
	int size3 = 13;
	int Result[13];

	//int after = SortedArrayRotation(Arr1,size,rotate);
	printf("After Rotation \n");
	//for(int i=0;i<7;i++)
	   //	printf(" %d  ",Arr1[i]);
     printf("\n");

	 int resultSize = MergeSortedArrayNONRepeatable(Arr1,Arr2,size1,size2,Result);

	 for(int i=0;i<resultSize;i++)
		printf(" %d  ",Result[i]);
	 printf ("\nresult size %d ",resultSize);

	/* int resultremoveDupli = RemoveDuplicateSortedArray( Arr3,size3);

	 for(int i=0;i<resultremoveDupli;i++)
		 printf(" %d  ",Arr3[i]);
	 printf ("\nresult size %d ",resultremoveDupli);*/
 return 0;
}
