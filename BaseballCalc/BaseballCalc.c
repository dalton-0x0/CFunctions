/*--------------------------------------------------------------*/ 
/* NAME:     Dalton Okechukwu                                   */ 
/*                                                              */ 
/* CLASS:    C Programming (INFO.90.267)                        */ 
/*                                                              */ 
/* DATE:     01-Apr-2016                                        */ 
/*                                                              */
/* DESCRIPTION:                                                 */
/* This program contains a main function and seven other        */
/* functions used to calculate baseball offensive statistics:   */
/* calcTotalBases - calculates and returns total bases          */
/* calcBattingAvg - calculates and returns batting average      */
/* calcHomeRunRatio - calculates and returns home run ratio     */
/* calcStrikeOutRatio - calculates and returns strikeout ratio  */
/* calcOnBasePercent - calculates and returns on base percentage*/
/* calcSluggingAvg - calculates and returns slugging average    */
/* printPlayerStats - prints the data in a formatted table      */
/*--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>   /* for malloc */
#include <ctype.h>    /* for toupper */
#include <string.h>

/*  declare global structure for each player's stats */
struct playerStats
{
    char firstName [10];  /* player's first name */
    char lastName  [10];  /* player's last name */
    float walks;          /* player's walks */
    float strikeOuts;     /* player's strike outs */
    float hitByPitch;     /* player's hits by pitch */
    float sacFlys;        /* player's sacrificial flys */
    float hits;           /* player's hits */
    float singles;        /* player's single runs */
    float doubles;        /* player's double runs */
    float triples;        /* player's triple runs */
    float homeRuns;       /* player's home runs */
    float atBats;         /* player's at bats */
    float totalBases;     /* to be calculated: total bases */
    float battingAvg;     /* to be calculated: batting average */
    float homeRunRatio;   /* to be calculated: home run ratio */
    float strikeOutRatio; /* to be calculated: strike out ratio */
    float onBasePercent;  /* to be calculated: on base %age */
    float sluggingAvg;    /* to be calculated: slugging avg */
    struct playerStats *next;  /*  pointer to the next node in linked list */
};
/* declare function prototypes */ 
/* see program main header for descriptions */ 
float calcTotalBases(float singles, float doubles, float triples, float homeRuns);
float calcBattingAvg(float hits, float atBats);
float calcHomeRunRatio(float homeRuns, float atBats);
float calcStrikeOutRatio(float strikeOuts, float atBats);
float calcOnBasePercent(float hits, float walks, float hitByPitch, float sacFlys, float atBats);
float calcSluggingAvg(float singles, float doubles, float triples, float homeRuns, float atBats);
void printPlayerStats(struct playerStats *play1);

