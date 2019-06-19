#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void swap(int *, int*);
int main(void)
{
  int a = 42, b = 1138;
  puts("# Pointers");
  printf("## Entering main()\n");
  printf("address of variable 'a' in main(): %p\n", (void*)&a);
  printf("value of variable 'a' in main(): %d\n", a);
  printf("address of variable 'b' in main(): %p\n", (void*)&b);
  printf("value of variable 'b' in main(): %d\n", b);
  printf ("In main, calling swap()\n");
  swap(&a, &b);
  printf("\n## back in main() after returning from swap()\n");
  printf("address of variable 'a' in main(): %p\n", (void*)&a);
  printf("value of variable 'a' in main(): %d\n", a);
  printf("address of variable 'b' in main(): %p\n", (void*)&b);
  printf("value of variable 'b' in main(): %d\n", b);
  printf("Leaving main()\n");
  return EXIT_SUCCESS;
}

void swap(int * p1, int * p2)
{
  /* need a temporary storage location for the number */
  int temp;
  printf("\n### Entering swap() - Using pointer to a poiner\n");
  /* pointer to a pointer !! */
  printf("Address of 'p1' in swap(): %p\n", (void*)&p1);
  printf("Value of 'p1' in swap(): %p\n", (void*)p1);
  printf("Value pointed to by p1 in swap(): %d\n", *p1);
  printf("Address of 'p2' in swap(): %p\n", (void*)&p2);
  printf("Value of 'p2' in swap(): %p\n", (void*)p2);
  printf("Value pointed to by p2 in swap(): %d\n", *p2);
  printf("doing swap\n");
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
  printf("Address of 'p1' in swap(): %p\n", (void*)&p1);
  printf("Value of 'p1' in swap(): %p\n", (void*)p1);
  printf("Value pointed to by p1 in swap(): %d\n", *p1);
  printf("Address of 'p2' in swap(): %p\n", (void*)&p2);
  printf("Value of 'p2' in swap(): %p\n", (void*)p2);
  printf("Value pointed to by p2 in swap(): %d\n", *p2);
  printf("leaving swap\n");
}
