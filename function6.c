/**
 * @file function6.c
 * @author phj
 * @brief 1000 자리의 수들의 덧셈, 뺄셈, 곱셈, 나눗셈을 수행하는 프로그램을 만들어보세요.
 * @remark 나눗셈의 경우 소수 부분을 잘라버리세요. 물론, 소수 부도 1000 자리로 구현해도 됩니다. 1000 자리 수들의 연산 수행 시간은 1 초 미만이여야 합니다. (난이도 : 上)
 * @version 0.1
 * @date 2022-02-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1001

/**
 * @brief 실행시간 매크로
 * @remark https://stackoverflow.com/a/48367129/13618438
 */
#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("time %s: %f sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)

int main(void)
{
    void sum(char *origin, char target[MAX_LENGTH]);
    void minus(char *origin, char target[MAX_LENGTH]);

    bool init(char *input);
    bool choice_menu(int *menu);
    bool num_input(char *input);
    void print_now_result(char *result);

    // 5 = nothing
    int menu = 5;
    char result[MAX_LENGTH] = {"0"};
    char input[MAX_LENGTH];

    while (true)
    {
        init(input);
        print_now_result(result);
        printf("---------------------------------------------\n");
        do
        {
            printf("선택 (1: 더하기, 2: 빼기, 3: 곱하기, 4: 나누기, 9: 초기화, 0: 종료) : ");
        } while (choice_menu(&menu));

        printf("---------------------------------------------\n");
        if (menu == 0)
        {
            return 0;
        }
        do
        {
            printf("수 입력: ");
        } while (num_input(input));

        switch (menu)
        {
        case 1:
            printf("sum \n");
            TICK(SUM);
            sum(result, input);
            TOCK(SUM);
            break;
        case 2:
            printf("minus \n");
            TICK(MINUS);
            minus(result, input);
            TOCK(MINUS);
            break;
        case 3:
            printf("multiply \n");
            break;
        case 4:
            printf("divide \n");
            break;
        case 9:
            printf("initialization \n");
            break;
        }

        // sum(result, num);

        // printf("입력%d: %c \n", i, num[i]);
    }

    return 0;
}
bool init(char *input)
{
    memset(input, 0, sizeof(input));
    // system("CLEAR");
}

bool choice_menu(int *menu)
{
    void clear_buffer();
    char b_null = '\0';
    scanf("%1d%c", menu, &b_null);
    // printf("%d !! \n", *menu);
    if (b_null != '\n')
    {
        // printf("너무 많은 숫자입니다.\n");
        clear_buffer();
        return true;
    }
    //*menu -= -48;
    return false;
}

int first_index(char *result, int len)
{
    int i = 0;
    for (i; i < len; i++)
    {
        if (result[i] != 48)
        {
            return i;
        }
    }
    return -1;
}

void print_now_result(char *result)
{
    int len = strlen(result);
    int i = first_index(result, len);

    if (i >= 0)
    {
        memcpy(result, &result[i], len - i + 1);
    }
    else
    {
        result = "0";
    }
    printf("현재: %s \n", result);
}

bool num_input(char *input)
{
    void clear_buffer();

    int comma_cnt = 0;
    char b_null = '\0';
    scanf("%1000s%c", input, &b_null);
    int len = strlen(input);

    printf("숫자: %d자\n", len);

    if (b_null != '\n')
    {
        printf("너무 많은 숫자입니다.\n");
        clear_buffer();
        return true;
    }

    for (int i = 0; i < len; i++)
    {

        if (input[i] < 48 || input[i] > 57)
        {
            if (input[i] == 46 && comma_cnt == 0 && i > 0 && i + 1 < len)
            {
                comma_cnt++;
            }
            else
            {
                printf("잘못된 입력입니다: %c\n", input[i]);
                return true;
            }
        }
    }

    int lenz = len + 1;
    int len_diff = MAX_LENGTH - lenz;

    if (len_diff > 0)
    {
        memmove(input + len_diff, input, lenz);
        memset(input, '0', len_diff);
    }

    return false;
}
void clear_buffer()
{
    char cBuffer = '\0';
    //버퍼지워주는 함수
    while ((cBuffer = getchar()) != '\n' && cBuffer != EOF)
        ;
}

