#include <stdio.h>

void main()

{

    char name[20] = "홍길동"; // 이름

    char grade = 'B'; // 등급

    int scoreKOR = 80; // 국어점수

    int scoreMAT = 75; // 수학점수

    int scoreENG = 86; // 영어점수

    int scoreSCI = 92; // 과학점수

    char comment[200]; // 평가

    int scoreTotal = 0; // 총점

    float scoreAverage = 0.0F; // 평균

    char endLoop = ' '; // Q : 작업종료

    do

    {

        // 사용자 입력
        printf("이름을 입력하세요 : ");

        scanf("%[^\n]", name);

        printf("국어점수를 입력하세요 : ");

        scanf("%d", &scoreKOR);

        printf("수학점수를 입력하세요 : ");

        scanf("%d", &scoreMAT);

        printf("영어점수를 입력하세요 : ");

        scanf("%d", &scoreENG);

        printf("과학점수를 입력하세요 : ");

        scanf("%d", &scoreSCI);

        getchar();

        printf("평가를 입력하세요 : ");

        fgets(comment, sizeof(comment), stdin);

        // 총점 계산

        scoreTotal = scoreKOR + scoreMAT + scoreENG + scoreSCI;

        // 평균 계산

        scoreAverage = (float)scoreTotal / 4;

        // 평균값에 대응하는 등급 구하기

        if (scoreAverage >= 90)

            grade = 'A';

        else if (scoreAverage >= 80)

            grade = 'B';

        else if (scoreAverage >= 70)

            grade = 'C';

        else if (scoreAverage >= 60)

            grade = 'D';

        else

            grade = 'F';

        // 화면 출력

        printf("%s의 성적\n", name);

        printf("등급 : %c\n", grade);

        printf("국어 점수 : %d\n", scoreKOR);

        printf("수학 점수 : %d\n", scoreMAT);

        printf("영어 점수 : %d\n", scoreENG);

        printf("과학 점수 : %d\n", scoreSCI);

        printf("총점 : %d\n평균 : %.1f\n", scoreTotal, scoreAverage);

        printf("평가 : %s\n", comment);

        printf("\n계속하려면 Enter, 끝내려면 Q키를 눌러주세요\n");

        endLoop = getchar();

    } while (endLoop != 'Q' && endLoop != 'q');
}
