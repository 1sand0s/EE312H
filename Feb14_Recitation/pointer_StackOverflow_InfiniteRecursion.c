#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void test(){
  //StackOverflow due to infinite recursion
  //Each function call test() allocates memory in the stack to hold the stack frame of test()
  test();

  //If depth of recursion is too large, go for loops since it avoids stackoverflow since no new stack frame is created
  //For example
  //comment out line : test();
  //And replace it with : while(1);
  //Execution will now run forever but won't crash since no new memory is being allocated on stack
}
int main(){

  test();
  
  return 0;
}
