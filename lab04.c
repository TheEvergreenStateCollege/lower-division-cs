#include <stdio.h>
int add(int a, int b) {
	return a + b;
}
int main(void) {
	int val;
	val = add(3, 5);
	printf("%d\n", val);
	return 0;
}
