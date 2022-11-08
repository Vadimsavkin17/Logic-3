#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale>


struct node
{
	char data[256];
	int elem;
	struct node* pred; // ������ �� ���������� ������� 
};

struct node* head = NULL, * last = NULL; // ��������� �� ������ � ��������� �������� ������

void in(const char* str, int val) {
	node* list = (node*)malloc(sizeof(node));
	if (head == NULL) {
		head = list;
		last = list;
		list->elem = val;
		strcpy_s(list->data, str);
	}
	else {
		char flag = 0;
		list->elem = val;
		strcpy_s(list->data, str);
		node* sravn = head, * sravnprev = head;
		while (flag == 0) {
			while (1) {
				if (sravn->elem == list->elem) {	//���� ������ �����
					if (sravn == last) {	//���� ��������� ������� ����� ���������
						last = list;
						sravn->pred = list;
						flag = 1;
						break;
					}
					else {
						list->pred = sravn->pred;
						sravn->pred = list;
						flag = 1;
						break;
					}
				}
				else if (sravn->elem < list->elem) {		//���� ����� � ������� �����������
					if (sravn == last) {
						last = list;
						sravn->pred = list;
						flag = 1;
						break;
					}
					else {
						sravnprev = sravn;
						sravn = sravn->pred;
						break;
					}
				}
				else if (sravn->elem > list->elem) {		//���� ����� � ������� �����������
					if (sravn == head) {
						list->pred = head;
						head = list;
						flag = 1;
						break;
					}
					else {
						list->pred = sravn;
						sravnprev->pred = list;
						flag = 1;
						break;
					}
				}
			}
		}
	}
}

void out() {
	if (head == NULL) {
		("������� ������\n");
		return;
	}
	else if (head == last) {
		printf("����������� �������: %s\n", head->data);
		free(head);
		head = NULL;
		last = NULL;
	}
	else {
		printf("����������� �������: %s\n", head->data);
		node* tmp = head;
		head = head->pred;
		free(tmp);
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	char data[256];
	int pr;
	int buf;
	while (1) {
		if (head != NULL) {
			node* list = head;
			printf("�������: ");
			while (1) {
				printf("%s ", list->data);
				if (list == last) {
					printf("\n");
					break;
				}
				list = list->pred;
			}
		}
		printf("�������: 1 ��� ��������� � �������, 2 ��� ���������� �� �������, 0 ��� ������ ");
		scanf("%d", &buf);
		printf("\n");
		if (buf == 1) {
			printf("������� ������ ��� ��������� � �������: ");
			scanf("%s", data);
			printf("������� ����� ��� ���������� � �������: ");
			scanf_s("%d", &pr);
			printf("\n");
			in(data, pr);
		}
		else if (buf == 2) {
			out();
		}
		else if (buf == 0) {
			exit(0);
		}
		else {
			printf("�� ����� ������� �������\n");
		}
	}
}
