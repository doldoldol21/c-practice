#include <stdio.h>

int main()
{
    int max_number(int *parr, int size);
    void print_sort_arrary(int *parr, int size);
    void print_addone_double_array(int(*parr)[3], int size_of_one);

    int arr[10];
    int double_arr[2][3] = {{1, 2, 3}, {11, 22, 33}};
    int input_num;
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("%d번째 수 입력: ", i + 1);
        if (scanf("%d", &input_num) == 0)
        {
            printf("숫자가 아닙니다.\n");
            return 0;
        }
        else
        {
            arr[i] = input_num;
        }
    }

    printf("입력한 배열 중 가장 큰 수 : %d \n", max_number(arr, (sizeof(arr) / sizeof(int))));

    printf("큰 수 정렬: ");
    print_sort_arrary(arr, sizeof(arr) / sizeof(int));
    print_addone_double_array(double_arr, (sizeof(double_arr) / sizeof(int)) / 3);
    return 0;
}

int max_number(int *parr, int size)
{
    int i;
    int max = parr[0];

    for (i = 0; i < size; i++)
    {
        if (parr[i] > max)
        {
            max = parr[i];
        }
    }

    return max;
}

void print_sort_arrary(int *parr, int size)
{
    int i;
    int j;
    int temp;

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (parr[j] > parr[i])
            {
                temp = parr[i];
                parr[i] = parr[j];
                parr[j] = temp;
            }
        }
    }
    for (i = 0; i < size; i++)
    {
        printf("%d", parr[i]);
        if (i + 1 != size)
        {
            printf(" > ");
        }
    }
    printf("\n");
}

void print_addone_double_array(int (*parr)[3], int size_of_one)
{
    int i;
    int j;

    for (i = 0; i < size_of_one; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("arr[%d][%d]: %d, ", i, j, parr[i][j] + 1);
        }
    }
    printf("\n");
}