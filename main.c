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
  printf("********************************\n    ��ӭ���������������ϵͳ    \n********************************\n");
	printf(
		"*�ף�����������*\n"
		"\t1.ѡ��*��Ա����*\n"
		"\t2.ѡ��*���ݹ���*\n"
		"\t3.ѡ��*��ס����*\n"
		"\t4.ѡ��*������ʩ����*\n"
		"\t5.ѡ��*�೵·�߹���*\n"
		"\t6.ѡ��*���ⷴӳ*��");
	scanf("%d", &n);

	if (n == 1)
	{
		printf(
			"����һ����Ҫ��ʲô��\n"
            "��������Ӧ���֣�\n"
			"\t1.ѡ���½���Ա\n"
            "\t2.ѡ���ѯ��Ա\n"
			"\t3.ѡ���Ա��ɾ�����޸�\n");
	}


	PeopleList l = people_list_new();
	people_list_push(&l, "haha");
	printf("%d:%s\n", people_list_at(l, 0).id, people_list_at(l, 0).name);
	return 0;
}
