#include <stdio.h>
#include <ostream>

char path[20];
int count= 1;
void mPrint() {
	printf("NO. %d: %s\n",count, path);
	count++;
}

bool canMove(int x, int y) {
	bool suc=true;
	if ((x==10) && (y==10)) {
		mPrint();
		return true;
	}
	if (x<=9 ) {
		path[x+y] = 'r';
		suc = canMove(x+1, y);
	}
	if (y<=9) {
		path[x+y] = 'd';
		suc = canMove(x, y+1);
	}
	if (!suc) printf("**********\n");
	return suc; 
}

int main() {
	
	canMove(0,0);
	return 0;

}
