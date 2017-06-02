#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//these are placeholder chars which are used for the ciphering mathematics
char y = 0;
char y_key = 0;

int main(int argc, string argv[])
{
    //check to ensure that the user only enters two command line arguments
    //i.e ./vigenere KEYWORD
    if(argc != 2)
    {
        //if argc != we simply exit
        printf("Invalid argc amount, was expecting only.\n");
        return 1;
    }
    
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        //an iteration through every char of argv to ensure that it is indeed an alphabet
        if (!(isalpha(argv[1][i])))
        {
            //if EACH char is not an alphabet, simply exit
            printf("Error: argv does not contain only alphabets.\n");
            return 1;
        }
    }
    
    //setting the limit for iteration involving the keyword
    int n = strlen(argv[1]);
    char mykey[n];
    
    //for simplicity, I am copying over every element from the keyword into this array of char
    //char arrays are easier to handle than strings in C, b/c strings are immutable
    //char arrays are relatively easier to handle
    for (int i = 0; i < n; i++)
    {
        //copying of keyword chars into mykey[]
        mykey[i] = argv[1][i];
    }
    
    //typical prompt to ask user for plaintext    
    printf("plaintext:  ");
    string plaintext = get_string();
    int j = 0 ;
    //j = j % n;    
    for(int i=0, l = strlen(plaintext);i < l; i++)
        
    {
        //j acts as the index for our keyword, it iterates through it
        //as it is independent of the incrementation for plaintext
        j = j % n;
        
        //we only do our ciphering math if the char in plaintext is indeed an alphabet
        //if not, we let it be
        if (isalpha(plaintext[i]))
        {
            if(isupper(plaintext[i]) && isupper(mykey[j]))
            {
                //this is my interpretation of the ciphering math
                //so basically I make an index of keyword ASCII chars by removing 65 for uppercase
                //I than mod it by 26, it converts our ASCII char into an alphabetical index
                y_key = (mykey[j] - 65) % 26;
                
                //I than do a similar thing for plaintext
                //make ASCII char into an alphabetical index of sorts
                //than for the proper shift, I just add y_key which is the placeholder for 
                //keyword into plaintext
                y = ((plaintext[i] - 65)  + y_key) % 26;
                y = y + 65 ;
                plaintext[i] = y;
               
             }    
            else if(islower(plaintext[i]) && islower(mykey[j]))
            {
                //this is my interpretation of the ciphering math
                //so basically I make an index of keyword ASCII chars by removing 97 for lowercase
                //I than mod it by 26, it converts our ASCII char into an alphabetical index

                //I than do a similar thing for plaintext
                //make ASCII char into an alphabetical index of sorts
                //than for the proper shift, I just add y_key which is the placeholder for 
                //keyword into plaintext

                y_key = (mykey[j] - 97) % 26;
                y = ((plaintext[i] - 97)  + y_key) % 26;
                y = y + 97 ;
                plaintext[i] = y;

            }
            else if(islower(plaintext[i]) && isupper(mykey[j]))
            {
                //mixed version of my ciphering math involving case where plaintext char is lower
                //and key is upper
                y_key = (mykey[j] - 65) % 26;
                y = ((plaintext[i] - 97)  + y_key) % 26;
                y = y + 97 ;
                plaintext[i] = y;
                
            }
            else if(isupper(plaintext[i]) && islower(mykey[j]))
            {
                
                //mixed version of my ciphering math involving case where plaintext char is upper
                //and key is lower
                y_key = (mykey[j] - 97) % 26;
                y = ((plaintext[i] - 65)  + y_key) % 26;
                y = y + 65 ;
                plaintext[i] = y;
                
            }
            //increment j
            j++;
        }        
    }
        //print ciphertext
        printf("ciphertext: %s", plaintext);
        printf("\n");
        return 0;
 }
    

