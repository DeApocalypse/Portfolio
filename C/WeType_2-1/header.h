#include <stdio.h>
#include <stdlib.h>
#include <time.h>		// tmie()
#include <windows.h>	// system()
#include <conio.h>		// _getch(), _kbhit()

// 사용자 배열을 전역 변수로 선언, 최대 20명, 각각 최대 20자
#define USER_NUM 21	
#define USER_NAME_LENGTH 21

//난이도별 목록 내 전체 단어 수
#define WORDS_MAX 100	

// 난이도별 글자 길이 (2*dificulty+2 = length)
#define EASY_LENGTH 4		// 1
#define NORMAL_LENGTH 6		// 2
#define HARD_LENGTH 8		// 3

// 난이도별 시간 할당 (time + dificulty =6)
#define EASY_TIME 5000		// 1
#define NORMAL_TIME 4000	// 2
#define HARD_TIME 3000		// 3

void game();		// 게임 실행 함수

// 사용자 정의 함수에 대한 원형 선언
void user_select();	// 사용자 선택 함수
void user_add();	// 사용자 추가 함수
void user_view();	// 사용자 정보 조회 함수
void user_modify();	// 사용자 이름 수정 함수
void user_del();	// 사용자 삭제 함수
void score_board();	// 점수판 출력 함수
void bubble_sort(int arr[], int cnt);		// 버블정렬, 정렬할 배열과 요소의 개수를 받음.
void readme();		// 게임 방법 출력 함수
void ending_credit();	// 엔딩 크레딧 출력 함수
void GameTitle();//게임 제목
void show_string(char* w);	// 게임 내 문자 출력 함수	
void correct(int dificulty);	// 정답인 경우 호출하는 함수
void wrong(int dificulty);		// 오답인 경우 호출하는 함수