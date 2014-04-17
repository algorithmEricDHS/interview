#include <stdio.h>
#include <ostream>

int a[8] = {0,0,0,0,0,0,0,0};
static int count=0;
void mPrint() {
	int i, j;
	count++;
	for (i=0;i<8; i++) {
		for(j=0;j<a[i]; j++) {
			printf ("$");
		}
		printf ("%d", a[i]);
		for (j=a[i]+1; j < 8; j++) printf ("$");
		printf("\n");
	}
	printf("No. %d way******************************\n", count);
	
}
bool canP (int row) {
	int i;
	int diff;
	for (i=0; i< row;i++) {
		diff = ((a[row] -a[i]) >0?(a[row]-a[i]):(a[i]-a[row]));
		if ((0 ==diff) || diff == (row - i)) return false; 
	}
	return true;
}
void mPlace(int row) {
	int i;
	if (8 == row) {
		mPrint();	
		return;
	}
	for(i=0;i<8;i++) {
		a[row] = i;
		if (canP(row))
		{
			mPlace(row+1);
		} 
	}
	
}

int main() {
	mPlace(0);
	return 0;
}
