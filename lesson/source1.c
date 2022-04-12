#pragma warning(disable: 4996)

/***********************************************************/
// [1-1] 배열 기반 순차 리스트
/***********************************************************/

#if 0

/***********************************************************/
// [1-1.1] 데이터 모델링
/***********************************************************/

#if 01

#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
}SCORE;

#define MAX_ST	20

SCORE exam[MAX_ST];

// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다


int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Delete_Data(int id);
int Search_Complete_Data(SCORE * p);
int Search_Data(int n, SCORE * p, int(*comp)(SCORE * x, SCORE* y));
int Compare_Id(SCORE * x, SCORE* y);
int Compare_Name(SCORE * x, SCORE* y);
int Compare_Jumsu(SCORE * x, SCORE* y);
int Sort_Bubble(SCORE * d, int order, int(*comp)(SCORE * x, SCORE * y));
int Sort_Select(SCORE * d, int order, int(*comp)(SCORE * x, SCORE * y));
int Sort_Insertion(SCORE * d, int order, int(*comp)(SCORE * x, SCORE * y));
int Insert_and_Sort_Data(SCORE * p);
int Copy_Data(int n, SCORE * p);
int Copy_All_Data(SCORE * p, int max);
int Print_All_Buffer(SCORE * d, int max);
int Sort_Quick(SCORE *d, int order, int m, int n, int(*comp)(SCORE * x, SCORE * y));

SCORE test[10] = { {10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
							   {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"} };

void Make_Test_Data(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		exam[i] = test[i];
	}
}

#endif

/***********************************************************/
// [1-1.2] 배열의 모든 자료 인쇄
/***********************************************************/

#if 0

int Print_All_Data(void)
{
	int i;

	for (i = 0; i < MAX_ST; i++) {
		if (exam[i].id == 0) break;
		printf("[%d] ID=%d, NAME=%s, SCORE=%d\n", i, exam[i].id, exam[i].name, exam[i].jumsu);
	}
	if (i == 0) return 0;
	return 1;
}

#endif

/***********************************************************/
// [1-1.3] 특정 요소번호의 데이터만 인쇄
/***********************************************************/

#if 1

int Print_Data(int no)
{
	if (no < 0 || exam[no].id == 0) return -1;
	printf("ID=%d, NAME=%s, SCORE=%d\n", exam[no].id, exam[no].name, exam[no].jumsu);
	return 1;



}

#endif

/***********************************************************/
// [1-1.4] 배열에 있는 모든 자료의 수를 계산
/***********************************************************/

#if 1

int Count_Data(void)
{
	int len;

	for (len = 0; exam[len].id != 0; len++);
	return len;
}

#endif

/***********************************************************/
// [1-1.5] 배열에 데이터 하나를 생성
/***********************************************************/

#if 1

int Create_Data(SCORE * p)
{
	printf("사번을 입력하시오 => ");
	scanf("%d", &(p->id));
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	return 1;
}

#endif

#if 0

void main(void)
{
	int i;

	for (i = 0; i < 3; i++)
	{
		Create_Data(&exam[i]);
		printf("\nCount = %d\n", Count_Data());
		printf("Print Result = %d\n", Print_Data(i));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}
}

#endif

/***********************************************************/
// [1-1.6] 데이터 하나를 생성하여 배열에 추가로 저장하는 함수
/***********************************************************/

#if 1

int Insert_Data(SCORE * p)
{
	int i;

	if (p->id == 0) return -1;
	for (i = 0; i < MAX_ST; i++) {
		if (exam[i].id == p->id) return -2;
		if (exam[i].id != 0) continue;
		exam[i] = *p;
		return i;
	}
	return -1;

}

#endif

#if 0

void main(void)
{
	SCORE tmp;

	do
	{
		Create_Data(&tmp);
		printf("\n\nInsert Result = %d\n", Insert_Data(&tmp));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("\n계속(아무키), 그만(x 키)\n");
	} while (getch() != 'x');
}

#endif

/***********************************************************/
// [1-1.7] 지정한 사번의 데이터 삭제 기능을 수행하는 함수
/***********************************************************/

#if 01

int Delete_Data(int id)
{
	int i,j;
	
	if (exam[0].id == 0) return -2;
	for (i = 0; i < MAX_ST; i++) {
		if (exam[i].id != id) continue;
		exam[i] = (SCORE) { 0, 0, 0 };
		for (j=i;j<MAX_ST-1 && exam[j+1].id != 0;j++) exam[j] = exam[j + 1];
		exam[j] = (SCORE) { 0, 0, 0 };
		return i;
	}
	return -1;

}

#endif

#if 0

void main(void)
{
	int i;

	Make_Test_Data(5);
	printf("Printed Data Count = %d\n", Print_All_Data());

	do
	{
		printf("\n삭제할 자료의 사번을 입력하시오 => ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\nDelete Element = %d\n", Delete_Data(i));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("\n계속(아무키), 그만(x 키)\n");
	} while (getch() != 'x');
}

#endif

/***********************************************************/
// [1-1.8] 모든 멤버가 일치하는 데이터를 탐색하는 함수
/***********************************************************/

#if 01

int Search_Complete_Data(SCORE * p)
{
	int i;

	if (exam[0].id == 0) return -2;
	for (i = 0; i < MAX_ST; i++) {
		if (exam[i].id == p->id && exam[i].jumsu == p->jumsu && 
			strcmp(exam[i].name,p->name)==0) return i;
	}
	return -1;
}

#endif

#if 0

void main(void)
{
	SCORE tmp;

	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	do
	{
		printf("\n탐색할 자료를 입력하시오\n");
		Create_Data(&tmp);
		printf("\n\nSearched Element = %d\n", Search_Complete_Data(&tmp));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("\n계속(아무키), 그만(x 키)\n");
	} while (getch() != 'x');
}

#endif

/***********************************************************/
// [1-1.9] 원하는 멤버를 갖는 데이터를 탐색하는 함수, 비교를 위한 call back 함수도 설계
/***********************************************************/

#if 01

int Search_Data(int n, SCORE * p, int(*comp)(SCORE * x, SCORE* y))
{
	int i;

	if (exam[0].id == 0) return -2;
	for (i = n; i < MAX_ST; i++) {
		if (comp(&exam[i], p) == 0) return i;
	}
	return -1;
}

int Compare_Id(SCORE * x, SCORE* y)
{
	return (x->id - y->id);
}

int Compare_Name(SCORE * x, SCORE* y)
{
	return (strcmp(x->name, y->name));
}

int Compare_Jumsu(SCORE * x, SCORE* y)
{
	return (x->jumsu - y->jumsu);
}

#endif

#if 0

void main(void)
{
	int n;
	SCORE tmp;

	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	do
	{
		printf("\n탐색할 자료를 입력하시오\n");
		Create_Data(&tmp);

		printf("\nSearched Element (ID) = %d\n", n = Search_Data(0, &tmp, Compare_Id));
		Print_Data(n);

		n = 0;
		printf("Printed Data Count = %d\n", Print_All_Data());

		do
		{
			printf("\nSearched Element (Name) = %d\n", n = Search_Data(n, &tmp, Compare_Name));
			Print_Data(n);
			n++;
		} while (n > 0);

		n = 0;
		printf("Printed Data Count = %d\n", Print_All_Data());

		do
		{
			printf("\nSearched Element (Jumsu) = %d\n", n = Search_Data(n, &tmp, Compare_Jumsu));
			Print_Data(n);
			n++;
		} while (n > 0);

		printf("\n계속(아무키), 그만(x 키)\n");
	} while (getch() != 'x');
}

#endif

/***********************************************************/
// [1-1.10] 자료를 버블소트로 정렬하는 함수
/***********************************************************/

#if 01

int Sort_Bubble(SCORE * d, int order, int(*comp)(SCORE * x, SCORE * y))
{
	int i, j, s, l;
	SCORE t;

	s = d - &d[0];
	for (l = 0; d[l].id != 0; l++);
	for (i = l - 1; i > s; i--) {
		for (j = s; j < i; j++) {
			if (d[j+1].id == 0) break;
			if (comp(&d[j], &d[j + 1]) == order) {
				t = d[j];
				d[j] = d[j + 1];
				d[j + 1] = t;
			}
		}
	}
	return l;
}

#endif

#if 0

void main(void)
{
	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, 1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, -1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, 1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, -1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, 1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, -1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
}

#endif

/***********************************************************/
// [1-1.11] 자료를 선택 정렬로 정렬하는 함수
/***********************************************************/

#if 01

int Sort_Select(SCORE * d, int order, int(*comp)(SCORE * x, SCORE * y))
{
	int i, j, s, len, tar;
	SCORE t;

	s = d-&d[0];
	for (len = 0; d[len].id != 0; len++);
	for (i = len - 1; i > s; i--) {
		for (tar = j = s; j <= i; j++) {
			if (comp(&d[j], &d[tar]) == order) tar = j;
		}
		t = d[tar];
		d[tar] = d[i];
		d[i] = t;
	}
	return len;
}

#endif

#if 0

void main(void)
{
#if 0

	SCORE tmp;

	do
	{
		Create_Data(&tmp);
		printf("\n\nInsert Result = %d\n", Insert_Data(&tmp));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("\n계속(아무키), 그만(x 키)\n");
	} while (getch() != 'x');

#endif 

#if 00

	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

#endif 

	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Select(exam, 1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Select(exam, -1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Select(exam, 1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Select(exam, -1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Select(exam, 1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Select(exam, -1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
}

#endif

/***********************************************************/
// [1-1.12] 자료를 삽입 정렬로 정렬하는 함수
/***********************************************************/

#if 01

int Sort_Insertion(SCORE * d, int order, int(*comp)(SCORE * x, SCORE * y))
{
	int i, j, k, s, l;
	SCORE t;

	s = d-&d[0];
	for (l = 0; d[l].id != 0; l++);
	for (i = s+1; i < l; i++) {
		t = d[i];
		for (j = s; j < i; j++) {
			if (comp(&d[j], &d[i]) == order) break;
		}
		if (j != i) {
			for (k = i; k > j; k--) {
				d[k] = d[k - 1];
			}
			d[j] = t;
		}
	}
	return l;
}

#endif

#if 0

void main(void)
{
#if 0

	SCORE tmp;

	do
	{
		Create_Data(&tmp);
		printf("\n\nInsert Result = %d\n", Insert_Data(&tmp));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("\n계속(아무키), 그만(x 키)\n");
	} while (getch() != 'x');

#endif 

#if 0

	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

#endif 

	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, 1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, -1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, 1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, -1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, 1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, -1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
}

#endif

/***********************************************************/
// [1-1.13] 사번순 정렬을 유지하면서 데이터를 배열에 추가하는 함수
/***********************************************************/

#if 01

int Insert_and_Sort_Data(SCORE * p)
{
	int i,j,l;

	l = Count_Data();
	if (l == MAX_ST) return -1;
	for (i = 0; i < l; i++) {
		if (exam[i].id == p->id) return -2;
		if (exam[i].id > p->id) break;
	}
	if (i != l) {
		for (j = l; j > i; j--) exam[j] = exam[j - 1];
		exam[i] = *p;
		return i;
	}
	exam[0] = *p;
	return 0;
}

#endif

#if 0

void main(void)
{
	int i;
	SCORE tmp;

	for (i = 0; i < sizeof(test) / sizeof(test[0]); i++)
	{
		printf("\n\nInsert Result = %d\n", Insert_and_Sort_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}

	tmp.id = 4;
	printf("\n\nInsert Result = %d\n", Insert_and_Sort_Data(&tmp));
	printf("Printed Data Count = %d\n", Print_All_Data());
}

#endif

/***********************************************************/
// [1-1.14] 지정한 데이터를 구조체에 복사하여 주는 함수를 
/***********************************************************/

#if 01

int Copy_Data(int n, SCORE * p)
{
	if (exam[n].id == 0) return -1;
	*p = exam[n];
	return 0;
}

#endif

#if 0

void main(void)
{
	SCORE tmp;

	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	printf("Data Copy Result = %d\n", Copy_Data(3, &tmp));
	printf("ID: %d, Name: %s, Score: %d\n", tmp.id, tmp.name, tmp.jumsu);
	printf("Data Copy Result = %d\n", Copy_Data(9, &tmp));
}

#endif

/***********************************************************/
// [1-1.15] 지정한 수 만큼 자료를 주어진 buffer에서 꺼내어 인쇄하는 함수
/***********************************************************/

#if 01

int Print_All_Buffer(SCORE * d, int max)
{
	int i;
	
	for (i = 0; i < max; i++) {
		if (d[i].id == 0) break;
		printf("[%d] ID=%d, NAME=%s, SCORE=%d\n", i, d[i].id, d[i].name, d[i].jumsu);
	}
	return i;
}

#endif

#if 0

void main(void)
{
	Make_Test_Data(10);
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("All Buffer Print = %d\n", Print_All_Buffer(exam, 10));
	printf("All Buffer Print = %d\n", Print_All_Buffer(exam, 4));
}

#endif

/***********************************************************/
// [1-1.16] 주어진 수 만큼의 자료를 전달받은 buffer에 복사하여 주는 함수
/***********************************************************/

#if 01

int Copy_All_Data(SCORE * p, int max)
{
	int i;

	for (i = 0; i < max; i++) {
		if (exam[i].id == 0) break;
		p[i] = exam[i];
	}
	return i;
}

#endif

#if 0

void main(void)
{
	SCORE tmp[MAX_ST];

	memset(tmp, 0, sizeof(tmp));
	Make_Test_Data(10);
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("All Data Copy Result = %d\n", Copy_All_Data(tmp, 10));
	printf("All Buffer Print = %d\n", Print_All_Buffer(tmp, 10));
	printf("Sorted Data Count = %d\n", Sort_Bubble(tmp, 1, Compare_Name));
	printf("All Buffer Print = %d\n", Print_All_Buffer(tmp, 10));
}

#endif

/***********************************************************/
// [1-1.17] 설계한 함수들을 이용한 성적처리 프로그램
/***********************************************************/

#if 0

/* 위의 예제에서 #if 0로 선언된 모든 main 함수는 #if 0로 만든후 여기에 main 함수 설계 */
#include <conio.h>

void Disp_menu(void)
{

}

void main(void)
{
	int i;
	SCORE tmp;
	int ch;
	int ret;
	int(*comp[3])(SCORE * x, SCORE * y) = { Compare_Id, Compare_Name,Compare_Jumsu };

	for (i = 0; i < sizeof(test) / sizeof(test[0]); i++)//입력 테스트 10개 미리 입력
	{
		//printf("\n\nInsert Result = %d\n", Insert_and_Sort_Data(&test[i]));
		//printf("Printed Data Count = %d\n", Print_All_Data());
	}

	for (;;)
	{
		printf("\n\n##################\n");
		printf("성적 처리 프로그램\n");
		printf("##################\n");
		printf("1: 자료추가\n");
		printf("2: 자료삭제\n");
		printf("3: 자료수정\n");
		printf("4: 전체인쇄\n");
		printf("5: 자료인쇄\n");
		printf("6: 정렬\n");
		printf("x: 끝내기\n");
		printf("메뉴를 선택하세요: ");

		ch = getch();//한글자 입력 받기
		printf("\n\n");
		memset(&tmp, 0, sizeof(tmp));
		if (ch == 'x') break;
		switch (ch)
		{
		case '1':
			if (Count_Data() == MAX_ST) break;
			Create_Data(&tmp);
			ret = Insert_and_Sort_Data(&tmp);
			break;
		case '2':
			printf("기준 선택 [0)사번 1)이름] : ");
			scanf("%d", &ch);
			printf("입력 : ");
			if (ch == 0) scanf("%d", &tmp.id);
			if (ch == 1) scanf("%s", tmp.name);
			while (Delete_Data(Search_Data(0, &tmp, comp[ch])) == 1);
			break;
		case '3':
			Create_Data(&tmp);
			if (ret = Delete_Data(tmp.id) < 0) break;
			if (ret = Insert_and_Sort_Data(&tmp) < 0) break;
			break;
		case '4':
			ret = Print_All_Data();
			break;
		case '5':
			printf("기준 선택 [0)사번 1)이름 2)성적] : ");
			scanf("%d", &ch);
			printf("입력 : ");
			if (ch == 0) scanf("%d", &tmp.id);
			if (ch == 1) scanf("%s", tmp.name);
			if (ch == 2) scanf("%d", &tmp.jumsu);
			while (Print_Data(Search_Data(0,&tmp, comp[ch])) == 1);
			break;
		case '6':
			printf("기준 선택 [1)이름 2)성적] : ");
			scanf("%d", &ch);
			Copy_All_Data(test,MAX_ST);
			Sort_Bubble(test, 1, comp[ch]);
			Print_All_Buffer(test, MAX_ST);
			break;
		default:
			printf("다시 입력하세요.\n");
		}
		if (ret < 0) printf("다시 입력하세요.\n");
	}
}

#endif

#endif 

/***********************************************************/
// [1-2] Quick Sort 함수 설계
/***********************************************************/

#if 0

int Sort_Quick(SCORE *d, int order, int m, int n, int(*comp)(SCORE * x, SCORE * y))
{


}

#endif

#if 0

void main(void)
{
	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, 1, 0, MAX_ST - 1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, -1, 0, MAX_ST - 1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, 1, 0, MAX_ST - 1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, -1, 0, MAX_ST - 1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, 1, 0, MAX_ST - 1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, -1, 0, MAX_ST - 1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
}

#endif

/***********************************************************/
// [1-3] 배열 기반 연결 리스트
/***********************************************************/

#if 0

/***********************************************************/
// [1-3.1] 데이터 모델링
/***********************************************************/

#if 01

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * next;
}SCORE;

SCORE Head;

#define MAX_ST		20

SCORE exam[MAX_ST];

// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다


int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
int Count_Node(SCORE * head);
int Print_Node(SCORE * head, int id);
int Delete_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);

SCORE test[MAX_ST] = { {10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
							   {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
							   {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
							   {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"} };

void Make_Test_Data(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		exam[i] = test[i];
	}
}

#endif

/***********************************************************/
// [1-3.2] 데이터 생성, 인쇄, 계수 함수 설계
/***********************************************************/

#if 01

int Create_Data(SCORE * p)
{
	printf("\n사번을 입력하시오 => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);
	p->next = (SCORE *)0x0;

	return 1;
}

int Print_All_Data(void)
{
	int i;

	printf("Head.next = 0x%.8X\n", Head.next);

	for (i = 0; i < MAX_ST; i++)
	{
		if (exam[i].id == 0) break;
		printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", i, &exam[i], exam[i].id, exam[i].name, exam[i].jumsu, exam[i].next);
	}

	return i;
}

int Print_Data(int no)
{
	if (exam[no].id == 0) return -1;
	printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", no, &exam[no], exam[no].id, exam[no].name, exam[no].jumsu, exam[no].next);
	return 1;
}

int Count_Data(void)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		if (exam[i].id == 0) break;
	}

	return i;
}

int Insert_Data(SCORE * p)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		if (exam[i].id == 0)
		{
			exam[i] = (*p);
			return i;
		}

		if (exam[i].id == p->id)
		{
			return -2;
		}
	}

	return -1;
}

#endif

/***********************************************************/
// [1-3.3] 데이터 하나를 생성하여 Linked List에 추가하는 함수
/***********************************************************/

#if 01

int Insert_Node(SCORE * head, SCORE * d)
{
	SCORE * cur = head;
	int cnt = 0;

	while (cur->next) {
		cur = cur->next;
		cnt++;
	}
	if (cnt >= MAX_ST) return -1;
	while (head->next) {
		if (head->next->id > d->id) break;
		else if (head->next->id == d->id) return -2;
		head = head->next;
	}
	d->next = head->next;
	head->next = d;
	return 1;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}
}

#endif

/***********************************************************/
// [1-3.4] link에 따라서 각 노드의 정보를 인쇄하도록 함수
/***********************************************************/
/***********************************************************/
// [1-3.5] link에 따라서 주어진 사번에 맞는 노드 를 찾아 주소를 리턴하는 함수
/***********************************************************/

#if 01

int Print_All_Node(SCORE * head)
{
	printf("Head.next = 0x%.8X\n", head->next);
	
	if (head->next == NULL) return 0;
	while (head->next) {
		head = head->next;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", head, head->id, head->name, head->jumsu, head->next);
	}
	return 1;
}

SCORE * Search_Id_Node(SCORE * head, int id)
{
	while (head->next) {
		head = head->next;
		if (head->id == id) return head;
	}
	return NULL;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	}

	printf("Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 8));

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
	}

	printf("Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 7));

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
	}
}

#endif

/***********************************************************/
// [1-3.6] list에 저장된 자료의 총수를 계산하는 함수
/***********************************************************/

#if 01

int Count_Node(SCORE * head)
{
	int cnt = 0;

	while (head->next) {
		head = head->next;
		cnt++;
	}
	return cnt;
}

#endif

/***********************************************************/
// [1-3.7] link에 따라서 주어진 사번에 맞는 자료를 인쇄하는 함수
/***********************************************************/

#if 01

int Print_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);
	if (p == NULL) return -1;
	printf("ID=%d, NAME=%s, SCORE=%d\n", p->id, p->name, p->jumsu);
	return 1;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
		printf("Node Count = %d\n", Count_Node(&Head));
	}

	printf("Print Node Result = %d\n", Print_Node(&Head, 8));
	printf("Print Node Result = %d\n", Print_Node(&Head, 7));
}

#endif

/***********************************************************/
// [1-3.8] link에 따라서 주어진 사번의 node를 찾아서 삭제하는 함수
/***********************************************************/

#if 01

int Delete_Node(SCORE * head, int id)
{
	if (head->next == NULL) return -1;
	while (head->next) {
		if (head->next->id == id) {
			head->next->id = 0;
			head->next = head->next->next;
			return 1;
		}
		head = head->next;
	}
	return -1;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 8));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 7));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 1));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 10));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

