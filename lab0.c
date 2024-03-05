#include <stdio.h>
int main(void)
{
printf("Hello, World!\n");
int i, sum = 0;
while(i < 200){
    
    sum += i;
    i+=2;
}
printf("%d", sum, "\n");

return 0;
}



