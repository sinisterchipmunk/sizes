#include <stdio.h>

int main(int argc, char **argv)
{
  printf("Correct values for sizeof(...) for this machine:\n\n");
  printf("char               : %ld\n", sizeof(char));
  printf("unsigned char      : %ld\n", sizeof(unsigned char));
  printf("signed char        : %ld\n", sizeof(signed char));
  printf("signed int         : %ld\n", sizeof(int));
  printf("   / int\n");
  printf("signed short int   : %ld\n", sizeof(signed short int));
  printf("   / short int\n");
  printf("   / short\n");
  printf("signed long int    : %ld\n", sizeof(signed long int));
  printf("   / long int\n");
  printf("   / long\n");
  printf("unsigned int       : %ld\n", sizeof(unsigned int));
  printf("   / unsigned\n");
  printf("unsigned short int : %ld\n", sizeof(unsigned short int));
  printf("   / unsigned short\n");
  printf("unsigned long int  : %ld\n", sizeof(unsigned long int));
  printf("   / unsigned long\n");
  printf("float              : %ld\n", sizeof(float));
  printf("double             : %ld\n", sizeof(double));
  printf("long double        : %ld\n", sizeof(long double));
}

