#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* returnLocalVariableStack(){
  // Segmentation fault due to Stack Overflow (too large variable)
  char p[10000000000] = "Hello World";

  printf("Address pointed to by local variable allocated on stack within scope : %p\n",p);
  return p;
}

int main(){

  char* p1 = NULL;
  char* p2 = NULL;

  p1 = returnLocalVariableStack();
  return 0;
}
