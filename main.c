#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* People��������д�ģ������ṹ��д�ı䳤���飬���ʣ��ʾ����볢�Զ���д�������� */

#include "people.h"
#include "facility.h"
#include "servant.h"
#include "house.h"
#include "say.h"
// Ȼ��busҲ���õ��������Ƕ�ά����
#include "bus.h"
#include "storage.h"

//array--��������
//readme��Ĵ���淶��ͬ�������ǰ�--zfn

#pragma clang diagnostic push
#pragma ide diagnostic ignored "LocalValueEscapesScope"
int main()
{
    char str[105];
    srand(time(NULL));
    printf("���Ƿ���ۿ����ǵ�����������\n\t1.�ۿ�\n\t2.ȡ��\n");
    fflush(stdout);
    long watch;
    scanf("%104s", str);
    watch = strtol(str, NULL, 10);
    if (watch == 1)
    {
        play_ani();
    }

    Data d = data_new();
    long a;
    while (1)
    {
        printf("���Ƿ���Ҫ��ȡ�ѱ�������ݣ�\n"
               "\t1.��\n"
               "\t2.��\n");
        fflush(stdout);
        scanf("%104s", str);
        a = strtol(str, NULL, 10);

        char array[105];
        if (a == 1)
        {
            printf("�������ļ�����\n");
            fflush(stdout);
            scanf("%104s", array);
            d = data_from_file(array);
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

        long the_n;
        if (!fst_time)
        {
            printf("����1����ʹ�ñ�ϵͳ�������������ֱ��沢�˳�\n");
            fflush(stdout);
            long array;
            scanf("%104s", str);
            array = strtol(str, NULL, 10);
            if (array == 1)
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
                say_sentence();
                scanf("%104s", str);
                the_n = strtol(str, NULL, 10);
            } else
            {
                the_n = 8;
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
            say_sentence();
            fflush(stdout);

            scanf("%104s", str);
            the_n = strtol(str, NULL, 10);
        }

        long n;
        switch(the_n)
        {
            case 1: //��Ա����
                printf(
                        "����һ����Ҫ��ʲô��\n"
                        "��������Ӧ���֣�\n"
                        "\t1.ѡ��*�½���Ա*\n"
                        "\t2.ѡ��*��ѯ��Ա*\n"
                        "\t3.ѡ��*��Ա��ɾ�����޸�*\n"
                        "\t4.ѡ��*������һ��*\n");
                fflush(stdout);
                scanf("%104s", str);
                n = strtol(str, NULL, 10);
                if (n == 4)
                {

                } else
                {
                    if (n == 1)//1.ѡ��*�½���Ա
                    {
                        char name[100]="";
                        printf("�����Ա���֣�\n");
                        fflush(stdout);
                        scanf("%99s", name);
                        int new_id = people_list_push(&d.people_list, name);
                        printf("�����ɹ������Ļ�ԱIDΪ��%d\n", new_id);
                        fflush(stdout);
                    }
                    if (n == 2)//2.ѡ��*��ѯ��Ա*
                    {
                        printf("���ѡ���ѯ�ķ�ʽ\n"
                               "\t1.��ID��ѯ\n"
                               "\t2.�����ֲ�ѯ\n"
                               "\t3.������л�Ա\n");
                        fflush(stdout);
                        scanf("%104s", str);
                        n = strtol(str, NULL, 10);
                        if (n == 1)
                        {
                            long ID, xiabiao;
                            printf("����������ѯ��ID:\n");
                            fflush(stdout);
                            scanf("%104s", str);
                            ID = strtol(str, NULL, 10);
                            xiabiao = people_find_by_id(d.people_list, ID);
                            if (xiabiao < 0)
                            {
                                printf("���û�������\n");
                                fflush(stdout);
                            } else
                            {
                                printf("�û�ID:%ld\n����:%s\n", ID, people_list_at(d.people_list, xiabiao)->name);
                                fflush(stdout);
                            }
                        } else if (n == 2)
                        {
                            char name[100];
                            int xiabiao;
                            printf("��������Ҫ��ѯ�����֣�\n");
                            fflush(stdout);
                            scanf("%99s", name);
                            xiabiao = people_find_by_name(d.people_list, name);
                            if (xiabiao < 0)
                            {
                                printf("���û�������\n");
                                fflush(stdout);
                            } else
                            {
                                printf("�û�ID:%d\n����:%99s\n", people_list_at(d.people_list, xiabiao)->id, name);
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
                                long one_more_time;
                                scanf("%104s", str);
                                one_more_time = strtol(str, NULL, 10);
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
                        long xiabiao, ID;

                        scanf("%104s", str);
                        ID = strtol(str, NULL, 10);
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
                            scanf("%104s", str);
                            confirm = strtol(str, NULL, 10);
                            if (confirm == 1)
                            {
                                char new_name[100];
                                printf("�������µ�����\n");
                                fflush(stdout);
                                scanf("%99s", new_name);
                                strcpy(people_list_at(d.people_list, xiabiao)->name, new_name);
                                printf("�����ɹ�����������Ϊ%s\n", new_name);
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
                break;

            case 2://ѡ��*���ݹ���*

                printf("����һ����Ҫ��ʲô��\n"
                       "��������Ӧ���֣�\n"
                       "\t1.ѡ��*�鿴���ݻ������*\n"
                       "\t2.ѡ��*��Ա�����ݰ���*\n"
                       "\t3.ѡ��*��ѯ��Ա���µķ���*\n"
                       "\t4.ѡ��*������һ��*\n");
                fflush(stdout);
                scanf("%104s", str);
                n = strtol(str, NULL, 10);
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
                    scanf("%104s", str);
                    n = strtol(str, NULL, 10);
                    if (n == 1)
                    {
                        printf("�������ԱID��\n");
                        fflush(stdout);
                        int people_id;
                        scanf("%104s", str);
                        people_id = strtol(str, NULL, 10);
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
                            scanf("%99s", house_name);
                            house_list_push(&d.house_list, house_name, people_id);
                            int new_id = house_list_push(&d.house_list, house_name, people_id);
                            printf("�����ɹ�����л���Ĺ���\n"
                                   "�����·���IDΪ%d\n", new_id);
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
                    printf("����������ID\n");
                    fflush(stdout);
                    int people_id;
                    scanf("%104s", str);
                    people_id = strtol(str, NULL, 10);
                    int xiabiao = people_find_by_id(d.people_list, people_id);
                    if (xiabiao < 0)
                    {
                        printf("��ID��Ӧ�Ļ�Ա������\n");
                        fflush(stdout);
                    } else
                    {
                        for (int i = 0; i < d.house_list.size; i++)
                        {
                            int ID;

                            if (house_list_at(d.house_list, i)->owner == ID)
                            {
                                printf("��%d�䷿��\n\tID:%d\n\t����:%s\n", i + 1, house_list_at(d.house_list, i)->id,
                                       house_list_at(d.house_list, i)->name);
                                fflush(stdout);
                            }
                        }
                    }
                }
                break;

            case 3://ѡ��*��ס����*

                printf("���Ƿ��Ѿ������ݣ�\n"
                       "\t1.��\n"
                       "\t2.��\n");
                fflush(stdout);

                scanf("%104s", str);
                n = strtol(str, NULL, 10);

                if (n == 1)//�ѹ�����
                {
                    printf("���������Ļ�ԱID\n");
                    int people_id;
                    fflush(stdout);
                    scanf("%104s", str);
                    people_id = strtol(str, NULL, 10);
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
                        scanf("%104s", str);
                        house_id = strtol(str, NULL, 10);
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
                            scanf("%104s", str);
                            n = strtol(str, NULL, 10);
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
                                scanf("%104s", str);
                                rent_id = strtol(str, NULL, 10);
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
                break;
            case 4://4.ѡ��*������ʩ����*

                printf("��ѡ�����Ĳ�����\n"
                       "\t1.*�û�������ʹ��������ʩ*\n"
                       "\t2.*������Ա������������ʩ*\n");
                fflush(stdout);
                scanf("%104s", str);
                n = strtol(str, NULL, 10);
                if (n == 1)
                {
                    printf("����Ҫʹ������������ʩ��\n"
                           "1.��\n"
                           "2.��\n");
                    fflush(stdout);
                    scanf("%104s", str);
                    n = strtol(str, NULL, 10);
                    if (n == 1)
                    {
                        printf("����Ҫ����ʹ��ʲô������ʩ��\n"
                               "������������ʩ������\n");
                        fflush(stdout);
                        char f_name[100];
                        scanf("%99s", f_name);
                        int xiabiao = facility_find_by_name(d.facility_list, f_name);
                        if (xiabiao < 0)
                        {
                            printf("��������ʩ�����ڣ�������Ҫ��������\n");
                        } else
                        {
                            printf("ʹ�óɹ�\n");
                        }
                    }//TODO �����Ĺ��������룬���Ҳ��ж��Ƿ��и�������ʩ������������ʹ�óɹ�����������޴���ʩ��������Ҫ���������룩
                } else if (n == 2)
                {
                    printf("����Ҫ��������ʩ�������������\n"
                           "\t1.��ѯ\n"
                           "\t2.���\n"
                           "\t3.�޸Ļ�ɾ��\n");
                    fflush(stdout);
                    int confirm_number;
                    scanf("%104s", str);
                    confirm_number = strtol(str, NULL, 10);
                    if (confirm_number == 1)//1.��ѯ��ʩ
                    {
                        printf("���������ַ�ʽ��ѯ������ʩ��\n"
                               "\t1.��ID��ѯ\n"
                               "\t2.�����Ʋ�ѯ\n"
                               "\t3.���������ʩ\n"
                               "ע�⣺�����������ֽ�������һ��\n");
                        fflush(stdout);
                        int c_number;
                        scanf("%104s", str);
                        c_number = strtol(str, NULL, 10);
                        if (c_number == 1)//1.��ID��ѯ
                        {
                            printf("�����������ѯ��������ʩID\n");
                            fflush(stdout);
                            int f_id;
                            scanf("%104s", str);
                            f_id = strtol(str, NULL, 10);
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
                            scanf("%99s", f_name);
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
                        char f_name[100];
                        printf("����������Ҫ��ӵ�������ʩ������\n");
                        fflush(stdout);
                        scanf("%99s", f_name);
                        int new_id = facility_list_push(&d.facility_list, f_name);
                        printf("�ѳɹ������Ϊ%s����ʩ,��IDΪ%d\n", f_name, new_id);
                    } else if (confirm_number == 3)//3.�޸Ļ�ɾ��
                    {
                        printf("��������ʩID:\n");
                        fflush(stdout);
                        int xiabiao, ID;
                        scanf("%104s", str);
                        ID = strtol(str, NULL, 10);
                        xiabiao = facility_find_by_id(d.facility_list, ID);
                        if (xiabiao < 0)
                        {
                            printf("����ʩ������\n");
                        } else
                        {
                            printf("��ʩID:%d\n����:%s\n", facility_list_at(d.facility_list, xiabiao)->id,
                                   facility_list_at(d.facility_list, xiabiao)->name);
                            printf("��ѡ�����Ĳ���? 1.�޸�\t2.ɾ��\t3.ȡ��\n");
                            fflush(stdout);
                            int confirm;
                            scanf("%104s", str);
                            confirm = strtol(str, NULL, 10);
                            if (confirm == 1)
                            {
                                char new_name[100];
                                printf("�������µ���ʩ����\n");
                                fflush(stdout);
                                scanf("%99s", new_name);
                                strcpy(facility_list_at(d.facility_list, xiabiao)->name, new_name);
                                printf("�����ɹ�����ʩ��������Ϊ%s\n", new_name);
                            } else if (confirm == 2)
                            {
                                facility_list_delete(&d.facility_list, xiabiao);
                                printf("ɾ���ɹ�\n");
                                fflush(stdout);
                            } else if (confirm == 3)
                            {

                            } else
                            {
                                printf("��������Ҳ����������\n");
                            }
                        }
                    }
                }//TODO �����Ĺ���
                break;
            case 5://5.ѡ��*������Ա����*

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
                    scanf("%104s", str);
                    n = strtol(str, NULL, 10);
                    if (n == 1)
                    {
                        printf("����������������\n");
                        fflush(stdout);
                        scanf("%99s", name2);
                        int new_id = servant_list_push(&d.servant_list, name2);
                        printf("ע��ɹ�������IDΪ%d", new_id);
                    }

                        // TODO �����Ĺ���
                    else if (n == 2)
                    {
                        printf("����������ID��\n");
                        fflush(stdout);
                        int s_id;

                        scanf("%104s", str);
                        s_id = strtol(str, NULL, 10);
                        int xiabiao = servant_find_by_id(d.servant_list, s_id);
                        if (xiabiao < 0)
                        {
                            printf("�÷�����Ա������\n");
                            fflush(stdout);
                        } else
                        {
                            char new_name[100];
                            printf("�������µ�����\n");
                            fflush(stdout);
                            scanf("%99s", new_name);
                            strcpy(facility_list_at(d.facility_list, xiabiao)->name, new_name);
                            printf("�����ɹ���IDΪ%d�ķ�����Ա��������Ϊ%s\n", s_id, new_name);
                        }
                    } else if (n == 3)
                    {
                        printf("����������������\n");
                        fflush(stdout);
                        char your_name[100];
                        scanf("%99s", your_name);
                        int xiabiao = servant_find_by_name(d.servant_list, your_name);
                        if (xiabiao < 0)
                        {
                            printf("�÷�����Ա������\n");
                            fflush(stdout);
                        } else
                        {
                            facility_list_delete(&d.facility_list, xiabiao);
                            printf("ɾ���ɹ�\n");
                            fflush(stdout);
                        }
                    }
                        // TODO �����Ĺ���
                        //��servant.h
                    else if (n == 4)
                    {}
                }
                break;
            case 6://6.ѡ��*���ⷴӳ*

                printf("��½ https://www.icourse163.org/learn/NEU-1002745019 ��ø������\n"
                       "��ӿͷ�΢�ţ����������ʲô��zhangyichuan_33��ȡһ��һ����\n");
                fflush(stdout);
                break;
            case 7:

                printf("�������ʲô������\n"
                       "1.�鿴�೵·��\n"
                       "2.��Ӱ೵·��\n"
                       "3.ɾ���೵·��\n"
                       "4.�޸İ೵·��\n"
                );
                fflush(stdout);
                scanf("%104s", str);
                n = strtol(str, NULL, 10);
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
                    scanf("%104s", str);
                    n = strtol(str, NULL, 10);

                    printf("������վ�����֣�\n");
                    fflush(stdout); // TODO �����㣬����������������ѭ������վ������
                }

                if (n == 3)
                {
                    printf("");//TODO ������WORK�����Ŀǰ�е���·
                    fflush(stdout);
                    printf("������Ҫɾ���ڼ�����·\n");
                    fflush(stdout);
                    scanf("%104s", str);
                    n = strtol(str, NULL, 10);
                }
                if (n == 4)
                {
                    printf("");//TODO ������WORK�����Ŀǰ�е���·(����ţ�
                    fflush(stdout);
                    printf("������Ҫ�޸ĵڼ�����·\n");
                    fflush(stdout);
                    scanf("%104s", str);
                    n = strtol(str, NULL, 10);


                    while (1)
                    {
                        //TODO ������ѡ��һվ��Ȼ��ִ�в���
                        printf("��ѡ�����%ld\n"
                               "����Ҫ��\n"
                               "1.*ɾ��*\n"
                               "2.*����*\n"
                               "3.*�޸�*\n", n);
                        fflush(stdout);
                        scanf("%104s", str);
                        n = strtol(str, NULL, 10);
                        // TODO cxh
                        printf("���Ƿ�ѡ������޸ĵ�ǰ��·��\n"
                               "1.�˳�\n"
                               "2.����\n");
                        fflush(stdout);
                        int flag;
                        scanf("%104s", str);
                        flag = strtol(str, NULL, 10);
                        if (flag == 1)
                        {
                            break;
                        }
                    }

                }
                break;
                //TODO �����кܶ�����Ĺ���
            case 8:
                // TODO �����Ĺ��� ѯ���Ƿ񱣴����ݡ������ļ���
                printf("�Ƿ񱣴����ݣ� 1.��\t2.��\n");
                fflush(stdout);
                int new_number;
                scanf("%104s", str);
                new_number = strtol(str, NULL, 10);
                if (new_number == 1)
                {

                    printf("�������ļ���\n");
                    fflush(stdout);
                    char new_file[100];
                    scanf("%99s", new_file);
                    data_save(d, new_file);
                    printf("�����ѱ�������Ϊ%s���ļ�\n", new_file);
                    fflush(stdout);
                } else
                {
                    printf("����δ����");
                    fflush(stdout);
                }
                return 0;
                break;

            default:
                printf("*************FBI WARING*********\n"
                       "*������Ҳ��ǰ�?                 *\n"
                       "*Ҳ���������������˭д�����ģ�     *\n"
                       "*����������Ĺ������������ʵ����  *\n"
                       "********************************\n"
                       "#��#\t#��#\t#��#\t#��#\t#��#\t#��#\t"
                       "#ϲ#\t#��#\t#��#\t#��#\t#Ϊ#\t#��#\t"
                       "#��#\t#��#\t#Ҫ#\t#��#\t#��#\t#��#\t"
                       "#ҵ#\t#��#\t#��#\n#��#\n@ZFN");
                fflush(stdout);
                break;
        }
    }

    return 0;
}