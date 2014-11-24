#include<stdio.h>

#define MAX 10

int main()
{
	int	x = 0, // even counter 
		y = 0, // odd counter
		even[MAX] = {0},
	    odd[MAX]  = {0};
	
	int i = 0;
	
	printf("Enter ten numbers : ");
	
	// do a while loop with the sum of x and y
	// if the sum is greater or equal to the MAX
	// exit the loop
	while(x + y < MAX)
	{
		int temp = 0;
		scanf("%d", &temp);
		
		// if the number is even 
		// set the even with x counter as temp
		// likewise is odd.
		if(temp % 2 == 0) even[x++] = temp;
		else	 		  odd[y++]  = temp;
		
	}
	
	// iterates from 0 to numbers of even
	printf("Even numbers(%d) : ", x);
	
	for(i = 0; i < x; i++) 
		printf("%d ", even[i]);
	
	printf("\n");
	
	// iterates from 0 to numbers of odd
	printf("Odd numbers(%d) : ", y);
	
	for(i = 0; i < y; i++)
		printf("%d ", odd[i]);
	
	printf("\n");
	
	getch();
	return 0;
}
