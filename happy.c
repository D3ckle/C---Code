#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;

	printf("n = ");
	scanf("%d", &n);

	int m = n;

	//TODO
	//add code below
	while(n!= 1 && n!=4){ //to check the upper limit does not reach 4, and if it does, it is an unhappy #
		int total = 0;
		while( n >= 1){ // adding up squares for the number of 
			total += (n%10)*(n%10); // adding up the squares towards the total
			n /= 10;
		}
		n = total;
		printf("%d\n", n); // to match the output in the example in hw specs
	}


	if(n==1) printf("%d is a happy number.\n", m);
	else printf("%d is NOT a happy number.\n", m);
	return 0;
}