/***********************************************************/
// [1-3.9] 주어진 버퍼에 자료를 모두 복사해 주는 함수 
/***********************************************************/

#if 01

int Copy_All_Node(SCORE * head, SCORE * buf)
{
	int i = 0;
	if (head->next == NULL) return -1;
	while (head->next) {
		head = head->next;
		buf[i] = *head;
		buf[i].next = &buf[i + 1];
		i++;
	}
	buf[i - 1].next = NULL;
	return i;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;
	SCORE new_head;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Node Count = %d\n", r = Count_Node(&Head));

	p = calloc(r, sizeof(SCORE));
	printf("Copy All Node Result = %d\n", Copy_All_Node(&Head, p));
	new_head.next = p;
	printf("Printed Node Count = %d\n", Print_All_Node(&new_head));
	free(p);
}

#endif

/***********************************************************/
// [1-3.10] node에서 요청한 자료의 수를 계수하거나 버퍼에 복사해 주는 함수
/***********************************************************/

#if 01

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (!strcmp(head->name, name)) n++;
		if (head->next == (SCORE *)0x0) return n;
		head = head->next;
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (head->jumsu == jumsu) n++;
		if (head->next == (SCORE *)0x0) return n;
		head = head->next;
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (!strcmp(head->name, name)) {
			buf[n] = *head;
			buf[n].next = &buf[n + 1];
			n++;
		}
		if (head->next == (SCORE *)0x0) {
			buf[n - 1].next = (SCORE *)0x0;
			return n;
		}
		head = head->next;
	}
}

int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (head->jumsu == jumsu) {
			buf[n] = *head;
			buf[n].next = &buf[n + 1];
			n++;
		}
		if (head->next == (SCORE *)0x0) {
			buf[n - 1].next = (SCORE *)0x0;
			return n;
		}
		head = head->next;
	}
}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;
	SCORE new_head;

	for (i = 0; i < 20; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));

	printf("Name Node Count = %d\n", r = Count_Name_Node(&Head, "lew"));
	p = calloc(r, sizeof(SCORE));
	printf("Copy Name Node Result = %d\n", Copy_Name_Node(&Head, "lew", p));
	new_head.next = p;
	printf("Printed Node Count = %d\n", Print_All_Node(&new_head));
	free(p);

	printf("Score Node Count = %d\n", r = Count_Score_Node(&Head, 100));
	p = calloc(r, sizeof(SCORE));
	printf("Copy Score Node Result = %d\n", Copy_Score_Node(&Head, 100, p));
	new_head.next = p;
	printf("Printed Node Count = %d\n", Print_All_Node(&new_head));
	free(p);
}

