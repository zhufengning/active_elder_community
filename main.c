#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* People��������д�ģ������ṹ��д�ı䳤���飬���ʣ��ʾ����볢�Զ���д��������*/

#include "people.h"
#include "facility.h"
#include "servant.h"
#include "house.h"
#include "storage.h"

//sz--��������
int main()
{
//    Data d = data_from_file("../a.json");
//    people_list_delete(&d.people_list, 0);
//    servant_list_delete(&d.servant_list, 0);
//    strcpy(people_list_at(d.people_list, 0)->name, "zzz");
//    data_save(d, "../b.json");
//    return 0;
    int a;
    printf("���Ƿ���Ҫ��ȡ�ѱ�������ݣ�\n"
           "1.��\n"
           "2.��\n");
    fflush(stdout);
    scanf("%d", &a);
    char sz[100];
    if (a == 1)
    {
        printf("�������ļ�����\n");
        scanf("%s", sz);
    }
    if (a == 2)
    { printf("������� \n"); }
    // TODO �����Ĺ���

    while (1)
    {
        int n;
        char sz2[100];
        char sz3[100];
        printf("********************************\n    ��ӭ���������������ϵͳ    \n********************************\n");
        printf(
                "*�ף�����������*\n"
                "\t1.ѡ��*��Ա����*\n"
                "\t2.ѡ��*���ݹ���*\n"
                "\t3.ѡ��*��ס����*\n"
                "\t4.ѡ��*������ʩ����*\n"
                "\t5.ѡ��*������Ա����*\n"
                "\t6.ѡ��*���ⷴӳ*\n"
                "\t7.�˳�ϵͳ��\n");
        fflush(stdout);
        scanf("%d", &n);


        if (n == 1)
        {
            printf(
                    "����һ����Ҫ��ʲô��\n"
                    "��������Ӧ���֣�\n"
                    "\t1.ѡ��*�½���Ա*\n"
                    "\t2.ѡ��*��ѯ��Ա*\n"
                    "\t3.ѡ��*��Ա��ɾ�����޸�*\n"
                    "\t4.ѡ��*������һ��*\n");
            fflush(stdout);
            scanf("%d", &n);
            char name[100];
            if (n == 4)
            {

            } else
            {
                if (n == 1)
                {
                    printf("�����Ա���֣�\n");
                    fflush(stdout);
                    scanf("%s", name);
                }
                if (n == 2)
                {
                    printf ("���ѡ���ѯ�ķ�ʽ\n"
                            "1.ID��ѯ\n"
                            "2.�����ֲ�ѯ\n"
                            "3.������л�Ա\n");
                    fflush(stdout);
                    scanf ("%d",n);
                    if (n==1){printf ("����������ID:\n");
                        fflush(stdout);}
                    // TODO �����Ĺ���,��������
                    if (n==2){printf ("�������������֣�\n");
                        fflush(stdout);
                        scanf("%s", name);}
                    // TODO �����Ĺ���
                    if (n==3){}//TODO �����Ĺ���,������л�Ա
                }
                if (n == 3)//��Ա��ɾ�����޸�
                {printf ("���������ID:\n");
                    fflush(stdout);
                    //  ���ݱ��ѡ��Ҫ�޸ĵĻ�Ա
                    // TODO �����Ĺ��� ��ѡ���޸ĵĻ�Ա֮��������û�Ա����Ϣ��
                }

            }
        } else if (n == 2)//ѡ��*���ݹ���*
        {
            printf("����һ����Ҫ��ʲô��\n"
                   "��������Ӧ���֣�\n"
                   "\t1.ѡ��*�鿴���ݻ������*\n"
                   "\t2.ѡ��*������*\n"
                   "\t3.ѡ��*������һ��*\n");
            fflush(stdout);
            scanf("%d", &n);
            if (n == 1)
            {
                printf("���ǵķ��ݶ���Ȩ����������֤���������ģ�\n");
                fflush(stdout);
            }
            if (n == 2)
            {
                printf("���Ƿ��Ѿ���Ϊ��Ա��\n"
                       "1.��\n"
                       "2.��\n");
                fflush(stdout);
                scanf("%d", &n);
                if (n == 1)
                {printf ("����������ID��\n");
                    fflush(stdout);
                    // TODO ����㣬��ѯ��Ա�Ƿ���ڣ������ھ�ʲô���������������Զ�����ҳ��
                    printf("�����Կ�ʼѡ������\n"
                           "�����뷿�����֣�\n");
                    fflush(stdout);
                    scanf("%s", sz2);
                }
                // TODO �����Ĺ���}
                if (n == 2)
                {
                    printf("�������ǻ�Ա��\n"
                           "�뷵����ҳע���Ա�Թ����ݣ�\n");
                    fflush(stdout);
                }
                if (n == 3)
                {

                }
            }
        } else if (n == 3)//ѡ��*��ס����*
        {
            printf("���Ƿ��Ѿ������ݣ�\n"
                   "1.��\n"
                   "2.��\n");
            fflush(stdout);
            scanf("%d", &n);
            if (n == 1)
            {
                printf("�����������ݵ�����\n");
                fflush(stdout);
                scanf("%s", sz3);
                // TODO �����Ĺ���
                printf("��������ϣ�����ķ��ݣ�\n"
                       "1.*��ס*\n"
                       "2.*����*\n"
                       "3.*����*: \n");
                fflush(stdout);
                scanf("%d", n);
                if (n == 1)
                {}// TODO �����Ĺ���
                if (n == 2)
                {}// TODO �����Ĺ���
                if (n == 3)
                {}// TODO �����Ĺ���
            } else if (n == 2)
            {

            }
        } else if (n == 4)//4.ѡ��*������ʩ����*
        {
            printf("��ѡ��������ݣ�\n"
                   "1.*�����û�*\n"
                   "2.*���ǹ�����Ա*\n");
            fflush(stdout);
            scanf("%d", &n);
            if (n == 1)
            {
                printf("����Ҫʹ������������ʩ��\n"
                       "1.��\n"
                       "2.��\n");
                fflush(stdout);
                scanf("%d", n);
                if (n == 1)
                {
                    printf("����Ҫ����ʹ��ʲô������ʩ��\n"
                           "������������ʩ������\n");
                    fflush(stdout);
                }//TODO �����Ĺ���
            }
            if (n == 2)
            {
                printf("����Ҫ����ʹ��ʲô������ʩ��\n"
                       "������������ʩ������\n");
                fflush(stdout);
            }//TODO �����Ĺ���


        } else if (n == 5)//5.ѡ��*������Ա����*
        {
            printf("��ѡ��������ݣ�\n"
                   "1.������Ա������Ա\n"
                   "2.�û�\n");
            fflush(stdout);
            char name2[100];
            if (n == 1)
            {
                printf("����һ�����ʲô��\n"
                       "1.*ע�������Ա*\n"
                       "2.*�޸ķ�����Ա��Ϣ*\n"
                       "3.*ɾ��������Ա*\n"
                       "4.*�����*\n");
                fflush(stdout);
                scanf("%d", n);
                if (n == 1)
                {
                    printf("����������������\n");
                    fflush(stdout);
                    scanf("%s", name2);
                }

                // TODO �����Ĺ���
                if (n == 2)
                {printf("����������������\n");
                    fflush(stdout);}

                if (n == 3)
                {printf("����������������\n");
                    fflush(stdout);}
                // TODO �����Ĺ���
                //��servant.h
                if (n == 4)
                {}
            }
        } else if (n == 6)//6.ѡ��*���ⷴӳ*
        {
            printf("��½ https://www.icourse163.org/learn/NEU-1002745019 ��ø������\n"
                   "��ӿͷ�΢�ţ����������ʲô��zhangyichuan_33��ȡһ��һ����\n");
            fflush(stdout);
        } else if (n == 7)
        {
            break;
        }
    }
    return 0;
}