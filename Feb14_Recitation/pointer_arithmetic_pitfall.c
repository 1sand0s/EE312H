#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void withLoopIndexing(char** str, char x){
  int j = 0;

  while((*str)[j++] != x);

  printf("Word after space using loop indexing : %s\n", *str + j);
}

void withPointerManipulation(char** str, char x){
  while(*(*str)++ != x);

  printf("Word after space using pointer manipulation : %s\n", *str);
}

int main(){

  char* str = malloc((strlen("Hello World") + 1)*sizeof(char));

  strncpy(str, "Hello World\0", 12 );

  printf("Value and address of str before calling any function : %s %p\n\n", str, str);

  withLoopIndexing(&str, ' ');
  printf("Value and address of str after calling function with loop indexing : %s %p\n\n", str, str);

  withPointerManipulation(&str, ' ');
  printf("Value and address of str after calling function with pointer manipulation : %s %p\n\n", str, str);

  printf("Address of str no longer the same as before after pointer manipulation, \ntherfore need to store starting address of str before pointer manipulation \notherwise cannot free str without memory leak\n");
  return 0;
}
