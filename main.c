#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* People��������д�ģ������ṹ��д�ı䳤���飬���ʣ��ʾ����볢�Զ���д�������� */

#include "people.h"
#include "facility.h"
#include "servant.h"
#include "house.h"

// Ȼ��busҲ���õ��������Ƕ�ά����
#include "bus.h"

#include "storage.h"

//sz--��������
//readme��Ĵ���淶��ͬ�������ǰ�--zfn
int main()
{
//    Data d = data_from_file("../a.json");
//    people_list_delete(&d.people_list, 0);
//    servant_list_delete(&d.servant_list, 0);
//    buschainlist_remove(d.buschain_list.root);
//    buschain_remove(d.buschain_list.root->hou->value.root);
//    strcpy(people_list_at(d.people_list, 0)->name, "zzz");
//    data_save(d, "../b.json");
//    return 0;
    Data d = data_new();
    int a;
    while (1)
    {
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
            d = data_from_file(sz);
            if (d.error != 0)
            {
                printf("�ļ�����ʧ��\n");
                continue;
            } else
            {
                break;
            };

        } else if (a == 2)
        {
            printf("������� \n");
            break;
        }
    }
    int fst_time = 1;
    while (1)
    {

        int n;
        if (!fst_time)
        {
            printf("����1����ʹ�ñ�ϵͳ�������������ֱ��沢�˳�\n");
            fflush(stdout);
            int sz;
            scanf("%d", &sz);
            if (sz == 1)
            {
                printf("********************************\n    ��ӭ���������������ϵͳ    \n********************************\n");
                printf(
                        "*�ף�����������*\n"
                        "\t1.ѡ��*��Ա����*\n"
                        "\t2.ѡ��*���ݹ���*\n"
                        "\t3.ѡ��*��ס����*\n"
                        "\t4.ѡ��*������ʩ����*\n"
                        "\t5.ѡ��*������Ա����*\n"
                        "\t6.ѡ��*���ⷴӳ*\n"
                        "\t7.ѡ��*�೵��·����*\n"
                        "\t8.�������ݼ��˳�ϵͳ��\n");
                fflush(stdout);
                scanf("%d", &n);
            } else
            {
                n = 8;
            }
        } else
        {
            fst_time = 0;
            printf("********************************\n    ��ӭ���������������ϵͳ    \n********************************\n");
            printf(
                    "*�ף�����������*\n"
                    "\t1.ѡ��*��Ա����*\n"
                    "\t2.ѡ��*���ݹ���*\n"
                    "\t3.ѡ��*��ס����*\n"
                    "\t4.ѡ��*������ʩ����*\n"
                    "\t5.ѡ��*������Ա����*\n"
                    "\t6.ѡ��*���ⷴӳ*\n"
                    "\t7.ѡ��*�೵��·����*\n"
                    "\t8.�������ݼ��˳�ϵͳ��\n");
            fflush(stdout);
            scanf("%d", &n);
        }


        if (n == 1) //��Ա����
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
            if (n == 4)
            {

            } else
            {
                if (n == 1)//1.ѡ��*�½���Ա
                {
                    char name[100];
                    printf("�����Ա���֣�\n");
                    fflush(stdout);
                    scanf("%s", name);
                    people_list_push(&d.people_list, name);
                }
                if (n == 2)//2.ѡ��*��ѯ��Ա*
                {
                    printf("���ѡ���ѯ�ķ�ʽ\n"
                           "1.ID��ѯ\n"
                           "2.�����ֲ�ѯ\n"
                           "3.������л�Ա\n");
                    fflush(stdout);
                    scanf("%d", &n);
                    if (n == 1)
                    {
                        int ID, xiabiao;
                        printf("����������ѯ��ID:\n");
                        fflush(stdout);
                        scanf("%d", &ID);
                        xiabiao = people_find_by_id(d.people_list, ID);
                        if (xiabiao < 0)
                        {
                            printf("���û�������\n");
                        } else
                        {
                            printf("�û�ID:%d\n����:%s\n", ID, people_list_at(d.people_list, xiabiao)->name);
                        }
                    }
                        // TODO �����Ĺ���,��������
                    else if (n == 2)
                    {
                        char name[100];
                        int xiabiao;
                        printf("�������������֣�\n");
                        fflush(stdout);
                        scanf("", name);
                        xiabiao = people_find_by_name(d.people_list, name);
                        if (xiabiao < 0)
                        {
                            printf("���û�������\n");
                        } else
                        {
                            printf("�û�ID:%d\n����:%s\n", people_list_at(d.people_list, xiabiao)->id, name);
                        }
                    }
                        // TODO �����Ĺ���
                    else if (n == 3)
                    {
                        while (1)
                        {
                            for (int i = 0; i < d.people_list.size; i++)
                            {
                                printf("��%d���û�\n\tID:%d\n\t����:%s\n", i + 1, people_list_at(d.people_list, i)->id,
                                       people_list_at(d.people_list, i)->name);
                            }
                            printf("���Ƿ�Ҫ�ٿ�һ�飿1.ȷ��\t2.ȡ��\n");
                            int one_more_time;
                            scanf("%d", &one_more_time);
                            if (one_more_time == 2)
                            {
                                break;
                            } else if (one_more_time == 1)
                            {
                                //do nothing
                            } else
                            {
                                printf("��������Ҳ������뿴��\n");
                            }
                        }
                    }//TODO �����Ĺ���,������л�Ա
                } else if (n == 3)//��Ա��ɾ�����޸�
                {
                    printf("�������ԱID:\n");
                    fflush(stdout);
                    //  ���ݱ��ѡ��Ҫ�޸ĵĻ�Ա
                    int xiabiao, ID, name;
                    scanf("%d\n", ID);
                    xiabiao = people_find_by_id(d.people_list, ID);
                    if (xiabiao < 0)
                    {
                        printf("���û�������\n");
                    } else
                    {
                        printf("�û�ID:%d\n����:%s\n", people_list_at(d.people_list, xiabiao)->id, name);
                        printf("�Ƿ�ȷ���޸�? 1.ȷ��\t2.ȡ��\n");
                        int confirm;
                        scanf("%d\n", &confirm);
                        if (confirm == 2)
                        {

                        } else if (confirm == 1)
                        {
                            int new_name;
                            printf("�������µ�����\n");
                            scanf("%d\n", new_name);
                            strcpy(people_list_at(d.people_list, xiabiao)->name, new_name);
                        } else
                        {
                            printf("��������Ҳ����������\n");
                        }
                    }


                }

            }
        } else if (n == 2)//ѡ��*���ݹ���*
        {
            printf("����һ����Ҫ��ʲô��\n"
                   "��������Ӧ���֣�\n"
                   "\t1.ѡ��*�鿴���ݻ������*\n"
                   "\t2.ѡ��*������*\n"
                   "\t3.ѡ��*��ѯ��Ա���µķ���*\n"
                   "\t4.ѡ��*������һ��*\n");
            fflush(stdout);
            scanf("%d", &n);
            if (n == 1)//1.ѡ��*�鿴���ݻ������*
            {
                printf("���ǵķ��ݶ���Ȩ����������֤���������ģ�\n");
                fflush(stdout);
            }
            if (n == 2)//2.ѡ��*������*
            {
                //TODO �����д�
                printf("���Ƿ��Ѿ���Ϊ��Ա��\n"
                       "1.��\n"
                       "2.��\n");
                fflush(stdout);
                scanf("%d", &n);
                if (n == 1)
                {
                    printf("����������ID��\n");
                    fflush(stdout);
                    int people_id;
                    scanf("%d", &people_id);
                    int xiabiao = people_find_by_id(d.people_list, people_id);
                    if (xiabiao < 0)
                    {
                        printf("��ID��Ӧ�Ļ�Ա������\n");
                    } else
                    {
                        char name[100];
                        strcpy(name, people_list_at(d.people_list, xiabiao)->name);
                        printf("��ӭ�����𾴵Ļ�Ա:%s\n", name);
                        printf("�����Կ�ʼѡ������\n"
                               "�����뷿�����֣�\n");
                        fflush(stdout);
                        char house_name[100];
                        scanf("%s", house_name);
                        house_list_push(&d.house_list, house_name, people_id);
                        printf("����ɹ�����л���Ĺ���\n");
                    }
                }
                    // TODO �����Ĺ���
                else if (n == 2)
                {
                    printf("�������ǻ�Ա��\n"
                           "�뷵����ҳע���Ա�Թ����ݣ�\n");
                    fflush(stdout);
                }
            } else if (n == 3)//3.ѡ��*��ѯ����*
            {
                int ID;
                printf("����������ID\n");
                fflush(stdout);
                int people_id;
                scanf("%d", &people_id);
                int xiabiao = people_id;
                if (xiabiao < 0)
                {
                    printf("��ID��Ӧ�Ļ�Ա������\n");
                } else
                {
                    for (int i = 0; i < d.house_list.size; i++)
                    {
                        if (house_list_at(d.house_list, i)->owner == ID)
                        {
                            printf("��%d�䷿��\n\tID:%d\n\t����:%s\n", i + 1, house_list_at(d.house_list, i)->id,
                                   house_list_at(d.house_list, i)->name);
                        }
                    }
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
                printf("�����������ݵ�ID\n");
                fflush(stdout);
                char house_id[100];
                scanf("%s", house_id);
                // TODO �����Ĺ���
                printf("��������ϣ�����ķ��ݣ�\n"
                       "1.*��ס*\n"
                       "2.*����*\n"
                       "3.*����*: \n");
                fflush(stdout);
                scanf("%d", &n);
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
                scanf("%d", &n);
                if (n == 1)
                {
                    printf("����Ҫ����ʹ��ʲô������ʩ��\n"
                           "������������ʩ������\n");
                    fflush(stdout);
                }//TODO �����Ĺ��������룬���Ҳ��ж��Ƿ��и�������ʩ������������ʹ�óɹ�����������޴���ʩ��������Ҫ���������룩
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
                scanf("%d", &n);
                if (n == 1)
                {
                    printf("����������������\n");
                    fflush(stdout);
                    scanf("%s", name2);
                }

                    // TODO �����Ĺ���
                else if (n == 2)
                {
                    printf("����������������\n");
                    fflush(stdout);
                } else if (n == 3)
                {
                    printf("����������������\n");
                    fflush(stdout);
                }
                    // TODO �����Ĺ���
                    //��servant.h
                else if (n == 4)
                {}
            }
        } else if (n == 6)//6.ѡ��*���ⷴӳ*
        {
            printf("��½ https://www.icourse163.org/learn/NEU-1002745019 ��ø������\n"
                   "��ӿͷ�΢�ţ����������ʲô��zhangyichuan_33��ȡһ��һ����\n");
        } else if (n == 7)
        {
            printf("�������ʲô������\n"
                   "1.�鿴�೵·��\n"
                   "2.��Ӱ೵·��\n"
                   "3.ɾ���೵·��\n"
                   "4.�޸İ೵·��\n"
            );
            fflush(stdout);
            scanf("%d", n);
            if (n == 1)
            {
                printf("1.*�鿴ĳ���೵·��*\n"
                       "2.*�鿴ȫ��·��*\n");
                fflush(stdout);
            }
            if (n == 2)
            {
                printf("������վ��������\n");
                fflush(stdout);
                scanf("%d", &n);

                printf("������վ�����֣�\n");
                fflush(stdout); // TODO �����㣬����������������ѭ������վ������
            }

            if (n == 3)
            {
                printf("");//TODO ������WORK�����Ŀǰ�е���·
                fflush(stdout);
                printf("������Ҫɾ���ڼ�����·\n");
                fflush(stdout);
                scanf("%d", &n);
            }
            if (n == 4)
            {
                printf("");//TODO ������WORK�����Ŀǰ�е���·(����ţ�
                fflush(stdout);
                printf("������Ҫ�޸ĵڼ�����·\n");
                fflush(stdout);
                scanf("%d", &n);
                while (1)
                {
                    printf("��ѡ�����%d,n\n"
                           "����Ҫ��\n"
                           "1.*ɾ��*\n"
                           "2.*����*\n"
                           "3.*�޸�*\n");
                    fflush(stdout);
                    scanf("%d", &n);
                    // TODO cxh
                    printf("���Ƿ�ѡ������޸ĵ�ǰ��·��\n"
                           "1.�˳�\n"
                           "2.����\n");
                    fflush(stdout);
                    int flag;
                    scanf("%d", &flag);
                    if (flag == 1)
                    {
                        break;
                    }
                }

            }
        }//TODO �����кܶ�����Ĺ���
        else if (n == 8)
        {
            // TODO �����Ĺ��� ѯ���Ƿ񱣴����ݡ������ļ���
            printf("�Ƿ񱣴����ݣ� 1.��\t2.��\n");
            fflush(stdout);
            int new_number;
            scanf("%d", &new_number);
            if (new_number == 1)
            {

                printf("�������ļ���\n");
                fflush(stdout);
                char new_file[100];
                scanf("%s", new_file);
                data_save(d, new_file);
                printf("�����ѱ�������Ϊ%s���ļ�\n", new_file);
                fflush(stdout);
            } else
            {
                printf("����δ����");
                fflush(stdout);
            }

            break;
        }
    }
    return 0;
}