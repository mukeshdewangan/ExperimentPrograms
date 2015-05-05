#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#define MAX 3
using namespace std;
int BinarySearch (int Array [], int size,int Key )
{
  int low =0,high=size-1;
  int middle=0 ;

  while(low<=high)
  {
	  middle =(low+high)/2;
      if(Array[middle]>Key)
	  {
	   high=middle-1;
	  }
	  else if (Array[middle]<Key)
	  {
	   low=middle+1;
	  }
	  else
	  {
	   return middle;
	  }
  }
  return -1;
}

bool BinarySearch2D(int **Array,int nrows,int ncolumns,int Key ) 
{
  for(int x =0;x<nrows;x++)
  {
    int y_pos= BinarySearch(Array[x],ncolumns,Key);
    if (y_pos!=-1)
	{
    printf("Found at x_pos =%d y_pos =%d \n",x,y_pos);
    return true;
    }
 
  }
 return false ;
 
}
void Print2D(int **Array,int nrows,int ncolumns ) 
{
	for(int i=0;i<nrows;i++)
	{
	 for(int j=0;j<ncolumns;j++)
	 {
	  printf("%d ",Array[i][j]);
	 }
	 printf("\n");
	}
  
}
int ** Input2D_Array(int **Array , int nrows ,int ncolumns)
{
    Array =(int **) malloc(nrows * sizeof(int *));
	if(Array == NULL)
		{
		fprintf(stderr, "out of memory\n");
		 return NULL;
		}
	for(int i = 0; i < nrows; i++)
		{
		Array[i] =(int *) malloc(ncolumns * sizeof(int));
		if(Array[i] == NULL)
			{
			fprintf(stderr, "out of memory\n");
			return NULL;
			}
		}
	int num=10;
	for(int i=0;i<nrows;i++)
	{
	 for(int j=0;j<ncolumns;j++)
	 {
	  Array[i][j]=num++;
	 }
	}
	//printf("Completed \n");
  return Array;
}

int main_2Dsort()
{
	int **Array=NULL;
	int nrows =3,ncolumns=3,i;
	Array= Input2D_Array(Array,nrows,ncolumns);
	int key=15;
	Print2D(Array,nrows,ncolumns);
	printf("Searching for %d  %d \n",key ,BinarySearch2D(Array,nrows,ncolumns,key));
	for(i = 0; i < nrows; i++)
		free(Array[i]);
	free(Array);

 return 0;
}

 // --Sorting Program--
  // -------------------
  // Example Program to sort
  // 2D array using linear
  // representation of the array



  void main_Binary2DArray(void)
  {
   int arr[MAX][MAX];
   int i,j,temp;
   int *arr_ptr;
   cout << "Enter the 2D Array Of 3x3 "<<endl;
   for(i=0;i<MAX;i++)
     for(j=0;j<MAX;j++)
       cin>>arr[i][j];

   // we have taken a pointer
   // to the 2D array to
   // represent it linearly

   // C-style type cast
   // is necessary here
   arr_ptr=(int*)arr;

   // sorting is done here.
   // selection sort method of
   // sorting is employed here
   // you can use whichever
   // method you like

   // here MAX*MAX is used 
   // because the no. of elements
   // in the linear representation
   // of the 2D array has that
   // many elements
   for(i=0;i<((MAX*MAX)-1);i++)
     for(j=i+1;j<(MAX*MAX);j++)
       if(*(arr_ptr+i)>*(arr_ptr+j))
       {
        temp=*(arr_ptr+i);
        *(arr_ptr+i)=*(arr_ptr+j);
        *(arr_ptr+j)=temp;
       }
   // sorting is done till here

   cout<<endl;

   for(i=0;i<MAX;i++)
   {
    for(j=0;j<MAX;j++)
    cout<<" "<<arr[i][j];
    cout<<endl;
   }
  }