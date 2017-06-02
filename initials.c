#include <stdio.h>
#include <cs50.h>
//need ctype.h for toupper
#include <ctype.h>
//need string.h for strlen
#include <string.h>

int main()
{
    //get user input
    string name = get_string();
    
    //n to set limit as strlen for our loop
    int n = strlen(name);
    
    //print the first letter upper case
    printf("%c",toupper(name[0]));
    for(int i= 0; i < n; i++)
    {
        /*go through each char in string
        if hit empty space
        upper case the next char
        */
        if(name[i] == 32)
        {
           printf("%c",toupper(name[i+1])); 
        }
    }
    //as per spec, print new line at the end
    printf("\n");
}