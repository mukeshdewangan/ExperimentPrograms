#include <stdio.h>

int main_stackgrowing(int argc, char **argv){
volatile int a;
volatile int b;

printf("Address of a is %u, and b is %u\n", &a, &b);

return 0;
}

