#include<stdio.h>

#define MAX 5

void display_2d_square_array(int ar[][MAX])
{
	// Loops through the array
	// In order to display
	// the value of the array
	for(i = 0; i < MAX; i++) {
		for(j = 0; j < MAX; j++) 
			printf("%d ", x[j][i]);
			
		printf("\n");
	}
}

int main()
{
	int i, j, k,
		x[MAX][MAX]; // Declaring the 2D array
	
	// Initializes the array from 1 to MAX elements of the array
	// by using k as the counter and th value initializer
	for(i = 0, k = 1; i < MAX; i++)
		for(j = 0; j < MAX; j++)
			x[j][i] = k++;
	
	printf("Original Matrix \n");
	display_2d_square_array(x); // Calling the function to print the array
	
	// Navigates through the array
	// However, there is a twist
	// Instead of navigating each one of them
	// I use i to initialize j
	// Which will be used to navigate each from the
	// right side of the array
	for(i = 0; i < MAX; i++)
		for(j = i; j < MAX; j++)
		{
			// If it is in the middle, SKIP the current iteration
			if(j == i) continue;
			
			// SWAP the values from the
			// right side to the left side
			// by using a temp variable.
			int temp = x[j][i];
			x[j][i] = x[i][j];
			x[i][j] = temp;
		}
	
	printf("Transpose of the Matrix \n");
	display_2d_square_array(x); // Calling the function to print the array

	getch();
	return 0;
}
