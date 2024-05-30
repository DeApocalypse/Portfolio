// 파일 step1.txt 에 있는 단어 5개 중 랜덤으로 3개를 뽑아 출력한다


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>		

#define MAX 100

int main_t()
{
    char* n[10];
    char* name;
    int a;

    srand(time(0));

    FILE* fp = NULL;
    int cnt = 0;

    fp = fopen("step1.txt", "r");  // 파일 열기 (파일이름: step1.txt)
    if (fp == NULL)
    {
        fprintf(stderr, "File Open Error!\n");  // 표준에러출력장치, File Open Error!라고 출력
        exit(1);
    }

    for (int i = 0; i < 5; i++) // 단어 5개 읽음
    {
        name = (char*)malloc(sizeof(char) * MAX);   // char 20개 크기만큼 동적 메모리 할당
        fgets(name, MAX, fp);  // 파일을 읽음
        n[i] = name;
    }

    //printf("\n");

    for (int i = 0; i < 3; i++)  // 3개 랜덤으로 뽑기
    {

        a = (rand() % 4) + 1;
        printf("%s", n[a]);

    }


    fclose(fp); // 파일닫기

    return 0;
}

