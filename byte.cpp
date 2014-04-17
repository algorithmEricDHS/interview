#include <stdio.h>
typedef struct A {
	unsigned int k:1;
}A;

int main() {
	unsigned int i =100;
	int count = 0;
	unsigned int j, n;
	for (j=31;j>0;j--) {
		n= (i<<j)>>31;
		printf("n is %d\n", n);
		if (n) count++;
	}
	printf("%d \n", count);
	return 0;
}
