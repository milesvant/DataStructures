#include <stdio.h>
#include <stdlib.h>
#include "mystack.h"

static void die(const char *message)
{
    perror(message);
    exit(1);
}

int main()
{
  double a[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  int n = sizeof(a)/sizeof(a[0]);
  struct Stack *testStack = initstack(n); // Tests initStack
  clearstack(testStack); // Tests clearStack
  return 0;
}
