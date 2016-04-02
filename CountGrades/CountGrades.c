#include <stdio.h>
#include <string.h>
#include <ctype.h> 
//**************************************************************/ 
// Function: countGrades
// 
// Purpose: Prints a report showing the total number of occurrences
// of each letter grade in an Array.
//
// Parameters: 
// inputGrades - an array of characters.
// 
// Returns: printed table showing grades and number of occurrences.
//**************************************************************/ 
void countGrades (char inputGrades[], int size);

int main(int argc, char **argv)
{
    char inputGrades[] = "ABBBDEEFFAAAACCCCDD";
    int size = strlen(inputGrades);
    countGrades (inputGrades, size);
    return (0);
}

void countGrades (char inputGrades[], int size) 
{ 
    char grades [size]; /* local variable for grades in uppercase */

    int i;             /* loop index */
    int countA = 0;    /* initialize counter for grade A */
    int countB = 0;    /* initialize counter for grade B */
    int countC = 0;    /* initialize counter for grade C */
    int countD = 0;    /* initialize counter for grade D */
    int countF = 0;    /* initialize counter for grade F */
    int countI = 0;    /* initialize counter for grade I */

    for (i=0; i < size; ++i) /* loop through every character */
    {
    	/* convert characters to uppercase and store in new array*/
    	grades [i] = toupper(inputGrades[i]); 

    	switch (grades[i])   /* use switch to compare */
    	{
    		case 'A':        /* if match, increase counter */
    		++countA;
    		break;

    		case 'B':        /* if match, increase counter */
    		++countB;
    		break;

    		case 'C':        /* if match, increase counter */
    		++countC;
    		break;

    		case 'D':        /* if match, increase counter */
    		++countD;
    		break;

    		case 'F':        /* if match, increase counter */
    		++countF;
    		break;

    		default:         /* otherwise, invalid input */
    		++countI;
    		break;
    	}
    }

    printf ("Grade \tTotal\n");      /* print headers */
    printf ("------ \t------\n");
    printf ("  A \t%3i\n" , countA); /* print results */
    printf ("  B \t%3i\n" , countB);  
    printf ("  C \t%3i\n" , countC); 
    printf ("  D \t%3i\n" , countD); 
    printf ("  F \t%3i\n" , countF); 
    printf ("  I \t%3i\n" , countI);
	
    return; /* return nothing: void function */
} /* end function */