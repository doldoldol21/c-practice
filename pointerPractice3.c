
#include <stdio.h>
#include <math.h>

// 소수 판별 함수
int isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 1;
        }
    }

    return 0;
}

// 소인수 분해 함수
// ex) input: 7, output: 소수입니다.
// ex) input: 12, output: 2 X 2 X 3
void print_factorization(int n)
{
    if (isPrime(n) == 0)
    {
        printf("%d: 소수입니다.\n", n);
        return;
    }
    if (n < 0)
    {
        printf("%d", -1);
        printf(" X ");
        n *= -1;
    }

    int i = 2;

    while (n > 1)
    {
        if (n % i == 0)
        {
            printf("%d", i);
            if (isPrime(n) == 1)
            {
                printf(" X ");
            }
            n /= i;
            i = 1;
        }

        i++;
    }
    printf("\n");
}

int main()
{

    print_factorization(4);
    print_factorization(2);
    print_factorization(3);
    print_factorization(20);
    print_factorization(45);
    print_factorization(180);

    return 0;
}