#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //as per spec, argc must be 2
    if (argc == 2)
    {
        //as command line argv is a string, per spec we convert it to int
        //calling atoi, takes string, gives int key
        int key = atoi(argv[1]);
        
        
        //prompting user for plaintext
        printf("plaintext:  ");
        string plaintext = get_string();
        
        
        //conversion to our ciphertext
        int n = strlen(plaintext);
        //c and y are placeholder variables
        char c = 0;
        char y = 0;
        for(int i=0; i < n; i++)
        {
            //first a check if our char is indeed an alphabet
            if(isalpha(plaintext[i]))
            {
                if(isupper(plaintext[i]))
                {
                    //do our ciphering
                    //a pattern of 65 is seen for upper case
                    //so we subtract 65 and make an index for upper case
                    c = plaintext[i] - 65;
                    y = (c  + key) % 26;
                    y = y + 65 ;
                    plaintext[i] = y;
                    
                    
                }
                else if(islower(plaintext[i]))
                {
                    //do our ciphering
                    //a pattern of 97 is seen for lower case
                    //so we subtract from 97 and make an index for lower case
                    c = plaintext[i] - 97;
                    y = (c  + key) % 26;
                    y = y + 97 ;
                    plaintext[i] = y;
                    
                }
            }
            
        }
        //print our cipher text
        printf("ciphertext:  %s",plaintext);
        printf("\n");
        return 0;
        
    }
    
    else
    {
        //incorrect command line arguments entered, so we exit.
        printf("Error: Incorrect amount of command line arguments entered. \n");
        return 1;
    }
}