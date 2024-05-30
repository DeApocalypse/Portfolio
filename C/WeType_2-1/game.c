#include "header.h"

extern char user[USER_NUM][USER_NAME_LENGTH];	// main의 사용자 배열과 연결
extern int userNum;								// main의 사용자 배열 인덱스와 연결

extern int playingUser;							// 게임을 진행하는 사용자 인덱스

int score_easy[USER_NUM];						// 사용자별 Easy 점수 저장 배열
int score_normal[USER_NUM];						// 사용자별 Normal 점수 저장 배열
int score_hard[USER_NUM];						// 사용자별 Hard 점수 저장 배열

double remain_time;		// 남은 시간

//사용자별 소모 시간
float user_time_easy[USER_NUM];
float user_time_normal[USER_NUM];
float user_time_hard[USER_NUM];

// 정답률 계산용 난이도별 사용자 정답 오답 수 저장 변수
float correct_cnt_easy[USER_NUM];
float correct_cnt_normal[USER_NUM];
float correct_cnt_hard[USER_NUM];
float wrong_cnt_easy[USER_NUM];
float wrong_cnt_normal[USER_NUM];
float wrong_cnt_hard[USER_NUM];

int question_num;		// 문제 번호 (난이도당 10문제 출력)

extern int SCORE;
extern int dificulty;		// 사용자가 선택하는 난이도 저장 변수

char* n[WORDS_MAX];			// 단어 목록
int word_random_index;			// 단어 배열 랜덤 index
int word_size = 0;		// 난이도에 따른 단어 저장 배열의 사이즈
int word_time = 0;		// 난이도에 따른 시간

char go_stop;		// 게임 종료 후 다음 단계로 넘어갈지를 받아들이는 변수

int correct_cnt;	// 정답 개수
int wrong_cnt;		// 오답 개수

float user_used_time;	// 사용자가 사용한 총 시간 (타이틀 바의 타수 계산시 사용)

// 난이도별 100개씩
char* easy_word[] = { "act", "age", "all", "any", "are", "arm", "ask", "bad", "bag", "bat", "bed","bet","big","bin","bio","bow","box","boy","bug","bus", "bus","but","can","cap","car","cat","ceo","cow","cry","cup","did","dog","dry","due","ear","egg","etc","eye","fan","fat","fee","few","fit", "fly","fog","fox","fun","gas","get","god","gum","gym","hat ","hen","her","hey","hip","his","hmm","hot","ice","ill","ink","jam","jaw","joy", "key","lag","lay","leg","let","lip","man","map","may","mid","mom","nap","net","nod","not","odd","oil","out","own","pet","pin", "pot","rat","red","see","set","six","ten","the","vet","wet","yet","you","zoo" };
char* normal_word[] = { "admit", "after", "alarm", "among", "angry", "apple", "below", "birth", "block", "block","board ","brave","brick","bring ","claim ","clock","cloth","codes","could","drawn","dress","drive","eager","early ","eight","empty","enrol ","enter","essay", "fifth","first","flame","flood","flown","fluid ","glare","guess","happy","hello","horse","house","hurry","issue ","knife","later ","leave","lunch","marry","maybe","meter","might","model","mouse", "music","naver","never","night","offer","ought","paper","phone","piano","place","pound","print","proud","queen","radio","reuse","roast","round","seven","shake","shape","shift","shirt","skate","skirt","smack", "snack","sorce","sound","space","spend","store ","swear","teach","third","three","today ","train","under","urban","vivid","where","which","while","witch","woman","world","would" };
char* hard_word[] = { "analyse", "abolish", "abusive", "annular", "applaud", "artless", "attract", "battery", "bedroom", "behinds","analyse","abolish","abusive","annular","applaud","artless","attract","battery","bedroom","behinds","bestows","central","chiefly","citizen","college","company", "conduce","consult","contain","control","country","courier","croatia","curable","curious","dancing","deliver","develop","dictate","dilutes","dirties","earnest","economy","educate","elastic","envelop","episode","example", "feeling","forsook","fouling","funeral","gassier","general","greater","handled","history","holders","horizon","however","hunting","journey","lagging","leanest","manager","meeting","moaners","monthly","numeral", "oppress","optical","ordered","organic","osmotic","outcome","outside","oversea","partner","peering","picture","popular","precise","present","pretend","prevent","product","profess","quelled", "quilted","refined","respond","ruinous","salable","seattle","serious","servant","settled","sipping","smartly","someone","special","stomach","success","teenage","through","tuesday","upgrade","various","whistle","willing" };


