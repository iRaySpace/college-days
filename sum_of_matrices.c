#include<stdio.h>

#define NUM_OF_MATRIX 3
#define SIZE 4

int main()
{
	// Declaring and Initializing the 3D MATRIX
	// with the size of NUM MATRIX
	// and SIZE and SIZE
	int matrix[NUM_OF_MATRIX][SIZE][SIZE]
		= {
			{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}},
		    {{2, 4, 6, 8}, {10, 12, 14, 16}, {18, 20, 22, 24}, {26, 28, 30, 32}},
		    {{0}, {0}, {0}, {0}}
		  };
	
	// Used for iteration purposes
	int x = 0,
		y = 0,
		z = 2; // Since I would like to start the last index of the MATRIX
			   // To store the SUM of the MATRICES
	
	// Iterating over the loop 
	// Adds the matrix of the current index - 1, y and x
	// to the current index - 2, y and x.
	// And stored in the current index y and x
	// current index - 2, in this case is the FIRST MATRIX
	// current index - 1, in this case is the SECOND MATRIX
	for(y = 0; y < SIZE; y++)
		for(x = 0; x < SIZE; x++) 
			matrix[z][y][x] = matrix[z - 1][y][x] 
							+ matrix[z - 2][y][x];
			
	
	// Responsible for printing the MATRIX
	for(z = 0; z < NUM_OF_MATRIX; z++)
	{
		// I use switch case to avoid if statements
		// I hate if statements sometimes
		// It just do the thing of knowing its place and output the 
		// designated text to be outputted
		// If 0 then it is the first matrix of the problem
		// If 1 it is second matrix
		// However, if it is 2, it is the sum of the matrices
		switch(z)
		{
			case 0: printf("First Matrix:\n\n");  	  break;
			case 1:	printf("Second Matrix:\n\n"); 	  break;
			case 2:	printf("Sum of the matrices:\n\n"); break;
		}
		
		// Iterates over y to SIZE
		// and Z to SIZE
		// SINCE it is a 4X4 MATRIX
		
		// ==
		// Z corresponds to the current MATRIX index
		// Y corresponds to the iteration of the arrays within the MATRIX array
		// X corresponds to the iteration of the values inside of an array within the MATRIX array
		// ==
		for(y = 0; y < SIZE; y++)
		{
			for(x = 0; x < SIZE; x++) 
				printf("%d\t", matrix[z][y][x]);
				
			printf("\n");
		}
		
		printf("\n");
	}
		
	getch();
	return 0;
}
