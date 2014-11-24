#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define LIMIT 1000

int main()
{
	int i = 0, // iterator
		c = 0, // counter
		prim[LIMIT] = {0}; // initializing array prim with LIMIT
	
	// Initializes the prim elements as 1
	for(i = 2; i < LIMIT; i++)
		prim[i] = 1;	
	
	// Iterates from 2 to sqrt LIMIT
	// I noticed that to have a limit of
	// sqrt(LIMIT) is the same LIMIT
	// So for performance purposes
	// Although not noticeable.
	// It's better to be efficient.
	// To reduce CPU overhead
	for(i = 2; i < sqrt(LIMIT); i++)
		if(prim[i] == 1)
		{
			int j;
			
			// It went to the multiples of i
			// Set as zero if it is a multiple of i
			for(j = i; i * j < LIMIT; j++)
				prim[i * j] = 0;
		}
	
	// Iterates over the primes' elements	
	for(i = 2; i < LIMIT; i++)
		// If prints the current i value
		// if parallel pointer is not zero
		// Together with the counter if it is not set as zero
		if(prim[i] != 0) {
			printf("%d\t", i);
			c++;
		}
		
	printf("\n\nA total of %d prime numbers were found.", c);
	
	getch();
	return 0;
}
