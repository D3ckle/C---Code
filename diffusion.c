#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//TODO
//Implement the below function
//Simulate one particle moving n steps in random directions
//Use a random number generator to decide which way to go at every step
//When the particle stops at a final location, use the memory pointed to by grid to 
//record the number of particles that stop at this final location
//Feel free to declare, implement and use other functions when needed

void one_particle(int *grid, int n)
{
	int x = 0, y = 0, z = 0; //starting location of origin
	for (int i = 0; i < n; i++) { // do n times; move in any of the 6 directions
		int move = rand()%6; //6 possible moves, ranging from 0-5
		if (move == 0) {x++;}
		else if (move == 1) {x--;}
		else if (move == 2) {y++;}
		else if (move == 3) {y--;}
		else if (move == 4) {z++;}
		else {z--;}
	}
	grid[(x+ n) + ((2*n) + 1)*(y+n)+((2*n) + 1)*(2*n +1)*(z+n)]++;
}

//TODO
//Implement the following function
//This function returns the fraction of particles that lie within the distance
//r*n from the origin (including particles exactly r*n away)
//The distance used here is Euclidean distance
//Note: you will not have access to math.h when submitting on Mimir
double density(int *grid, int n, double r)
{
	double inside = 0, total = 0;
	//inside = number of particles within the spherical radius of r*n
	//total = total number of particles
	for (int x = -n; x <= n; x++){ //ranges from farthest on x-axis
    	for (int y = -n; y <= n; y++){ // ranges from farthest on y-axis
        	for (int z = -n; z <= n; z++){ // ranges from farthest on z-axis
				total += grid[(x+n) + ((2*n)+1)*(y+n) + ((2*n) +1)*((2*n)+ 1 ) * (z+n)];
            	if (((x*x) + (y*y) + (z*z)) <= (r*n*r*n)){ //distance eqn squared to remove sqrt; within the spherical radius
                	inside += grid[(x + n) + ((2*n) + 1)*(y + n) + ((2*n)+1)*((2*n)+1)*(z+n)];
                }
            }
        }
	}
	double ratio = inside / total; //the ratio between the particles in the sphere compared to all particles
    return ratio;    
}

//use this function to print results
void print_result(int *grid, int n)
{
    printf("radius density\n");
    for(int k = 1; k <= 20; k++)
    {
        printf("%.2lf   %lf\n", 0.05*k, density(grid, n, 0.05*k));
    }
}

//TODO
//Finish the following function
//See the assignment decription on Piazza for more details
void diffusion(int n, int m)
{
	//fill in a few line of code below
	int *grid = calloc(((2*n)+1)*((2*n)+1)*((2*n)+1), sizeof(int));

	for(int i = 1; i<=m; i++) one_particle(grid, n);
	print_result(grid, n);
	//fill in some code below
	free(grid);
}

int main(int argc, char *argv[])
{
	
	if(argc != 3)
	{
		printf("Usage: %s n m\n", argv[0]);
		return 0; 
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	assert(n >= 1 && n <=50);
	assert(m >= 1 && m <= 1000000);
	srand(12345);
	diffusion(n, m);
	return 0;
}