#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdbool.h>
//**************************************************************/ 
// Function: legalWord
// 
// Purpose: 
// Determines if a given word is legal. A word is illegal if it 
// contains no vowels. The letter Y is considered to be a legal
// vowel. The following assumptions are made about the word: 
// 1) The string being passed is a combination of letters only.
// 2) The string being passed is null terminated.
//
// Parameters: 
// char oneWord[] - a one word string
// 
// Returns: 
// legal - if legal, returns 1 (true) to calling function, 
// if the word is not legal, returns  0 (false) to 
// calling function..
//**************************************************************/ 
int legalWord (char inputStr[]);

int main(int argc, char **argv)
{
    char inputStr[] = "sch";
    int checkMarker = legalWord(inputStr);
    
    printf("Is input string legal? %s\n",checkMarker == 0 ? "FALSE" : "TRUE");
    
    return(0);
}

int legalWord (char oneWord[]) 
{
    int i = 0;           /* loop counter (character counter) */
    int numOfVowels = 0; /* counter (number of vowels in string) */
    int legal;           /* legality checker 0 = false, 1 = true, ref. (stdbool.h) */
    while (oneWord[i] != '\0')      /* loop until null terminator */
    {
        switch(toupper(oneWord[i])) /* change case for uniformity */
        {
            case 'A':       /* legal vowel from problem statement */
            numOfVowels++;
            break;
            
            case 'E':       /* legal vowel from problem statement */
            numOfVowels++;
            break;
            
            case 'I':       /* legal vowel from problem statement */
            numOfVowels++;
            break;
            
            case 'O':       /* legal vowel from problem statement */
            numOfVowels++;
            break;
            
            case 'U':       /* legal vowel from problem statement */
            numOfVowels++;
            break;
            
            case 'Y':       /* legal vowel from problem statement */
            numOfVowels++;
            break;
            
            default:
            legal = 0;      /* the word is illegal */
            break;
        }
        i++;                /* increase loop counter */
    }
    if (numOfVowels > 0)    /* if we found any vowels, then */
    {
        legal = 1;          /* the word is legal */
    }
    return (legal);         /* return to calling function */
}  /* end legalWord function */