int comma_index(char *numbers)
{
    int len = strlen(numbers);
    for (int i = 0; i < len; i++)
    {
        if (numbers[i] == 46)
        {
            return i;
        }
    }

    return -1;
}

// 아스키코드를 숫자로
int ascii_to_num(int num)
{
    return num - 48;
}

/**
 * @brief shiftLeft from stackoverflow
 *
 * @remark https://stackoverflow.com/a/26748140/13618438
 * @param myarray   array
 * @param size      array length
 * @param shiftBy   shift size
 */
void shiftLeft(char *myarray, int size, int shiftBy)
{
    if (shiftBy > size)
    {
        shiftBy = shiftBy - size;
    }

    if (size == 1)
    {
        // do nothing
    }
    else
    {
        char temp;
        // for loop to print the array with indexes moved up (to the left) <-- by 2
        for (int i = 0; i < size - shiftBy; i++)
        {                                      // EXAMPLE shift by 3  for a c-string of 5
            temp = myarray[i];                 // temp = myarray[0]
            myarray[i] = myarray[i + shiftBy]; // myarray[0] == myarray[2]
            myarray[i + shiftBy] = temp;       // myarray[2] = temp(value previously at index i)
        }
    }
}

// 두 수
void comma_sycronized(char *origin, char *target, int origin_len, int target_len)
{
    int o_comma_index, t_comma_index;
    o_comma_index = comma_index(origin);
    t_comma_index = comma_index(target);

    if (o_comma_index >= 0 && t_comma_index >= 0)
    {
        printf("%d :: %d\n", origin_len - o_comma_index, target_len - t_comma_index);
        if (origin_len - o_comma_index > target_len - t_comma_index)
        {
            shiftLeft(target, target_len, (origin_len - o_comma_index) - (target_len - t_comma_index));
        }
        else if (target_len - t_comma_index > origin_len - o_comma_index)
        {
            shiftLeft(origin, origin_len, (target_len - t_comma_index) - (origin_len - o_comma_index));
        }
    }
    else if (o_comma_index >= 0 || t_comma_index >= 0)
    {

        if (t_comma_index < 0)
        {
            shiftLeft(target, origin_len, origin_len - o_comma_index);
            target[target_len - (origin_len - o_comma_index)] = '.';
        }
        else if (o_comma_index < 0)
        {
            shiftLeft(origin, origin_len, target_len - t_comma_index);
            origin[target_len - (target_len - t_comma_index)] = '.';
        }
    }
}

void sum(char *origin, char target[MAX_LENGTH])
{

    int origin_len = strlen(origin);

    if (origin_len <= 1 && origin[0] == 0)
    {
        memcpy(origin, target, strlen(target) + 1);
        return;
    }

    int target_len = strlen(target);

    char result[MAX_LENGTH];
    int num = 0, j = 0, i = 0;

    memcpy(result, origin, origin_len + 1);
    memmove(result + (target_len - origin_len), result, origin_len + 1);
    memset(result, '0', (target_len - origin_len));

    comma_sycronized(result, target, strlen(result), target_len);

    // printf("%d :: %d\n", o_comma_index, t_comma_index);

    // printf("%d that %c\n", start, target[start]);

    // printf("origin: %s , target: %s \n", result, target);

    for (i = target_len - 1, target_len = 0; i >= target_len; i--)
    {
        if (target[i] == 46 && result[i] == 46 || target[i] == 468 && result[i] == 48)
        {
            continue;
        }
        j = 0;
        num = ascii_to_num(target[i]);

        do
        {
            if (result[i - j] == 46)
            {
                j++;
                continue;
            }
            num = ascii_to_num(result[i - j]) + num;
            result[i - j++] = (num % 10) + 48;
            num /= 10;

            if (i - j < -1)
            {

                return;
            }

        } while (num > 0);
    }

    memcpy(origin, result, strlen(result) + 1);
}

