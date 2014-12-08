#include<stdio.h>

// "I hereby certify that this program code submitted as a requirement for the course CS 12 A is accomplished with all due honesty. 
//  I am fully aware of the consequences should I cheat in this program code. 
//  Consequences for any actions considered academic dishonesty are stipulated in the XU Student Handbook."

#define SIZE 5
#define OFFSET 1 // Since the array is zero-based

int main()
{
	// Declaring an array
	// with the SIZE as the maximum
	// num of arrays and nested arrays
	// 5 * 5 = 25 arrays all in all.
	int arr[SIZE][SIZE];
	
	// Used for iteration purposes
	int x, y;
	
	// Iterating over the size of the array
	for(y = 0; y < SIZE; y++)
		for(x = 0; x < SIZE; x++)	
			// Tertiary expression
			// If it is true
			// It will return 0
			// However, I used tertiary expression again
			// tertiary-ception.
			// If x < (SIZE - OFFSET) - y
			// It will return 1 else -1
			arr[y][x] = (x == (SIZE - OFFSET) - y) ? 0 
					  : ((x < (SIZE - OFFSET) - y) ? 1 : -1);
	
	// (SIZE - OFFSET) - y , further explanation:
	// If you get the current SIZE of the MATRIX - OFFSET
	// You will get the last index of the square matrix
	// Since, you will need to find out the middle
	// You need to subtract it by the current iteration value of y
	
	// Responsible for displaying the square matrix
	for(y = 0; y < SIZE; y++) {
		
		for(x = 0; x < SIZE; x++) printf("%d\t", arr[y][x]);
		printf("\n\n");
		
	}
	
	getch();
	return 0;
}
