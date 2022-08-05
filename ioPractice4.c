#include <stdio.h>
#include <string.h>

int main()
{

    char name[10] = "\0";
    char temp[255] = "\0";
    int l = 0;
    do
    {
        scanf("%s", temp);

        l = strlen(temp) + 1;
        printf("length: %d\n", l);

        if (l > sizeof(name))
        {
            printf("너무 긴 이름을 입력하셨습니다.\n");
        }
        else
        {
            strcpy(name, temp);
        }

    } while (l > sizeof(name));

    return 0;
}