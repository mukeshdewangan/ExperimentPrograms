#include <stdio.h>

//template <typename INT> 
//T rol(T val) 
//{ 
//	return (val << 1) | (val >> (sizeof(T)*CHAR_BIT-1)); 
//}
unsigned int circularRight(unsigned int n,unsigned int time)
{
 return((n>>time)|(n<<((sizeof (int)*8) - time)));
}

unsigned int circularLeft(unsigned int n,unsigned  int time )
{
 return ((n<<time)|(n>>((sizeof (int)*8)- time)));
}

int main_flipBit ()
{
  unsigned int a =14;
  // unsigned int b=circularRight(a,20);
  a=circularRight(a,2);
  
  if(a&0x01)
  {
    a>>=1;
	a<<=1;
  }
  else
  {
   a=a|0x01;
  } 
  a=circularLeft(a,2);
  printf("  left 13 , 3 %d\n" ,a );
  return 0;
}