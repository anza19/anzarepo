#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("Enter how long you shower for: ");
    int duration = get_int();
    while(duration < 0)
    {
        printf("Enter a valid POSITIVE integer for duration: ");
        duration = get_int();
    }
    int bottles = duration * 12;
    printf("You have consumed %d bottles of water while showering for %d minutes.\n",bottles,duration);
    
    return 0;
}