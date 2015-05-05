#include <stdio.h>
#define max(a,b)  ((a>b)?(a):(b))

int MaxSub(int Array [], int size )
{
  int maxSum = 0;
  for(int i=0;i<size ;i++)
  {
   int sum =0;
   for(int j=i;j<size;j++)
   {
     sum=sum+Array[j];
	 maxSum=max(sum,maxSum);
   }
  }
  return maxSum;
}
int main_subArray ()
{
	int Array []={-1,7,-9,5,12,-15,10};
	printf("Maxsum = %d \n",MaxSub(Array,7));

  return 0;
}