#include <stdlib.h>

char* p;
void test(){
  p = malloc(sizeof(char));

  //Didn't free 'p' before test() returns,
  //But we still have reference to it since 'p' scope is global
  //We have thus a way of clearing it even after main() returns so
  //Valgrind's memcheck indicates we still have a way of freeing the memory and hence
  //we have 1byte that's not been freed but still reachable or can be freed
}

int main(){
  test();
  
  return 0;
}
