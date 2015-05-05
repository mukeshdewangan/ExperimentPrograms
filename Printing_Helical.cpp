#include <stdio.h>


void PrintInSpiral(int numbers[5][5], int size)
{
		int k,i,j;int total =0;
    for(i=size-1 ,j=0;(j<=i);i-- ,j++)
	{
      	  for(k=j;k<i;k++)
		 printf(" %d ",numbers[j][k],total++);
	  for(k=j;k<i;k++)
		 printf(" %d ",numbers[k][i],total++);
	  for(k=i;k>j;k--)
		 printf(" %d ",numbers[i][k],total++);
	  for(k=i;k>j;k--)
		 printf(" %d ",numbers[k][j],total++);
	//printf("value of i = %d ,j = %d ",i,j);
	}
    
	int m= (size-1)/2; //calculate the position of the middle element 
	if (size% 2 == 1) printf("%d", numbers[m][m]);//to print the middle element also

	//printf ("\ntotal  %d ",total);
	
}
int main0 ()
{
	int Array [5][5]={{1 , 2 , 3 , 4 , 17},{5 , 6 , 7 , 8 ,18 },{9, 10 , 11, 12,19},{13, 14, 15, 16,20 },{21,22,23,24,25}};
	
	PrintInSpiral(Array,5);

return 0;
}