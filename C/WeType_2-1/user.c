#include "header.h"

// 사용자 조회 혹은 순위표 출력시 사용자의 확인을 받는 변수
char user_sign;

extern char user[USER_NUM][USER_NAME_LENGTH];	// main의 사용자 배열과 연결
extern int userNum;								// main의 사용자 배열 인덱스와 연결
extern int playingUser;							// 게임을 진행하는 사용자 인덱스
extern int score_easy[USER_NUM];				//사용자별 easy 점수 배열
extern int score_normal[USER_NUM];				//사용자별 normal 점수 배열
extern int score_hard[USER_NUM];				//사용자별 hard 점수 배열

//사용자별 시간 소요
extern float user_time_easy[USER_NUM];
extern float user_time_normal[USER_NUM];
extern float user_time_hard[USER_NUM];

// 정답률 계산용 난이도별 사용자 정답 오답 수 저장 변수
extern float correct_cnt_easy[USER_NUM];
extern float correct_cnt_normal[USER_NUM];
extern float correct_cnt_hard[USER_NUM];
extern float wrong_cnt_easy[USER_NUM];
extern float wrong_cnt_normal[USER_NUM];
extern float wrong_cnt_hard[USER_NUM];

int score[USER_NUM];	// 점수 순으로 내림차순 정렬 시 '점수'를 담는 배열
int rank[USER_NUM];		// 점수 순으로 내림차순 정렬 시 '인덱스 번호'를 담는 배열


int dificulty;		// 사용자가 선택하는 난이도 저장 변수

void user_select()	// 사용자 선택 함수
{
	if (userNum == 0)
	{
		printf("\t\t등록된 사용자가 없습니다!\n\t\t사용자를 추가해 주세요.\n\n");
		Sleep(500);
	}
	else
	{
		printf("\n*****************************\"사용자 선택\"***************************\n\n");
		for (int i = 0; i < userNum; i++)
		{
			printf("\t   %d. %s\n", i + 1, user[i]);
		}
		while (1)
		{
			printf("\n\t    게임을 시작할 사용자의 번호를 입력해 주세요.\n\t>> ");
			scanf("%d", &playingUser);
			if (playingUser - 1 < 0 || playingUser - 1 >= userNum)
			{
				printf("\t\t잘못 입력하셨습니다.\n\n\n");
				return 0;
			}	
			else
			{
				while (1)
				{
					printf("\n 게임의 난이도를 선택해 주세요. (1: Easy, 2: Normal, 3: Hard)\n>> ");		// 난이도 조절 -> 1.미리 난이도별 함수 구현? 아니면 2.함수 하나에 상수를 다르게?
					scanf(" %d", &dificulty);
					switch (dificulty)
					{
					case 1:		// easy
					case 2:		// normal
					case 3:		// hard
						//word(dificulty);	//선택한 난이도의 상수를 게임에 할당
						game();
						break;
					default:	// 잘못 입력하셨습니다.
						printf("\n잘못 입력하셨습니다.\n");
					}
					return 0;
				}
				break;
			}
		}
		game();
	}
}

void user_add()		// 사용자 추가 함수
{
	printf("\n*****************************\"사용자 추가\"***************************\n\n");
	printf("    추가하고자 하는 사용자의 이름을 입력해 주세요. (최대 20자)\n\t>> ");
	scanf("%s", user[userNum]);
	printf("\n\t\t사용자 추가 완료!\n\n");
	printf("\t    %d. %s\n\n", userNum + 1, user[userNum]);
	userNum += 1;		// 사용자 배열 인덱스 증가
}

void user_view()	// 사용자 정보 조회 함수
{
	float easy_rate;
	float normal_rate;
	float hard_rate;

	float easy_per_min;
	float normal_per_min;
	float hard_per_min;

	if (userNum == 0)
		printf("\t\t등록된 사용자가 없습니다!\n\n");
	else
	{
		printf("\n*****************************\"사용자 조회\"***************************\n\n");

		for (int i = 0; i < userNum; i++)
		{
			// 정답률, 타수 예외처리 (분모가 0일 시)
			if (correct_cnt_easy[i] + wrong_cnt_easy[i] == 0)
				easy_rate = 0;
			else
				easy_rate = (100 * correct_cnt_easy[i] / (float)(correct_cnt_easy[i] + wrong_cnt_easy[i]));

			if (correct_cnt_normal[i] + wrong_cnt_normal[i] == 0)
				normal_rate = 0;
			else
				normal_rate = (100 * correct_cnt_normal[i] / (float)(correct_cnt_normal[i] + wrong_cnt_normal[i]));

			if (correct_cnt_hard[i] + wrong_cnt_hard[i] == 0)
				hard_rate = 0;
			else
				hard_rate = (100 * correct_cnt_hard[i] / (float)(correct_cnt_hard[i] + wrong_cnt_hard[i]));
			if (user_time_easy[i] == 0)
				easy_per_min = 0;
			else
				easy_per_min = correct_cnt_easy[i] * EASY_LENGTH * 60 / user_time_easy[i];
			if (user_time_normal[i] == 0)
				normal_per_min = 0;
			else
				normal_per_min = correct_cnt_normal[i] * NORMAL_LENGTH * 60 / user_time_normal[i];
			if (user_time_hard[i] == 0)
				hard_per_min = 0;
			else
				hard_per_min = correct_cnt_hard[i] * HARD_LENGTH * 60 / user_time_hard[i];


			printf("\t%d. %s\n", i+1, user[i]);
			printf("    [ Easy    >> 점수: %d점, 정답률: %.1f%%, 타수: %.1f타/분 ]\n", score_easy[i], easy_rate, easy_per_min);
			printf("    [ Normal  >> 점수: %d점, 정답률: %.1f%%, 타수: %.1f타/분 ]\n", score_normal[i], normal_rate, normal_per_min);
			printf("    [ Hard    >> 점수: %d점, 정답률: %.1f%%, 타수: %.1f타/분 ]\n\n", score_hard[i], hard_rate, hard_per_min);
		}

	}
	printf("\n\t    아무 키나 눌러 돌아가기...\n\n\n");
	user_sign = _getch();
}

