#include "header.h"

char user_sign;	// 사용자 조회 혹은 순위표 출력시 사용자의 확인을 받는 변수
char user[USER_NUM][USER_NAME_LENGTH];	// 사용자 배열을 전역 변수로 선언, 최대 20명, 각각 최대 20자
int userNum;				// 사용자 배열 내 인덱스

// 타이틀에 출력되는 정보 저장 변수
int playingUser;
int SCORE;
extern int dificulty;
extern int correct_cnt;
extern int wrong_cnt;
extern float user_used_time;


main(void)
{

	int user_choice_1;

	while (1)
	{
		system("tiTle \"WeType\" 타자연습게임");		// 제목 지정
		system("mode con: cols=69 lines=31");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("********************************************************************\n");
		printf("********************************************************************\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printf("********************************\"WE\"********************************\n");
		Sleep(500);
		printf("*******************************\"TYPE\"*******************************\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("********************************************************************\n");
		printf("********************************************************************\n\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("\t\t   Press ENTER key to Continue...\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getchar();

		while (1)
		{

			printf("\t\t\t     1. 선택\n\n");
			printf("\t\t\t     2. 추가\n\n");
			printf("\t\t\t     3. 조회\n\n");
			printf("\t\t\t     4. 수정\n\n");
			printf("\t\t\t     5. 삭제\n\n");
			printf("\t\t\t     6. 순위표\n\n");
			printf("\t\t\t     7. 게임방법\n\n");
			printf("\t\t\t     8. 크레딧\n\n");
			printf("\t\t\t     0. 종료\n\n\t>> ");

			scanf(" %d", &user_choice_1);

			switch (user_choice_1)
			{
			case 1:		// <게임 실행>
				user_select();
				break;
			case 2:		// 새로운 사용자 추가
				user_add();
				break;
			case 3:		// 사용자 조회 (정확도, 타수)
				user_view();
				break;
			case 4:		// 사용자 이름 수정
				user_modify();
				break;
			case 5:		// 사용자 삭제
				user_del();
				break;
			case 6:		// 순위표 출력
				score_board();
				break;
			case 7:		// 게임 방법 출력
				readme();
				break;
			case 8:		// 크레딧 출력
				ending_credit();
				break;
			case 0:		// 게임 종료
				printf("\n\t 플레이 해 주셔서 감사합니다! 게임을 종료합니다.\n\n");
				Sleep(1000);
				return 0;
				break;
			default:	// 잘못 입력하셨습니다. (재귀 호출 사용)
				printf("\n\t  잘못 입력하셨습니다!\n\n\n");
				Sleep(1000);
			}


		}

	}

}
void GameTitle()   // 게임 시작 후 상단 타이틀
{
	float correct_rate;
	float per_min;

	if (correct_cnt + wrong_cnt == 0)
		correct_rate = 0;
	else
		correct_rate = 100 * ((float)correct_cnt / (correct_cnt + wrong_cnt));

	if (user_used_time == 0)
		per_min = 0;
	else
		per_min = correct_cnt * (2*dificulty+2) * 60 / user_used_time;

	
	system("cls");
	// 현재 사용자 출력(이름 길이에 따라 간격 조절)
	if (strlen(user[playingUser - 1]) < 6)
		printf("\t  Player[%s]\t\t", user[playingUser - 1]);
	else
		printf("\t  Player[%s]\t", user[playingUser - 1]);	// 현재 사용자 출력
	printf("\t   Score[%d]\n", SCORE);						// 점수 출력
	printf("\t  Rate[%.1f%%]\t\t", correct_rate);			// 정답률 출력
	printf("\t   Per Min[%.1f]\n", per_min);				// 분당 타수 출력			
	printf("\t  Level[%d]\t\t", dificulty);					// 레벨 출력
	printf("   Press 1 to Pause ESC to Exit\n");
	for (int i = 0; i < 69; i++)
	{
		printf("_");
	}
	printf("\n");
}

void readme()		// 7. 게임 방법 설명
{
	char* n[33];	// 게임 설명 총 32줄
	char* name;

	srand(time(0));

	FILE* fp = NULL;
	int cnt = 0;

	fp = fopen("readme.txt", "r");	// 파일 열기 (파일이름: credit.txt)
	if (fp == 0)
	{
		fprintf(stderr, "File Open Error!\n");	//표준에러출력장치
		exit(1);
	}
	for (int i = 0; i < 32; i++)	// 총 32줄 읽음
	{
		name = (char*)calloc(100, sizeof(char));	// 100만큼의 동적 메모리 할당
		fgets(name, 100, fp);	//파일 읽음
		n[i] = name;
	}
	printf("\n");
	for (int i = 0; i < 32; i++)	// 조금씩 시간 간격 두고 한 줄씩 출력
	{
		printf("%s", n[i]);
		Sleep(500);
	}
	Sleep(1500);
	printf("\n\n\n\t    아무 키나 눌러 돌아가기...\n\n");
	user_sign = _getch();
	fclose(fp);		// 파일 닫기
	free(name);		// 동적 메모리 반납
}

void ending_credit()	// 8. 엔딩 크레딧
{
	char* n[36];		// 엔딩 크레딧 총 33줄
	char* name;

	srand(time(0));

	FILE* fp = NULL;
	int cnt = 0;

	fp = fopen("credit.txt", "r");	// 파일 열기 (파일이름: credit.txt)
	if (fp == 0)
	{
		fprintf(stderr, "File Open Error!\n");	//표준에러출력장치
		exit(1);
	}
	for (int i = 0; i < 35; i++)	// 총 43줄 읽음
	{
		name = (char*)calloc(150, sizeof(char));	// 150만큼의 동적 메모리 할당
		fgets(name, 150, fp);	//파일 읽음
		n[i] = name;
	}
	printf("\n");
	for (int i = 0; i < 35; i++)	// 조금씩 시간 간격 두고 한 줄씩 출력
	{
		printf("%s", n[i]);
		Sleep(500);				// 최종 제출 전에 수정 (느리게 출력되게)
	}
	Sleep(1000);
	printf("\n\n   감사합니다!\n");
	Sleep(1000);
	printf("\n\n\t    아무 키나 눌러 돌아가기...\n\n");
	user_sign = _getch();
	fclose(fp);		//파일 닫기
	free(name);		// 동적 메모리 반납
}