// 입력한 값이 더 높아 음수가 되는지 체크하는 함수
bool minus_negative_check(char origin[], char target[], int len)
{
    int origin_first_index = 0;
    int target_first_index = 0;
    int origin_first_num = 0;
    int target_first_num = 0;

    for (int i = 0; i < len; i++)
    {
        if (origin_first_num > 0 && target_first_num > 0)
        {
            break;
        }
        if (origin[i] == target[i])
        {
            continue;
        }
        if (origin_first_num == 0 && origin[i] > 48)
        {
            origin_first_index = i;
            origin_first_num = origin[i];
        }
        if (target_first_num == 0 && target[i] > 48)
        {
            target_first_index = i;
            target_first_num = target[i];
        }
    }

    // printf("oi: %d on: %d, ti: %d tn: %d \n", origin_first_index, origin_first_num, target_first_index, target_first_num);
    if (origin_first_index == 0 && origin_first_num == 0 && (target_first_num > 0))
    {
        return true;
    }

    if (origin_first_index > target_first_index)
    {
        return true;
    }
    else if (origin_first_index == target_first_index && target_first_num > origin_first_num)
    {
        return true;
    }

    return false;
}

int minus_process(char *result, int i)
{
    if (result[i] > 48)
    {
        printf("전 요기::: %c, %d\n", result[i], i);
        result[i] -= 1;
        printf("후 요기::: %c, %d\n----------------\n", result[i], i);
        return 10;
    }

    int n = minus_process(result, i - 1);
    // printf("n::: %d\n", n);
    printf("전 요기::: %c, %d\n", result[i], i);
    result[i] = (n - 1) + 48;
    printf("후 요기::: %c, %d\n----------------\n", result[i], i);
    return n;
}

void minus(char *origin, char target[MAX_LENGTH])
{
    int origin_len = strlen(origin);

    if (origin_len <= 1 && origin[0] == 0)
    {
        memcpy(origin, target, strlen(target) + 1);
        return;
    }

    int target_len = strlen(target);

    char result[MAX_LENGTH];
    int i = 0;

    memcpy(result, origin, origin_len + 1);
    memmove(result + (target_len - origin_len), result, origin_len + 1);
    memset(result, '0', (target_len - origin_len));

    comma_sycronized(result, target, target_len, target_len);

    bool negative_check = minus_negative_check(result, target, target_len);
    printf("check: %d\n", negative_check);

    for (i = target_len - 1, target_len = 0; i >= target_len; i--)
    {
        if ((target[i] == 46 && result[i] == 46) || (target[i] == 48 && result[i] == 48))
        {
            continue;
        }

        if (negative_check)
        {

            if (target[i] < result[i])
            {
                // printf("%d and %d  \n", target[i], result[i]);
                printf("시작인덱스::: %d\n", i);
                target[i] = minus_process(target, i) + 48;
                printf("naa::: %d\n", target[i]);
            }
            target[i] = (ascii_to_num(target[i]) - ascii_to_num(result[i])) + 48;
        }
        else
        {
            if (result[i] < target[i])
            {
                printf("시작인덱스::: %d\n", i);
                result[i] = minus_process(result, i) + 48;
                printf("naa::: %d\n", result[i]);
            }
            result[i] = (ascii_to_num(result[i]) - ascii_to_num(target[i])) + 48;
        }
    }

    if (negative_check)
    {
        target[first_index(target, MAX_LENGTH) - 1] = '-';
        //    printf("%d 시작 %d\n", target[i], result[i]);
        memcpy(origin, target, MAX_LENGTH);
    }
    else
    {
        printf("ren1: %ld taren: %d \n", strlen(result), MAX_LENGTH);
        memcpy(origin, result, MAX_LENGTH);
    }
}