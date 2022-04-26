#include <stdio.h>
#include <stdlib.h>

void print_sudoku(int sudoku[9][9])
{
  printf("The Sudoku contains:\n");
  for (int j=0; j<9; j++)
  {
    for (int i=0; i<9;i++)
    {
      printf("%d  ",sudoku[j][i]);
    }
    printf("\n");
  }
}

int check_sudoku(int sudoku[9][9])
{
    /*
    *  This function checks whether a Sudoku is properly
    * solved. That means that each row, column, and
    * 3x3 subgrid uses each digit only once.
    * 
    *  If *ignores* zeros, so you can use it to check
    * that a partial solution is valid
    */

    int numbers[10];
    for (int n = 0; n < 10; n++)
    {
        numbers[n] = 0;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            //printf("%d\n", sudoku[i][j]);
            if (sudoku[i][j] != 0 && numbers[sudoku[i][j]] == 1)
            {
                return 0;
            }
            else
                numbers[sudoku[i][j]] = 1;
        }
        //printf("------------\n\n");
        for (int n = 0; n < 10; n++)
        {
            numbers[n] = 0;
        }
    }
    
    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            if (sudoku[i][j] != 0 && numbers[sudoku[i][j]] == 1)
            {
                return 0;
            }
            else
                numbers[sudoku[i][j]] = 1;
        }

        for (int n = 0; n < 10; n++)
        {
            numbers[n] = 0;
        }
    }


    for (int k = 0; k < 3; k++)
    {
        for (int b = 0; b < 3; b++)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    //printf("%d\n", sudoku[i + (3*k)][j + (3*b)]);
                    if (sudoku[i + (3*k)][j + (3*b)] != 0 && numbers[sudoku[i + (3*k)][j + (3*b)]] == 1)
                    {
                        return 0;
                    }
                    else
                        numbers[sudoku[i + (3*k)][j + (3*b)]] = 1;
                }
                //printf("~~\n");
            }
            //printf("------------\n\n");
            for (int n = 0; n < 10; n++)
            {
                numbers[n] = 0;
            }
        }
    }

    return 1;
}

int solved(int sudoku[9][9])
{
  /*
   * This function checks whether a given Sudoku is
   * completely solved (it has no zeros, all digits
   * are used once per row, column, and sub-grid.
   * It returns 1 if the Sudoku is solved, zero
   * otherwise
   */
  
  int numbers[10];
    for (int n = 0; n < 10; n++)
    {
        numbers[n] = 0;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            //printf("%d\n", sudoku[i][j]);
            if (sudoku[i][j] == 0 || numbers[sudoku[i][j]] == 1)
            {
                return 0;
            }
            else
                numbers[sudoku[i][j]] = 1;
        }
        //printf("------------\n\n");
        for (int n = 0; n < 10; n++)
        {
            numbers[n] = 0;
        }
    }
    
    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            if (sudoku[i][j] == 0 || numbers[sudoku[i][j]] == 1)
            {
                return 0;
            }
            else
                numbers[sudoku[i][j]] = 1;
        }

        for (int n = 0; n < 10; n++)
        {
            numbers[n] = 0;
        }
    }


    for (int k = 0; k < 3; k++)
    {
        for (int b = 0; b < 3; b++)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    //printf("%d\n", sudoku[i + (3*k)][j + (3*b)]);
                    if (sudoku[i + (3*k)][j + (3*b)] == 0 || numbers[sudoku[i + (3*k)][j + (3*b)]] == 1)
                    {
                        return 0;
                    }
                    else
                        numbers[sudoku[i + (3*k)][j + (3*b)]] = 1;
                }
                //printf("~~\n");
            }
            //printf("------------\n\n");
            for (int n = 0; n < 10; n++)
            {
                numbers[n] = 0;
            }
        }
    }
  
    return 1;  
}


