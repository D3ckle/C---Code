#include <stdio.h>
#include <stdlib.h>

int oddSumHelp(int count, int bound, int value)
{
	//fill in your code below
//count = the number of integers whose total sum is value
//bound = the upper limit the numbers can be at / must be small than bound
//value = the value which we want the sums of the numbers to equal to
int cur_num = bound; //using the bound as a stepping stone to check if it is a valid number to check for the seqence
if (count == 0 && value == 0)
{ //fail safe for the recursive steps
	return 1; //if 1 is returned then that means it is a valid number used as a part of the solution
}
if (count < 0 || bound <= 0 || value < 0){ //only accounting for positive # inputs
	return 0;
}
if (bound %2 == 0) { //skip the even numbers, and go to the next step for an odd #
	return oddSumHelp(count, bound - 1, value);
}
if (oddSumHelp(count - 1, bound - 1, value - bound) == 1) { //found a proper number sequence to satisfy its sum = value
	printf("%d ", cur_num);
	return 1;
}
return oddSumHelp(count, bound - 1, value);
}

//Do not change the code below
void oddSum(int count, int bound, int value)
{
    	if(value <= 0 || count <= 0 || bound <= 0) return;
    
    	if(bound % 2 == 0) bound -= 1;

    	if(!oddSumHelp(count, bound, value)) printf("No solutions.\n");
	else printf("\n");
}

int main(int argc, char *argv[])
{
	if(argc != 4) return -1;

	int count = atoi(argv[1]);
	int bound = atoi(argv[2]);
	int value = atoi(argv[3]);

	//oddSum(12,30,200);
	//oddSum(10,20,100);
	//oddSum(20,20,200);
	oddSum(count, bound, value);
	return 0;
}

