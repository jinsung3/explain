#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 함수 선언
int getRandomScore();
int chooseDoll(int score);

int new(int a) {

    int score = a;
    int doll = chooseDoll(score); // 점수에 따라 인형 선택
    printf("당신의 점수는 ... %d\n", score);
    if (score < 100) {
        printf("이것이 당신의 실력..? 더 커서 돌아오세요.\n");
    } else {
        printf("축하합니다! %d번 인형을 획득하셨습니다!\n", doll);
    }

    return 0;
}

// 점수에 따라 인형 선택 함수
int chooseDoll(int score) {
    if (score >= 300000) {
        printf("   \n");
        printf("  @@@  \n");
        printf(" @@@@@ \n");
        printf("@@@@@@@\n");
        printf(" @@@@@ \n");
        printf("   ||   \n");
        return 10; // 300,000 이상일 경우 10번 인형 획득
    } else if (score >= 13000) {
        printf("  __  \n");
        printf(" /  \\ \n");
        printf(" |  | \n");
        printf(" \\__/ \n");
        printf("      \n");
        return 9; // 15000 이상일 경우 9번 인형 획득
    } else if (score >= 11000) {
        printf("  /\\  \n");
        printf(" /  \\ \n");
        printf("/____\\ \n");
        printf("      \n");
        return 8; // 13000 이상일 경우 8번 인형 획득
    } else if (score >= 9000) {
        printf("  ||  \n");
        printf("  ||  \n");
        printf("  ||  \n");
        printf("  ||  \n");
        printf("  ||  \n");
        return 7; // 11000 이상일 경우 7번 인형 획득
    } else if (score >= 7000) {
        printf("  //\\  \n");
        printf(" //__\\ \n");
        printf("//    \\\n");
        printf("      \n");
        return 6; // 9000 이상일 경우 6번 인형 획득
    } else if (score >= 5000) {
        printf("  ||||  \n");
        printf("  ||||  \n");
        printf("  ||||  \n");
        printf("  ||||  \n");
        printf("       \n");
        return 5; // 7000 이상일 경우 5번 인형 획득
    } else if (score >= 3000) {
        printf("  ||  \n");
        printf("  ||  \n");
        printf("  ||  \n");
        printf("  ||  \n");
        printf("      \n");
        return 4; // 5000 이상일 경우 4번 인형 획득
    } else if (score >= 2000) {
        printf("  @@  \n");
        printf(" @  @ \n");
        printf("@    @\n");
        printf(" @  @ \n");
        printf("  @@  \n");
        return 3; // 3000 이상일 경우 3번 인형 획득
    } else if (score >= 1000) {
        printf("  /\\  \n");
        printf("  \\/  \n");
        printf(" /\\   \n");
        printf("/__\\  \n");
        printf("      \n");
        return 2; // 2000 이상일 경우 2번 인형 획득
    } else if (score >= 100) {
        printf("  _   \n");
        printf(" / \\  \n");
        printf("( o ) \n");
        printf(" \\_/  \n");
        printf("      \n");
        return 1; // 100 이상일 경우 1번 인형 획득
    }
}