#include <stdio.h>
long power(long x ,unsigned int n)
{
	if(n==1)
	{
	  return (x);
	}
	if(n%2)
	{
	  return ((power(x*x,n/2))*x);
	}
	else 
	{
	  return(power(x*x,n/2));
	}
 
}
int main_power () 
{
	 long a=5;
	 unsigned int pow =5;
	 long ans = power(a,pow);
	 printf("Answer (a^n)  %ld  ",ans);
	 return 0;
}