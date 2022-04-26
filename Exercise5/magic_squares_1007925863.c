////////////////////////////////////////////////
// CSC A48 - Winter 2022
//
// Exercise 5 - Solving Magic Squares
//
// (c) 2022 F. Estrada
////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

void solveMagicSquare(int square[6][6])
{
 // This function receives an array of size 6x6
 // that corresponds to a magic square.
 // It then finds any entries with value -1
 // (which means they are not known),
 // and figures out what their value should
 // be to solve the magic square.
 //
 // Conditions:
 // You can not hard-code the value of the rows
 // and columns in the magic square - because
 // we will test this with a *different* magic
 // square than the one in this starter code
 //
 // Your function has to (somehow) figure out
 // what the sum of the rows and columns should be,
 // and then figure out for each entry whose
 // value is -1, what its value is to correctly
 // complete the magic square.
 //
 // This is about problem solving - you don't
 // need any fancy pointer management or anything
 // like that. Just plain old C with a 2D array
 // and a bit of thinking.
 //
 // As a reminder. 2D arrays in C are indexed as
 // array[i][j] - gives you the element at row i,
 // column j

 //////////////////////////////////////
 
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
        }

        // If row filled, set sum to the temp sum.
        if (num_count == 6) {
            row_sum = temp_sum;
        }
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
            }
        }
    }
    
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


 //////////////////////////////////////
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
    int magic[6][6]={{32,29,4,1,24,21},{30,-1,2,3,-1,23},{12,9,17,20,28,25},{10,11,18,-1,26,27},{13,-1,36,33,5,8},{14,15,34,35,6,-1}};

    printMagicSquare(magic);
    printf("Solving Magic Square!\n");
    solveMagicSquare(magic);
    printMagicSquare(magic);

    return 0;
}
#endif
