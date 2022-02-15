#include <stdlib.h>

void test(){
  char* p = malloc(sizeof(char));

  //Didn't free 'p' before test() returns,
  //Impossible to get reference to 'p' once it's out of scope
  //We have thus assuredly no way of freeing memory allocated to 'p'
  //We have thus definitely lost 1 byte
}

int main(){
  test();
  
  return 0;
}