/*-----------------------------------------------------------------------------*/
/* FUNCTION:     main                                                          */
/*                                                                             */
/* DESCRIPTION:  This function will prompt the user for information regarding  */
/*               all the players to be considered and creates a linked list    */
/*               of platerStats structures to contain all the  data.  It also  */
/*               calls the six calculator funtions and one printing function   */
/*               already described. It places each data point into the linked  */
/*               list at the appropriate node.                                 */
/*                                                                             */
/* PARAMETERS:   None                                                          */
/*                                                                             */
/* OUTPUTS:      headpointer - pointer to first node of new linked list        */
/*                                                                             */
/* CALLS:        calcTotalBases, calcBattingAvg, calcHomeRunRatio,             */
/* calcStrikeOutRatio, calcOnBasePercent, calcSluggingAvg, printPlayerStats    */
/*-----------------------------------------------------------------------------*/
int main()
{
    char   answer[5];       /* storage for user's response to adding more players */
    char   value;           /* gets the first character of above answer */
    int    moreData = 1;    /* flag to check if another player is to be processed */
    
    struct playerStats *currentPointer,   /* pointer to current node */
                       *headPointer;      /* always points to first node */
                       
    /* Set up storage for first node */
    headPointer = (struct playerStats *) malloc (sizeof(struct playerStats));
    currentPointer = headPointer;
    while (moreData)
    {
		/* Read in and assign player stats by input prompts */
        printf("Enter player's first and last name: ");
        scanf("%s %s", &currentPointer->firstName, &currentPointer->lastName);
        printf("Enter %s %s's Walks (BB): ", &currentPointer->firstName, &currentPointer->lastName);
        scanf("%f", &currentPointer->walks);
        printf("Enter %s %s's Strike Outs (SO): ", &currentPointer->firstName, &currentPointer->lastName);
        scanf("%f", &currentPointer->strikeOuts);
        printf("Enter %s %s's Hit by Pitch (HBP): ", &currentPointer->firstName, &currentPointer->lastName);
        scanf("%f", &currentPointer->hitByPitch);
        printf("Enter %s %s's Sac Flys (SF): ", &currentPointer->firstName, &currentPointer->lastName);
        scanf("%f", &currentPointer->sacFlys);
        printf("Enter %s %s's Hits (H): ", &currentPointer->firstName, &currentPointer->lastName);
        scanf("%f", &currentPointer->hits);
        printf("Enter %s %s's Singles(1B): ", &currentPointer->firstName, &currentPointer->lastName);
        scanf("%f", &currentPointer->singles);
        printf("Enter %s %s's Doubles (2B): ", &currentPointer->firstName, &currentPointer->lastName);
        scanf("%f", &currentPointer->doubles);
        printf("Enter %s %s's Triples (3B): ", &currentPointer->firstName, &currentPointer->lastName);
        scanf("%f", &currentPointer->triples);
        printf("Enter %s %s's Home Runs (HR): ", &currentPointer->firstName, &currentPointer->lastName);
        scanf("%f", &currentPointer->homeRuns);
        printf("Enter %s %s's Number of At Bats (AB): ", &currentPointer->firstName, &currentPointer->lastName);
        scanf("%f", &currentPointer->atBats);
        
        /* call function as described, assign outputs */
        currentPointer->totalBases     = calcTotalBases(currentPointer->singles, currentPointer->doubles, 
                                         currentPointer->triples, currentPointer->homeRuns);
        currentPointer->battingAvg     = calcBattingAvg(currentPointer->hits, currentPointer->atBats);
        currentPointer->homeRunRatio   = calcHomeRunRatio(currentPointer->homeRuns, currentPointer->atBats);
        currentPointer->strikeOutRatio = calcStrikeOutRatio(currentPointer->strikeOuts, currentPointer->atBats);
        currentPointer->onBasePercent  = calcOnBasePercent(currentPointer->hits, currentPointer->walks, 
                                         currentPointer->hitByPitch, currentPointer->sacFlys, currentPointer->atBats);
        currentPointer->sluggingAvg    = calcSluggingAvg(currentPointer->singles, currentPointer->doubles, 
                                         currentPointer->triples, currentPointer->homeRuns, currentPointer->atBats);
        
        /* confirm if there's more input */
        printf("\nWould you like to add another player? (Y/N):");
        scanf("%s", answer);
 
        /* if no, end */
        if ((value = toupper(answer[0])) != 'Y')
        {
			currentPointer->next = (struct playerStats *) NULL;
			moreData = 0; 
        }
        else /* if yes, point to next */
        {
			/* set the next pointer of the current node to point to the new node */
			currentPointer->next = (struct playerStats *) malloc (sizeof(struct playerStats));
			/* move the current node pointer to the new node */
			currentPointer = currentPointer->next;
		}
    } /* end while loop */
    
    /* call printing function */
    printPlayerStats(headPointer);
    
    /* goodbye message */
    printf("End of Program, Thank You\n");
    
    return (0); /* return safely*/
} /* end main */

/*-----------------------------------------------------------------------------*/
/* FUNCTION:     calcTotalBases                                                */
/*                                                                             */
/* DESCRIPTION:  This function will calculate the total bases scored           */
/*                                                                             */
/* PARAMETERS:   float singles, float doubles, float triples, float homeRuns   */
/*                                                                             */
/* OUTPUTS:      float totalBases                                              */
/*                                                                             */
/* CALLS:        None                                                          */
/*-----------------------------------------------------------------------------*/
float calcTotalBases(float singles, float doubles, float triples, float homeRuns)
{
    float totalBases;
    totalBases = (singles + (2*doubles) + (3*triples) + (4*homeRuns));
    return (totalBases);
} /* end calcTotalBases */

/*-----------------------------------------------------------------------------*/
/* FUNCTION:     calcBattingAvg                                                */
/*                                                                             */
/* DESCRIPTION:  This function will calculate the player's batting average     */
/*                                                                             */
/* PARAMETERS:   float hits, float atBats                                      */
/*                                                                             */
/* OUTPUTS:      float battingAvg                                              */
/*                                                                             */
/* CALLS:        None                                                          */
/*-----------------------------------------------------------------------------*/
float calcBattingAvg(float hits, float atBats)
{
    float battingAvg;
    battingAvg = hits/atBats;
    return (battingAvg);
} /* end calcBattingAvg */

/*-----------------------------------------------------------------------------*/
/* FUNCTION:     calcHomeRunRatio                                              */
/*                                                                             */
/* DESCRIPTION:  This function will calculate the player's homerun ratio       */
/*                                                                             */
/* PARAMETERS:   float homeRuns, float atBats                                  */
/*                                                                             */
/* OUTPUTS:      float homeRunRatio                                            */
/*                                                                             */
/* CALLS:        None                                                          */
/*-----------------------------------------------------------------------------*/
float calcHomeRunRatio(float homeRuns, float atBats)
{
    float homeRunRatio;
    homeRunRatio = homeRuns/atBats;
    return (homeRunRatio);
}/* end calcHomeRunRatio */

