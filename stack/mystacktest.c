#include <stdio.h>
#include <stdlib.h>
#include "mystack.h"

static void die(const char *message)
{
    perror(message);
    exit(1);
}

/*
 * Simple tests to test functionality of mystack
 */
int main()
{
  double a[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  int n = sizeof(a)/sizeof(a[0]);
  struct Stack *testStack = initstack(&n); // Tests initStack
  for(int i=0; i<n; ++i) { // Test push
	if(push(testStack, (void *)(a+i)) == NULL)
		die("push failed");
  }
  void *popVal;
  for(int i=0; i<n; ++i) { // Tests pop
  	if((popVal = pop(testStack)) == NULL) {
		die("pop failed");
	}
	else{
		printf("%f\n", *(double *)popVal);
	}
  }
  clearstack(testStack); // Tests clearStack
  return 0;
}
