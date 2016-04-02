#include <stdio.h>
#include <string.h>
#include <ctype.h>
//**************************************************************/ 
// Function: getStringProperties
// 
// Purpose: 
// Returns in a structure the following characteristics of a given string:  
//   1) string length (use strlen),        
//   2) number of upper case characters
//   3) number of lower case characters,        
//   4) number of digits
//   5) number of blank spaces
//   6) number of non-alphanumeric characters.
//
// Parameters: 
// char string[] - input string
// 
// Returns: 
// strData - struct stringProperties strData (a structure variable)
//**************************************************************/ 
struct stringProperties
{
    int strLength;
    int strUpper;
    int strLower;
    int strDigit;
    int strBlank;
    int strNonAlpha;
};

struct stringProperties getStringProperties(char string[]);

int main(int argc, char **argv)
{
    char string[] = "ABCDE ##@## 0123456789 abcde";
    struct stringProperties strData = getStringProperties(string);
    printf("Length:%i \nUppercase:%i \nLowercase:%i \nDigits:%i \nBlanks:%i \nNon-alphanumeric:%i\n", 
    strData.strLength,
    strData.strUpper,
    strData.strLower,
    strData.strDigit,
    strData.strBlank,
    strData.strNonAlpha);
    
    return 0;
}

/* declare function of return type struct */
struct stringProperties getStringProperties(char string[])
{
    /* initialize and declare structure variable */
    struct stringProperties strData = {0,0,0,0,0,0};
    
    /* get structure length and assign to member */
    strData.strLength = strlen(string);
    
    int i; /* declare loop index */
    
    /* loop through the string */
    for(i = 0; string[i] != '\0'; i++)
    {
        if(isupper(string[i]))      /* use ctype.h check uppercase */
        {
            strData.strUpper++;     /* if true increment member count */
        }
        else if(islower(string[i])) /* use ctype.h check lowercase */
        {
            strData.strLower++;
        }
        else if(isdigit(string[i])) /* use ctype.h check if digit */
        {
            strData.strDigit++;
        }
        else if(isspace(string[i])) /* use ctype.h check whitespace */
        {
            strData.strBlank++;
        }
        else if(!isalnum(string[i])) /* use ctype.h check non-alphanumeric */
        {
            strData.strNonAlpha++;
        }
    }
    return (strData); /* return structure variable to caling function */
}