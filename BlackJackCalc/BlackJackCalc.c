//**************************************************************/ 
// Function: main
// 
// Purpose: takes the values of a two-card blackjack hands as
// input and returns the point total of the hand. The value  of 
// the cards '2' through '9' is equal to their face value, 
// the cards 'T', 'K', 'Q', 'J' are worth 10 points and the 
// ace ('A') is worth 11 points unless it comes with another ace,
// then that second ace is worth only 1 point.
//
// Parameters: 
// char card1 - first card
// char card2 - second card
//
// Returns: 
// int card_hand_value - total hand value of 2 cards
// checks validity of input and returns error message if invalid
//**************************************************************/

#include <stdio.h>
#include <string.h> 
#include <ctype.h> 

/* for me, best solution for readability & maintainability is */
/* by use of switch statements and macro to define case/switch body */
#define CARD_VALUE(ch_input,char_val,card_val) case ch_input: card_val = char_val; break;

/* main function */
int main ()
{
    char card1; /* first card character */
    char card2; /* second card character */
    
    /* prompt user for input */
    printf("Enter two cards (0-9, T=10, K, Q, J, A):"); 
    scanf("%c %c", &card1, &card2);
    
    int card1_int; /* first card integer value */
    int card2_int; /* second card integer value */
    card1 = toupper(card1); /* take care of lower case input */
    card2 = toupper(card2);
    
    /* switch to first card input */
    switch(card1)
    {
        /* problem statement defines value of each character */
        CARD_VALUE('2',2,card1_int);
        CARD_VALUE('3',3,card1_int);
        CARD_VALUE('4',4,card1_int);
        CARD_VALUE('5',5,card1_int);
        CARD_VALUE('6',6,card1_int);
        CARD_VALUE('7',7,card1_int);
        CARD_VALUE('8',8,card1_int);
        CARD_VALUE('9',9,card1_int);
        CARD_VALUE('T',10,card1_int);
        CARD_VALUE('K',10,card1_int);
        CARD_VALUE('Q',10,card1_int);
        CARD_VALUE('J',10,card1_int);
        case 'A':
        card1_int = 11;
        break;
        
        default:
        /* warn user of invalid entry */
        printf("***Invalid Entry. %c is not a valid card.", card1);
        return(0); /* end main */
        break;
    } /* switch 1 */
    
    /* switch to second card input */
    /* see comments for switch 1 */
    switch(card2)
    {
        CARD_VALUE('2',2,card2_int);
        CARD_VALUE('3',3,card2_int);
        CARD_VALUE('4',4,card2_int);
        CARD_VALUE('5',5,card2_int);
        CARD_VALUE('6',6,card2_int);
        CARD_VALUE('7',7,card2_int);
        CARD_VALUE('8',8,card2_int);
        CARD_VALUE('9',9,card2_int);
        CARD_VALUE('T',10,card2_int);
        CARD_VALUE('K',10,card2_int);
        CARD_VALUE('Q',10,card2_int);
        CARD_VALUE('J',10,card2_int);
        case 'A':
        if (card1_int == 11)
        {
            card2_int = 1;
        }
        else
        {
            card2_int = 11;
        }
        break;
        
        default:
        printf("***Invalid Entry. %c is not a valid card.", card2);
        return(0); /* end main */
        break;
    } /* switch 2 */
    /* if all goes well and there are no invalid entries */
    /* compute total hand value */
    int card_hand_value = card1_int + card2_int;
    /* print total hand value */
    printf("The total is %i.", card_hand_value);
    return(0); /* end main */
} /* end main */

void Remove_String_Spaces (char *original_String){

// find out what the string size/length to save some memory later
int string_size = (strlen(original_String))+1;
//create a pointer to use it later in the "For Loop" in order to manipulate the string.
char *my_pointer;
// create an array to hold the original_string temporarily and set its maximum size (including spaces).
char temporar_array [string_size];
//copy what inside the original string to the array
strcpy(temporar_array, original_String);
//now you have the original string without changing its address in RAM.
//assign the value inside the temporar_array to the pointer
my_pointer = temporar_array;
//create a new array to copy the new string to it while looping.
//and this array will collect the chars after removing the spaces later, one by one.
//in order to save some memory in RAM, the maximum size of it will be the string length including the spaces
//declare the array and set its size using the string_size variable
char array_new_string [string_size];
//looping variable
int i = 0;
//"For Loop" to let the array_new_string pick up the chars from the original    string in the my_pointer but not the spaces,
//as long as the looping variable (i) is less than the string length
for (i = 0 ; i < string_size; my_pointer++ , i++){
 // while the address of the char contains a space, increment the the pointer (my_pointer) -only- to the next char in the string and evaluate again.
    while(*my_pointer  == ' ') {

       my_pointer ++ ;

     }
  // assign the proper char in the string which does not equal space according the previous While Loop to the element number (i) in the array_new_string to  .
   array_new_string[i] = *my_pointer ;
 }

 // finally copy the new string (which does not contain spaces)to the parameter which contained the original string.
strcpy(original_String,  array_new_string);

}