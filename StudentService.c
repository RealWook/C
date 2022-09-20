#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct student {   // �л� ����ü ����, typedef ����ϸ� ����ü ���� ������ �� struct �Ⱥٿ��� ��.
    int num;    // �й�
    char name[25];   // �̸�
    char gender[5];   // ����
    char addr[80];   // �ּ�
}Student;  //����ü ��Ī

#define MAX_STUDENT 10 //�ִ� �л����� 10������ ����
Student stues[MAX_STUDENT] = { 0 }; //����ü �迭���� stues ����

//�Լ��� ����
void menu(); //�޴��Լ�
void in_(); //�����Է� �Լ�
void view_(); //������� �Լ�

int c_num = 0; //������ �Ϸ� ���� �� ����ü �迭�� �ε��� ����, ����ü �迭 �ε����� �������Ѿ� �ϹǷ�, ���������� �ʱ�ȭ


int main() { //�޴� �Լ��� �����ϴ� �����Լ�
    menu();
}

void menu() { //�޴� ���� �Լ�

    int choice = 0; //�޴� �Է� ���� ����

    while (1) {
        printf("<<<�л� ���� �ý���>>>\n");
        printf("�޴� :  1 > �Է�, 2 >���, 3 > ����\n");

        printf("\n�޴��� �Է��ϼ��� >> ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            in_(); //�Է��Լ� �̵�
            break;
        case 2:
            view_(); //����Լ� �̵�
            break;
        case 3:
            printf("\n���α׷� ����\n");
            return;
        default:
            printf("�޴��� �ٽ� �Է����ּ���.\n\n");
            break;
        }
    }
}

void in_() { //�л����� �Է��Լ�

    int save = 0; //���� ����� ���� ����

    while (1) { 

        printf("\n�й� : ");
        scanf_s("%d", &stues[c_num].num); //����ü �迭 stues�� [���������� ����� c_num�� �ε��� = (�ʱⰪ)0]�� �°� �����Ѵ�.
        printf("�̸� : ");
        scanf_s("%s", stues[c_num].name, 30);
        printf("���� : ");
        scanf_s("%s", stues[c_num].gender, 30);
        printf("�ּ� : ");
        scanf_s("%s", stues[c_num].addr, 30);

        printf("\n���� �Ͻðڽ��ϱ�? ���� : 1 , ��� : 2  >> ");
        scanf_s("%d", &save);

        if (save == 1) {
            printf("����Ϸ�\n\n");
            c_num++; //������ �Ϸ��ϰ� c_num�� ������������ ����ü �迭�� �ε��� ���� ���������ش�.
            break;
        }
        else if (save == 2) {
            printf("\n������ �ٽ� �Է��ϼ���\n"); //c_num�� ������Ű�� �ʾ�, �ε����� �״���� ���¿���, ���Է��� �޴´�.
        }
    }
}

void view_() { //�л����� ����Լ�

    printf("\n---�л� ����---\n");

    for (int i = 0; i < MAX_STUDENT; i++) {
        if (stues[i].num != 0) { //�й��� 0�� �ƴ� ���� ����Ѵ�.
            printf("�й� : %d\n", stues[i].num);
            printf("�̸� : %s\n", stues[i].name);
            printf("���� : %s\n", stues[i].gender);
            printf("�ּ� : %s\n", stues[i].addr);
            printf("\n");
        }
    }
}