void game()		// 게임 실행 함수
{
	question_num = 1;	// 문제 번호 초기화
	correct_cnt = 0;	// 정답 개수 초기화
	wrong_cnt = 0;		// 오답 개수 초기화
	user_used_time = 0;	// 사용 시간 초기화

	switch (dificulty)
	{
	case 1:
		word_size = EASY_LENGTH;
		word_time = EASY_TIME;
		break;
	case 2:
		word_size = NORMAL_LENGTH;
		word_time = NORMAL_TIME;
		break;
	case 3:
		word_size = HARD_LENGTH;
		word_time = HARD_TIME;
		break;
	}

	char ch;			// 사용자 입력 단어 각각 체크용 변수

	// 최대 크기인 HARD 난이도 기준으로 생성
	char word[HARD_LENGTH + 1];	// 랜덤 생성 단어 배열 저장
	char input[HARD_LENGTH + 1];	// 사용자 입력 단어 배열 저장

	time_t s_time;		// start(시작) time
	int j = 0;		// 사용자 입력 단어 개수 체크용 변수

	remain_time = 0;		// 남은 시간
	double last_time = 0;

	clock_t start, end;	// 시간 측정용 변수

	double pause_total_time = 0;		// 일시정지에 소요된 총 시간 저장 변수

	srand(time(0));

	printf("\n게임을 진행하는 사용자 -->> %s\n\n", user[playingUser - 1]);

	Sleep(2000);
	printf("3..\n\n");
	Sleep(1000);
	printf("2..!\n\n");
	Sleep(1000);
	printf("1..!!!\n\n");
	Sleep(1000);

	printf("\n%s님, 게임을 시작합니다!\n\n", user[playingUser - 1]);
	SCORE = 0;
	Sleep(1500);
	system("cls");
	show_string(word);
	s_time = time(0);
	start = clock();

	while (question_num <= 10)
	{
		//pause_total_time = 0;

		if (time(0) == s_time + word_time / CLOCKS_PER_SEC + pause_total_time)	// start time 기준으로 n초 경과
		{
			//system("cls");
			printf("\n시간 초과!\n\n");
			wrong(dificulty);
			Sleep(1000);
			start = clock();
			s_time = time(0);
			j = 0;		// 사용자 입력 배열 초기화
			question_num++;
			show_string(word);
		}
		if (_kbhit())		// 키보드가 입력되면 _kbhit()함수가 1을 반환, 조건문 실행
		{
			ch = _getch();
			if (ch == 27)	// 사용자가 esc키(27)을 입력하면 프로그램 종료		--> 종료하시겠습니까? 로 수정
			{
				printf("\n\n메뉴로 돌아갑니다...\n\n");
				break;
			}
			if (ch == '1')
			{
				pause_total_time = 0;
				clock_t pause_start, pause_end;
				pause_start = clock();
				printf("\nGame Pause, Press 1 to Continue!\n");
				while (_getch() != '1');
				pause_end = clock();
				pause_total_time = (pause_end - pause_start);
				printf("\n>> ");
				for (int i = 1; i < j + 1; i++)
					printf("%c", input[i - 1]);
			}
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			{
				printf("%c", ch);		// 내가 입력한 값을 출력
				input[j] = ch;
				j++;
			}
			if (ch == 8)	// 사용자가 back-space(8)을 입력한 경우
			{
				if (j > 0)	// j가 0보다 큰 경우에만 input[] 배열의 j인덱스 1 감소
				{
					input[j - 1] = 0;
					printf("\b \b");  //커서 옮긴 후 빈 공간 삽입, 다시 커서 옮기기
					j--;
				}
			}
			if (ch == 13)		// 사용자가 엔터를 입력했을 때
			{
				end = clock();
				remain_time = (double)word_time / CLOCKS_PER_SEC - ((end - start - pause_total_time) / (double)CLOCKS_PER_SEC);
				pause_total_time = 0;
				input[j] = 0;	// 사용자 입력 배열의 마지막 인덱스에 0을 넣어서 문자열로 생성

				/* 입력값 확인용 코드
				printf("\n");
				for (int i = 0; i < sizeof(word); i++) {
					printf("%c", word[i]);
				}
				printf("\n");
				for (int i = 0; i < sizeof(word); i++) {
					printf("%c", input[i]);
				}
				printf("\n\n");
				*/

				if (!strcmp(word, input))		// strcmp()를 이용해 word배열과 input배열의 문자열 비교
					correct(dificulty);
				else
					wrong(dificulty);
				printf("\n");
				s_time = time(0);
				j = 0;
				start = clock();
				question_num++;
				if (question_num > 10)
					break;
				show_string(word);
			}
		}
	}
	system("cls");
	GameTitle();//갱신
	printf("\n\t게임을 종료합니다!\n\n");
	Sleep(1000);
	if (correct_cnt >= 8)		// 80%이상 맞혔을 시 다음 단계로 진행 가능
	{
		printf("와우!! 80%% 이상 맞히셨습니다! 다음 레벨로 진행하시겠습니까? (Y/N)\n레벨 3일 시 현재 레벨 재 시작.)\n");
		while (1)
		{
			printf(">> ");
			scanf("%s", &go_stop);
			if (go_stop == 'Y' || go_stop == 'y')
			{
				if (dificulty < 3)
					dificulty++;
				game();		// 재귀 함수 사용
				break;
			}
			else if (go_stop == 'N' || go_stop == 'n')
			{
				printf("메뉴로 돌아갑니다..\n\n");
				Sleep(1000);
				return 0;
				break;
			}
			else
				printf("\n잘못 입력하셨습니다!\n\n");
		}
	}
}