#endif

#endif

/***********************************************************/
// [1-4] 배열 기반 연결 리스트 - 다중 링크
/***********************************************************/

#if 0

/***********************************************************/
// [1-4.1] 데이터 모델링
/***********************************************************/

#if 0

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * nid;
	struct _score  * njumsu;
}SCORE;

SCORE Head;

#define MAX_ST		20

SCORE exam[MAX_ST];

// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다



int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
int Print_All_Id_Node(SCORE * head);
int Print_All_Jumsu_Node(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
SCORE * Search_Jumsu_Node(SCORE * head, int jumsu);
int Count_Node(SCORE * head);
int Print_Id_Node(SCORE * head, int id);
int Print_Jumsu_Node(SCORE * head, int jumsu);
int Delete_Id_Node(SCORE * head, int id);
void Delete_One_Jumsu_Node(SCORE * head, int jumsu, int id);
int Delete_Jumsu_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);

SCORE test[MAX_ST] = { {10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
							   {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
							   {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
							   {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"} };

void Make_Test_Data(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		exam[i] = test[i];
	}
}

int Create_Data(SCORE * p)
{
	printf("\n사번을 입력하시오 => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);
	p->nid = (SCORE *)0x0;
	p->njumsu = (SCORE *)0x0;

	return 1;
}

int Print_All_Data(void)
{
	int i;

	printf("Head.nid = 0x%.8X, Head.njumsu = 0x%.8X\n", Head.nid, Head.njumsu);

	for (i = 0; i < MAX_ST; i++)
	{
		if (exam[i].id == 0) break;
		printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X, njumsu = 0x%.8X\n", i, &exam[i], exam[i].id, exam[i].name, exam[i].jumsu, exam[i].nid, exam[i].njumsu);
	}

	return i;
}

int Print_Data(int no)
{
	if (exam[no].id == 0) return -1;
	printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X, njumsu = 0x%.8X\n", &exam[no], exam[no].id, exam[no].name, exam[no].jumsu, exam[no].nid, exam[no].njumsu);
	return 1;
}

int Count_Data(void)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		if (exam[i].id == 0) break;
	}

	return i;
}

int Insert_Data(SCORE * p)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		if (exam[i].id == 0)
		{
			exam[i] = (*p);
			return i;
		}

		if (exam[i].id == p->id)
		{
			return -2;
		}
	}

	return -1;
}

#endif

/***********************************************************/
// [1-4.2] 데이터 하나를 생성하여 Linked List에 추가하는 함수
/***********************************************************/

#if 0

int Insert_Node(SCORE * head, SCORE * d)
{





}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}
}

#endif

/***********************************************************/
// [1-4.3] link에 따라서 각 노드의 정보를 인쇄하는 함수
/***********************************************************/
/***********************************************************/
// [1-4.4] link에 따라서 주어진 사번에 맞는 노드 를 찾아 주소를 리턴하는 함수
/***********************************************************/

#if 0

int Print_All_Node(SCORE * head)
{
	Print_All_Id_Node(head);
	return Print_All_Jumsu_Node(head);
}

int Print_All_Id_Node(SCORE * head)
{





}

int Print_All_Jumsu_Node(SCORE * head)
{





}

SCORE * Search_Id_Node(SCORE * head, int id)
{




}

SCORE * Search_Jumsu_Node(SCORE * head, int jumsu)
{




}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	}

	printf("[Id] Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 8));

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", p->id, p->name, p->jumsu, p->nid);
	}

	printf("[Id] Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 7));

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", p->id, p->name, p->jumsu, p->nid);
	}

	p = &Head;

	for (;;)
	{
		printf("p = 0x%.8X", p);
		printf("[Jumsu] Searched Node Address = 0x%.8X\n", p = Search_Jumsu_Node(p, 50));
		if (p == (SCORE *)0x0) break;
		printf("ID=%d, NAME=%s, SCORE=%d, njumsu = 0x%.8X\n", p->id, p->name, p->jumsu, p->njumsu);
	}
}

#endif

/***********************************************************/
// [1-4.5] list에 저장된 자료의 총수를 계산하는 함수
/***********************************************************/
/***********************************************************/
// [1-4.6] link에 따라서 주어진 사번에 맞는 자료를 인쇄하는 함수
/***********************************************************/

#if 0

int Count_Node(SCORE * head)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		if (head->nid == (SCORE *)0x0) return i;
		head = head->nid;
	}
	return i;
}

int Print_Id_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", p->id, p->name, p->jumsu, p->nid);
		return 1;
	}

	return -1;
}

int Print_Jumsu_Node(SCORE * head, int jumsu)
{
	SCORE * p = head;
	int r = -1;

	for (;;)
	{
		p = Search_Jumsu_Node(p, jumsu);
		if (p == (SCORE *)0x0) break;
		printf("ID=%d, NAME=%s, SCORE=%d, njumsu = 0x%.8X\n", p->id, p->name, p->jumsu, p->njumsu);
		r = 1;
	}

	return r;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
		printf("Node Count = %d\n", Count_Node(&Head));
	}

	printf("Print Id(8) Node Result = %d\n", Print_Id_Node(&Head, 8));
	printf("Print Id(7) Node Result = %d\n", Print_Id_Node(&Head, 7));
	printf("Print Jumsu(50) Node Result = %d\n", Print_Jumsu_Node(&Head, 50));
	printf("Print Jumsu(100) Node Result = %d\n", Print_Jumsu_Node(&Head, 100));
	printf("Print Jumsu(31) Node Result = %d\n", Print_Jumsu_Node(&Head, 31));
}

#endif

/***********************************************************/
// [1-4.7] link에 따라서 주어진 사번의 node를 찾아서 삭제하는 함수
/***********************************************************/

#if 0

int Delete_Id_Node(SCORE * head, int id)
{






}

void Delete_One_Jumsu_Node(SCORE * head, int jumsu, int id)
{





}

int Delete_Jumsu_Node(SCORE * head, int jumsu)
{





}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i < MAX_ST; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Id(8) Node Result = %d\n", Delete_Id_Node(&Head, 8));
	printf("Delete Id(7) Node Result = %d\n", Delete_Id_Node(&Head, 7));
	printf("Delete Id(1) Node Result = %d\n", Delete_Id_Node(&Head, 1));
	printf("Delete Id(10) Node Result = %d\n", Delete_Id_Node(&Head, 10));
	printf("Delete Id(25) Node Result = %d\n", Delete_Id_Node(&Head, 25));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Jumsu(45) Node Result = %d\n", Delete_Jumsu_Node(&Head, 45));
	printf("Delete Jumsu(20) Node Result = %d\n", Delete_Jumsu_Node(&Head, 20));
	printf("Delete Jumsu(90) Node Result = %d\n", Delete_Jumsu_Node(&Head, 90));
	printf("Delete Jumsu(100) Node Result = %d\n", Delete_Jumsu_Node(&Head, 100));
	printf("Delete Jumsu(87) Node Result = %d\n", Delete_Jumsu_Node(&Head, 97));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

/***********************************************************/
// [1-4.8] node에서 요청한 자료의 수를 계수하거나 버퍼에 복사해 주는 함수
/***********************************************************/

#if 0

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	if (head->nid == (SCORE *)0x0) return 0;
	head = head->nid;

	for (;;)
	{
		if (!strcmp(head->name, name)) n++;
		if (head->nid == (SCORE *)0x0) return n;
		head = head->nid;
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	if (head->njumsu == (SCORE *)0x0) return 0;
	head = head->njumsu;

	for (;;)
	{
		if (head->jumsu == jumsu) n++;
		if (head->njumsu == (SCORE *)0x0) return n;
		head = head->njumsu;
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{






}

int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf)
{






}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;
	SCORE new_head;

	for (i = 0; i < 20; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));

	printf("Name Node Count = %d\n", r = Count_Name_Node(&Head, "lew"));
	p = calloc(r, sizeof(SCORE));
	printf("Copy Name Node Result = %d\n", Copy_Name_Node(&Head, "lew", p));
	new_head.nid = p;
	printf("Printed Node Count = %d\n", Print_All_Id_Node(&new_head));
	free(p);

	printf("Score Node Count = %d\n", r = Count_Score_Node(&Head, 100));
	p = calloc(r, sizeof(SCORE));
	printf("Copy Score Node Result = %d\n", Copy_Score_Node(&Head, 100, p));
	new_head.njumsu = p;
	printf("Printed Node Count = %d\n", Print_All_Jumsu_Node(&new_head));
	free(p);
}

#endif

#endif

/***********************************************************/
// [1-5] 배열 기반 연결 리스트 - 더블 링크
/***********************************************************/

#if 0

/***********************************************************/
// [1-5.1] 기존 Linked List 방식중 그대로 사용하는 함수들
// 단, 인쇄할 때 Prev Node 값도 인쇄하도록 추가한다
/***********************************************************/

#if 01

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * next;
	struct _score  * prev;
}SCORE;

SCORE Head;

#define MAX_ST		20

SCORE exam[MAX_ST];

// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다



int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
int Print_All_Node_Reverse(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
int Count_Node(SCORE * head);
int Print_Node(SCORE * head, int id);
int Delete_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);
int Print_Selected_Node(SCORE *head, int id, int num);
int Print_Selected_Node_Reverse(SCORE *head, int id, int num);

SCORE test[MAX_ST] = { {10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
							   {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
							   {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
							   {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"} };

void Make_Test_Data(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		exam[i] = test[i];
	}
}

int Create_Data(SCORE * p)
{
	printf("\n사번을 입력하시오 => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);
	p->next = (SCORE *)0x0;
	p->prev = (SCORE *)0x0;

	return 1;
}

int Print_All_Data(void)
{
	int i;

	printf("Head= 0x%.8X, Head.next=0x%.8X, Head.prev=0x%.8X\n", &Head, Head.next, Head.prev);

	for (i = 0; i < MAX_ST; i++)
	{
		if (exam[i].id == 0) break;
		printf("[%d] addr=0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", i, &exam[i], exam[i].id, exam[i].name, exam[i].jumsu, exam[i].next, exam[i].prev);
	}

	return i;
}

int Print_Data(int no)
{
	if (exam[no].id == 0) return -1;
	printf("[%d] addr=0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", no, &exam[no], exam[no].id, exam[no].name, exam[no].jumsu, exam[no].next, exam[no].prev);
	return 1;
}

int Count_Data(void)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		if (exam[i].id == 0) break;
	}

	return i;
}

int Insert_Data(SCORE * p)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		if (exam[i].id == 0)
		{
			exam[i] = (*p);
			return i;
		}

		if (exam[i].id == p->id)
		{
			return -2;
		}
	}

	return -1;
}

int Print_All_Node(SCORE * head)
{
	int i;

	printf("Head.next = 0x%.8X Head.prev = 0x%.8X\n", head->next, head->prev);

	for (i = 0; i < MAX_ST; i++)
	{
		if (head->next == (SCORE *)0x0) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head->next, head->next->id, head->next->name, head->next->jumsu, head->next->next, head->next->prev);
		head = head->next;
	}
	return i;
}

int Count_Node(SCORE * head)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		if (head->next == (SCORE *)0x0) return i;
		head = head->next;
	}
	return i;
}

int Print_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", p->id, p->name, p->jumsu, p->next, p->prev);
		return 1;
	}

	return -1;
}

int Copy_All_Node(SCORE * head, SCORE * buf)
{
	int i;
	if (head->next == NULL) return -1;

	for (i = 0; i < MAX_ST; i++)
	{
		if (head->next == NULL) break;
		buf[i] = *head->next;
		buf[i].next = &buf[i + 1];
		head = head->next;
	}

	buf[i - 1].next = NULL;
	return i;
}

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (!strcmp(head->name, name)) n++;
		if (head->next == (SCORE *)0x0) return n;
		head = head->next;
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (head->jumsu == jumsu) n++;
		if (head->next == (SCORE *)0x0) return n;
		head = head->next;
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (!strcmp(head->name, name))
		{
			buf[n] = *head;
			buf[n].next = &buf[n + 1];
			n++;
		}
		if (head->next == (SCORE *)0x0) break;
		head = head->next;
	}
	buf[n - 1].next = (SCORE *)0x0;
	return n;
}

