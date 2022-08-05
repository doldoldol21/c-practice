#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char day[100];
    char time[100];
    int imp;
    char title[200];
    char body[200];
} every;

int main()
{
    every *EVERY, *cal;
    int n, i, m;
    printf("입력할 일정의 개수를 입력하세요: ");
    scanf("%d", &n);

    EVERY = (every *)malloc(sizeof(every) * (n));
    cal = (every *)malloc(sizeof(every) * (n));

    printf("'날짜(yyyyMMdd) 시간(hhmm) 중요도 제목 내용' 순으로 입력하세요\n");
    for (m = 0; m < n; m++)
    {
        scanf(" %s %s %d %s %s", EVERY[m].day, EVERY[m].time, &EVERY[m].imp, EVERY[m].title, EVERY[m].body);
        for (i = 0; i < 4; i++)
        {
            printf("%d: %c \n", i, EVERY[m].day[i]);
            cal[m].day[i] = EVERY[m].day[i];
        }
        for (i = 5; i < 7; i++)
        {
            printf("%d: %c \n", i, EVERY[m].day[i - 1]);
            cal[m].day[i - 1] = EVERY[m].day[i - 1];
        }
        for (i = 8; i < 10; i++)
        {
            cal[m].day[i - 2] = EVERY[m].day[i - 2];
        }
        EVERY[m].day[4] = ',';
        EVERY[m].day[7] = ',';
        EVERY[m].day[10] = ',';
        for (i = 0; i < 2; i++)
        {
            cal[m].time[i] = EVERY[m].time[i];
        }
        for (i = 3; i < 5; i++)
        {
            cal[m].time[i] = EVERY[m].time[i - 1];
        }
        EVERY[m].time[2] = ',';
    }
    for (m = 0; m < n; m++)
    {
        printf("날짜: %s, 시간: %s, 중요도: %d, 제목: %s, 내용: %s\n", cal[m].day, cal[m].time, EVERY[m].imp, EVERY[m].title, EVERY[m].body);
    }
    free(EVERY);
    free(cal);
    return 0;
}
