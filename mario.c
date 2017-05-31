#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("Height: ");
    int height = get_int();
    /*while loop to check user input*/
    while(height < 0 || height > 23)
    {
        //printf("Retry: ");
        printf("%d \n",height);
        height = get_int();
    }
    
    for(int x = 0; x < height; x++) 
	{
		/*Printing the spaces*/
        for(int y = 0; y < (height-x)-1; y++)
        {
            printf(" ");
        }
        /*Printing the # symbol*/
		for(int z = 0; z < x+2; z++)
		{
			printf("#");
		}
		printf("\n");
	}
	
	return 0;
    
}