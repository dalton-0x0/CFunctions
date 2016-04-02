#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdbool.h>
//**************************************************************/ 
// Function: checkPalindrome
// 
// Purpose: 
// An interactive function to etermine if a given string is a 
// palindrome.
// 
// A palindrome is a word or sentence that reads the same forward 
// as it does backward.
//
// Parameters: 
// char inputStr[] - an array of characters
// 
// Returns: 
// void - prints feedback to user when called from calling 
// function.
//**************************************************************/ 
void checkPalindrome (char inputStr[]);

int main(int argc, char **argv)
{
    char inputStr[] = " never odd or even ";
    checkPalindrome(inputStr);
    
    return (0);
}

void checkPalindrome (char inputStr[])
{
    /* step 1: remove spaces in array of characters (if any) */
    /* get string length, include null terminator */
    int inputStrSize = (strlen(inputStr)) + 1;
    
    /* temporary array to hold inpString, size includes spaces*/
    char tempArray [inputStrSize];
    
    /* copy inputStr to tempArray using strcpy */
    /* in so doing, inputStr's address is unchanged */
    strcpy(tempArray, inputStr);
    
    /* create a pointer to tempArray */
    char *myPtr;
    myPtr = tempArray;
    
    /* a new string is created to be manipulated */
    /* will collect the characters after spaces are */
    /* removed from tempArray. */
    char newInputStr[inputStrSize];
    
    int i = 0; /* loop counter */
    
    for (i = 0; i < inputStrSize; myPtr++, i++)
    {
        while (*myPtr == ' ')      /* while current pointer value is space */
        {
            myPtr++;               /* skip it*/
        }
        newInputStr[i] = *myPtr;   /* assign non-space chars to new input string */
    }
    strcpy(inputStr, newInputStr); /* copy into inputStr, preserve address */
    
    
    /* step 2: change inputStr to lowercase */
    int j;  /* loop counter */
    for (j = 0; inputStr[j]; j++)
    {
        /* convert eacch character using tolower function */
        inputStr[j] = tolower(inputStr[j]);
    }
    /* print results for user */
    printf("Forward  string is: ");
    printf("%s\n", inputStr);
    
    
    /* step 3: create a backward string */
    
    /* get length of inputString (since not same as original */
    int strLength = strlen(inputStr);
    
    /* copy contents of inputStr into reverseStr */
    /* start with the last character in inputStr */
    char reverseStr[strLength];
    int k;   /* loop counter */ 
    for (k = 1; k <= strLength; k++) /* recall array elements */
    {
        /* recall how to access array elements */
        reverseStr[k-1] = inputStr[strLength-k];
    }
    
    /* print backward string for user */
    printf("Backward string is: ");
    printf("%s\n", reverseStr);
    
    /* step 4: compare inputStr and reverseStr */
    /* if they are the same, we have a palindrome */
    
    /* use strcmp function for comparison */
    /* recall strcmp retuns 0 for same */
    if (strcmp(inputStr, reverseStr) == 0)
    {
        /* print confirmation for user */
        printf("The string is a Palindrome.\n");
    }
    else
    {
        /* print confirmation for user */
        printf("The string is not a Palindrome.\n");
    }
} /* end function */