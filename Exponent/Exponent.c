#include <stdio.h>

//**************************************************************/ 
// Function: x_to_the_n
// 
// Purpose: raises an integer to a positive integer power.
//
// Parameters: 
// x - integer to be exponentiated
// n - integer exponent
// 
// Returns: result of exponentiation.
//**************************************************************/ 
int x_to_the_n (int x, int n);
int main(int argc, char **argv)
{
    int x = 5;
    int n = 2;
    int answer = x_to_the_n (x, n);
    printf("%i raised to the power %i is: %i\n", x, n, answer);
    return 0;
}

int x_to_the_n (int x, int n)
{
	long int result = x; /* assign x to local variable */

	int i;               /* initialize loop index */

	/* loop through (n-1) times */ 
	/* if n = 1, this loop doesn't run, result is returned */
	for (i = 1; i <= (n-1); ++i) 
	{
	    result *= x;     /* multiply by x and assign back to result */ 
	}
	return (result);     /* return result to calling function */ 
} /* end function */