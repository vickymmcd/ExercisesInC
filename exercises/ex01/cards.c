/*
 * Program to evaluate face card values.
 * Modified by Vicky McDermott
 * Released under the Vegas Public License.
 * (c)2014 The College Blackjack Team.
 */

 #include <stdio.h>
 #include <stdlib.h>

 /* Prompts the user for input and puts the reply in the given buffer.

    User input is truncated to the first two characters.

    prompt: string prompt to display
    card_name: buffer where result is stored
 */
 void get_card_name(char *prompt, char *card_name){
   puts(prompt);
   scanf("%2s", card_name);
 }

 /* Gets the card value value based on the card name.

    card_name: name of the card inputted
    my_default: default value for when it is a number
 */
 int get_card_val(char card_name, int my_default){
   int val = 0;
   switch(card_name){
     case 'K':
     case 'Q':
     case 'J':
       val = 10;
       break;
     case 'A':
       val = 11;
       break;
     case 'X':
       break;
     default:
       val = my_default;
       if (val < 1 || val > 10){
         puts("Error! Bad value!");
         break;
       }
   }
   return val;
 }

 /* Updates the count depending on the value.

    val: the value to check and use to update count
    count: the current count value
 */
 int update_count(int val, int count){
   if (val >= 3 && val <= 6)
     count++;
   else if (val == 10)
     count--;
   return count;
 }

 /* Main function to evaluate face card values.
 */
 int main()
 {
   char card_name[3];
   int count = 0;
   int val;
   do{
     get_card_name("Enter the card name: ", card_name);
     val = get_card_val(card_name[0], atoi(card_name));
     if (val == 0){
       continue;
     }
     count = update_count(val, count);
     printf("Current count: %i\n", count);
   } while(card_name[0] != 'X');
   return 0;
 }