void solve_sudoku(int sudoku[9][9], int depth)
{

    /*
    * This function solves an input Sudoku, the
    * input has a value of 0 for any entries that
    * are not yet decided. If no solution exists
    * the function returns the input array *exactly
    * as it was* when the function was called.
    * 
    * The 'depth' parameter is provided in case you
    * want to use it to help debug and trace your
    * code. You do not need to use it if you don't
    * want to, and the problem can be solved without
    * using the depth value at all. 
    * 
    * The automated checker won't look at the depth
    * either.
    */

    int missing = 0;
    int missing_index = -1;
    int numbers[10];
    int invalid_counter = 0;
    int invalid_counter_s = 0;
    int num_invalid[10];
    int num_invalid_s[10];
    int index_wanted[10];
    for (int n = 0; n < 10; n++)
    {
        numbers[n] = 0;
    }

    for (int n = 0; n < 10; n++)
    {
        num_invalid[n] = 0;
    }
    for (int n = 0; n < 10; n++)
    {
        index_wanted[n] = -1;
    }
    for (int n = 0; n < 10; n++)
    {
        index_wanted_s[n] = -1;
    }

    if (check_sudoku(sudoku) == 0 || solved(sudoku) == 1)
    {
        printf("Sudoku is solved, or is invalid.\n");
        //return;
    }
    

    // check each row for 1

        // find what numbres are missing in the row
        // for each zero, try each check if a number is already in row, column, box
        //      if not, add one to counter which is open, story in array
        //  if counter only one, then add the one stored in array


    for (int i = 0; i < 9; i++) // for each row
    {
        int row_pos = -1;
        if ((float)i / 3.0 < 1.0)
        {
            row_pos = 0;
        }
        else if ((float)i / 3.0 < 2.0)
        {
            row_pos = 3;
        }
        else
        {
            row_pos = 6;
        }

        for (int j = 0; j < 9; j++) // finding missing numbers pt. 1
        {
            if (sudoku[i][j] != 0)
            {
                numbers[sudoku[i][j]] = 1;
            }
            else
            {
                missing++;
                missing_index = j;
            }
        }

        // if only one missing, :>

        if (missing == 1)
        {
            for (int j = 1; j < 10; j++) // which numbers are missing?
            {
                if (numbers[j] == 0)
                {
                    sudoku[i][missing_index] = j;
                    printf("Only one missing number: %d, at index %d\n", j, missing_index);
                }
            }
        }
        else if (missing > 1)
        {
            for (int j = 0; j < 9; j++) // for each zero..
            {
                if (sudoku[i][j] == 0)
                {
                    int num_wanted = 0;
                    for (int k = 1; k < 10; k++) // for each missing number..
                    {
                        if (numbers[k] == 0)
                        {
                            // k
                            // check, col, sub

                            int col_counter = 0;
                            for (int c = 0; c < 9; c++)
                            {
                                if (sudoku[c][j] == k) // check if each missing number can go here, increase counter if cannot
                                {

                                    //printf("%d cannot go in (%d, %d)\n", k, i, j);
                                    invalid_counter ++;
                                    num_invalid[k] ++;
                                    // if this number cant go in 3 spots and there are only 4 avail, :>
                                    if (num_invalid[k] == missing - 1)
                                    {
                                        printf("ROW: %d can only go in (%d, %d).\n", k, i, index_wanted[k]);
                                        sudoku[i][index_wanted[k]] = k;
                                        numbers[k] = 1;
                                    }

                                    break;
                                }
                                else if (c == 8)
                                {
                                    num_wanted = k;
                                }
                                col_counter++;
                            }

                            if (col_counter == 9)
                            {
                                //printf("COL: Row %d does not contain %d\n", j, k);
                                index_wanted[k] = j;
                            }
                            col_counter = 0;

                            // check sub

                            // rn: for each zero, fro each missing number,  check zero position and check the subgrid
                            int col_pos = -1;

                            if ((float)j <= 2)  // first third subgrid
                            {
                                col_pos = 0;
                            }
                            else if((float)j <= 5)
                            {
                                col_pos = 3;
                            }
                            else
                            {
                                col_pos = 6;
                            }

                            for (int y = row_pos; y < row_pos + 3; y++)
                            {
                                for (int z = col_pos; z < col_pos + 3; z++)
                                {
                                    if (sudoku[y][z] == k)
                                    {
                                        // for this subgrid, for every zero in these set cols
                                        for (int w = col_pos; w< col_pos + 3; w++)
                                        {
                                            if (sudoku[i][w] == 0)
                                            {
                                                num_invalid_s[k]++;
                                            }
                                        }
                                        invalid_counter_s ++;

                                        break;
                                    }
                                }
                            }



                        }


                    }

                    if (invalid_counter == missing - 1)
                    {
                        printf("Onlny one number can go in row %d, column %d: %d\n", i, j, num_wanted);
                        
                        sudoku[i][j] = num_wanted;
                        num_wanted = 0;
                    }
                    // else
                    // {
                    //     printf("%d\n", invalid_counter);
                    // }
                    invalid_counter = 0;

                }
            }

            // for (int j = 1; j < 10; j++) // which numbers are missing?
            // {
            //     if (numbers[j] == 0)
            //     {
            //         printf("In this %dth row, missing: %d\n", i+1, j);
            //     }
            // }
            // printf("----\n");

        }
        missing = 0;
        missing_index = -1;
        invalid_counter = 0;
        invalid_counter_s = 0;
        for (int n = 0; n < 10; n++)  // reset numbers array
        {
            numbers[n] = 0;
        }
        for (int n = 0; n < 10; n++)  // reset numbers array
        {
            num_invalid[n] = 0;
        }
        for (int n = 0; n < 10; n++)  // reset numbers array
        {
            index_wanted[n] = -1;
        }
        for (int n = 0; n < 10; n++)  // reset numbers array
        {
            index_wanted_s[n] = -1;
        }
        //printf("-----\n");
    }

    // check each col for 1


    for (int i = 0; i < 9; i++) // for each i number of columns
    {

        for (int j = 0; j < 9; j++) // finding missing numbers pt. 1
        {
            if (sudoku[j][i] != 0)
            {
                numbers[sudoku[j][i]] = 1;
            }
            else
            {
                missing++;
                missing_index = i;
            }
        }

        if (missing == 1)
        {
            for (int j = 1; j < 10; j++) // which numbers are missing?
            {
                if (numbers[j] == 0)
                {
                    sudoku[missing_index][i] = j;
                    printf("COL: Only one missing number: %d, at col number %d\n", j, missing_index);
                }
            }
        }
        else if (missing > 1)
        {
            for (int j = 0; j < 9; j++) // for each zero..
            {
                if (sudoku[j][i] == 0)
                {
                    int num_wanted = 0;
                    for (int k = 1; k < 10; k++) // for each missing number..
                    {
                        if (numbers[k] == 0)
                        {
                            // k
                            // check, col, sub
                            int row_counter = 0;
                            for (int c = 0; c < 9; c++)
                            {
                                if (sudoku[j][c] == k) // check if each missing number can go here, increase counter if cannot
                                {
                                    //printf("%d cannot go in (%d, %d)\n", k, i, j);
                                    invalid_counter ++;

                                    num_invalid[k] ++;
                                    // if this number cant go in 3 spots and there are only 4 avail, :>
                                    if (num_invalid[k] == missing - 1)
                                    {
                                        printf("COL: %d can only go in (%d, %d).\n", k, index_wanted[k], i);
                                        sudoku[index_wanted[k]][i] = k;
                                        numbers[k] = 1;
                                    }

                                    break;
                                }
                                else if (c == 8)
                                {
                                    num_wanted = k;
                                }
                                row_counter++;
                            }

                            if (row_counter == 9)
                            {
                                //printf("COL: Row %d does not contain %d\n", j, k);
                                index_wanted[k] = j;
                            }
                            row_counter = 0;
                        }
                    }

                    if (invalid_counter == missing - 1)
                    {
                        printf("COL: Only one number can go in row %d, column %d: %d\n", j, i, num_wanted);
                        
                        sudoku[j][i] = num_wanted;
                        num_wanted = 0;
                    }
                    // else
                    // {
                    //     printf("%d\n", invalid_counter);
                    // }
                    invalid_counter = 0;

                }
            }
        }


        missing = 0;
        missing_index = -1;
        invalid_counter = 0;
        for (int n = 0; n < 10; n++)  // reset numbers array
        {
            numbers[n] = 0;
        }
        for (int n = 0; n < 10; n++)  // reset numbers array
        {
            num_invalid[n] = 0;
        }
        for (int n = 0; n < 10; n++)  // reset numbers array
        {
            index_wanted[n] = -1;
        }
        //printf("-----\n");
    }

    // check each subbox for 1

}

