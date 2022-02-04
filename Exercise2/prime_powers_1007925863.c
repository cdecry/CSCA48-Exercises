#include <stdio.h>

float power(float x, int p);

int main()
{
    float float_value = 1.4142f;
    int prime_counter;

    for (int i = 2; i < 101; i++)
    {
        prime_counter = 0;

        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                prime_counter += 1;
            }
        }

        if (prime_counter == 0)
            {
                printf("p=%d, %.4f^%d = %f\n", i, float_value, i, power(float_value, i));
            }
    }

    return 0;
}

float power(float x, int p)
{
    float result = x;

    for (int i = 1; i < p; i++)
    {
        result = result * x;
    }
    
    return result;
}