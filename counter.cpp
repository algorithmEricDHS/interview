#include <stdio.h>
#include <ostream>

int main() {
        int i, j, k;
        int sum;
	int n=1;
        for(i=0; i<=4;i++) {
                for (j=0;j<=((100-25*i)/10);j++){
                        for (k=0; k<=(100-25*i-10*j);k++) {
                                sum = 25*i + 10 *j + k;
                                if (100==sum) {
					printf("NO. %d way: 25*%d + 10*%d + 1* %d \n", n,i,j,k);
					n++;
				}
                        }
                }
        }


        return 0;
}
