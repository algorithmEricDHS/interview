#include <stdio.h>
#include <malloc.h>
#include <string.h>
int main () {
	for(int i=0;i<257;i++) {
		printf ("%d is: %c \n",i, i);
	}
	char a[10] = "naaaa";
	printf("%s\n",a);
	char *b = (char *)malloc (sizeof(char) * 10);
	//b = (char *) memcpy (b,a, 9);
	b =a;
	printf("%s\n",b);
	int j=0;
	while(*b != EOF) {
		printf ("%c, %d, %d\n", *b, j, (int)(*b));
		b++;
		j++;
	}
	printf("\n");
	
	return 0;
}
