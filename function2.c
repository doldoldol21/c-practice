#include <stdio.h>

int main()
{

    void avg_and_sort(int(*parr)[4], int size, float(*avg_arr)[2]);

    void print_passorfail_ofavg(float(*avg_arr)[2], int size, const int pass_score);

    const int pass_score = 70;
    int player_size;

    printf("학생 수: ");
    scanf("%d", &player_size);

    int arr[player_size][4];
    float avg_arr[player_size][2];

    for (int i = 0; i < player_size; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            switch (j)
            {
            case 0:
                printf("학생 번호: ");
                break;
            case 1:
                printf("수학 점수: ");
                break;
            case 2:
                printf("국어 점수: ");
                break;
            case 3:
                printf("영어 점수: ");
                break;
            }
            scanf("%d", &arr[i][j]);
        }
    }

    avg_and_sort(arr, player_size, avg_arr);
    int i, j;
    for (i = 0; i < player_size; i++)
    {
        printf("%d 학생의 평균점수 : %f \n", (int)avg_arr[i][0], avg_arr[i][1]);
    }
    print_passorfail_ofavg(avg_arr, player_size, pass_score);
    return 0;
}

void print_passorfail_ofavg(float (*avg_arr)[2], int size, const int pass_score)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d 학생은 ", (int)avg_arr[i][0]);
        if (avg_arr[i][1] > pass_score)
        {
            printf("합격");
        }
        else
        {
            printf("불합격");
        }
        printf("입니다. \n");
    }
}

void avg_and_sort(int (*parr)[4], int size, float (*avg_arr)[2])
{

    int i, j, k, sum;

    for (i = 0; i < size; i++)
    {
        sum = 0;
        for (j = 1; j < 4; j++)
        {
            sum += parr[i][j];
        }
        avg_arr[i][0] = (float)parr[i][0];
        avg_arr[i][1] = (float)sum / 3;
    }

    float temp_avg_arr[2];

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (avg_arr[j][1] > avg_arr[i][1])
            {
                for (k = 0; k < 2; k++)
                {
                    temp_avg_arr[k] = avg_arr[i][k];
                    avg_arr[i][k] = avg_arr[j][k];
                    avg_arr[j][k] = temp_avg_arr[k];
                }
            }
        }
    }
}