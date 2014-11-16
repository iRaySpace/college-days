#include <iostream>
#include <cmath>

#define MAX 10

// offset paramaters
#define FC_OFFSET 0
#define SC_OFFSET 1

using namespace std;

int main()
{
	int x = 0;

	while(x < MAX * 2)
	{
		int y = x < MAX ? x : (MAX * 2 - x) - 1; // zero-based be like
		int z = (MAX - y) - 1; // zero-based

		// printing wonders
		while(y > 0 - FC_OFFSET && y-- < MAX) cout << "- ";
		while(z > 0 - SC_OFFSET && z-- < MAX) cout << "* ";
	
		cout << endl;
		
		x = (x == MAX - 1 || 
			 x ==(MAX * 2 / 2) - 1) 
			 ? x += 2 
			 : x += 1;
		// escapes unnecessary parts

	}

	return 0;
}