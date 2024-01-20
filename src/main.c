#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
  #ifdef DEBUG
    #pragma message "DEBUG BUILD"
  #else
    #pragma message "PRODUCTION BUILD"
  #endif
  
  printf("Hello, World!");
  
  return 0;
}