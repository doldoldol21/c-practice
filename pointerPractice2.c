/* 포인터 이용하기 */
#include <stdio.h>
int main()
{
    int arr[10] = {100, 98, 97, 95, 89, 76, 92, 96, 100, 99};

    int *parr = arr;
    int sum = 0;

    while (parr - arr <= 9)
    {
        printf("parr: %p / parr - arr: %ld\n", parr, parr - arr);
        sum += (*parr);
        parr++;
    }
    printf("arr: %ld / parr: %ld \n", arr, parr);
    printf("내 시험 점수 평균 : %d \n", sum / 10);
    return 0;
}