void show_string(char* w)		// 단어 출력 함수
{
	system("cls");//갱신
	GameTitle();//갱신
	int i = 0;
	word_random_index = rand() % 100;		// 랜덤으로 인덱스 뽑기

	switch (dificulty)
	{
	case 1:
		for (i = 0; i < 3; i++) {
			w[i] = easy_word[word_random_index][i];
		}
		break;
	case 2:
		for (i = 0; i < 5; i++) {
			w[i] = normal_word[word_random_index][i];
		}
		break;
	case 3:
		for (i = 0; i < 8; i++) {
			w[i] = hard_word[word_random_index][i];
		}
		break;
	}

	w[i] = '\0';		// 배열의 마지막엔 null 추가, 문자열로 바꾸기

	printf("\n%d. %s\n", question_num, w);		// 문자열 형식 지정자를 사용해 출력
	printf(">> ");
}

void correct(int dificulty)
{
	printf("\n정답!\t");
	//if (remain_time >= 0)
	printf("남은 시간은 %.1f초\n", remain_time);
	correct_cnt += 1;
	user_used_time += (6 - dificulty) - remain_time;
	Sleep(1000);
	switch (dificulty)
	{
	case 1:	// Easy
		// 정답 시 기본 50점+남은 시간*10 추가
		correct_cnt_easy[playingUser - 1] += 1;
		score_easy[playingUser - 1] += (correct_cnt * 50 + remain_time * 10);
		SCORE += (correct_cnt * 50 + remain_time * 10);
		user_time_easy[playingUser - 1] += (6 - dificulty) - remain_time;		//사용자별 소모 시간 ( 해당 난이도 총 시간 - 남은 시간)
		break;
	case 2:	// Normal
		// 정답 시 기본 70점+남은 시간*15 추가
		correct_cnt_normal[playingUser - 1] += 1;
		score_normal[playingUser - 1] += (correct_cnt * 70 + remain_time * 15);
		SCORE += (correct_cnt * 70 + remain_time * 15);
		user_time_normal[playingUser - 1] += (6 - dificulty) - remain_time;		//사용자별 소모 시간 ( 해당 난이도 총 시간 - 남은 시간)
		break;
	case 3:	// Hard
		// 정답 시 기본 100점+남은 시간*20 추가
		correct_cnt_hard[playingUser - 1] += 1;
		score_hard[playingUser - 1] += (correct_cnt * 100 + remain_time * 20);
		SCORE += (correct_cnt * 100 + remain_time * 20);
		user_time_hard[playingUser - 1] += (6 - dificulty) - remain_time;		//사용자별 소모 시간 ( 해당 난이도 총 시간 - 남은 시간)
		break;
	}
}

void wrong(int dificulty)
{
	printf("\n오답..\n");
	wrong_cnt += 1;
	Sleep(1000);
	user_used_time += (6 - dificulty) - remain_time;
	switch (dificulty)
	{
	case 1:	// Easy
		// 오답 시 50점 차감 (0점 까지만)
		if (SCORE >= 50)
		{
			score_easy[playingUser - 1] -= 50;
			SCORE -= 50;
		}
		else
		{
			score_easy[playingUser - 1] = 0;
			SCORE = 0;
		}
		wrong_cnt_easy[playingUser - 1] += 1;
		user_time_easy[playingUser - 1] += (6 - dificulty) - remain_time;		//사용자별 소모 시간 ( 해당 난이도 총 시간 - 남은 시간)
		break;
	case 2:	// Normal
		// 오답 시 70점 차감 (0점 까지만)
		if (SCORE >= 70)
		{
			score_normal[playingUser - 1] -= 70;
			SCORE -= 70;
		}
		else
		{
			score_normal[playingUser - 1] = 0;
			SCORE = 0;
		}
		wrong_cnt_normal[playingUser - 1] += 1;
		user_time_normal[playingUser - 1] += (6 - dificulty) - remain_time;		//사용자별 소모 시간 ( 해당 난이도 총 시간 - 남은 시간)
		break;
	case 3:	// Hard
		// 오답 시 100점 차감 (0점 까지만)
		if (SCORE >= 100)
		{
			score_hard[playingUser - 1] -= 100;
			SCORE -= 100;
		}
		else
		{
			score_hard[playingUser - 1] = 0;
			SCORE = 0;
		}
		wrong_cnt_hard[playingUser - 1] += 1;
		user_time_hard[playingUser - 1] += (6 - dificulty) - remain_time;		//사용자별 소모 시간 ( 해당 난이도 총 시간 - 남은 시간)
		break;
	}
}