/*-----------------------------------------------------------------------------*/
/* FUNCTION:     calcStrikeOutRatio                                            */
/*                                                                             */
/* DESCRIPTION:  This function will calculate the player's strikeout ratio     */
/*                                                                             */
/* PARAMETERS:   float strikeOuts, float atBats                                */
/*                                                                             */
/* OUTPUTS:      float strikeOutRatio                                          */
/*                                                                             */
/* CALLS:        None                                                          */
/*-----------------------------------------------------------------------------*/
float calcStrikeOutRatio(float strikeOuts, float atBats)
{
    float strikeOutRatio;
    strikeOutRatio = strikeOuts/atBats;
    return (strikeOutRatio);
} /* calcStrikeOutRatio */

/*-----------------------------------------------------------------------------*/
/* FUNCTION:     calcOnBasePercent                                             */
/*                                                                             */
/* DESCRIPTION:  This function will calculate the player's on base percentage  */
/*                                                                             */
/* PARAMETERS:   float hits, float walks, float hitByPitch, float sacFlys,     */
/*               float atBats                                                  */
/*                                                                             */
/* OUTPUTS:      float onBasePercent                                           */
/*                                                                             */
/* CALLS:        None                                                          */
/*-----------------------------------------------------------------------------*/
float calcOnBasePercent(float hits, float walks, float hitByPitch, float sacFlys, float atBats)
{
    float onBasePercent;
    onBasePercent = (hits + walks + hitByPitch)/(atBats + walks + hitByPitch + sacFlys);
    return (onBasePercent);
}/* end calcOnBasePercent */

/*-----------------------------------------------------------------------------*/
/* FUNCTION:     calcSluggingAvg                                               */
/*                                                                             */
/* DESCRIPTION:  This function will calculate the player's slugging average    */
/*                                                                             */
/* PARAMETERS:   float singles, float doubles, float triples, float homeRuns,  */
/* float atBats                                                                */
/*                                                                             */
/* OUTPUTS:      float sluggingAvg                                             */
/*                                                                             */
/* CALLS:        None                                                          */
/*-----------------------------------------------------------------------------*/
float calcSluggingAvg(float singles, float doubles, float triples, float homeRuns, float atBats)
{
    float sluggingAvg;
    sluggingAvg = (singles + (2*doubles) + (3*triples) + (4*homeRuns))/(atBats);
    return (sluggingAvg);
}/* end calcSluggingAvg */

/*-----------------------------------------------------------------------------*/
/* FUNCTION:     printPlayerStats                                              */
/*                                                                             */
/* DESCRIPTION:  This function will print the contents of a linked list of     */
/*               baseball players. It will traverse the list from beginning to */
/*               end, printing the contents at each node.  It will also print  */
/*               a list of compiled stats regarding the players                */
/*                                                                             */
/*                                                                             */
/* PARAMETERS:   player1 - pointer to a linked list of baseball players        */
/*                                                                             */
/* OUTPUTS:      None                                                          */
/*                                                                             */
/* CALLS:        None                                                          */
/*-----------------------------------------------------------------------------*/
void printPlayerStats(struct playerStats *player1)
{
    struct playerStats *tempPlayer;  /* tmp pointer value to current player node */
    
	int i = 0;                       /* counts the player nodes printed */
 
	char name [20];                  /* string to hold full name for each player */
 
	/* Start a beginning of list and print out each value               */
	/* loop until tempPlayer points to null (remember null is 0 or false)  */
	printf("---------------------------------------------------------------\n");
	printf ("%-10s \t%s \t%s \t%s \t%s \t%s \t%s \n", 
	"Name", 
	"TBP", 
	"BAV", 
	"HRR", 
	"SOR", 
	"OBP",
    "SLA");
	printf("---------------------------------------------------------------\n");
	for(tempPlayer = player1; tempPlayer ; tempPlayer = tempPlayer->next)
	{
		i++;
        /* copy and concatenate names */
		strcpy(name, tempPlayer -> firstName);
		strcat(name, " ");
		strcat(name, tempPlayer -> lastName);
        /* print data */
		printf("%-10s \t%3.0f \t%0.3f \t%0.3f \t%0.3f \t%0.3f \t%0.3f\n", 
		name, 
        tempPlayer->totalBases,
        tempPlayer->battingAvg, 
        tempPlayer->homeRunRatio, 
        tempPlayer->strikeOutRatio, 
        tempPlayer->onBasePercent,
        tempPlayer->sluggingAvg);
	}
	printf("---------------------------------------------------------------\n");
}/* end printPlayerStats */