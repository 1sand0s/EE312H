#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* returnLocalVariableStack(){
  char p[10] = "Hello World";

  printf("Address pointed to by local variable allocated on stack within scope : %p\n",p);
  return p;
}

char* returnLocalVariableHeap(){
  char* p = malloc((strlen("Hello World") + 1)*sizeof(char));

  strncpy(p, "Hello World\0", 12);

  printf("Address pointed to by local variable allocated on heap within scope : %p\n",p);
  return p;
}

int main(){

  char* p1 = NULL;
  char* p2 = NULL;

  p1 = returnLocalVariableStack();
  p2 = returnLocalVariableHeap();

  printf("Address of returned local variable allocated on stack and its content : %p %p\n", p1, p1);
  printf("Address of returned local variable allocated on heap and its content : %p %s\n", p2, p2);

  printf("\n\nWe see that the address returned for local variable allocated on stack outside its scope is nil or 0x0\nthis is because the OS takes care managing memory for all variables allocated on the Stack and frees the\nmemory allocated to a local variable once the execution passes outside its scope. But the programmer\nis responsible for freeing variables allocated on the heap\n");
  return 0;
}
