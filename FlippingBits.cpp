#include <stdio.h>
 
void PrintBit(unsigned  int num)
{
 int i=31;
 while(i>=0)
 {
 printf("%d",(num>>i--)&1U);  
 }
}
unsigned int BitsFlip(unsigned int num , unsigned int digit )
{
 return  (num ^ (1U <<digit));
}
int main_mask ()
{
  unsigned  int num_to_flip, digit;
  puts("Enter the no. to flip bits ");
  scanf("%d",&num_to_flip);
  puts("Enter the digits to flip");
  scanf("%d",&digit);

  printf("No is   ");
  PrintBit(num_to_flip);
  puts("\nAfter flipping bits(starting with index 0 )");
  num_to_flip=BitsFlip(num_to_flip,digit);
  printf("No is   ");
  PrintBit(num_to_flip);

  return 0;
}