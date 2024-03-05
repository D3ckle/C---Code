#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;

	printf("n = ");
	scanf("%d", &n);

	//TODO
	//add code below 
    double pi = 0.0;
    for (i = 0; i <= n; i++) { // in order to do each step of the summation, we need to calulate each value between 0 and 'n' (input)
        double denom = 1; //the changing denominator for the pi aprox. equation 
        for (int x = 1; x <= i; x++){ // since we can not use the power function, we must manually multiply 16 'i' times
            denom *= 16;
        }
        pi += (4.0/(8*i+1)-2.0/(8*i+4)-1.0/(8*i+5)-1.0/(8*i+6))*(1/denom);
    }
	
	printf("PI = %.10f\n", pi);
	return 0;
}