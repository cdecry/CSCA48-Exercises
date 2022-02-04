#include <stdio.h>

int the_primes[100];

int is_prime(int x)
{
    if (x <= 1)
    {
        return 0;
    }
    else {
        for (int i = 2; i < x; i++)
        {
            if (x % i == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

void primitive(void)
{
    int index = 0;
    int num = 2;
    while (index < 100)
    {
        if (is_prime(num) == 1)
        {
            the_primes[index] = num;
            index++;
        }
        num++;
    }
}


int main()
{
    primitive();
    printf("%d\n", is_prime(-2));
}