int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (head->jumsu == jumsu)
		{
			buf[n] = *head;
			buf[n].next = &buf[n + 1];
			n++;
		}
		if (head->next == (SCORE *)0x0) break;
		head = head->next;
	}
	buf[n - 1].next = (SCORE *)0x0;
	return n;
}

#endif

/***********************************************************/
// [1-5.2] 데이터 하나를 생성하여 Linked List에 추가하는 함수
/***********************************************************/

#if 01

int Insert_Node(SCORE * head, SCORE * d)
{
	int i;

	for (i = 0; i < MAX_ST; i++) {
		if (head->next == NULL) break;
		if (head->next->id == d->id) return -2;
		if (head->next->id > d->id) {
			d->next = head->next;
			d->prev = head;
			d->next->prev = d;
			d->prev->next = d;
			return 1;
		}
		head = head->next;
	}
	if (i == MAX_ST) return -1;
	d->next = NULL;
	d->prev = head;
	d->prev->next = d;
	return 1;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}
}

#endif

/***********************************************************/
// [1-5.3] 주어진 사번의 node를 찾아서 삭제하는 함수
/***********************************************************/

#if 01

SCORE * Search_Id_Node(SCORE * head, int id)
{
	while (head->next) {
		if (head->next->id == id) return head->next;
		head = head->next;
	}
	return 0;
}

int Delete_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);
	if (p == NULL) return -1;
	p->prev->next = p->next;
	if (p->next != NULL) p->next->prev = p->prev;
	p->id = 0;
	return 1;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("[8] Delete Node Result = %d\n", Delete_Node(&Head, 8));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("[7] Delete Node Result = %d\n", Delete_Node(&Head, 7));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("[1] Delete Node Result = %d\n", Delete_Node(&Head, 1));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("[10] Delete Node Result = %d\n", Delete_Node(&Head, 10));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

/***********************************************************/
// [1-5.4] 더블 링크 사용의 장점 1, 내림차순 검색
/***********************************************************/

#if 01

int Print_All_Node_Reverse(SCORE * head)
{
	while (head->next) head = head->next;
	while (head->prev) {
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head, head->id, head->name, head->jumsu, head->next, head->prev);
		head = head->prev;
	}
	return 1;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count(Up) = %d\n", Print_All_Node(&Head));
	printf("Printed Node Count(Down) = %d\n", Print_All_Node_Reverse(&Head));
	printf("[8] Delete Node Result = %d\n", Delete_Node(&Head, 8));
	printf("Printed Node Count(Down) = %d\n", Print_All_Node_Reverse(&Head));
}

#endif

/***********************************************************/
// [1-5.5] 더블 링크 사용의 장점 2, 역방향으로 일정 범위 인쇄
/***********************************************************/

#if 01

int Print_Selected_Node(SCORE * head, int id, int num)
{
	int i = 0;
	SCORE * p =Search_Id_Node(head, id);

	if (p == NULL) return -1;
	while (p && i < num) {
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", p, p->id, p->name, p->jumsu, p->next, p->prev);
		p = p->next;
		i++;
	}
	return i;
}

int Print_Selected_Node_Reverse(SCORE *head, int id, int num)
{
	int i = 0;
	SCORE * p = Search_Id_Node(head, id);

	if (p == NULL) return -1;
	while (p && i < num) {
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", p, p->id, p->name, p->jumsu, p->next, p->prev);
		p = p->prev;
		i++;
	}
	return i;
}

#endif

