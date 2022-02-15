#include <stdlib.h>

typedef struct dummy{
  int a;
  char* next;
}dummy;
  
char* test(){
  char* p1 = malloc(sizeof(char));
  return p1;
}

int main(){
  struct dummy* p1 = malloc(sizeof(struct dummy));

  p1->next = test();
  
  //Didn't free 'p1' before main() returns,
  //Since 'p1' scope is local to main(), we have no way of referencing this memory again
  //Therefore we have definitely lost memory allocated to p1
  //But by loosing reference to p1 we have indirectly lost memory allocated to what p1->next was pointing to (returned by test())
  
  return 0;
}
