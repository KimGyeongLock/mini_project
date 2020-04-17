#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[50]; //제품명
    int gram; //중량
    int price; //가격
    int g_price; //표준가격
    int star; //별점수
} Snack;

int createSnack(Snack *s); //새로운 Snack 추가
void readSnack(Snack s); //Snack 출력
int updateSnack(Snack *s); //Snack 수정
int deleteSnack(Snack *s); //Snack 삭제 (포인터배열 => null)
void saveFile(Snack *s[],int count); //file 저장
int loadFile(Snack *s[]); //file 불러오기
void searchSnack(Snack *s[],int count); //snack 검색
void searchName(Snack *s[],int count); //이름별 검색
void searchPrice(Snack *s[],int count); //가격별 검색
void searchStar(Snack *s[],int count); //별점수별 검색
