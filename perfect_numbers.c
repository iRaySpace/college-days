#include<stdio.h>
#include<stdbool.h>

#define MAX 10000

bool is_perfect_num(int num)
{
	int x = 1,
		sum = 0;
	
	// iterates over the number between 1 and the given number
	// sums up if it is divisible
	while(x < num)
	{
		if(num % x == 0) 
			sum = sum + x;
			
		x++;
	}
	
	if(sum == num) return true;
	else 		   return false;
		
}

void disp_perfect_num()
{
	int x;
	
	printf("The perfect numbers are : \n");
	
	// iterates over the number between 1 and the MAX given numbers
	// prints if is a perfect number
	for(x = 1; x < MAX; x++)
		if (is_perfect_num(x))
			printf("%d\n", x);
}

int main()
{
	disp_perfect_num();
	getch();
	return 0;
}
