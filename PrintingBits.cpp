#include <stdio.h>
#include <malloc.h>
typedef unsigned int uint ;

uint  SwapBits(uint num , uint i, uint j)
{
   uint high =((num >>i) & 1U) ;
   uint low = ((num >>j )& 1U) ;
   if(low^high)
   {
       num= num^ (1U << i)|(1U << j);
   }
   return num;
}
uint ReverseBits (uint num )
{
  uint i=0,size =(sizeof(int)*8);
  for(;i<size /2 ;i++)
  {
   num = SwapBits(num,i,size-i-1);
  }
  return num;
}
void PrintBits (uint bits)
{
 int b=sizeof(uint)*8;
 //printf("size of array = %d ",b);
 bool * p= (bool *)malloc(b);
 int k;
 bool res =0;
  for(k=0;k<b;k++)
  {
    res= (bits & 0x01);
	p[k]=res;
	bits>>=1;
  }
  k--;
  printf ("\"");
  for(;k>=0;k--)
  {
   printf("%d",p[k]);	
  }
}
int main_printingBits()
{
 uint  bits  =152124;
 PrintBits(bits);
 bits =ReverseBits(bits);
 PrintBits(bits);

 return 0;
}