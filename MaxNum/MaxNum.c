#include <stdio.h>

//**************************************************************/ 
// Function: maxNum 
// 
// Purpose: Returns the largest value of 4 integer arguments.
//
// Parameters: 
// x, y, w, z - integers
// 
// Returns: max - largest number.
//**************************************************************/ 

int maxNum (int x, int y, int w, int z);
int main()
{
    int theMax = maxNum (89, 45, 156, 14);
    printf("The maximum argument is: %i\n", theMax);
    return (0);
}

int maxNum (int x, int y, int w, int z) 
{ 
    int tempArray [4] = {x, y, w, z}; /* initialize a local array variable */

    int i; /* loop index */

    int max = 0; /* initialize local variable for storage */

    for (i=0; i < 4; ++i) /* loop through temp array */
    {
    	if (tempArray[i] > max) /* compare array element to max */
    	{
    		max = tempArray[i]; /* replace max if greater */
    	}
    	else
    	{
    		max = max; /* do nothing otherwise */
    	}
    }
    return (max); /* return largest number */
} /* end function */