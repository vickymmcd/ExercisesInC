/* Vicky McDermott

Program that takes input integers from the user and sums them up.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int get_input (int* count, int* array){
  """Function that gets input from the user and stores it in an array.
  """

  char input_num[10];

  while(scanf("%9s", input_num) != EOF)
  {

    if(*count>=10){
      printf("Sorry you entered too many values. \n");
      return 1;
    }

    if(strcmp(input_num, "0")==0){
      array[*count] = 0;
    }
    else{
      if(atoi(input_num)==0){
        printf("Sorry that string can't be converted to an integer. \n");
        return 1;
      }
      else{
        array[*count]= atoi(input_num);
      }
    }
    *count=*count+1;
  }
  return 0;
}

int get_sum(int *count, int *array){
  """Function that finds and returns the sum of count values in the given array.
  """

  int i;
  int sum = 0;

  for (i=0; i<*count; i++) {
      sum = sum+array[i];
  }

  return sum;
}

int main ()
{
    int array[10];
    int count = 0;
    int sum;

    printf("Enter up to 10 numbers to be added together. \n");

    if(get_input(&count, array)==1){
      return 1;
    }

    sum = get_sum(&count, array);

    printf("The sum of those numbers is: %d\n", sum);

}
