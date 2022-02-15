#include <stdio.h>

typedef struct dummy{
  int a;
  int b;
}dummy;

int main(){
    
  printf("Size required by variables of datatypes belonging to\n1. char : %ld\n2. int : %ld\n3. struct dummy : %ld\n\n",
	 sizeof(char),
	 sizeof(int),
	 sizeof(struct dummy));

  //Since pointers contain addresses, regardless of the datatype they are pointing to they are going to have the same size

  printf("Size required by pointers to variables of datatypes belonging to\n1. char : %ld\n2. int : %ld\n3. struct dummy : %ld\n",
	 sizeof(char*),
	 sizeof(int*),
	 sizeof(struct dummy*));
  return 0;
}
