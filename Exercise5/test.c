#include<stdio.h>
#include<stdlib.h>

void solveMagicSquare(int square[6][6])
{
    //int numbers[36];
    int row_sum = -1;
    int num_count = 0;

    // Init array of numbers to choose from
    /*for (int n = 0; n < 36; n++) {
        numbers[n] = n+1;
        //printf("%d\n", numbers[n-1]);
    }*/

    // Checking every number, ''removing'' options already in magix square

    // Loop over rows
    for (int i = 0; i < 6; i++) {
        int temp_sum = 0;
        num_count = 0;
        // Loop over numbers in each 'row'
        for (int j = 0; j < 6; j++) {

            // If box not -1, remove from numbers options, add temporary sum, increase numbers in row count
            if (square[i][j] != -1 && row_sum == -1) {
                //numbers[square[i][j]-1] = -1;
                temp_sum = temp_sum + square[i][j];
                num_count++;
            }
            printf("%d ", square[i][j]);
        }

        // If row filled, set sum to the temp sum.
        if (num_count == 6) {
            row_sum = temp_sum;
            // printf("num_count is 6, row_sum is: %d\n", row_sum);
        }
        printf("\n");
    }

    // if no row is filed, check if col is filled
    if (row_sum == -1)
    {
        for (int j = 0; j < 6; j++) {
            int temp_sum = 0;
            num_count = 0;
            for (int i = 0; i < 6; i++) {
                if (square[i][j] != -1) {
                    temp_sum = temp_sum + square[i][j];
                    num_count++;
                }
            }
            if (num_count == 6) {
                row_sum = temp_sum;
                //printf("num_count is 6, row_sum is: %d\n", row_sum);
            }
        }
    }
    
    //printf("Sum: %d\n", row_sum);


    // SOLVING :C
    int num_needed = 0;
    int solved = 1; // 0 for no, 1 for yes


    for (int c = 0; c < 12; c++) {
        for (int i = 0; i < 6; i++) {
            int temp_sum = 0;
            num_count = 0;
            
            for (int j = 0; j < 6; j++) {
                if (square[i][j] != -1) {
                    temp_sum = temp_sum + square[i][j];
                    num_count++;
                }
            }
            if (num_count == 5) {
                num_needed = row_sum - temp_sum;
                //printf("Sum:%d  Temp_sum:%d\n", row_sum, temp_sum);
                // printf("This row missing 1 num, number needed is: %d\n", num_needed);
                for(int j = 0; j < 6; j++)
                {
                    if (square[i][j] == -1)
                    {
                        square[i][j] = num_needed;
                        //numbers[num_needed - 1] = -1;
                    }
                }
            }
        }

        // check col for focus , then loop row + col
        for (int j = 0; j < 6; j++) {
            int temp_sum = 0;
            num_count = 0;
            for (int i = 0; i < 6; i++) {
                if (square[i][j] != -1) {
                    temp_sum = temp_sum + square[i][j];
                    num_count++;
                }
            }
            if (num_count == 5)
            {
                num_needed = row_sum - temp_sum;
                // printf("Sum:%d  Temp_sum:%d\n", row_sum, temp_sum);
                // printf("This col. missing 1 num, number needed is: %d\n", num_needed);
                for(int i = 0; i < 6; i++)
                {
                    if (square[i][j] == -1)
                    {
                        square[i][j] = num_needed;
                        //numbers[num_needed - 1] = -1;
                    }
                }
            }
        }

    }

    // now, check if solved:

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {

            if (square[i][j] == -1) {
                solved = 0;
                break;
            }
        }
    }

    if (solved == 1)
    {
        printf("Magic square is solved!\n");
    }
    else
    {
        printf("NOT SOLVED.");

        // implement harder algo :c

    }

}


// DO NOT MODIFY ANYTHING BELOW THIS LINE!
// (we mean it! the auto-checker won't be happy)
void printMagicSquare(int square[6][6])
{
   // Prints out the contents of a magic square 6x6

   int i,j,sum;

   for (i=0; i<6; i++)
   {
       sum=0;
       for (j=0; j<6; j++)
       {
           printf("%03d, ",square[i][j]);
           sum=sum+square[i][j];
       }
       printf(" : %03d\n",sum);
   }

   printf("---------------------------\n");

   for (j=0; j<6; j++)
   {
       sum=0;
       for (i=0; i<6; i++)
       {
	   sum=sum+square[i][j];
       }
       printf("%03d, ",sum);
   }
   printf("\n");
}

#ifndef __testing   // This is a compiler directive - used by the auto-checker to enable/disable this part of the code
int main()
{
    int magic[6][6]={{72, 63, 38, 56, 43, 61},{45, -1, 65, -1, 70, 52},{40, 58, -1, 60, 44, 62},{67, 49, 42, -1, 71, 53},{68, -1, 46, 64, 39, -1},{-1, -1, -1, -1, 66, 48}};

    /*
    72, 63, 38, 56, 43, 61
    45, 54, 65, 47, 70, 52
    40, 58, 69, 60, 44, 62
    67, 49, 42, 51, 71, 53
    68, 59, 46, 64, 39, 57
    41, 50, 73, 55, 66, 48
    */

    printMagicSquare(magic);
    printf("Solving Magic Square!\n");
    solveMagicSquare(magic);
    printMagicSquare(magic);

    return 0;
}
#endif