int main()
{
    int Sudoku[9][9]={{5, 3, 0, 0, 7, 0, 0, 0, 0},
                      {6, 0, 0, 1, 9, 5, 0, 0, 0},
                      {0, 9, 8, 0, 0, 0, 0, 6, 0},
                      {8, 0, 0, 0, 6, 0, 0, 0, 3},
                      {4, 0, 0, 8, 0, 3, 0, 0, 1},
                      {7, 0, 0, 0, 2, 0, 0, 0, 6},
                      {0, 6, 0, 0, 0, 0, 2, 8, 0},
                      {0, 0, 0, 4, 1, 9, 0, 0, 5},
                      {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    
    int Solved_sudoku[9][9]={{5, 3, 4, 6, 7, 8, 9, 1, 2},
                             {6, 7, 2, 1, 9, 5, 3, 4, 8},
                             {1, 9, 8, 3, 4, 2, 5, 6, 7},
                             {8, 5, 9, 7, 6, 1, 4, 2, 3},
                             {4, 2, 6, 8, 5, 3, 7, 9, 1},
                             {7, 1, 3, 9, 2, 4, 8, 5, 6},
                             {9, 6, 1, 5, 3, 7, 2, 8, 4},
                             {2, 8, 7, 4, 1, 9, 6, 3, 5},
                             {3, 4, 5, 2, 8, 6, 1, 7, 9}};
    
    check_sudoku(Solved_sudoku);
    
    
    print_sudoku(Sudoku);
    solve_sudoku(Sudoku, 0);
    print_sudoku(Sudoku);

    // printf("unsolved sudoku check status: %d\n", check_sudoku(Sudoku));
    // printf("unsolved sudoku solved status: %d\n", solved(Sudoku));
    // printf("Solved sudoku check status: %d\n", check_sudoku(Solved_sudoku));
    // printf("Solved sudoku solved status: %d\n", solved(Solved_sudoku));
}