#include <stdio.h>
#include <string.h>

int main()
{

    char msg[100];
    int a;

    printf("입력하세요.\n");

    while (1)
    {
        scanf(" %[^\n]", msg);
        if (msg[1] == '\0' && (msg[0] == 'q' || msg[0] == 'Q'))
        {
            break;
        }
        printf("result: %s %lu \n", msg, strlen(msg));
    }
    printf("end \n");

    return 0;
}