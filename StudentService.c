//본 프로그램은 간단한 학생 정보 입출력 프로그램입니다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct student {   // 학생 구조체 정의, typedef 사용하면 구조체 변수 선언할 때 struct 안붙여도 됨.
    int num;    // 학번
    char name[25];   // 이름
    char gender[5];   // 성별
    char addr[80];   // 주소
}Student;  //구조체 별칭

#define MAX_STUDENT 10 //최대 학생수는 10명으로 지정
Student stues[MAX_STUDENT] = { 0 }; //구조체 배열변수 stues 선언

//함수의 선언
void menu(); //메뉴함수
void in_(); //정보입력 함수
void view_(); //정보출력 함수

int c_num = 0; //저장이 완료 됐을 때 구조체 배열의 인덱스 변수, 구조체 배열 인덱스를 증가시켜야 하므로, 전역변수로 초기화


int main() { //메뉴 함수를 실행하는 메인함수
    menu();
}

void menu() { //메뉴 선택 함수

    int choice = 0; //메뉴 입력 숫자 변수

    while (1) {
        printf("<<<학생 정보 시스템>>>\n");
        printf("메뉴 :  1 > 입력, 2 >출력, 3 > 종료\n");

        printf("\n메뉴를 입력하세요 >> ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            in_(); //입력함수 이동
            break;
        case 2:
            view_(); //출력함수 이동
            break;
        case 3:
            printf("\n프로그램 종료\n");
            return;
        default:
            printf("메뉴를 다시 입력해주세요.\n\n");
            break;
        }
    }
}

void in_() { //학생정보 입력함수

    int save = 0; //저장 물어보는 숫자 변수

    while (1) { 

        printf("\n학번 : ");
        scanf_s("%d", &stues[c_num].num); //구조체 배열 stues의 [전역변수로 선언된 c_num의 인덱스 = (초기값)0]에 맞게 저장한다.
        printf("이름 : ");
        scanf_s("%s", stues[c_num].name, 30);
        printf("성별 : ");
        scanf_s("%s", stues[c_num].gender, 30);
        printf("주소 : ");
        scanf_s("%s", stues[c_num].addr, 30);

        printf("\n저장 하시겠습니까? 저장 : 1 , 취소 : 2  >> ");
        scanf_s("%d", &save);

        if (save == 1) {
            printf("저장완료\n\n");
            c_num++; //저장을 완료하고 c_num을 후위증가시켜 구조체 배열의 인덱스 값을 증가시켜준다.
            break;
        }
        else if (save == 2) {
            printf("\n정보를 다시 입력하세요\n"); //c_num을 증가시키지 않아, 인덱스는 그대로인 상태에서, 재입력을 받는다.
        }
    }
}

void view_() { //학생정보 출력함수

    printf("\n---학생 정보---\n");

    for (int i = 0; i < MAX_STUDENT; i++) {
        if (stues[i].num != 0) { //학번이 0이 아닌 값만 출력한다.
            printf("학번 : %d\n", stues[i].num);
            printf("이름 : %s\n", stues[i].name);
            printf("성별 : %s\n", stues[i].gender);
            printf("주소 : %s\n", stues[i].addr);
            printf("\n");
        }
    }
}
