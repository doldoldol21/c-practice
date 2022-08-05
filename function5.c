/**
 * @file function5.c
 * @author phj
 * @brief 계산기 문제
 * @version 0.1
 * @date 2022-01-25
 *
 *
 */

#include <stdio.h>
#include <stdbool.h>

int main()
{

    bool f = true;
    int menu, num;
    int result = 0;

    while (f)
    {
        printf(" 메뉴 선택 : \n");
        printf(" (1): 더하기 : \n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            f = false;
            break;
        case 1:
            result = sum(result, num);
            break;
        case 2:
            result = minus(result, num);
            break;
        case 3:
            result = mul(result, num);
            break;
        case 4:
            result = div(result, num);
            break;
        default:
            f = false;
            break;
        }
    }

    return 0;
}

int sum(int a, int b)
{
    return a + b;
}
int minus(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int div(int a, int b)
{
    return a / b;
}