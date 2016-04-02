#include <stdio.h>

//**************************************************************/ 
// Function: frequency 
// 
// Purpose: Counts the frequency of occurence of an array element
// among the first n elements of the array.
//
// Parameters: 
// theArray - array containing element of interest
// n - number of elements to search starting from first
// x - integer value of element of interest 
// 
// Returns: countX - number of x found in array
//**************************************************************/ 
int frequency (int theArray[], int n, int x);
int main()
{
    int theArray[] = {1,1,1,1,1,1,1,1,2,6,5,8,4,9,9,5,4,2,2,2};
    int arrayLength = sizeof(theArray) / sizeof(theArray[0]);
    printf("The number of %i's found array is: %i\n", 9, frequency(theArray, arrayLength, 9));
    return (0);
}


int frequency (int theArray[], int n, int x) 
{ 
    int countX = 0; /* local counter variable */

    int i; /* loop index */

    for (i=0; i < n; ++i) /* search only within given range */
    {
    	if (theArray[i] == x) /* compare current element to search */
    	{
            ++countX; /* increase count if true */
    	}
    	else 
    	{
    	    countX = countX; /* do nothing otherwise */
    	}
    }
    return (countX); /* return number of x found */
} /* end function */