#include <stdio.h>

int main () {
	char c[] = "中文aa";
	char *p = c;
	int i=0;
	while (*p != '\0') {
		printf("i is %d, c is %c, unsigned is %d\n", i, *p, (unsigned char)*p);
		p++;
		i++;
	}
	return 0;
}
