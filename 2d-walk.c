#include <stdio.h>
#include <stdlib.h>

double two_d_random(int n)
{

	//Fill in code below
	//When deciding which way to go for the next step, generate a random number as follows.
	//r = rand() % 4;
	//Treat r = 0, 1, 2, 3 as up, right, down and left respectively.

	//The random walk should stop once the x coordinate or y coordinate reaches $-n$ or $n$. 
	//The function should return the fraction of the visited $(x, y)$ coordinates inside (not including) the square.

int xcord = 0;
int ycord = 0;
int count = 1;
int check = 1;
int* X = calloc(0, sizeof(int));
int* Y = calloc(0, sizeof(int));
do
{
	int r = rand() % 4;
	switch(r) {
		case 0: //up: increase y
		ycord++;
		break;
		case 1: // right increase x
		xcord++;
		break;
		case 2: // down decreasy y
		ycord--;
		break;
		default: //left decrease x
		xcord--;
		break;
	}
	if (xcord == n || xcord == (n*-1) || (ycord == n || ycord  == (n*-1))){//(xcord == abs(n) || ycord == abs(n)){
		check = 0;
		break;
	}
	int chk = 1;
	for(int i = 0; i < count; i++){
		if (xcord == X[i] && ycord == Y[i]){
			chk = 0;
		}
	}
	if(chk == 1 && check == 1){
		X = realloc(X, (count+1) * sizeof(X));
		X[count] = xcord;
		Y = realloc(Y, (count+1) * sizeof(Y));
		Y[count] = ycord;
		count++;
	}
}
while(check == 1);

double frac = (2*n - 1) * (2*n - 1);
frac = count/frac;
return frac;
}




//Do not change the code below
int main(int argc, char* argv[])
{
int trials = 1000;
int i, n, seed;
if (argc == 2) seed = atoi(argv[1]);
else seed = 12345;
srand(seed);
for(n=1; n<=64; n*=2)
{
double sum = 0.;
for(i=0; i < trials; i++)
{
double p = two_d_random(n);
sum += p;
}
printf("%d %.3lf\n", n, sum/trials);
}
return 0;
}
