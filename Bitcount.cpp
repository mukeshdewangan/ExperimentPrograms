#include <stdio.h>
int BitCount (int a , int b)
{
   int And =  a^b;
   int count =0;
    while (And>0)
	{
	 And>>=1;
	 if(And && 0x01)
	 {
	  count ++ ;
	 }
	}
   return  count ;
}
int main_bitCount ()
{
	int a =8;
	int b=6;
	int change = BitCount(a,b);
	 printf("change bits  %d  ",change);

 return 0;
}