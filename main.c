#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "people.h"
#include "facility.h"
#include "servant.h"
#include "house.h"
#include "storage.h"

int main() {
    int back = 0;
    do {
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


    if (n == 1) {
        printf(
                "����һ����Ҫ��ʲô��\n"
                "��������Ӧ���֣�\n"
                "\t1.ѡ��*�½���Ա*\n"
                "\t2.ѡ��*��ѯ��Ա*\n"
                "\t3.ѡ��*��Ա��ɾ�����޸�*\n"
                "\t4.ѡ��*������һ��*");
        scanf("%d", &n);
        char name[100];
            if (n == 4) {
                back = 1;
            } else {
                back = 0;
                if (n == 1) {
                    scanf("%s", name);
                }
                if (n == 2) {
                    scanf("%s", name);
                    // TODO�����Ĺ���
                }
                if (n == 3) {
                    // TODO�����Ĺ���
                }

            }
        }
    } while (back);

    PeopleList l = people_list_new();
    people_list_push(&l, "haha");
    printf("%d:%s\n", people_list_at(l, 0).id, people_list_at(l, 0).name);
    return 0;
}
