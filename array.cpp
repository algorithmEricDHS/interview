#include <stdio.h>
#include <vector>

using namespace std;

void printA (int a[], int l) {
	int i;
	for (i=0; i<l; i++) {
		printf("it is %d\n", a[i]);
	}
	
}
int main(int argc, char* argv[]) {
	int a[]= {0,1,2,3,4,5,6};
	printA (a, 7);
	vector<int> v(5,10);
	v.push_back(1);
	v.push_back(3);
	vector<int>::iterator ite;
	for (ite=v.begin();ite!=v.end();ite++) {
		printf("data is %d \n", *ite);
	}
	char c;
	for (c=0;(unsigned char)c<255;c++) {
		printf("%c, %d, unsigned int %d, 0x%x\n", c, (int)c,(unsigned int)c, c );
	}
}

