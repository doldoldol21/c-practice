#include <stdio.h>

int main()
{

    char a = ' ';

    a = getchar();
    printf("c: %c \n", a);

    if (a == 'a')
    {
        goto A;
    }
    else
    {
        goto B;
    }

A:
    printf("여기는 A \n");
    return 0;

B:
    printf("여기는 B \n");
    return 0;
}