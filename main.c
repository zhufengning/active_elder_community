#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "people.h"
#include "facility.h"
#include "servant.h"
#include "house.h"
int main() 
{
	int n;

	printf(
		"�ף�����������\n"
		"\t����1ѡ���Ա����\n"
		"\t����2ѡ���ݹ���\n"
		"\t����3ѡ����ס����\n"
		"\t����4ѡ�񳡹���ʩ����\n"
		"\t����5ѡ��೵·�߹���\n"
		"\t����6ѡ�����ⷴӳ��");
	scanf("%d", &n);

	if (n == 1)
	{
		printf(
			"����һ����Ҫ��ʲô��\n"
			"\t����1ѡ���½���Ա\n"
            "\t����2ѡ���ѯ��Ա\n"
			"\t����3ѡ���Ա��ɾ�����޸�\n");
	}


	PeopleList l = people_list_new();
	people_list_push(&l, "haha");
	printf("%d:%s\n", people_list_at(l, 0).id, people_list_at(l, 0).name);
	return 0;
}
