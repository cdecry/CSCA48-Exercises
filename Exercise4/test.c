#include<stdio.h>
#include<stdlib.h>
#define MAX_STR_LEN 1024

void wordSwapper(char *dest, char *src)
{
    // Find string length
    int string_length = 0;

    while (*(src + string_length) != '\0')
    {
        string_length++;
    }

    int valid_space_start = 0;
    int j = string_length - 1;
    int i = 0;

    // Find valid_space_start
    for(int k = valid_space_start; k < string_length; k++)
    {
        if (*(src + k) == ' ' && *(src + k - 1) != ' ')
        {
            valid_space_start = k;
            //printf("Valid space start is: %d\n", valid_space_start);
            break;
        }
    }

    // Iterates backwards
    while (j >= 0) 
    {
        int letters = 0;
        int space_count = 0;

        // Counts letters until space
        while (*(src + j) != ' ' && j >= 0)
        {
            letters = letters + 1;
            j--;
        }

        // Iterates forwards n letters, set destination index 0 to i as letters
        for (int k = 1; k < letters + 1; k++) 
        {
            *(dest + i) = *(src + j + k);
            i++;
        }
        //printf("Added %d letters\n", letters);

        if ((letters > 0 && j > 0) || valid_space_start == 0)
        {
            // Count spaces from valid_space start
            while(*(src + valid_space_start) == ' ')
            {
                space_count++;
                //printf("Space count is: %d\n", space_count);
                valid_space_start++;
            }

            // Find new valid space start
            for(int k = valid_space_start; k < string_length; k++)
            {
                if (*(src + k) == ' ' && *(src + k - 1) != ' ')
                {
                    valid_space_start = k;
                    //printf("Valid space start is: %d\n", valid_space_start);
                    break;
                }
            }

            // Add correct number of spaces
            for(int k = 0; k < space_count; k++)
            {
                *(dest + i) = ' ';
                i++;
                //printf("Adding %d spaces\n", space_count);
            }
        }
        
        j--;
    }
    *(dest + i) = '\0';
}

#ifndef __TESTING
int main()
{
    char source[MAX_STR_LEN]="silence .is a looking bird:the turning; edge, of life. e. e. cummings";
    char destination[MAX_STR_LEN]="I am a destination string and I contain lots of junk 1234517265716572@qsajdkuhasdgsahiehwjauhiuiuhdsj!";

    printf("The original string is: \n%s\n",source);

    // Call word swapper with the address of the first character in 'source' and the first character in 'destination'
    wordSwapper(&destination[0], &source[0]);
    // You could also call wordSwapper like this: wordSwapper(destination,source) since, as we will have seen in
    // lecture this week, the array's name can be used to pass into a function the address of the first entry
    // in the array.
    
    printf("Destination string after swapping: \n%s\n",destination);    
}
#endif