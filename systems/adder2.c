/*
 *  Copy code from chapter 7 of Dive into Systems
 *
 *  Andersen Ader 
 *  CSF24Q2 - Systems Week 6
 *
 * */

#include <stdio.h>

//adds two to an integer and returns the result
int adder2(int a) {
    return a + 2;
}

int main(void){
    int x = 40;
    x = adder2(x);
    printf("x is: %d\n", x);
    return 0;
}
