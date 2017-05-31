#include <stdio.h>
#include <cs50.h>
/*need for round function
round( ) function in C returns the nearest integer value of the 
float/double/long double argument passed to this function, took inspiration from here:
http://fresh2refresh.com/c-programming/c-arithmetic-functions/c-round-function/
*/
#include <math.h>

int main()
{
    printf("How much change is owed?\n");
    float change = get_float();
    while(change < 0)
    {
        printf("How much change is owed?\n");
        change = get_float();
    }
    
    /*this allows us to convert our change into cent and round it off as well*/
    int cents = (int)round(change*100);
    
    int coins =0;
    /*nested while loop decrements value of $0.25, $0.10, $0.05 and $0.01 as long as cent is >0
    it also increments our counter coin each time
    */
    while(cents > 0)
    {
        while(cents >= 25)
    {
        coins ++;
        cents = cents - 25;
       
    }
    while(cents >= 10)
    {
        coins ++;
        cents = cents - 10;
      
    }
    while(cents >= 5)
    {
        coins ++;
        cents = cents - 5;
    }
    while(cents >= 1)
    {
        coins ++;
        cents = cents - 1;
    }
}
   
    printf("%d\n",coins);
    return 0;
 
}