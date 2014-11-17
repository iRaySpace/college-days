#include<stdio.h>

int display_solid_square(int sym, int sid)
{
	int x;
	
	// iterating from 0 to given number of sides - 1
	// if x is divisible by the side given by the user
	// prints newline with the given symbol
	
	// reminder: alternative to nested looping
	for(x = 0; x < sid * sid; x++)
		(x % sid != 0) 
			? printf("%c", sym) // if true
			: printf("\n%c", sym); // if false
}

int main()
{
	int ch = 0,
		nm = 0;
		
	printf("Enter the symbol : ");
	scanf("%c", &ch);
	
	printf("Enter the number : ");
	scanf("%d", &nm);
	
	display_solid_square(ch, nm);
	
	getch();
	return 0;	
}
