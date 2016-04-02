#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdbool.h>
//**************************************************************/ 
// Function: validDate
// 
// Purpose: Function that is passed a month, day, and year as 
// integers and will determine if that date is valid. Parameters
// must be entered in the order specified (mm, dd, yyyy).
//
// Parameters: 
// mm   - month passed as integer
// dd   - day passed as integer
// yyyy - year passed as integer
// 
// Returns: 
// valid - if valid, returns 1 (true) to calling function, 
// if the date is not valid, returns 0 (false) to 
// calling function.
//**************************************************************/  
int validDate (int mm, int dd, int yyyy);

int main(int argc, char **argv)
{
    int checkMarker1 = validDate (5, 31, 1961);
    int checkMarker2 = validDate (13, 4, 1967);
    int checkMarker3 = validDate (2, 29, 2016);
    
    printf("Is 05/31/1961 valid? %s\n",checkMarker1 == 0 ? "FALSE" : "TRUE");
    printf("Is 13/04/1967 valid? %s\n",checkMarker2 == 0 ? "FALSE" : "TRUE");
    printf("Is 02/29/2016 valid? %s\n",checkMarker3 == 0 ? "FALSE" : "TRUE");
    
    return (0);
}

int validDate (int mm, int dd, int yyyy)
{
    int valid = 0; /* validity checker 0 = false ref. (stdbool.h) */
    
    /* create an array of number of days in a month */
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    /* check for leap year, by definition: */
    /* leap year if year is a multiple of 4 */
    /* not leap year if it's a multiple of 100 */
    /* unless it is also a multiple of 400 */
    
    if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0))
    {
        /* if leap year, change month 2 no of days to 29 */
        monthDays[1] = 29;
    }
    if (yyyy != 0) /* check validity of year */
    {
        if (mm >= 1 && mm <= 12) /* check validity of month */
        {
            if (dd <= monthDays[mm-1]) /* check validity of day */
            {
                /* if all these check out ok, then date is valid */
                valid = 1; /* validity checker 1 = true ref. (stdbool.h) */
            }
        }
    }
    return (valid); /* return validity */
} /* end function */

