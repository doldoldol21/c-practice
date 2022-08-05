#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("time %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)

char *to_binary(int num)
{

    int i = 0, j = 0;
    char cArr[15];
    char *result;

    result = malloc(sizeof(cArr) + 1);

    for (i = 0; num > 0; i++)
    {
        cArr[i] = num % 2;
        num = num / 2;
    }

    for (i = i - 1; i >= 0; i--)
    {
        *(result + j++) = cArr[i] + '0';
        // printf("%d는 %d \n", i, cArr[i]);
    }

    *(result + j) = '\0';

    return result;
}

int to_int(char *arr)
{

    char *start = &arr[0];
    int total = 0;
    while (*start)
    {
        // printf("pointer: %p \n", start);

        total *= 2;
        printf("total: %d \n", total);
        if (*start++ == '1')
        {
            total += 1;
            printf("더하기 1 : %d\n", total);
        }
    }
    return total;
}

int main(int argc, char const *argv[])
{
    TICK(MAIN);

    char s[16] = "안녕하세요";

    int t = 123, i;

    int a = 10, b = 3;

    printf("😀 : %s, 몫은 : %d , 나머지는 : %d, 변환 값: 0x%x \n", s, t / 16, t % 16, t);

    char *ba = to_binary(t);
    printf("이진수로 t: %s \n", ba);

    int bai = to_int(ba);
    printf("to long: %d \n", bai);

    printf("왼쪽 t: %d => %s \n", bai << 1, to_binary(bai << 1));
    printf("오른쪽 t: %d => %s \n", bai >> 1, to_binary(bai >> 1));

    free(ba);
    TOCK(MAIN);
    return 0;
}
