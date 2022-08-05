#include <stdio.h>

/**
 * @file function4.c
 * @date 2022/01/25
 * @author phj
 * @version 1.0.0
 * @brief 자기 자신을 호출하는 함수를 이용해서 1 부터 특정한 수까지의 곱을 구하는 프로그램을 만들어보세요.
 */
int main()
{
    int sum_loop_from_one(int s, int t);

    // input number
    int n, result;
    int *sum;

    printf("하나의 숫자를 입력: ");
    scanf("%d", &n);
    result = sum_loop_from_one(1, n);
    printf("1부터 %d까지의 합: %d\n", n, result);

    return 0;
}

/**
 * @brief 1부터 s 까지의 숫자 합
 * @date 2022/01/25
 * @author phj
 *
 * @param s start number
 * @param t target number
 * @return int
 * @remark 테스트용
 */
int sum_loop_from_one(int s, int t)
{
    printf("s: %d, t: %d \n", s, t);
    if (s == t)
    {
        return s;
    }
    return s + sum_loop_from_one(s + 1, t);
}