void user_modify()	// 사용자 이름 수정 함수
{
	int changeNum;		// 수정할 사용자의 인덱스 번호
	if (userNum == 0)
		printf("\t\t등록된 사용자가 없습니다!\n\n\n");
	else {
		printf("\n*****************************\"사용자 수정\"***************************\n\n");
		while (1)
		{
			printf("\t    이름을 수정할 사용자의 번호를 입력해 주세요.\n\t>> ");
			scanf("%d", &changeNum);
			if (changeNum - 1 < 0 || changeNum - 1 >= userNum)
				printf("\t\t잘못 입력하셨습니다.\n\n");
			else
				break;
		}
		printf("\t    해당 사용자의 이름: %s\n\n", user[changeNum - 1]);
		printf("\t    이름을 새로 입력해 주세요.\n\t>> ");
		scanf("%s", user[changeNum - 1]);
		printf("\n\t\t사용자 수정 완료!\n\n");
		printf("\t\t%d. %s\n\n", changeNum, user[changeNum - 1]);
	}
}

void user_del()		// 사용자 삭제 함수
{
	int delNum;		// 삭제할 사용자의 인덱스 번호
	if (userNum == 0)
		printf("\t\t등록된 사용자가 없습니다!\n\n\n");
	else
	{
		printf("\n*****************************\"사용자 삭제\"***************************\n\n");
		while (1)
		{
			printf("\t    삭제할 사용자의 번호를 입력해 주세요.\n\t>> ");
			scanf("%d", &delNum);
			if (delNum - 1 < 0 || delNum - 1 >= userNum)
				printf("\t    잘못 입력하셨습니다.\n\n");
			else
				break;
		}
		for (int i = delNum - 1; i < userNum - 1; i++)			// 다음 사용자를 앞으로 한 칸 옮기기
		{
			strcpy(user[i], user[i + 1]);
			score_easy[i] = score_easy[i + 1];
			score_normal[i] = score_normal[i + 1];
			score_hard[i] = score_hard[i + 1];
			correct_cnt_easy[i] = correct_cnt_easy[i + 1];
			wrong_cnt_easy[i] = wrong_cnt_easy[i + 1];
			correct_cnt_normal[i] = correct_cnt_normal[i + 1];
			wrong_cnt_normal[i] = wrong_cnt_normal[i + 1];
			correct_cnt_hard[i] = correct_cnt_hard[i + 1];
			wrong_cnt_hard[i] = wrong_cnt_hard[i + 1];
			user_time_easy[i] = user_time_easy[i + 1];
			user_time_normal[i] = user_time_normal[i + 1];
			user_time_hard[i] = user_time_hard[i + 1];
		}
		userNum--;
		printf("\n\t\t%d번 사용자를 삭제하였습니다.\n\n\n", delNum);
	}
}

void score_board()	// 점수판 출력 함수
{	
	printf("\n*****************************\"Score Board\"***************************\n\n");

	bubble_sort(score_easy, userNum);
	printf("\tEasy\n");
	for (int i = 0; i < userNum; i++)
	{
		printf("\t       %d등 >> %s:\t\t%d점\n", i + 1, user[rank[i]], score_easy[rank[i]]);
	}

	bubble_sort(score_normal, userNum);
	printf("\n\tNormal\n");
	for (int i = 0; i < userNum; i++)
	{
		printf("\t       %d등 >> %s:\t\t%d점\n", i + 1, user[rank[i]], score_normal[rank[i]]);
	}

	bubble_sort(score_hard, userNum);
	printf("\n\tHard\n");
	for (int i = 0; i < userNum; i++)
	{
		printf("\t       %d등 >> %s:\t\t%d점\n", i + 1, user[rank[i]], score_hard[rank[i]]);
	}
	printf("\n\t    아무 키나 눌러 돌아가기...\n\n\n");
	user_sign = _getch();
}

void bubble_sort(int arr[], int cnt)
{	
	// 점수 순으로 내림차순 정렬 시 인덱스 번호를 담는 배열
	for (int i = 0; i < userNum; i++)
		score[i] = arr[i];
	for (int i = 0; i < userNum; i++)
		rank[i] = i;

	int temp_1;
	int temp_2;

	// 정렬 (Sorting)
	for (int i = 0; i < userNum; i++)
	{
		for (int j = 0; j < userNum - 1; j++)
		{
			if (score[j] < score[j + 1])
			{
				temp_1 = score[j];
				score[j] = score[j + 1];
				score[j + 1] = temp_1;
				
				temp_2 = rank[j];
				rank[j] = rank[j + 1];
				rank[j + 1] = temp_2;
			}
		}
	}

}