#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//TODO
void letter_counts(char a[], int n, int counts[26])
{
    int index = 0;
for (int i = 0; i < n; i++){

    for (int x = 0; x < index; x++){
        if (a[i] != counts[x]){ //new occurance of a
            counts[index] = a[i];
            index++;
        }
    }
}
//have ceated a list of all unique letters into counts
for (int i = 0; i < n; i++){
    for (int x = 0; x < index; x++){
        if (a[i] == counts[x]){
            counts[x]++; //add for each occurance of the same type of letter is found
        }
    }       
}
}

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("Usage: %s n\n", argv[0]);
        return -1;
    }
    int n = atoi(argv[1]);
    printf("n=%d\n", n);
    assert(n >= 1 && n <= 10000);

    char a[n];
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += 2*i +1;
        a[i] = sum % 26 + 97;
    }

    int counts[26];
    letter_counts(a, n, counts);
    //TODO

    //printf("%2d %d\n", a[i], counts[i]);
    for (int i =0; i < n; i++){
        if (&counts[i] != &counts[0]){
                printf("%c %d\n", a[i], counts[i]);
        }

    }

    return 0;
}