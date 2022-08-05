#include <stdio.h>
#include <string.h>
int main()
{

    char a[10] = "안녕";

    printf("%s\n", a);

    strcpy(a, "아니요");

    printf("%s\n", a);

    return 0;
}