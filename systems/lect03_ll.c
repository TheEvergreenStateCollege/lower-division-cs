/*
create linked list 
use gdb
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct intNode_struct{
  int dataVal;
  struct intNode_struct *next;
}intNode;

/*
length of linked list
param: p pointer to linked list
todo: fill in code
 */
int length(intNode *p) {
  int len = 0;

  return len;
}

int main() {
  int i=0; //loop counter
  const int SIZE = 20;
  intNode *tail = NULL;
  intNode *head = NULL;
  intNode *ptr = NULL;
  // draw a picture
  /*
    -------
    |  |  |
    -------
   */
  
  head = (intNode *)malloc(sizeof(intNode));
  
  for (i=0; i<SIZE; i++){
    ptr = (intNode *)malloc(sizeof(intNode));
    tail->next = ptr;
    tail = tail->next ;
  }


  return 0;
}




