#include <stdio.h>

int main(){

  /*
   *  Example : 
   *  
   *          int a = 10;  
   *          
   *          Meaning of 'int a' (Declaration)
   *          // A memory in stack (stack frame of main) is allocated for 'a' of type int
   *          // Let the starting address of this memory be 0x7fff (assumption)
   *          // Then the next 4 bytes (0x7fff - 0x7ffc) is reserved for contents of 'a'
   *
   *          Meaning of 'a = 10' (Assignment)
   *          // Address starting from 0x7fff up to 0x7ffc (4 bytes for int [verify with sizeof(int)]) 
   *          // is used to store value assigned to 'a' which is 10 
   *         
   *        STACK AFTER (int a = 10)
   *          ~~~~~~~~~~~
   *          ~         ~ 
   *          ~~~~~~~~~~~ 
   *          ~         ~ <---- 0x7fff
   *          ~         ~
   *          ~         ~ <---- 0x7ffe
   *          ~   10    ~                 <------ storage space for 'a'
   *          ~         ~ <---- 0x7ffd
   *          ~         ~ 
   *          ~         ~ <---- 0x7ffc
   *          ~~~~~~~~~~~ 
   *
   *
   *          int* p = &a; 
   *
   *          Meaning of 'int* p' (Declaration)
   *          // A memory in stack (stack frame of main) is allocated for 'p' of type int*
   *          // This memory starts at 0x7ffb (0x7fff - 4 - 1) based on previous 
   *          // assumption
   *          // Then the next 8 bytes (0x7ffb - 0x7ff4) is reserved for contents of 'p'
   *
   *          Meaning of 'p = &a' (Assignment)
   *          // Address starting from -x7ffb up to 0x7ff4 (8 bytes for int* [verify with sizeof(int*)])
   *          // is used to store the value assigned to 'p' which is address of 'a' (&a)
   *                       
   *         
   *        STACK AFTER (int* p = &a)
   *          ~~~~~~~~~~~
   *          ~         ~ 
   *          ~~~~~~~~~~~ 
   *          ~         ~ <---- 0x7fff
   *          ~         ~
   *          ~         ~ <---- 0x7ffe
   *          ~   10    ~                <------ storage space for 'a'
   *          ~         ~ <---- 0x7ffd
   *          ~         ~ 
   *          ~         ~ <---- 0x7ffc
   *          ~~~~~~~~~~~ 
   *          ~         ~ <---- 0x7ffb
   *          ~         ~
   *          ~         ~ <---- 0x7ffa
   *          ~         ~ 
   *          ~         ~ <---- 0x7ff9
   *          ~         ~ 
   *          ~         ~ <---- 0x7ff8
   *          ~ 0x7fff  ~                <------ storage space for 'p'
   *          ~         ~ <---- 0x7ff7
   *          ~         ~
   *          ~         ~ <---- 0x7ff6
   *          ~         ~ 
   *          ~         ~ <---- 0x7ff5
   *          ~         ~ 
   *          ~         ~ <---- 0x7ff4
   *          ~~~~~~~~~~~ 
   *
   *         
   *         -> '&p' gives the starting address of 'p' which is 0x7ffb
   *         
   *         -> 'p' points/contains the starting address of 'a' which is 0x7fff
   *         
   *         -> '&a' gives the starting address of 'a' which is 0x7fff
   *         
   *         -> 'a' gives the contents of address starting at 0x7fff which is 10
   *         
   *         -> '*p' dereferences 'p' to give the contents of contents of p
   *                                           contents of p is 0x7fff
   *                                           contents of 0x7fff is 10
   *              Therefore dereferencing 'p' gives 10
   *
   */
  
  int a = 10;

  int* p = &a;

  printf("Address of p : %p\n", &p);             
  printf("Content of p : %p\n", p);
  printf("Address of a : %p\n", &a);
  printf("Content of a : %d\n", a);
  printf("Content of a by dereferencing p : %d\n", *p);

  return 0;
}
