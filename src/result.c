#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// 게임 정보를 영구저장할려고 만듬

//  사용자 정의 타입 - 내맘대로 만든다
static struct result
{
    char name[30];
    int point;
    int year;
    int month;
    int day;
    int hour;
    int min;
} temp_result;

// 게임 결과 영구 저장
void save_result(int point)
{
    FILE *fp = NULL;
    // add binary
    fp = fopen("result", "ab");

    temp_result.point = point;

    printf("이름을 입력하세요: ");
    scanf("%s", &temp_result.name);

    // ptime은, time_t 구조체를 저장하기 위한 변수다
    time_t ptime = time(NULL);    // 현재 시각을 초 단위로 가져오기 (385475723934 초)
  
    // t는 struct tm의 주소값을 저장하기 위한 변수
    struct tm *t = localtime(&ptime); // 초 단위의 시간을 분리하여 구조체에 넣기 (38472385239473 -> 2024년, 03월, 20일 몇시 몇분)

    // -> : 구조체 포인터에서만 쓸수 있다
    // temp_result.year = (*t).tm_year + 1900;
    temp_result.year = t->tm_year + 1900; // 1900 == 0년
    temp_result.month = t->tm_mon + 1; // 1월 == 0월
    temp_result.day = t->tm_mday;
    temp_result.hour = t->tm_hour;
    temp_result.min = t->tm_min;

    // file write
    // &temp_result 에 저장된 값을, 파일에 쓰겠다 (temp_result -> file)
    // sizeof(struct result) : temp_result 구조체의 길이를 결과값으로 가짐 => 왜 필요함? => temp_result의 주소값을 인자로 받기 떄문에,
  // 어디까지 읽어야하는지, 정보가 필요함
    fwrite(&temp_result, sizeof(struct result), 1, fp);
    fclose(fp);
}

// 저장된 파일에서, 이전 게임 결과 내용 불러오기
// TODO: 이어하기 기능
int print_result(void)
{
    // file pointer -> 파일의 주소값을 저장하기 위한 변수
    // pointer => 주소값을 저장하기 위한 변수
    FILE *fp = NULL;
    // file open "result" read binary
    // result 파일이 없으면 -> NULL
    fp = fopen("result", "rb");
  
    if (fp == NULL)
        return 0;

    // 파일 있음
    while (1)
    {
        // file read
        // temp_result : 우리가 만든 커스텀 타입
        // sizeof(struct result) : 우리가 만든 커스텀 타입의 크기를 결과값으로 가짐
        // fread 함수는, 파일이 열려있는 동안, 이어서 동작한다
        // &temp_result : 결과값을, 해당 구조체에 저장한다
        // 1 : 1개 꺼내오겠다
        // fp : 이 파일에서 꺼내오겠다
        fread(&temp_result, sizeof(struct result), 1, fp);

        // end of file
        // fp 파일이 끝에 도달했으면, 결과값 1
        // 아니면 0
        if (feof(fp))
            break;
    
        printf("point: %d\n", temp_result.point);
        printf("name: %s\n", temp_result.name);
        printf("time: %d-%d-%d %d:%d\n", temp_result.year, temp_result.month, temp_result.day, temp_result.hour, temp_result.min);
    }
    // file close
    fclose(fp);
    return 0;
}
