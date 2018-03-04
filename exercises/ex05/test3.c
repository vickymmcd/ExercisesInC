#include <stdio.h>

main(){
  unsigned int x = 1<<32;
  int y;
  x = x-1;
  // flip all the bits and add 1
  y = (12^x)+1;
  printf("%d\n", y);
}
