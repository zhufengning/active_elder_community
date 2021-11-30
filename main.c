#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void mysleep(double t)
{
    clock_t st = clock();
    while ((double) (clock() - st) / CLOCKS_PER_SEC < t);
}

int main()
{
    printf("���Ƿ���ۿ����ǵ�����������\n\t1.�ۿ�\n\t2.ȡ��\n");
    fflush(stdout);
    int watch;
    scanf("%d", &watch);
    if (watch == 1)
    {
        printf("ϵͳ������");
        fflush(stdout);
        mysleep(0.6);
        printf(".");
        fflush(stdout);
        mysleep(0.6);
        printf(".");
        fflush(stdout);
        mysleep(0.6);
        printf(".\n");
        fflush(stdout);
        mysleep(0.6);
        printf("��ϵͳ��������Ĺ���ʦ");
        fflush(stdout);
        mysleep(0.6);
        printf("���������з����������죬");
        fflush(stdout);
        mysleep(0.6);
        printf("ֻ����������������顣��\n");
        mysleep(0.6);
        fflush(stdout);
        printf("3..");
        fflush(stdout);
        mysleep(0.6);
        printf("2..");
        fflush(stdout);
        mysleep(0.6);
        printf("1..\n");
        fflush(stdout);
        mysleep(0.6);
        printf("�������\n");
    }

    Data d = data_new();
    int a;
    while (1)
    {
        printf("���Ƿ���Ҫ��ȡ�ѱ�������ݣ�\n"
               "\t1.��\n"
               "\t2.��\n");
        fflush(stdout);
        scanf("%d", &a);
        char sz[100];
        if (a == 1)
        {
            printf("�������ļ�����\n");
            fflush(stdout);
            scanf("%s", sz);
            d = data_from_file(sz);
            if (d.error != 0)
            {
                printf("�ļ�����ʧ��\n");
                fflush(stdout);
                continue;
            } else
            {
                break;
            }

        } else if (a == 2)
        {
            printf("������� \n");
            fflush(stdout);
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
                printf("********************************\n    ��ӭ�����������������̨ϵͳϵͳ    \n********************************\n��ȷ���ڹ���Ա�ļල��ʹ�ñ�ϵͳ�����򽫱���Ϊ�Ƿ�����\n");
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
                           "\t1.��ID��ѯ\n"
                           "\t2.�����ֲ�ѯ\n"
                           "\t3.������л�Ա\n");
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
                            fflush(stdout);
                        } else
                        {
                            printf("�û�ID:%d\n����:%s\n", ID, people_list_at(d.people_list, xiabiao)->name);
                            fflush(stdout);
                        }
                    } else if (n == 2)
                    {
                        char name[100];
                        int xiabiao;
                        printf("��������Ҫ��ѯ�����֣�\n");
                        fflush(stdout);
                        scanf("", name);
                        xiabiao = people_find_by_name(d.people_list, name);
                        if (xiabiao < 0)
                        {
                            printf("���û�������\n");
                            fflush(stdout);
                        } else
                        {
                            printf("�û�ID:%d\n����:%s\n", people_list_at(d.people_list, xiabiao)->id, name);
                            fflush(stdout);
                        }
                    } else if (n == 3)
                    {
                        while (1)
                        {
                            for (int i = 0; i < d.people_list.size; i++)
                            {
                                printf("��%d���û�\n\tID:%d\n\t����:%s\n", i + 1, people_list_at(d.people_list, i)->id,
                                       people_list_at(d.people_list, i)->name);
                                fflush(stdout);
                            }
                            printf("���Ƿ�Ҫ�ٿ�һ�飿1.ȷ��\t2.ȡ��\n");
                            fflush(stdout);
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
                                fflush(stdout);
                            }
                        }
                    }
                } else if (n == 3)//��Ա��ɾ�����޸�
                {
                    printf("�������ԱID:\n");
                    fflush(stdout);
                    //  ���ݱ��ѡ��Ҫ�޸ĵĻ�Ա
                    int xiabiao, ID;
                    scanf("%d", &ID);
                    xiabiao = people_find_by_id(d.people_list, ID);
                    if (xiabiao < 0)
                    {
                        printf("���û�������\n");
                        fflush(stdout);
                    } else
                    {
                        printf("�û�ID:%d\n����:%s\n", people_list_at(d.people_list, xiabiao)->id,
                               people_list_at(d.people_list, xiabiao)->name);
                        printf("��ѡ�����Ĳ���? 1.�޸�\t2.ɾ��\t3.ȡ��\n");
                        fflush(stdout);
                        int confirm;
                        scanf("%d", &confirm);
                        if (confirm == 1)
                        {
                            char new_name[100];
                            printf("�������µ�����\n");
                            fflush(stdout);
                            scanf("%s", new_name);
                            strcpy(people_list_at(d.people_list, xiabiao)->name, new_name);
                        } else if (confirm == 2)
                        {
                            people_list_delete(&d.people_list, xiabiao);
                            printf("ɾ���ɹ�\n");
                            fflush(stdout);
                        } else if (confirm == 3)
                        {
                            printf("ȡ���ɹ�\n");
                            fflush(stdout);
                        } else
                        {
                            printf("��������Ҳ����������\n");
                            fflush(stdout);
                        }
                    }
                }
            }
        } else if (n == 2)//ѡ��*���ݹ���*
        {
            printf("����һ����Ҫ��ʲô��\n"
                   "��������Ӧ���֣�\n"
                   "\t1.ѡ��*�鿴���ݻ������*\n"
                   "\t2.ѡ��*��Ա�����ݰ���*\n"
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
                printf("�������Ƿ��Ѿ���Ϊ��Ա��\n"
                       "\t1.��\n"
                       "\t2.��\n");
                fflush(stdout);
                scanf("%d", &n);
                if (n == 1)
                {
                    printf("�������ԱID��\n");
                    fflush(stdout);
                    int people_id;
                    scanf("%d", &people_id);
                    int xiabiao = people_find_by_id(d.people_list, people_id);
                    if (xiabiao < 0)
                    {
                        printf("��ID��Ӧ�Ļ�Ա������\n");
                        fflush(stdout);
                    } else
                    {
                        char name[100];
                        strcpy(name, people_list_at(d.people_list, xiabiao)->name);
                        printf("��ӭ�����𾴵Ļ�Ա:%s\n", name);
                        printf("�����Կ�ʼѡ������\n"
                               "������������ķ��ݵ����֣���������μ������ֲᣩ\n");
                        fflush(stdout);
                        char house_name[100];
                        scanf("%s", house_name);
                        house_list_push(&d.house_list, house_name, people_id);
                        printf("�����ɹ�����л���Ĺ���\n");
                        fflush(stdout);
                        //TODO �����·��ݵ�ID�ǣ�
                    }
                } else if (n == 2)
                {
                    printf("�������ǻ�Ա��\n"
                           "�뷵����ҳע���Ա�԰����ݹ���\n");
                    fflush(stdout);
                }
            } else if (n == 3)//3.ѡ��*��ѯ����*
            {
                int ID;
                printf("����������ID\n");
                fflush(stdout);
                int people_id;
                scanf("%d", &people_id);
                int xiabiao = people_find_by_id(d.people_list, people_id);
                if (xiabiao < 0)
                {
                    printf("��ID��Ӧ�Ļ�Ա������\n");
                    fflush(stdout);
                } else
                {
                    for (int i = 0; i < d.house_list.size; i++)
                    {
                        if (house_list_at(d.house_list, i)->owner == ID)
                        {
                            printf("��%d�䷿��\n\tID:%d\n\t����:%s\n", i + 1, house_list_at(d.house_list, i)->id,
                                   house_list_at(d.house_list, i)->name);
                            fflush(stdout);
                        }
                    }
                }
            }

        } else if (n == 3)//ѡ��*��ס����*
        {
            printf("���Ƿ��Ѿ������ݣ�\n"
                   "\t1.��\n"
                   "\t2.��\n");
            fflush(stdout);

            scanf("%d", &n);
            if (n == 1)//�ѹ�����
            {
                printf("���������Ļ�ԱID\n");
                int people_id;
                fflush(stdout);
                scanf("%d", &people_id);
                int xiabiao = people_find_by_id(d.people_list, people_id);
                if (xiabiao < 0)
                {
                    printf("��ID��Ӧ�Ļ�Ա������\n");
                    fflush(stdout);
                } else
                {
                    printf("�����������·�����ID\n");
                    fflush(stdout);
                    int house_id;
                    scanf("%d", &house_id);
                    int xiabiao = house_find_by_id(d.house_list, house_id);
                    if (xiabiao < 0)
                    {
                        printf("�÷��ݲ�����\n");
                        fflush(stdout);
                    } else
                    {
                        int is_his = 1;
                        for (int i = 0; i < d.house_list.size; i++)
                        {
                            if (house_list_at(d.house_list, i)->owner != people_id)
                            {
                                printf("������Ͳ������ķ���( ^��^)\n");
                                fflush(stdout);
                                is_his = 0;
                                break;
                            }
                        }// TODO ֻ����ӵ��ר��������Ա������²�����ס����
                        if (!is_his)
                            continue;
                        int servant_xiabiao = -1;

                        for (int i = 0; i < d.servant_list.size; i++)
                        {
                            if (servant_list_at(d.servant_list, i)->target_id == people_id)
                            {
                                servant_xiabiao = i;
                                break;
                            }
                        }
                        if (servant_xiabiao < 0)
                        {
                            printf("����û��ר��������Ա\n"
                                   "����˾�ṩ���ʵ�ר������\n"
                                   "ʱ�̱������ĲƲ���ȫ\n"
                                   "����ѡ�����ķ�����Ա���������ǵķ���\n");
                            fflush(stdout);
                            continue;
                        }
                        printf("%d�ŷ�����Ա%s�߳�Ϊ������\n", servant_list_at(d.servant_list, servant_xiabiao)->id,
                               servant_list_at(d.servant_list, servant_xiabiao)->name);
                        printf("�������·��ݵ���ס��Ϣ\n"
                               "\t1.*������ס*\n"
                               "\t2.*����*\n"
                               "\t3.*����*: \n");
                        fflush(stdout);
                        scanf("%d", &n);
                        if (n == 1)
                        {
                            house_list_at(d.house_list, xiabiao)->type = 1;
                            printf("��ӭ��ס\n");
                            fflush(stdout);
                        } else if (n == 2)
                        {
                            printf("��������ϣ����������ID\n");
                            fflush(stdout);
                            int rent_id, xiabiao;
                            scanf("%d", &rent_id);
                            xiabiao = people_find_by_id(d.people_list, rent_id);
                            if (xiabiao < 0)
                            {
                                printf("���û�������\n");
                                fflush(stdout);
                            } else
                            {
                                house_list_at(d.house_list, xiabiao)->type = 2;
                                house_list_at(d.house_list, xiabiao)->tenant = rent_id;
                                printf("�����ɹ������ķ�����Ϣ�Ѹ���Ϊ�����У���������IDΪ%d\n", rent_id);
                                fflush(stdout);
                            }
                        } else if (n == 3)
                        {
                            house_list_at(d.house_list, xiabiao)->type = 0;
                            printf("�����ɹ�������IDΪ%d�ķ�����Ϣ�Ѹ���Ϊ������\n", house_id);
                            fflush(stdout);
                        }
                    }
                }
            } else if (n == 2)//���Ƿ�������ѡ���
            {
                printf("��ȥ��\n");
                fflush(stdout);
            }
        } else if (n == 4)//4.ѡ��*������ʩ����*
        {
            printf("��ѡ�����Ĳ�����\n"
                   "\t1.*�û�������ʹ��������ʩ*\n"
                   "\t2.*������Ա������������ʩ*\n");
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
            } else if (n == 2)
            {
                printf("����Ҫ��������ʩ�������������\n"
                       "\t1.��ѯ\n"
                       "\t2.���\n"
                       "\t3.�޸�\n");
                fflush(stdout);
                int confirm_number;
                scanf("%d", &confirm_number);
                if (confirm_number == 1)//1.��ѯ��ʩ
                {
                    printf("���������ַ�ʽ��ѯ������ʩ��\n"
                           "\t1.��ID��ѯ\n"
                           "\t2.�����Ʋ�ѯ\n"
                           "\t3.���������ʩ\n"
                           "ע�⣺�����������ֽ�������һ��\n");
                    fflush(stdout);
                    int c_number;
                    scanf("%d", &c_number);
                    if (c_number == 1)//1.��ID��ѯ
                    {
                        printf("�����������ѯ��������ʩID\n");
                        fflush(stdout);
                        int f_id;
                        scanf("%d", &f_id);
                        int xiabiao = facility_find_by_id(d.facility_list, f_id);
                        if (xiabiao < 0)
                        {
                            printf("��ID��Ӧ��������ʩ������\n");
                            fflush(stdout);
                        } else
                        {
                            Facility *t = facility_list_at(d.facility_list, xiabiao);
                            printf("��ʩID:%d\t��ʩ����:%s\n", t->id, t->name);
                            fflush(stdout);
                        }
                    } else if (c_number == 2)//2.�����Ʋ�ѯ
                    {
                        printf("�����������ѯ��������ʩ����\n");
                        fflush(stdout);
                        char f_name[100];
                        scanf("%s", f_name);
                        printf("�����ǲ�ѯ���\n");
                        fflush(stdout);
                        for (int i = 0; i < d.facility_list.size; i++)
                        {
                            if (strcmp(facility_list_at(d.facility_list, i)->name, f_name) == 0)
                            {
                                Facility *t = facility_list_at(d.facility_list, i);
                                printf("��ʩID:%d\t��ʩ����:%s\n", t->id, t->name);
                                fflush(stdout);
                            }
                        }
                        printf("��ѯ��ϣ�����Ϊ���в�ѯ���\n");
                        fflush(stdout);
                    } else if (c_number == 3)//3.���������ʩ
                    {
                        for (int i = 0; i < d.facility_list.size; i++)
                        {
                            Facility *t = facility_list_at(d.facility_list, i);
                            printf("��ʩID:%d\t��ʩ����:%s\n", t->id, t->name);
                            fflush(stdout);
                        }
                    }
                } else if (confirm_number == 2)//2.���������ʩ
                {

                }
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
            fflush(stdout);
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
                    //TODO ������ѡ��һվ��Ȼ��ִ�в���
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
