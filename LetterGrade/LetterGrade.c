#include <stdio.h>

//**************************************************************/ 
// Function: letterGrade
// 
// Purpose: Returns the grade for a given text score.
//
// Parameters: 
// score - test score from 0 to 100.
// 
// Returns: grade - letter grade.
//**************************************************************/
char letterGrade (float score);

int main()
{
    char yourGrade = letterGrade(85);
    printf("Your Grade is: %c\n", yourGrade);
    return (0);
}

char letterGrade (float score) 
{ 
    char grade; /* local variable for grade */

    if (score > 100 || score < 0) /* check if score is out of range */
    	grade = 'I'; /* if so, return grade I for invalid */
    else if (score >= 90) /* score 90 - 100 = 'A' */
    	grade = 'A';
    else if (score >= 80) /* score 80 - 89 = 'B' */
    	grade = 'B';
    else if (score >= 70) /* score 70 - 79 = 'C' */
        grade = 'C';
    else if (score >= 60) /* score 60 - 69 = 'D' */
        grade = 'D';
    else
    	grade = 'F';      /* score below 60 = 'A' */

    return (grade); /* return letter grade to calling function */
} /* end function */