#include <stdio.h>
void SWAP(int &a, int &b)  
 {  
	a ^= b; 
	b ^= a;
	a ^= b;
	
  } 



template <typename T1 ,typename T2>
T2  Add(T1 &t1 , T2 &t2)
{
	if(t1 >t2 )
		return t1 ;
	else 
	    return t2;
}
int main_template ()
{
	int x = 10;
	int y = 5;
	int z = 4;

 // What happens now?
 void (*ptr) (int& ,int& );
 ptr=&SWAP;
 ptr(x,y);
 printf("X %d Y %d   ",x,y);
 float a=3.5,b=8.7,sum=0;
 int c=9;
 sum =Add<float,int >(a,c);
 printf("a =%.2f  ,b = %.2f  result %.2f ",a,b,sum);
 return 0;
}