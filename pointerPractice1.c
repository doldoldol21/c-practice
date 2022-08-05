#include <stdio.h>
#include <string.h>

int main()
{

    int a[5] = {1, 2, 3, 4, 5};
    int *p = a;

    printf("size: %ld\n", sizeof(a));
    /*
    for (int i = 0, max = sizeof(a); i < max; i++)
    {
        printf("%p \n", (p + i));
    }
    */
    printf("%d \n", *p);

    return 0;
}