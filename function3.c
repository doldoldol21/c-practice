

#include <stdio.h>
/**
 * @file fucntion3.c
 * @date 2022/01/25
 * @author phj
 * @version 1.0.0
 * @brief C언어 연습
 * @brief  유클리도 호제법을 이용한 최대공약수
 */
int main()
{
    int gcd_of_euclideanalgorithm(int n1, int n2);

    int gcd;

    int num1 = 1112;
    int num2 = 695;

    gcd = gcd_of_euclideanalgorithm(num1, num2);

    printf("(%d, %d) 최대공약수: %d \n", num1, num2, gcd);
    return 0;
}

/**
 *
 * @fn int gcd_of_euclideanalgorithm(int n1, int n2)
 * @brief 두개의 숫자로 유클리도 호제법을 이용하여 최대공약수를 구한 뒤 리턴
 * @date 2022/01/25
 * @author phj
 *
 * @param n1 int
 * @param n2 int
 * @return h int 는 1이상
 * @remark 테스트용
 */
int gcd_of_euclideanalgorithm(int n1, int n2)
{
    if (n1 > n2)
    {
        return n2 ? gcd_of_euclideanalgorithm(n2, n1 % n2) : n1;
    }
    else
    {
        return n1 ? gcd_of_euclideanalgorithm(n1, n2 % n1) : n2;
    }
}