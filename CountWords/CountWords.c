#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdbool.h>
//**************************************************************/ 
// Function: countWords
// 
// Purpose: Counts the number of words in an array of characters
// (i.e. a string). This function assumes at least one word will 
// be entered by user. Another assumption is that white spaces 
// and/or the terminating null character are delimiters between
// words. It is a robust function that takes into consideration 
// of white spaces both before and after a word without counting
// them. 
//
// Parameters: 
// stringOfWords[] - string with words to be counted (must have 
//                   at least one word).
// 
// Returns: 
// countWords - number of words in the given string.
//**************************************************************/ 
int countWords (char stringOfWords[]);

int main(int argc, char **argv)
{
    char inputStr[] = " one TWO three      foUR five SIX   seVEN    ";
    
    printf("The number of words in the string is: %i\n",countWords(inputStr));
    
    return(0);
}

int countWords (char stringOfWords[]) 
{
	int i = 0;          /* loop counter (character counter) */
	int numOfWords = 0; /* word counter */
	int strLength;      /* number of characters in string */
	/* recall that strlen does not include the terminating */
	/* null character in its count */
	strLength = strlen(stringOfWords);
	
	/* skip white spaces at beginning of string array */
	while (stringOfWords[i] == ' ')
	{
		i++;
	}
	/* continue loop counter after skipping white spaces */
	/* at beginning of string array */
	for (; i <= strLength; i++)
	{
		/* this if-statement is sure to capture the first word */
		if (stringOfWords[i] == ' ' || stringOfWords[i] == '\0')
		{
			numOfWords++;
			/* from problem statement: assume that one or more */
			/* consecutive white spaces is a delimiter between words */
			/* while loop checks for consecutive white spaces and */
			/* does not add to word counter if consecutive */
			while (stringOfWords[i++] == ' ')
			{
				/* continue until a non-white space is found */
				/* or a terminating null character is found */
				if (stringOfWords[i] != ' ' || stringOfWords[i] == '\0')
				{
					/* do nothing, exit while loop */
					/* return to for loop */
				}
			}
		}
	}
	return (numOfWords); /* return number of words*/
} /* end function */