#if 0
void main(void)
{
	int i;
	int r;

	for (i = 0; i < MAX_ST; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count(Up) = %d\n", Print_All_Node(&Head));
	printf("Printed Node Count(Down) = %d\n", Print_All_Node_Reverse(&Head));

	r = Print_Selected_Node(&Head, 7, 3);
	printf("Printed Data Number => %d\n", r);

	r = Print_Selected_Node(&Head, 19, 3);
	printf("Printed Data Number => %d\n", r);

	r = Print_Selected_Node_Reverse(&Head, 7, 3);
	printf("Printed Data Number => %d\n", r);

	r = Print_Selected_Node_Reverse(&Head, 2, 3);
	printf("Printed Data Number => %d\n", r);
}

#endif

#endif

/***********************************************************/
// [1-6] 선형 리스트 - stack
/***********************************************************/

#if 0

#include <stdio.h>

#define MAX_STACK		10
#define STACK_EMPTY	MAX_STACK
#define STACK_FULL		0

int Push_Stack(int data);
int Pop_Stack(int *p);
int Print_Stack(void);
int Count_Full_Data_Stack(void);
int Count_Empty_Data_Stack(void);

int a[MAX_STACK + 1] = { 1,2,3,4,5,6,7,8,9,10,11 };
int Stack[MAX_STACK];
int Sptr = STACK_EMPTY;

int Push_Stack(int data)
{
	if (Sptr == STACK_FULL) return -1;
	Stack[--Sptr] = data;
	return 1;
}

int Pop_Stack(int *p)
{
	if (Sptr == STACK_EMPTY) return -1;
	*p = Stack[Sptr++];
	return 1;
}

int Print_Stack(void)
{
	int i;

	for (i = Sptr; i < MAX_STACK; i++)
	{
		printf("STACK[%d] = %d\n", i, Stack[i]);
	}

	return MAX_STACK - Sptr;
}

int Count_Full_Data_Stack(void)
{
	return STACK_EMPTY - Sptr;
}

int Count_Empty_Data_Stack(void)
{
	return Sptr - STACK_FULL;
}

void main(void)
{
	int i;

	for (i = 0; i < (MAX_STACK + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");

	for (i = 0; i < 5; i++)
	{
		printf("Push Result = %d\n", Push_Stack(a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}

	for (i = 0; i < 5; i++)
	{
		printf("Pop Result = %d\n", Pop_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}

	for (i = 0; i < (MAX_STACK + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");

	for (i = 0; i < (MAX_STACK + 1); i++)
	{
		printf("Push Result = %d\n", Push_Stack(a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}

	for (i = 0; i < (MAX_STACK + 1); i++)
	{
		printf("Pop Result = %d\n", Pop_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}

	for (i = 0; i < (MAX_STACK + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");
}

#endif

/***********************************************************/
// [1-7] 선형 리스트 - Linear Queue
/***********************************************************/

#if 0

#include <stdio.h>

#define MAX_Q			5
#define Q_EMPTY		0
#define Q_FULL			MAX_Q

int In_Queue(int data);
int Out_Queue(int *p);
int Print_Queue(void);
int Count_Full_Data_Queue(void);
int Count_Empty_Data_Queue(void);

int a[MAX_Q + 1] = { 1,2,3,4,5,6 };
int Queue[MAX_Q];
int Wrptr = Q_EMPTY;
int Rdptr = Q_EMPTY;

int In_Queue(int data)
{
	if (Wrptr == Q_FULL) {
		if (Rdptr == Q_EMPTY) return -1;
		for (int i = 0; i < Wrptr - Rdptr; i++) { Queue[i] = Queue[Rdptr+i]; }
		Wrptr = Wrptr - Rdptr;
		Rdptr = 0;
	}
	Queue[Wrptr++] = data;
	return 1;
}

int Out_Queue(int *p)
{
	if (Rdptr == Wrptr) return -1;
	*p = Queue[Rdptr++];
	return 1;
}

int Print_Queue(void)
{
	int i;

	for (i = Rdptr; i < Wrptr; i++)
	{
		printf("Queue[%d] = %d\n", i, Queue[i]);
	}

	return Wrptr - Rdptr;
}

int Count_Full_Data_Queue(void)
{
	return Wrptr - Rdptr;
}

int Count_Empty_Data_Queue(void)
{
	return MAX_Q - (Wrptr - Rdptr);
}

void main(void)
{
	int i;

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");

	for (i = 0; i < 3; i++)
	{
		printf("Queue Result = %d\n", In_Queue(a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < 3; i++)
	{
		a[i] = 0;
	}

	for (i = 0; i < 3; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("Queue Result = %d\n", In_Queue(a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		a[i] = 0;
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");
}

#endif

/***********************************************************/
// [1-8] 선형 리스트 - Circular Queue
/***********************************************************/

#if 0

#include <stdio.h>

#define MAX_Q		8
#define Q_MIN		0
#define Q_MAX		MAX_Q

int In_Queue(int data);
int Out_Queue(int *p);
int Print_Queue(void);
int Count_Full_Data_Queue(void);
int Count_Empty_Data_Queue(void);

int a[MAX_Q + 1] = { 1,2,3,4,5,6,7,8,9 };
int Queue[MAX_Q];
int Wrptr = Q_MIN;
int Rdptr = Q_MIN;

int In_Queue(int data)
{
	if ((Wrptr + 1) % MAX_Q == Rdptr) return -1;
	Queue[Wrptr] = data;
	Wrptr = (++Wrptr) % MAX_Q;
	return 1;
}

int Out_Queue(int *p)
{
	if (Rdptr == Wrptr) return -1;
	*p = Queue[Rdptr];
	Rdptr = (++Rdptr) % MAX_Q;
	return 1;
}

int Print_Queue(void)
{
	int i;
	int rd = Rdptr;
	int n = Count_Full_Data_Queue();

	for (i = 0; i < n; i++)
	{
		printf("Queue[%d] = %d\n", rd, Queue[rd++]);
		rd %= MAX_Q;
	}

	return n;
}

int Count_Full_Data_Queue(void)
{
	if (Rdptr > Wrptr) return MAX_Q - (Rdptr - Wrptr);
	return Wrptr - Rdptr;
}

int Count_Empty_Data_Queue(void)
{
	return MAX_Q - Count_Full_Data_Queue() - 1;
}

void main(void)
{
	int i;

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");

	for (i = 0; i < 3; i++)
	{
		printf("Queue Result = %d\n", In_Queue(a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < 3; i++)
	{
		a[i] = 0;
	}

	for (i = 0; i < 3; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("Queue Result = %d\n", In_Queue(a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		a[i] = 0;
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");
}

#endif

/***********************************************************/
// [2-1] 힙 기반 Linked List
/***********************************************************/

#if 0

/***********************************************************/
// [2-1.1] 기존 배열 기반 linked list 방식중 그대로 사용하는 함수들
/***********************************************************/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * next;
}SCORE;

SCORE Head;

// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다



int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
int Count_Node(SCORE * head);
int Print_Node(SCORE * head, int id);
int Delete_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);

#define MAX_ST  20

SCORE test[MAX_ST] = { {10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
							   {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
							   {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
							   {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"} };

int Create_Data(SCORE * p)
{
	printf("\n사번을 입력하시오 => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);
	p->next = (SCORE *)0x0;

	return 1;
}

int Print_All_Node(SCORE * head)
{
	int n = 0;

	printf("Head.next = 0x%.8X\n", head->next);
	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", head, head->id, head->name, head->jumsu, head->next);
		n++;
		if (head->next == (SCORE *)0x0) return n;
		head = head->next;
	}
}

SCORE * Search_Id_Node(SCORE * head, int id)
{
	if (head->next == (SCORE *)0x0) return (SCORE *)0x0;
	head = head->next;

	for (;;)
	{
		if (head->id == id) return head;
		if (head->next == (SCORE *)0x0) return (SCORE *)0x0;
		head = head->next;
	}
}

int Count_Node(SCORE * head)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		n++;
		if (head->next == (SCORE *)0x0) return n;
		head = head->next;
	}
}

int Print_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
		return 1;
	}

	return -1;
}

int Copy_All_Node(SCORE * head, SCORE * buf)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return -1;
	head = head->next;

	for (;;)
	{
		buf[n] = *head;
		buf[n].next = &buf[n + 1];
		if (head->next == (SCORE *)0x0)
		{
			buf[n].next = (SCORE *)0x0;
			return n + 1;
		}
		n++;
		head = head->next;
	}
}

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (!strcmp(head->name, name)) n++;
		if (head->next == (SCORE *)0x0) return n;
		head = head->next;
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (head->jumsu == jumsu) n++;
		if (head->next == (SCORE *)0x0) return n;
		head = head->next;
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (!strcmp(head->name, name))
		{
			buf[n] = *head;
			buf[n].next = &buf[n + 1];
			n++;
		}

		if (head->next == (SCORE *)0x0)
		{
			buf[n - 1].next = (SCORE *)0x0;
			return n;
		}

		head = head->next;
	}
}

int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (head->jumsu == jumsu)
		{
			buf[n] = *head;
			buf[n].next = &buf[n + 1];
			n++;
		}

		if (head->next == (SCORE *)0x0)
		{
			buf[n - 1].next = (SCORE *)0x0;
			return n;
		}

		head = head->next;
	}
}

/***********************************************************/
// [2-1.2] 전달받은 데이터를 힙에 생성하고 Linked List에 추가하는 함수 (calloc 사용)
/***********************************************************/

#if 01

int Insert_Node(SCORE * head, SCORE * d)
{
	SCORE * p;
	while (head->next) {
		if (head->next->id == d->id) return -2;
		if (head->next->id > d->id) break;
		head = head->next;
	}
	if ((p = calloc(1, sizeof(SCORE))) == NULL) return -1;
	*p = *d;
	p->next = head->next;
	head->next = p;
	return 1;
}

#endif

#if 0

void main(void)
{
	int i;
	SCORE * p;

	for (i = 0; i < 8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));

	printf("Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 8));

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
	}

	printf("Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 7));

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
	}
}

#endif

/***********************************************************/
// [2-1.3] 전달받은 사번의 자료를 링크와 힙에서 삭제하는 함수 (free 사용)
/***********************************************************/

#if 01

int Delete_Node(SCORE * head, int id)
{
	SCORE * p;

	while (head->next) {
		if (head->next->id == id) {
			p = head->next;
			head->next = head->next->next;
			free(p);
			return 1;
		}
		head = head->next;
	}
	return -1;
}

#endif

#if 0

void main(void)
{
	int i;

	for (i = 0; i < 8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 8));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 7));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 1));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 10));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

#endif

/***********************************************************/
// [2-2] 힙 기반 연결 리스트 - 다중 링크
/***********************************************************/

#if 0

/***********************************************************/
// 기존 배열 기반 연결 리스트와 동일하게 사용되는 함수들 
/***********************************************************/

#if 01

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * nid;
	struct _score  * njumsu;
}SCORE;

SCORE Head;

#define MAX_ST		20

SCORE exam[MAX_ST];

// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다


int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
int Print_All_Id_Node(SCORE * head);
int Print_All_Jumsu_Node(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
SCORE * Search_Jumsu_Node(SCORE * head, int jumsu);
int Count_Node(SCORE * head);
int Print_Id_Node(SCORE * head, int id);
int Print_Jumsu_Node(SCORE * head, int jumsu);
int Delete_Id_Node(SCORE * head, int id);
void Delete_One_Jumsu_Node(SCORE * head, int jumsu, int id);
int Delete_Jumsu_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);

SCORE test[MAX_ST] = { {10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
							   {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
							   {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
							   {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"} };

int Create_Data(SCORE * p)
{
	printf("\n사번을 입력하시오 => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);
	p->nid = (SCORE *)0x0;
	p->njumsu = (SCORE *)0x0;

	return 1;
}


int Print_All_Node(SCORE * head)
{
	Print_All_Id_Node(head);
	return Print_All_Jumsu_Node(head);
}

int Print_All_Id_Node(SCORE * head)
{
	int i = 0;

	printf("[Id] Head.nid = 0x%.8X\n", head->nid);

	for (;;)
	{
		if (head->nid == (SCORE *)0x0) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", head->nid, head->nid->id, head->nid->name, head->nid->jumsu, head->nid->nid);
		head = head->nid;
		i++;
	}
}

int Print_All_Jumsu_Node(SCORE * head)
{
	int i = 0;

	printf("[Jumsu] Head.njumsu = 0x%.8X\n", head->njumsu);

	for (;;)
	{
		if (head->njumsu == (SCORE *)0x0) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", head->njumsu, head->njumsu->id, head->njumsu->name, head->njumsu->jumsu, head->njumsu->njumsu);
		head = head->njumsu;
		i++;
	}
}

SCORE * Search_Id_Node(SCORE * head, int id)
{
	for (;;)
	{
		if (head->nid == (SCORE *)0x0) return (SCORE *)0x0;
		if (head->nid->id == id) return head->nid;
		head = head->nid;
	}
}

SCORE * Search_Jumsu_Node(SCORE * head, int jumsu)
{
	for (;;)
	{
		if (head->njumsu == (SCORE *)0x0) return (SCORE *)0x0;
		if (head->njumsu->jumsu == jumsu) return head->njumsu;
		head = head->njumsu;
	}
}

int Count_Node(SCORE * head)
{
	int i = 0;

	for (;;)
	{
		if (head->nid == (SCORE *)0x0) return i;
		head = head->nid;
		i++;
	}
}

int Print_Id_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", p->id, p->name, p->jumsu, p->nid);
		return 1;
	}

	return -1;
}

int Print_Jumsu_Node(SCORE * head, int jumsu)
{
	SCORE * p = head;
	int r = -1;

	for (;;)
	{
		p = Search_Jumsu_Node(p, jumsu);
		if (p == (SCORE *)0x0) break;
		printf("ID=%d, NAME=%s, SCORE=%d, njumsu = 0x%.8X\n", p->id, p->name, p->jumsu, p->njumsu);
		r = 1;
	}

	return r;
}

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	if (head->nid == (SCORE *)0x0) return 0;
	head = head->nid;

	for (;;)
	{
		if (!strcmp(head->name, name)) n++;
		if (head->nid == (SCORE *)0x0) return n;
		head = head->nid;
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	if (head->njumsu == (SCORE *)0x0) return 0;
	head = head->njumsu;

	for (;;)
	{
		if (head->jumsu == jumsu) n++;
		if (head->njumsu == (SCORE *)0x0) return n;
		head = head->njumsu;
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{
	int n = 0;

	if (head->nid == (SCORE *)0x0) return 0;
	head = head->nid;

	for (;;)
	{
		if (!strcmp(head->name, name))
		{
			buf[n] = *head;
			buf[n].nid = &buf[n + 1];
			n++;
		}
		if (head->nid == (SCORE *)0x0) break;
		head = head->nid;
	}
	buf[n - 1].nid = (SCORE *)0x0;
	return n;
}

int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf)
{
	int n = 0;

	if (head->njumsu == (SCORE *)0x0) return 0;
	head = head->njumsu;

	for (;;)
	{
		if (head->jumsu == jumsu)
		{
			buf[n] = *head;
			buf[n].njumsu = &buf[n + 1];
			n++;
		}
		if (head->njumsu == (SCORE *)0x0) break;
		head = head->njumsu;
	}
	buf[n - 1].njumsu = (SCORE *)0x0;
	return n;
}

#endif

/***********************************************************/
// [2-2.1] 데이터 하나를 생성하여 Linked List에 추가하는 함수  (calloc 사용)
/***********************************************************/

#if 01

int Insert_Node(SCORE * head, SCORE * d)
{
	SCORE * p, *head2;
	head2 = head;
	while (head->nid) {
		if (head->nid->id == d->id) return -2;
		if (head->nid->id > d->id) break;
		head = head->nid;
	}
	if ((p = calloc(1, sizeof(SCORE))) == NULL) return -1;
	*p = *d;
	p->nid = head->nid;
	head->nid = p;
	while (head2->njumsu) {
		if (head2->njumsu->jumsu > d->jumsu) break;
		head2 = head2->njumsu;
	}
	p->njumsu = head2->njumsu;
	head2->njumsu = p;
	return 1;
}

#endif

#if 0

void main(void)
{
	int i;

	for (i = 0; i < 8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	}
}

#endif

/***********************************************************/
// [2-2.2] link에 따라서 주어진 사번의 node를 찾아서 삭제하는 함수 (free 사용)
/***********************************************************/

#if 01

int Delete_Id_Node(SCORE * head, int id)
{
	SCORE * temp = head;
	SCORE * p = 0;

	while (head->nid) {
		if (head->nid->id == id) {
			p = head->nid;
			head->nid = head->nid->nid;
			break;
		}
		head = head->nid;
	}
	if (p == 0) return -1;
	head = temp;
	Delete_One_Jumsu_Node(head, p->jumsu, p->id);
	free(p);
	return 1;
}

void Delete_One_Jumsu_Node(SCORE * head, int jumsu, int id)
{
	while (head->njumsu) {
		if (head->njumsu->jumsu == jumsu && head->njumsu->id == id) {
			head->njumsu = head->njumsu->njumsu;
			break;
		}
		head = head->njumsu;
	}
}

int Delete_Jumsu_Node(SCORE * head, int jumsu)
{
	int flag = 0;
	SCORE * p;
	
	while ((p = Search_Jumsu_Node(head, jumsu))) {
		flag = 1;
		if (Delete_Id_Node(head, p->id) == -1) return -1;
	}
	if (flag) return 1;
	return -1;
}

#endif

#if 01

void main(void)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Id(8) Node Result = %d\n", Delete_Id_Node(&Head, 8));
	printf("Delete Id(7) Node Result = %d\n", Delete_Id_Node(&Head, 7));
	printf("Delete Id(1) Node Result = %d\n", Delete_Id_Node(&Head, 1));
	printf("Delete Id(10) Node Result = %d\n", Delete_Id_Node(&Head, 10));
	printf("Delete Id(25) Node Result = %d\n", Delete_Id_Node(&Head, 25));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Jumsu(45) Node Result = %d\n", Delete_Jumsu_Node(&Head, 45));
	printf("Delete Jumsu(20) Node Result = %d\n", Delete_Jumsu_Node(&Head, 20));
	printf("Delete Jumsu(90) Node Result = %d\n", Delete_Jumsu_Node(&Head, 90));
	printf("Delete Jumsu(100) Node Result = %d\n", Delete_Jumsu_Node(&Head, 100));
	printf("Delete Jumsu(87) Node Result = %d\n", Delete_Jumsu_Node(&Head, 97));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

#endif

/***********************************************************/
// [2-2.3] 힙 기반 연결 리스트 - 더블 링크
/***********************************************************/

#if 0

/***********************************************************/
// [2-2.3] 기존 Linked List 방식중 그대로 사용하는 함수들
/***********************************************************/

#if 01

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * next;
	struct _score  * prev;
}SCORE;

SCORE Head;

#define MAX_ST		20

SCORE exam[MAX_ST];

// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다


int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
int Print_All_Node_Reverse(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
int Count_Node(SCORE * head);
int Print_Node(SCORE * head, int id);
int Delete_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);
int Print_Selected_Node(SCORE *head, int id, int num);
int Print_Selected_Node_Reverse(SCORE *head, int id, int num);

SCORE test[MAX_ST] = { {10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
							   {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
							   {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
							   {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"} };


int Create_Data(SCORE * p)
{
	printf("\n사번을 입력하시오 => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);
	p->next = (SCORE *)0x0;
	p->prev = (SCORE *)0x0;

	return 1;
}

SCORE * Search_Id_Node(SCORE * head, int id)
{
	for (;;)
	{
		if (head->next == (SCORE *)0x0) return (SCORE *)0x0;
		if (head->next->id == id) return head->next;
		head = head->next;
	}
}

int Count_Node(SCORE * head)
{
	int i = 0;

	for (;;)
	{
		if (head->next == (SCORE *)0x0) return i;
		head = head->next;
		i++;
	}
}

int Print_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", p->id, p->name, p->jumsu, p->next, p->prev);
		return 1;
	}

	return -1;
}

int Copy_All_Node(SCORE * head, SCORE * buf)
{
	int i = 0;
	if (head->next == NULL) return -1;

	for (;;)
	{
		if (head->next == NULL) break;
		buf[i] = *head->next;
		buf[i].next = &buf[i + 1];
		head = head->next;
		i++;
	}

	buf[i - 1].next = NULL;
	return i;
}

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (!strcmp(head->name, name)) n++;
		if (head->next == (SCORE *)0x0) return n;
		head = head->next;
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (head->jumsu == jumsu) n++;
		if (head->next == (SCORE *)0x0) return n;
		head = head->next;
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (!strcmp(head->name, name))
		{
			buf[n] = *head;
			buf[n].next = &buf[n + 1];
			n++;
		}
		if (head->next == (SCORE *)0x0) break;
		head = head->next;
	}
	buf[n - 1].next = (SCORE *)0x0;
	return n;
}

int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (head->jumsu == jumsu)
		{
			buf[n] = *head;
			buf[n].next = &buf[n + 1];
			n++;
		}
		if (head->next == (SCORE *)0x0) break;
		head = head->next;
	}
	buf[n - 1].next = (SCORE *)0x0;
	return n;
}

int Print_All_Node(SCORE * head)
{
	int i = 0;

	printf("Head.next = 0x%.8X Head.prev = 0x%.8X\n", head->next, head->prev);

	for (;;)
	{
		if (head->next == (SCORE *)0x0) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head->next, head->next->id, head->next->name, head->next->jumsu, head->next->next, head->next->prev);
		head = head->next;
		i++;
	}
}

int Print_All_Node_Reverse(SCORE * head)
{
	int i = 0;

	printf("Head.next = 0x%.8X Head.prev = 0x%.8X\n", head->next, head->prev);

	while (head->next != (SCORE *)0x0)
	{
		head = head->next;
	}

	printf("Tail.next = 0x%.8X Tail.prev = 0x%.8X\n", head->next, head->prev);

	for (;;)
	{
		if (head->prev == (SCORE *)0x0) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head, head->id, head->name, head->jumsu, head->next, head->prev);
		head = head->prev;
		i++;
	}
}

int Print_Selected_Node(SCORE * head, int id, int num)
{
	int i = 0;

	head = Search_Id_Node(head, id);

	if (head == (SCORE *)0x0) return -1;

	printf("==================================================================================\n");

	while (i < num)
	{
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head, head->id, head->name, head->jumsu, head->next, head->prev);
		i++;
		if (head->next == (SCORE *)0x0) break;
		head = head->next;
	}

	return i;
}

int Print_Selected_Node_Reverse(SCORE *head, int id, int num)
{
	int i = 0;

	head = Search_Id_Node(head, id);

	if (head == (SCORE *)0x0) return -1;

	printf("==================================================================================\n");

	while (i < num)
	{
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head, head->id, head->name, head->jumsu, head->next, head->prev);
		i++;
		if (head->prev->prev == (SCORE *)0x0) break;
		head = head->prev;
	}

	return i;
}

#endif

/***********************************************************/
// [2-2.3] 데이터 하나를 생성하여 Linked List에 추가하는 함수 (calloc 사용)
/***********************************************************/

#if 01

int Insert_Node(SCORE * head, SCORE * d)
{
	SCORE * p;

	while (head->next) {
		if (head->next->id == d->id) return -2;
		if (head->next->id > d->id) break;
		head = head->next;
	}
	if ((p = calloc(1, sizeof(SCORE))) == NULL) return -1;
	*p = *d;
	p->next = head->next;
	p->prev = head;
	p->prev->next = p;
	if (p->next) p->next->prev = p;
	return 1;
}

#endif

#if 0

void main(void)
{
	int i;

	for (i = 0; i < 8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	}
}

#endif

/***********************************************************/
// [2-2.4] 주어진 사번의 node를 찾아서 삭제하는 함수
/***********************************************************/

#if 01

int Delete_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);

	if (p == NULL) return -1;
	p->prev->next = p->next;
	if (p->next) p->next->prev = p->prev;
	free(p);
	return 1;
}

#endif

#if 0

void main(void)
{
	int i;

	for (i = 0; i < 8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 8));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 7));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 1));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 10));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

#endif

/***********************************************************/
// [2-3] 힙 기반 선형자료구조
/***********************************************************/

/***********************************************************/
// [2-3.1] 힙 기반 stack
/***********************************************************/

#if 0

#include <stdio.h>
#include <malloc.h>

typedef struct _stk
{
	int num;
	struct _stk * next;
}STACK;

STACK * Sptr = (STACK *)0;
STACK a[10] = { {1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0} };

int Push_Stack(STACK * data);
int Pop_Stack(STACK * p);
int Print_Stack(void);
int Count_Full_Data_Stack(void);

int Push_Stack(STACK *data)
{
	STACK * p = calloc(1, sizeof(STACK));
	if (p == NULL) return -1;
	*p = *data;
	p->next = Sptr;
	Sptr = p;
	return 1;
}

int Pop_Stack(STACK *p)
{
	STACK * temp = Sptr;

	if (Sptr == NULL) return -1;
	*p = *Sptr;
	Sptr = Sptr->next;
	free(temp);
	return 1;
}

int Print_Stack(void)
{
	STACK * p = Sptr;

	if (p == NULL) return -1;
	while (p) {
		printf("addr %.8X num = %d next %.8X\n", p,p->num,p->next);
		p = p->next;
	}
	return 1;
}

int Count_Full_Data_Stack(void)
{
	STACK * p = Sptr;
	int cnt = 0;

	while (p) {
		cnt++;
		p = p->next;
	}
	return cnt;
}

void main(void)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("Push Result = %d\n", Push_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d\n", Count_Full_Data_Stack());
	}

	for (i = 0; i < 6; i++)
	{
		printf("Pop Result = %d\n", Pop_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d\n ", Count_Full_Data_Stack());
	}

	for (i = 0; i < 3; i++)
	{
		printf("Push Result = %d\n", Push_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d\n", Count_Full_Data_Stack());
	}

	for (i = 0; i < 5; i++)
	{
		printf("Pop Result = %d\n", Pop_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d\n ", Count_Full_Data_Stack());
	}

	printf("\n");
}

#endif

/***********************************************************/
// [2-3.2] 힙 기반  Linear Queue
/***********************************************************/

#if 0

#include <stdio.h>
#include <malloc.h>

typedef struct _que
{
	int num;
	struct _que * next;
}QUEUE;

QUEUE * Wrptr = (QUEUE *)0;;
QUEUE * Rdptr = (QUEUE *)0;;

QUEUE a[10] = { {1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0} };

int In_Queue(QUEUE * data);
int Out_Queue(QUEUE * p);
int Print_Queue(void);
int Count_Full_Data_Queue(void);

int In_Queue(QUEUE * data)
{
	QUEUE * p;

	if ((p = calloc(1, sizeof(QUEUE))) == NULL) return -1;
	*p = *data;
	if (Wrptr == NULL) Rdptr = p;
	else Wrptr->next = p;
	p->next = NULL;
	Wrptr = p;
	return 1;
}

int Out_Queue(QUEUE * p)
{
	QUEUE * temp = Rdptr;

	if (Rdptr == NULL) return -1;
	*p = *Rdptr;
	Rdptr = Rdptr->next;
	if (Rdptr == NULL) Wrptr = NULL;
	free(temp);
	return 1;
}

int Print_Queue(void)
{
	QUEUE * p = Rdptr;

	if (p == NULL) return -1;
	while (p->next) {
		printf("addr %.8X num = %d next %.8X\n", p, p->num, p->next);
		p = p->next;
	}
	printf("addr %.8X num = %d next %.8X\n", p, p->num, p->next);
	return 1;
}

int Count_Full_Data_Queue(void)
{
	int i = 0;
	QUEUE * p = Rdptr;

	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

void main(void)
{
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("Queue Result = %d\n", In_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}

	for (i = 0; i < 2; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}

	for (i = 0; i < 4; i++)
	{
		printf("Queue Result = %d\n", In_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}

	for (i = 0; i < 7; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}

	for (i = 0; i < 3; i++)
	{
		printf("Queue Result = %d\n", In_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}

	for (i = 0; i < 3; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}
}

#endif

/***********************************************************/
// [3-1] 힙 기반 비선형 자료구조 - 이진 트리
/***********************************************************/

#if 0

/***********************************************************/
// [3-1.1] 이진 Tree의 인쇄
/***********************************************************/

#if 0

#include <stdio.h>

struct node
{
	char *name;
	struct node *left;
	struct node *right;
};

void Print_All_Node1(struct node *p);
void Print_All_Node2(struct node *p);
void Print_All_Node3(struct node *p);

void main(void)
{
	struct node root, node1, node2, node3, node4;

	root.left = &node1;
	root.right = &node2;
	root.name = "root";
	node1.left = &node3;
	node1.right = &node4;
	node1.name = "node1";
	node2.left = NULL;
	node2.right = NULL;
	node2.name = "node2";
	node3.left = NULL;
	node3.right = NULL;
	node3.name = "node3";
	node4.left = NULL;
	node4.right = NULL;
	node4.name = "node4";

	printf("In-order Traverse===============\n");
	Print_All_Node1(&root);
	printf("Pre-order Traverse===============\n");
	Print_All_Node2(&root);
	printf("Post-order Traverse===============\n");
	Print_All_Node3(&root);
}

void Print_All_Node1(struct node *p)
{
	if (p->left) Print_All_Node1(p->left);
	printf("Name = %s\n", p->name);
	if (p->right) Print_All_Node1(p->right);
}

void Print_All_Node2(struct node *p)
{
	printf("Name = %s\n", p->name);
	if (p->left) Print_All_Node2(p->left);
	if (p->right) Print_All_Node2(p->right);
}

void Print_All_Node3(struct node *p)
{
	if (p->left) Print_All_Node3(p->left);
	if (p->right) Print_All_Node3(p->right);
	printf("Name = %s\n", p->name);
}

#endif

/***********************************************************/
// [3-1.2] 이진 트리를 위한 기본 함수들
/***********************************************************/

#if 01

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * left;
	struct _score  * right;
	struct _score  * parent;
}SCORE;

SCORE * Root = (SCORE *)0x0;

#define MAX_ST		20

// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다

void Print_All_Node(SCORE * p);
void Delete_All_Node(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
SCORE * Search_Node(SCORE * head, int id);
int Delete_Node(SCORE * head, int id);
SCORE * Create_Node(SCORE * d);
int Create_Data(SCORE * p);

SCORE test[MAX_ST] = { {10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
							   {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
							   {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
							   {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"} };

int Create_Data(SCORE * p)
{
	printf("\n사번을 입력하시오 => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);
	p->left = (SCORE *)0x0;
	p->right = (SCORE *)0x0;

	return 1;
}

void Print_All_Node(SCORE * p)
{
	if (p == (SCORE *)0)
	{
		printf("No Data\n");
		return;
	}

	if (p->left) Print_All_Node(p->left);
	printf("addr=0x%.8X, ID=%d, NAME=%s, SCORE=%d, left=0x%.8X, right=0x%.8X parent=0x%.8X\n", p, p->id, p->name, p->jumsu, p->left, p->right, p->parent);
	if (p->right) Print_All_Node(p->right);
}

#endif

/***********************************************************/
// [3-1.3] 데이터 하나를 생성하여 Linked List에 추가하는 함수 (calloc 사용)
/***********************************************************/

#if 01

SCORE * Create_Node(SCORE * d)
{
	SCORE * p;

	p = calloc(1, sizeof(SCORE));
	if (p == (void *)0x0) return p;
	*p = *d;
	p->left = (SCORE *)0x0;
	p->right = (SCORE *)0x0;

	return p;
}

int Insert_Node(SCORE * head, SCORE * d)
{
	SCORE * p;

	if ((p = Create_Node(d)) == NULL) return -1;
	while (head) {
		p->parent = head;
		if (head->id == d->id) { free(p); return -2; }
		else if (head->id > d->id) {
			if (head->left == NULL) {
				head->left = p;
				return 1;
			}
			head = head->left;
		}
		else if (head->id < d->id) {
			if (head->right == NULL) {
				head->right = p;
				return 1;
			}
			head = head->right;
		}
	}
	Root = p;
	return 1;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i < MAX_ST; i++)
	{
		printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
		Print_All_Node(Root);
	}
}

#endif

/***********************************************************/
// [3-1.4] 주어진 사번의 node를 찾아서 노드의 주로를 리턴하는 함수
/***********************************************************/

#if 01

SCORE * Search_Node(SCORE * head, int id)
{
	while (head) {
		if (head->id == id) return head;
		else if (head->id > id) head = head->left;
		else if (head->id < id) head = head->right;
	}
	return NULL;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	}

	Print_All_Node(Root);

	printf("Search Result = 0x%.8X\n", p = Search_Node(Root, 1));
	if (p) 	printf("addr=0x%.8X, ID=%d, NAME=%s, SCORE=%d, left=0x%.8X, right=0x%.8X\n", p, p->id, p->name, p->jumsu, p->left, p->right);

	printf("Search Result = 0x%.8X\n", p = Search_Node(Root, 10));
	if (p) 	printf("addr=0x%.8X, ID=%d, NAME=%s, SCORE=%d, left=0x%.8X, right=0x%.8X\n", p, p->id, p->name, p->jumsu, p->left, p->right);

	printf("Search Result = 0x%.8X\n", p = Search_Node(Root, 9));
	if (p) 	printf("addr=0x%.8X, ID=%d, NAME=%s, SCORE=%d, left=0x%.8X, right=0x%.8X\n", p, p->id, p->name, p->jumsu, p->left, p->right);

	printf("Search Result = 0x%.8X\n", p = Search_Node(Root, 4));
	if (p) 	printf("addr=0x%.8X, ID=%d, NAME=%s, SCORE=%d, left=0x%.8X, right=0x%.8X\n", p, p->id, p->name, p->jumsu, p->left, p->right);

	printf("Search Result = 0x%.8X\n", p = Search_Node(Root, 7));
	if (p) 	printf("addr=0x%.8X, ID=%d, NAME=%s, SCORE=%d, left=0x%.8X, right=0x%.8X\n", p, p->id, p->name, p->jumsu, p->left, p->right);
}

#endif

/***********************************************************/
// [3-1.5] 주어진 사번의 node를 찾아서 삭제하는 함수
/***********************************************************/

#if 01

void Delete_All_Node(SCORE * p)
{
	if (p->left) Delete_All_Node(p->left);
	if (p->right) Delete_All_Node(p->right);
	if (p == Root) Root = (SCORE *)0;
	free(p);
}

#endif

#if 0

// 삭제할 대상 노드가 leaf인 경우 삭제 함수
// main 함수에서 "자식 없는 노드의 삭제" 부분만 실험

int Delete_Node(SCORE * head, int id)
{
	SCORE * r;

	r = Search_Node(head, id);

	// 탐색 실패 
	if (r == NULL) return -1;

	// 삭제할 노드가 leaf 노드 상태의 Root일 경우 Root에 NULL 복사
	// Root가 아니면 삭제 노드를 연결하고 있는 부모의 left 또는 right에 NULL 대입

	if (r == head) Root = NULL;
	else {
		if (r->parent->left == r) r->parent->left = NULL;
		if (r->parent->right == r) r->parent->right = NULL;
	}
	free(r);
	return 1;
}

#endif

#if 0

// 삭제할 대상 노드가 leaf 또는 자식이 하나인 경우 삭제 함수
// main 함수에서 "자식 없는 노드의 삭제" 부분과 "자식이 1인 노드의 삭제" 까지 실험

int Delete_Node(SCORE * head, int id)
{
	// 후계자의 주소를 저장할 변수
	SCORE * next;
	SCORE * r;

	r = Search_Node(head, id);

	// 탐색 실패 
	if (r == NULL) return -1;

	// [1] 후계자 선정
	// leaf이면 next는 NULL
	// 자식이 하나면 삭제할 노드의 left 또는 right에 존재하는 후계자 주소를 next에 저장
	// 자식이 하나면 NULL이 아닌 r->left 또는 r->right가 존재한다

	if (r->right) next = r->right;
	else if (r->left) next = r->left;
	else next = NULL;

	// [2] 자식이 하나 있는 경우라면 후계자 parent를 삭제할 노드의 부모와 연결
	// 후계자의 parent 값(next->parent)에 삭제할 노드의 parent 값(r->parent)를 복사

	if (next) next->parent = r->parent;

	// [3] 삭제할 노드의 부모의 left 또는 right에 후계자 연결
	// 삭제할 노드가 leaf 노드 상태의 Root일 경우 Root에 후계자 주소(next) 복사
	// Root가 아니면 삭제 노드를 연결하고 있는 부모의 left 또는 right에 후계자 주소(next) 복사
	// leaf일 경우는 후계자에 NULL을 대입하여 두었으므로 별도로 구분하여 작성할 필요가 없다
	
	if (r == head) Root = next;
	else if (r->parent->right == r) r->parent->right = next;
	else if (r->parent->left == r) r->parent->left = next;
	free(r);
	return 1;
}

#endif

#if 01

// 삭제할 대상 노드가 자식 둘 인 경우까지 포함하는 최종 삭제 함수
// main 함수에서 모든 단계를 실험 실시

int Delete_Node(SCORE * head, int id)
{
	SCORE * next = NULL; 			// 후계자 저장 변수
	SCORE * r;					// 삭제할 노드 저장 변수

	r = Search_Node(head, id);
	if (r == NULL) return -1;

	// 자식이 둘이면 후계자 탐색 및 후계자를 삭제할 노드의 데이터에 복사하고 최종적으로 r에 후계자 주소 대입
	if ((r->left != NULL) && (r->right != NULL))
	{
		// 필요시 변수들을 자유롭게 선언하여 사용
		// 후계자 정보를 삭제할 노드에 복사할 때 parent, left, right는 원래 삭제 노드의 값을 유지해야 한다
		// 즉 링크들은 그대로 유지하고 순수한 정보만 복사하여야 한다

		next = r->right;
		while (next->left) next = next->left;
		if (next->right) next->right->parent = next->parent;
		if (next->parent->left == next) next->parent->left = next->right;
		else next->parent->right = next->right;
		next->left = r->left;
		next->right = r->right;
	}

	// 자식이 둘이면 r에 삭제할 대상 주소가 저장되어 있고 하나거나 leaf이면 처음부터 삭제 대상이 들어 있음
	// 따라서 아래 코드는 자식 수와 무관하게 기존 leaf 및 자식 하나인 노드 삭제 코드와 동일함
	else {
		if (r->right) next = r->right;
		else next = r->left;
	}

	if (next) next->parent = r->parent;
	if (r != Root) {
		if (r == r->parent->right) r->parent->right = next;
		else  r->parent->left = next;
	}
	else{
		Root = next;
	}

	free(r);
	return 1;
}

#endif

#if 0

int Delete_Node(SCORE * head, int id)
{
	SCORE * p = head;
	SCORE * prev = Root;
	SCORE * next;
	SCORE * temp;

	while (p != (SCORE *)0)
	{
		if (id == p->id) break;
		prev = p;
		if (id > p->id) p = p->right;
		else p = p->left;
	}

	// 탐색 실패 

	if (p == (SCORE *)0) return -1;

	// Leaf Node 삭제

	if ((p->left == (SCORE *)0) && (p->right == (SCORE *)0))
	{






	}

	// Single Child Node 삭제

	else if ((p->left == (SCORE *)0) || (p->right == (SCORE *)0))
	{






	}

	// 자식이 둘인 Node 삭제

	else
	{






	}

	free(p);
	return 1;
}

#endif

#if 01

void main(void)
{
	int i;
	int r;

	/* 자식 없는 노드의 삭제 */

#if 0

	// 1. Root Only 삭제

	printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", 0, r = Insert_Node(Root, &test[0]), test[0].id);
	Print_All_Node(Root);
	printf("Delete Node #10 Result = %d, Root = %d\n", Delete_Node(Root, 10), Root->id);
	Print_All_Node(Root);

#endif

#if 0

	// 2. Left Leaf 노드 삭제 

	for (i = 0; i < 7; i++) printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	Print_All_Node(Root);
	printf("Delete Node #3 Result = %d, Root = %d\n", Delete_Node(Root, 3), Root->id);
	printf("Delete Node #1 Result = %d, Root = %d\n", Delete_Node(Root, 1), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif

#if 0

	// 3. Right Leaf 노드 삭제 

	for (i = 0; i < 20; i++) printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	Print_All_Node(Root);
	printf("Delete Node #13 Result = %d, Root = %d\n", Delete_Node(Root, 13), Root->id);
	printf("Delete Node #9 Result = %d, Root = %d\n", Delete_Node(Root, 9), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif

	/* 자식이 1인 노드의 삭제 */

#if 0

	// 1. Left만 있는 Root 삭제 

	for (i = 0; i < 10; i++) printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	Print_All_Node(Root);
	printf("Delete Node #10 Result = %d, Root = %d\n", Delete_Node(Root, 10), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif

#if 0

	// 2. Right만 있는 Root 삭제 

	printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", 0, r = Insert_Node(Root, &test[0]), test[0].id);
	for (i = 10; i < 20; i++) printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	Print_All_Node(Root);
	printf("Delete Node #10 Result = %d, Root = %d\n", Delete_Node(Root, 10), Root->id);
	printf("Delete Node #8 Result = %d, Root = %d\n", Delete_Node(Root, 8), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif

#if 0

	// 3. Left만 있는 노드 삭제 

	for (i = 0; i < 20; i++) printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	Print_All_Node(Root);
	printf("Delete Node #7 Result = %d, Root = %d\n", Delete_Node(Root, 7), Root->id);
	printf("Delete Node #19 Result = %d, Root = %d\n", Delete_Node(Root, 19), Root->id);
	printf("Delete Node #14 Result = %d, Root = %d\n", Delete_Node(Root, 14), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif

#if 0

	// 4. Right만 있는 노드 삭제 

	for (i = 0; i < 20; i++) printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	Print_All_Node(Root);
	printf("Delete Node #5 Result = %d, Root = %d\n", Delete_Node(Root, 5), Root->id);
	printf("Delete Node #12 Result = %d, Root = %d\n", Delete_Node(Root, 12), Root->id);
	printf("Delete Node #11 Result = %d, Root = %d\n", Delete_Node(Root, 11), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif

	/* 자식이 2인 노드의 삭제  */
	
#if 01

	// 1. Root 삭제 

	for (i = 0; i < 20; i++) printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	Print_All_Node(Root);
	printf("Delete Node #10 Result = %d, Root = %d\n", Delete_Node(Root, 10), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif

#if 01

	// 2. 중간 노드 삭제 

	for (i = 0; i < 15; i++) printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	Print_All_Node(Root);
	printf("Delete Node #2 Result = %d, Root = %d\n", Delete_Node(Root, 2), Root->id);
	Print_All_Node(Root);
	printf("Delete Node #15 Result = %d, Root = %d\n", Delete_Node(Root, 15), Root->id);
	Print_All_Node(Root);
	printf("Delete Node #3 Result = %d, Root = %d\n", Delete_Node(Root, 3), Root->id);
	Print_All_Node(Root);
	printf("Delete Node #4 Result = %d, Root = %d\n", Delete_Node(Root, 4), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif
}

#endif

#endif

/***********************************************************/
// [3-2] Hash Table
/***********************************************************/

#if 0

/***********************************************************/
// [3-2.1] Hash Table을 위한 기본 함수들
/***********************************************************/

#if 01

#include <stdio.h>
#include <string.h>
#include <conio.h>

#include <malloc.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
}SCORE;

#define MAX_ST		20
#define HASH_KEY	10
#define STEP		1

SCORE Hash_table[MAX_ST];

// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다



int Create_Data(SCORE * p);
int Get_Hash_Key(int id);
void Init_Hash_Table(void);
void Print_All_Data(void);
int Insert_Data(SCORE * d);
SCORE * Search_Data(int id);
int Delete_Data(int id);

SCORE test[MAX_ST + 2] = { {10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
							   {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
							   {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
							   {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"}, \
							   {21, 58, "seo"}, {23, 88, "oh"} };

int Create_Data(SCORE * p)
{
	printf("\n사번을 입력하시오 => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);

	return 1;
}

int Get_Hash_Key(int id)
{
	return id % HASH_KEY;
}

void Init_Hash_Table(void)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		Hash_table[i].id = -1;
	}
}

#endif

#if 0

void Print_All_Data(void)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		if (Hash_table[i].id != -1) printf("[%d] ID: %d, NAME: %s\n", i, Hash_table[i].id, Hash_table[i].name);
	}
}

#endif

/***********************************************************/
// [3-2.2] Insert => Open Address 방법
/***********************************************************/

#if 0

int Insert_Data(SCORE * d)
{
	//for문으로 반복횟수세기. step이 소수면 현재 방식 부정확
	int key = Get_Hash_Key(d->id);
	int end = key>0 ? key-1:MAX_ST-1;
	while (Hash_table[key].id != -1 && key != end) key = (key + STEP) % MAX_ST; 
	if (key == end) return -1;
	Hash_table[key] = *d;
	return key;

	/*int pos, key;
	pos = key = Get_Hash_Key(d->id);

	for (;;) {
		if (Hash_table[pos].id == -1) {
			Hash_table[pos] = *d;
			return pos;
		}
		pos += STEP;
		if (pos == key) return -1;
		if (pos >= MAX_ST) pos = 0;
	}*/
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for (i = 0; i < (MAX_ST + 2); i++)
	{
		printf("[Loop: %d] Inserted Position=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
		Print_All_Data();
	}
}

#endif

/***********************************************************/
// [3-2.3] Search
/***********************************************************/

#if 01

SCORE * Search_Data(int id)
{
	int key = Get_Hash_Key(id);
	
	if (Hash_table[key].id == -1) return NULL;
	for (int cnt = 0; cnt<MAX_ST; cnt++) {
		if (Hash_table[key].id == id) return &Hash_table[key];
		key = (key + STEP) % MAX_ST;
	}
	return NULL;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;

	Init_Hash_Table();

	for (i = 0; i < 15; i++)
	{
		printf("[Loop: %d] Inserted Position=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	}

	Print_All_Data();
	printf("Serch Result=0x%.8X\n", p = Search_Data(3));
	if (p) printf("ID=%d, NAME=%s\n", p->id, p->name);
	printf("Serch Result=0x%.8X\n", p = Search_Data(12));
	if (p) printf("ID=%d, NAME=%s\n", p->id, p->name);
	printf("Serch Result=0x%.8X\n", p = Search_Data(25));
	if (p) printf("ID=%d, NAME=%s\n", p->id, p->name);
}

#endif

/***********************************************************/
// [3-2.4] Delete 함수의 예
/***********************************************************/

#if 0

int Delete_Data(int id)
{
	SCORE * p;

	p = Search_Data(id);
	if (p == (SCORE *)0) return -1;
	p->id = -1;
	return 1;
}

#endif

/***********************************************************/
// [3-2.5] 삭제 노드 ID를 -2로 하도록 delete 함수 설계를 다시 진행한다
// 삭제 전략이 달라지면서 Insert 전략도 수정되어야 한다. 
// 새로은 Insert 함수가 설계되면 [3-3.2]에서 설계된 Insert_Data 함수는 삭제한다
/***********************************************************/

#if 01

int Delete_Data(int id)
{
	SCORE * p;

	p = Search_Data(id);
	if (p == NULL) return -1;
	p->id = -2;
	return 1;
}

int Insert_Data(SCORE * d)
{
	int pos;
	int key;

	pos = key = Get_Hash_Key(d->id);

	for (;;)
	{
		if ((Hash_table[pos].id == -1) || (Hash_table[pos].id == -2))
		{
			Hash_table[pos] = *d;
			return pos;
		}

		pos += STEP;
		if (pos == key) return -1;
		if (pos > MAX_ST) pos = 0;
	}
}

void Print_All_Data(void)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		if ((Hash_table[i].id != -1) && (Hash_table[i].id != -2)) printf("[%d] ID: %d, NAME: %s\n", i, Hash_table[i].id, Hash_table[i].name);
	}
}

#endif

#if 01

void main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for (i = 0; i < 15; i++)
	{
		printf("[Loop: %d] Inserted Position=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	}

	Print_All_Data();
	printf("[3] Delete Result=%d\n", r = Delete_Data(3));
	printf("[12] Delete Result=%d\n", r = Delete_Data(12));
	printf("[25] Delete Result=%d\n", r = Delete_Data(25));
	printf("[3] Delete Result=%d\n", r = Delete_Data(3));
	printf("[12] Delete Result=%d\n", r = Delete_Data(12));
	Print_All_Data();

	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[13]), test[13].id);
	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[5]), test[5].id);
	Print_All_Data();
}

#endif

#endif

/***********************************************************/
// [3-2.6] Hash Table => 해시 키 발생 함수의 변경
/***********************************************************/

#if 0

/***********************************************************/
// [3-2.6] Hash Table을 위한 기본 함수들
/***********************************************************/

#if 0

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
}SCORE;

#define MAX_ST		20

#if 0
#define HASH_KEY	10
#define STEP				1
#else
#define HASH_KEY	7  // 가급적 소수
#define STEP				8  // 테이블의 요소수와 서로 소 관계인 수
#endif

SCORE Hash_table[MAX_ST];

// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다



int Create_Data(SCORE * p);
int Get_Hash_Key(int id);
void Init_Hash_Table(void);
void Print_All_Data(void);
int Insert_Data(SCORE * d);
SCORE * Search_Data(int id);
int Delete_Data(int id);

SCORE test[MAX_ST + 2] = { {10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
							   {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
							   {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
							   {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"}, \
							   {21, 58, "seo"}, {23, 88, "oh"} };

int Create_Data(SCORE * p)
{
	printf("\n사번을 입력하시오 => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);

	return 1;
}

int Get_Hash_Key(int id)
{
	return id % HASH_KEY;
}

void Init_Hash_Table(void)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		Hash_table[i].id = -1;
	}
}

void Print_All_Data(void)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		if ((Hash_table[i].id != -1) && (Hash_table[i].id != -2)) printf("[%d] ID: %d, NAME: %s\n", i, Hash_table[i].id, Hash_table[i].name);
	}
}

int Delete_Data(int id)
{
	SCORE * p;

	p = Search_Data(id);
	if (p == (SCORE *)0) return -1;
	p->id = -2;
	return 1;
}

int Insert_Data(SCORE * d)
{
	int pos;
	int cnt = 0;
	static int insert_cnt;

	pos = Get_Hash_Key(d->id);

	for (;;)
	{
		if ((Hash_table[pos].id == -1) || (Hash_table[pos].id == -2))
		{
			Hash_table[pos] = *d;
			insert_cnt += cnt + 1;
			printf("cnt = %d, total insert count = %d\n", cnt + 1, insert_cnt);
			return pos;
		}

		pos += STEP;
		cnt++;
		if (cnt > MAX_ST) return -1;
		if (pos > MAX_ST) pos %= MAX_ST;
	}
}

SCORE * Search_Data(int id)
{
	int pos;
	int cnt = 0;
	static int search_cnt;

	pos = Get_Hash_Key(id);

	for (;;)
	{
		if (Hash_table[pos].id == id) return &Hash_table[pos];
		if (Hash_table[pos].id == -1) return (SCORE *)0;
		pos += STEP;
		cnt++;
		search_cnt += cnt + 1;
		printf("cnt = %d, total search count = %d\n", cnt + 1, search_cnt);
		if (cnt > MAX_ST) return (SCORE *)0;
		if (pos > MAX_ST) pos %= MAX_ST;
	}
}

#endif

/***********************************************************/
// [3-2.6] Insert 효율
/***********************************************************/

#if 0

void main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for (i = 0; i < MAX_ST; i++)
	{
		printf("[Loop: %d] Inserted Position=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
		Print_All_Data();
	}
}

#endif

/***********************************************************/
// [3-2.7] Search 효율
/***********************************************************/

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;

	Init_Hash_Table();

	for (i = 0; i < 15; i++)
	{
		printf("[Loop: %d] Inserted Position=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	}

	Print_All_Data();
	printf("Serch Result=0x%.8X\n", p = Search_Data(3));
	if (p) printf("ID=%d, NAME=%s\n", p->id, p->name);
	printf("Serch Result=0x%.8X\n", p = Search_Data(12));
	if (p) printf("ID=%d, NAME=%s\n", p->id, p->name);
	printf("Serch Result=0x%.8X\n", p = Search_Data(25));
	if (p) printf("ID=%d, NAME=%s\n", p->id, p->name);
}

#endif

/***********************************************************/
// [3-2.8] Insert, Search, Delete
/***********************************************************/

#if 0

void main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for (i = 0; i < 15; i++)
	{
		printf("[Loop: %d] Inserted Position=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	}

	Print_All_Data();
	printf("[3] Delete Result=%d\n", r = Delete_Data(3));
	printf("[12] Delete Result=%d\n", r = Delete_Data(12));
	printf("[25] Delete Result=%d\n", r = Delete_Data(25));
	printf("[3] Delete Result=%d\n", r = Delete_Data(3));
	printf("[12] Delete Result=%d\n", r = Delete_Data(12));
	Print_All_Data();

	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[13]), test[13].id);
	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[5]), test[5].id);
	Print_All_Data();
}

#endif

#endif

/***********************************************************/
// [3-2.9] Hash Table => Chainning 방법의 구현
/***********************************************************/

#if 0

/***********************************************************/
// [3-2.9] Hash Table을 위한 기본 함수들
/***********************************************************/

#if 01

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score * next;
}SCORE;

#define MAX_ST		20
#define HASH_KEY	5

SCORE Hash_table[HASH_KEY];



int Create_Data(SCORE * p);
int Get_Hash_Key(int id);
void Init_Hash_Table(void);
void Print_All_Data(void);
int Insert_Data(SCORE * d);
SCORE * Search_Data(int id);
int Delete_Data(int id);

SCORE test[MAX_ST + 2] = { {10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
							   {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
							   {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
							   {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"}, \
							   {21, 58, "seo"}, {23, 88, "oh"} };

int Create_Data(SCORE * p)
{
	printf("\n사번을 입력하시오 => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);

	return 1;
}

int Get_Hash_Key(int id)
{
	return id % HASH_KEY;
}

void Init_Hash_Table(void)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		Hash_table[i].next = (SCORE *)0;
	}
}

void Print_All_Data(void)
{
	int i;
	SCORE * p;

	for (i = 0; i < MAX_ST; i++)
	{
		p = Hash_table[i].next;

		for (;;)
		{
			if (p == (SCORE *)0) break;
			printf("[%d] address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", i, p, p->id, p->name, p->next);
			p = p->next;
		}
	}
}

#endif

/***********************************************************/
// [3-2.10] Insert
/***********************************************************/

#if 01

int Insert_Data(SCORE * d)
{
	SCORE * p;
	SCORE * cur;
	int key;

	if ((p = calloc(1, sizeof(SCORE))) == NULL) return -1;
	*p = *d;
	key = Get_Hash_Key(p->id);
	cur = &Hash_table[key];
	while (cur->next) {
		cur = cur->next;
		if (cur->id == d->id) {
			free(p);
			return -1;
		}
	}
	cur->next = p;
	return 1;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for (i = 0; i < MAX_ST; i++)
	{
		printf("[Loop: %d] Insert Result=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
		Print_All_Data();
	}
}

#endif

/***********************************************************/
// [3-2.11] Delete
/***********************************************************/

#if 01

int Delete_Data(int id)
{
	SCORE * cur, * p;
	int key = Get_Hash_Key(id);

	cur = &Hash_table[key];
	while (cur->next) {
		if (cur->next->id == id) {
			p = cur->next;
			cur->next = cur->next->next;
			free(p);
			return 1;
		}
		cur = cur->next;
	}
	return -1;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for (i = 0; i < MAX_ST; i++) printf("[Loop: %d] Insert Result=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	Print_All_Data();

	printf("[1] Delete Result=%d\n", r = Delete_Data(1));
	printf("[11] Delete Result=%d\n", r = Delete_Data(11));
	printf("[16] Delete Result=%d\n", r = Delete_Data(16));
	printf("[9] Delete Result=%d\n", r = Delete_Data(9));
	printf("[10] Delete Result=%d\n", r = Delete_Data(10));
	Print_All_Data();

	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[1]), test[1].id);
	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[11]), test[11].id);
	Print_All_Data();
}

#endif

/***********************************************************/
// [3-2.12] Search
/***********************************************************/

#if 01

SCORE * Search_Data(int id)
{
	SCORE * p;

	p = Hash_table[Get_Hash_Key(id)].next;
	while (p) {
		if (p->id == id) return p;
		p = p->next;
	}
	return NULL;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;

	Init_Hash_Table();

	for (i = 0; i < MAX_ST; i++) printf("[Loop: %d] Insert Result=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	Print_All_Data();

	printf("Serch Result=0x%.8X\n", p = Search_Data(3));
	if (p) printf("[%d] address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", i, p, p->id, p->name, p->next);
	printf("Serch Result=0x%.8X\n", p = Search_Data(12));
	if (p) printf("[%d] address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", i, p, p->id, p->name, p->next);
	printf("Serch Result=0x%.8X\n", p = Search_Data(25));
	if (p) printf("[%d] address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", i, p, p->id, p->name, p->next);
}

#endif

#endif

/***********************************************************/
// [3-2.13] Hash Table => 졍렬 기능을 갖는 Chainning 방법
// 완성된 위의 예제를 복사하여 처음부터 모두 재설계하라
/***********************************************************/

