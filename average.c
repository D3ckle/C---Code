#include <stdio.h>
// Only this line of comment is provided
int main(void)
{
int i = 0;

double total = 0; double average = 0;
double x;
while (scanf("%lf", &x) == 1) { // pay attention to %lf

total+=x; i++;
average = total/i;
printf("Total=%f Average=%f\n", total, average); // pay attention to %f

};

}

