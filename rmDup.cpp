#include <stdio.h>

void rmDup(char * s) {
	int i[128] = {0};
	char *tmp, *tail;
	int t;
	tmp = s;
	tail =s;
	while (*tmp) {
		t = (unsigned char)(*tmp);
		if (0 == i[t]) {
			i[t] ++;
			*tail = *tmp;
			tail++;
		}
		tmp++;
	}
	*tail = NULL;	
}

int main(int argv, char *argc[]) {
	char s[]="abcdabcdffee";
	char *s1=s;
	rmDup(s);
	printf("result is %s\n", s);
	return 0;

}
