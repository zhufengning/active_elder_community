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
    printf("���Ƿ���Ҫ��ȡ�ѱ�������ݣ�"
           "1.��"
           "2.��");
    scanf("%d", &a);
    char sz[100];
    if (a == 1)
    { scanf("%s", sz); }
    if (a == 2)
    { printf("������� \n"); }
    // TODO �����Ĺ���

    int back = 0;
    do
    {
        back = 0;
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
                "\t6.ѡ��*���ⷴӳ*��");
        scanf("%d", &n);


        if (n == 1)
        {
            printf(
                    "����һ����Ҫ��ʲô��\n"
                    "��������Ӧ���֣�\n"
                    "\t1.ѡ��*�½���Ա*\n"
                    "\t2.ѡ��*��ѯ��Ա*\n"
                    "\t3.ѡ��*��Ա��ɾ�����޸�*\n"
                    "\t4.ѡ��*������һ��*");
            scanf("%d", &n);
            char name[100];
            if (n == 4)
            {
                back = 1;
            } else
            {
                if (n == 1)
                {
                    scanf("%s", name);
                }
                if (n == 2)
                {
                    scanf("%s", name);
                    // TODO �����Ĺ���
                }
                if (n == 3)
                {
                    // TODO �����Ĺ���
                }

            }
        } else if (n == 2)
        {
            printf("����һ����Ҫ��ʲô��\n"
                   "��������Ӧ���֣�\n"
                   "\t1.ѡ��*�鿴���ݻ������*\n"
                   "\t2.ѡ��*������*\n"
                   "\t3.ѡ��*������һ��*");
            scanf("%d", &n);
            if (n == 1)
            { printf("���ǵķ��ݶ���Ȩ����������֤���������ģ�"); }
            if (n == 2)
            {
                printf("���Ƿ��Ѿ���Ϊ��Ա��"
                       "1.��"
                       "2.��");
                scanf("%d", &n);
                if (n == 1)
                {
                    printf("�����Կ�ʼѡ������\n"
                           "����ѡ����һ�����ݣ�\n"
                           "�����뷿�����֣�");
                    scanf("%s", sz2);
                }
                // TODO �����Ĺ���}
                if (n == 2)
                {
                    printf("�������ǻ�Ա��\n"
                           "�뷵����ҳע���Ա�Թ����ݣ�");
                    back = 1;
                }
                if (n == 3)
                {
                    back = 1;
                }
            }
        } else if (n == 3)
        {
            printf("���Ƿ��Ѿ������ݣ�"
                   "1.��"
                   "2.��");
            scanf("%d", &n);
            if (n == 1)
            {
                printf("�����������ݵ�����");
                scanf("%s", sz3);
                // TODO �����Ĺ���
                printf ("��������ϣ�����ķ��ݣ�\n"
                        "1.*��ס*\n"
                        "2.*����*\n"
                        "3.*����*: ");
                scanf ("%d",n);
                if (n==1){}// TODO �����Ĺ���
                if (n==2){}// TODO �����Ĺ���
                if (n==3){}// TODO �����Ĺ���
            }//sz3������
            if (n == 2)
            { back = 1; }
        }else if (n==4){printf ("��ѡ��������ݣ�\n"
                                "1.*�����û�*\n"
                                "2.*���ǹ�����Ա*");
            scanf ("%d",&n);
            if (n==1){printf ("����Ҫ����������ʩ��\n"
                              "1.��\n"
                              "2.��");
            scanf ("%d",n);
            if (n==1){printf("����Ҫ����ʲô������ʩ��\n"
                             "1.*\n"
                             "2.*\n"
                             "3.*\n"
                             "4.�˳�");}//���������������<-->
                             if (n==4){break;}
            if (n==2){break;}}
            if (n==2){printf ("����Ҫ�½�ʲô������ʩ��\n"
                              "1.*\n"
                              "2.*\n"
                              "3.*\n"
                              "4.�˳�");
            scanf ("%d",&n);
            if (n==4){break;}
            //������Ҳû�С�������������
            }


        }
        else if (n==5){printf ("��ѡ��������ݣ�\n"
                               "1.������Ա������Ա\n"
                               "2.�û�\n");
            char name2[100];
        if (n==1) {printf ("����һ�����ʲô��\n"
                           "1.*ע���Ϊ������Ա*\n"
                           "2.*�޸ķ�����Ա��Ϣ*\n"
                           "3.*ɾ��������Ա��Ϣ*\n"
                           "4.���ʵ����");
        scanf ("%d",n);
        if (n==1){printf ("����������������\n");
        scanf ("%s",name2);}
            // TODO �����Ĺ���
        if (n==2){}

        if (n==3){}
        // TODO �����Ĺ���
        //��servant.h
        if(n==4){break;}
                 }
        }else if (n==6){printf ("��½www.hlzzsq.com��ø������\n"
                                "��ӿͷ�΢�ţ����������ʲô��zhangyichuan_33��ȡһ��һ����\n");}



    } while (back);


    PeopleList l = people_list_new();
    people_list_push(&l, "haha");
    printf("%d:%s\n", people_list_at(l, 0)->id, people_list_at(l, 0)->name);
    return 0;
}