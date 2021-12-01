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

void on_error();
void clrbuf();

int main()
{
    char str[105];
    srand(time(NULL));
    printf("���Ƿ���ۿ����ǵ�����������\n\t1.�ۿ�\n\t2.ȡ��\n");
    fflush(stdout);
    long watch;
    scanf("%104s", str);clrbuf();
    watch = strtol(str, NULL, 10);
    if (watch == 1)
    {
        play_ani();
    } else if (watch != 2)
    {
        on_error();
    }

    while(1)
    {
        printf("ע�����\n"
               "\t1.�벻Ҫ���볤�ȳ���99���ַ����������ӲҪ��ô�������ԣ����򲻻��������������������ᱻ���ԡ���\n"
               "\t2.�벻Ҫ���뺬�пո�����֣������ӲҪ��ô�������ԣ����򲻻������Ҳ����Ӱ��������룬������һ���ո�����ַ��ᱻ���ԣ�\n"
               "���������ϸ�Ķ�����֪��������1\n");
        scanf("%104s", str);clrbuf();
        long known = strtol(str, NULL, 10);
        if (known == 1)
        {
            break;
        } else
        {
            on_error();
        }
    }

    Data d = data_new();
    long a;
    while (1)
    {
        printf("���Ƿ���Ҫ��ȡ�ѱ�������ݣ�\n"
               "\t1.��\n"
               "\t2.��\n");
        fflush(stdout);
        scanf("%104s", str);clrbuf();
        a = strtol(str, NULL, 10);

        char array[105];
        if (a == 1)
        {
            printf("�������ļ�����\n");
            fflush(stdout);
            scanf("%104s", array);clrbuf();
            d = data_from_file(array);
            if (d.error != 0)
            {
                printf("�ļ�����ʧ��\n");
                on_error();
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
        } else
        {
            on_error();
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
            scanf("%104s", str);clrbuf();
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
                scanf("%104s", str);clrbuf();
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

            scanf("%104s", str);clrbuf();
            the_n = strtol(str, NULL, 10);
        }

        long n;
        switch (the_n)
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
                scanf("%104s", str);clrbuf();
                n = strtol(str, NULL, 10);
                if (n == 4)
                {

                } else
                {
                    if (n == 1)//1.ѡ��*�½���Ա
                    {
                        char name[100] = "";
                        printf("�����Ա���֣�\n");
                        fflush(stdout);
                        scanf("%99s", name);clrbuf();
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
                        scanf("%104s", str);clrbuf();
                        n = strtol(str, NULL, 10);
                        if (n == 1)
                        {
                            long ID;
                            printf("����������ѯ��ID:\n");
                            fflush(stdout);
                            scanf("%104s", str);clrbuf();
                            ID = strtol(str, NULL, 10);
                            int *ans_list = people_find_by_id(d.people_list, ID);
                            if (ans_list[0] == 0)
                            {
                                printf("���û�������\n");
                                fflush(stdout);
                            } else if(ans_list[0] == 1)
                            {
                                printf("�û�ID:%ld\n����:%s\n", ID, people_list_at(d.people_list, ans_list[1])->name);
                            } else
                            {
                                printf("��������ID�ظ���\n����Ϊ���ؽ��б�\n��ע�⣬����Ӧ���ֶ��༭�����ļ�\n");
                                pl_rebuild(&d.people_list);
                                //pl,hl,sl,fl
                                for (int i = 0; i < d.people_list.size; ++i)
                                    printf("�û�ID:%d\n����:%s\n", people_list_at(d.people_list, i)->id, people_list_at(d.people_list, i)->name);
                                printf("�б��ؽ���ϣ������²�ѯ��\n");
                                fflush(stdout);
                            }
                        } else if (n == 2)
                        {
                            char name[100];
                            int xiabiao;
                            printf("��������Ҫ��ѯ�����֣�\n");
                            fflush(stdout);
                            scanf("%99s", name);clrbuf();
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
                                scanf("%104s", str);clrbuf();
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
                        } else
                        {
                            on_error();
                        }
                    } else if (n == 3)//��Ա��ɾ�����޸�
                    {
                        printf("�������ԱID:\n");
                        fflush(stdout);
                        //  ���ݱ��ѡ��Ҫ�޸ĵĻ�Ա
                        long xiabiao, ID;

                        scanf("%104s", str);clrbuf();
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
                            scanf("%104s", str);clrbuf();
                            confirm = strtol(str, NULL, 10);
                            if (confirm == 1)
                            {
                                char new_name[100];
                                printf("�������µ�����\n");
                                fflush(stdout);
                                scanf("%99s", new_name);clrbuf();
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
                                on_error();
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
                scanf("%104s", str);clrbuf();
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
                    scanf("%104s", str);clrbuf();
                    n = strtol(str, NULL, 10);
                    if (n == 1)
                    {
                        printf("�������ԱID��\n");
                        fflush(stdout);
                        int people_id;
                        scanf("%104s", str);clrbuf();
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
                            scanf("%99s", house_name);clrbuf();
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
                    } else
                    {
                        on_error();
                    }
                } else if (n == 3)//3.ѡ��*��ѯ����*
                {
                    printf("����������ID\n");
                    fflush(stdout);
                    int people_id;
                    scanf("%104s", str);clrbuf();
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

                scanf("%104s", str);clrbuf();
                n = strtol(str, NULL, 10);

                if (n == 1)//�ѹ�����
                {
                    printf("���������Ļ�ԱID\n");
                    int people_id;
                    fflush(stdout);
                    scanf("%104s", str);clrbuf();
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
                        scanf("%104s", str);clrbuf();
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
                            scanf("%104s", str);clrbuf();
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
                                scanf("%104s", str);clrbuf();
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
                            } else
                            {
                                on_error();
                            }
                        }
                    }
                } else if (n == 2)//���Ƿ�������ѡ���
                {
                    printf("��ȥ��\n");
                    fflush(stdout);
                } else
                {
                    on_error();
                }
                break;
            case 4://4.ѡ��*������ʩ����*

                printf("��ѡ�����Ĳ�����\n"
                       "\t1.*�û�������ʹ��������ʩ*\n"
                       "\t2.*������Ա������������ʩ*\n");
                fflush(stdout);
                scanf("%104s", str);clrbuf();
                n = strtol(str, NULL, 10);
                if (n == 1)
                {
                    printf("����Ҫʹ������������ʩ��\n"
                           "1.��\n"
                           "2.��\n");
                    fflush(stdout);
                    scanf("%104s", str);clrbuf();
                    n = strtol(str, NULL, 10);
                    if (n == 1)
                    {
                        printf("����Ҫ����ʹ��ʲô������ʩ��\n"
                               "������������ʩ������\n");
                        fflush(stdout);
                        char f_name[100];
                        scanf("%99s", f_name);clrbuf();
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
                    scanf("%104s", str);clrbuf();
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
                        scanf("%104s", str);clrbuf();
                        c_number = strtol(str, NULL, 10);
                        if (c_number == 1)//1.��ID��ѯ
                        {
                            printf("�����������ѯ��������ʩID\n");
                            fflush(stdout);
                            int f_id;
                            scanf("%104s", str);clrbuf();
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
                            scanf("%99s", f_name);clrbuf();
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
                        } else
                        {
                            on_error();
                        }
                    } else if (confirm_number == 2)//2.���������ʩ
                    {
                        char f_name[100];
                        printf("����������Ҫ��ӵ�������ʩ������\n");
                        fflush(stdout);
                        scanf("%99s", f_name);clrbuf();
                        int new_id = facility_list_push(&d.facility_list, f_name);
                        printf("�ѳɹ������Ϊ%s����ʩ,��IDΪ%d\n", f_name, new_id);
                    } else if (confirm_number == 3)//3.�޸Ļ�ɾ��
                    {
                        printf("��������ʩID:\n");
                        fflush(stdout);
                        int xiabiao, ID;
                        scanf("%104s", str);clrbuf();
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
                            scanf("%104s", str);clrbuf();
                            confirm = strtol(str, NULL, 10);
                            if (confirm == 1)
                            {
                                char new_name[100];
                                printf("�������µ���ʩ����\n");
                                fflush(stdout);
                                scanf("%99s", new_name);clrbuf();
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
                                on_error();
                            }
                        }
                    } else
                    {
                        on_error();
                    }
                }
                break;
            case 5://5.ѡ��*������Ա����*

                printf("��ѡ�����Ĳ�����\n"
                       "1.�༭������Ա��Ϣ\n"
                       "2.�޸��û��ķ�����Ա\n");
                fflush(stdout);
                char name2[100];
                if (n == 1)
                {
                    printf("����һ�����ʲô��\n"
                           "1.*��ѯ������Ա��Ϣ*\n"
                           "2.*ע�������Ա*\n"
                           "3.*�޸ķ�����Ա��Ϣ*\n"
                           "4.*ɾ��������Ա*\n"
                           "5.*�����*\n");
                    fflush(stdout);
                    scanf("%104s", str);clrbuf();
                    n = strtol(str, NULL, 10);
                    if (n == 1)
                    {

                    } else if (n == 2)
                    {
                        printf("����������������\n");
                        fflush(stdout);
                        scanf("%99s", name2);clrbuf();
                        int new_id = servant_list_push(&d.servant_list, name2);
                        printf("ע��ɹ�������IDΪ%d", new_id);
                    } else if (n == 3)
                    {
                        printf("����������ID��\n");
                        fflush(stdout);
                        int s_id;

                        scanf("%104s", str);clrbuf();
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
                            scanf("%99s", new_name);clrbuf();
                            strcpy(facility_list_at(d.facility_list, xiabiao)->name, new_name);
                            printf("�����ɹ���IDΪ%d�ķ�����Ա��������Ϊ%s\n", s_id, new_name);
                        }
                    } else if (n == 4)
                    {
                        printf("����������������\n");
                        fflush(stdout);
                        char your_name[100];
                        scanf("%99s", your_name);clrbuf();
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
                    } else if (n == 5)
                    {
                    } else
                    {
                        on_error();
                    }
                } else if (n == 2)
                {
                    printf("��ѡ�����Ĳ���\n"
                           "\t1.��ѯ���ķ�����Ա\n"
                           "\t2.�޸����ķ�����Ա\n"
                           "\t3.ɾ�����ķ�����Ա\n"
                           "\t4.�˳�\n");
                    scanf("%104s", str);clrbuf();
                    long x = strtol(str, NULL, 0);
                    switch (x)
                    {
                        case 1://1.��ѯ���ķ�����Ա
                        {
                            //for()
                            break;
                        }
                        case 2://2.�޸����ķ�����Ա
                        {
                            break;
                        }
                        case 3://ɾ�����ķ�����Ա
                        {
                            break;
                        }
                        case 4:
                        {
                            //do nothing
                            break;
                        }
                        default:
                            on_error();
                    }
                } else
                {
                    on_error();
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
                scanf("%104s", str);clrbuf();
                n = strtol(str, NULL, 10);
                if (n == 1)//1.�鿴�೵·��
                {
                    printf("1.*�鿴ĳ���೵·��*\n"
                           "2.*�鿴ȫ��·��*\n");
                    fflush(stdout);
                    scanf("%104s", str);clrbuf();
                    long c_number = strtol(str, NULL, 10);
                    if (c_number == 1)
                    {
                        printf("��Ҫ�鿴�ڼ����İ೵·�ߣ���������Ļ���������-1���ز���ѯȫ��·�ߣ�\n");
                        fflush(stdout);
                        scanf("%104s", str);clrbuf();
                        long list_number = strtol(str, NULL, 10);
                        int i = 0;
                        if (list_number == -1)
                        {}
                        else if (list_number < 1)
                            on_error();
                        else
                        {
                            for (BusChainNode *it = d.buschain_list.root->hou; it != NULL; it = it->hou)
                            {
                                ++i;
                                if (i == list_number)
                                {
                                    for (BusStop *jt = it->value.root->hou; jt != NULL; jt = jt->hou)
                                    {
                                        printf("%s", jt->value);
                                        if (jt->hou != NULL)
                                        {
                                            printf("->");
                                        }
                                    }
                                    printf("\n");
                                    break;
                                }
                            }
                            if (i < list_number)on_error();
                        }
                    } else if (c_number == 2)
                    {
                        int i = 0;
                        for (BusChainNode *it = d.buschain_list.root->hou; it != NULL; it = it->hou)
                        {
                            ++i;
                            printf("��%d����·��", i);
                            for (BusStop *jt = it->value.root->hou; jt != NULL; jt = jt->hou)
                            {
                                printf("%s", jt->value);
                                if (jt->hou != NULL)
                                {
                                    printf("->");
                                }
                            }
                            printf("\n");
                        }
                    } else
                    {
                        on_error();
                    }
                } else if (n == 2)//2.��Ӱ೵·��
                {
                    printf("������վ��������\n");
                    fflush(stdout);
                    scanf("%104s", str);clrbuf();
                    n = strtol(str, NULL, 10);
                    printf("������վ�����֣��Կո�ָ�����\n");
                    fflush(stdout); // TODO ����㣬����������������ѭ������վ������
                    BusChain new_bus_stations = buschain_create();
                    for (int i = 1; i <= n; i++)
                    {
                        char station_name[100];
                        scanf("%99s", station_name);
                        BusStop *p = new_bus_stations.root;
                        while (p->hou != NULL)
                        {
                            p = p->hou;
                        }
                        buschain_insert(p, station_name);
                    }
                    clrbuf();
                    buschainlist_insert(d.buschain_list.root, new_bus_stations);
                } else if (n == 3)//3.ɾ���೵·��
                {
                    printf("������Ҫɾ���ڼ�����·\n\t"
                           "��������Ļ���������-1�����ز�ͨ����ѯ���ܲ鿴��·�б�Ŷ��\n");
                    fflush(stdout);
                    scanf("%104s", str);clrbuf();
                    long d_number = strtol(str, NULL, 10);
                    if (d_number == -1)
                    {

                    } else if (d_number > 0)
                    {
                        int i = 0;
                        for (BusChainNode *it = d.buschain_list.root->hou; it != NULL; it = it->hou)
                        {
                            ++i;
                            if (i == d_number)
                            {
                                buschainlist_remove(it);
                                printf("����·��ɾ��\n");
                                break;
                            }
                        }
                        if (i < d_number)
                        {
                            printf("ɾ��ʧ�ܣ���·�߲�����\n");
                        }
                    } else
                        on_error();
                } else if (n == 4)//4.�޸İ೵·��
                {
                    printf("������Ҫ�޸ĵڼ�����·\n"
                           "��������Ļ���������-1�����ز�ͨ����ѯ���ܲ鿴��·�б�Ŷ��");
                    fflush(stdout);
                    scanf("%104s", str);clrbuf();
                    n = strtol(str, NULL, 10);
                    if (n == -1)
                    {

                    } else if (n > 0)
                    {
                        int i = 0;
                        BusChainNode *pt;

                        for (BusChainNode *it = d.buschain_list.root->hou; it != NULL; it = it->hou)
                        {
                            ++i;
                            if (i == n)
                            {
                                pt = it;
                                int j = 0;
                                for (BusStop *jt = it->value.root->hou; jt != NULL; jt = jt->hou)
                                {
                                    ++j;
                                    printf("%d:%s", j, jt->value);
                                    if (jt->hou != NULL)
                                    {
                                        printf("->");
                                    }
                                }
                                printf("\n");
                                break;
                            }
                        }
                        if (i < n)
                        {
                            printf("û��������·\n");
                        }//�����Ŵ���
                        else
                        {
                            int cont = 1;
                            while (cont)
                            {
                                //���������������������ڼ�վ
                                printf("��ѡ�����Ĳ�����\n"
                                       "1.*ɾ��һ��վ��*\n"
                                       "2.*����һ��վ��*\n"
                                       "3.*�޸�һ��վ��*\n"
                                       "4.*�����޸�*\n");
                                fflush(stdout);
                                scanf("%104s", str);clrbuf();
                                n = strtol(str, NULL, 10);
                                switch (n)
                                {
                                    case 1://1.*ɾ��һ��վ��
                                    {
                                        printf("����������Ҫɾ����վ��ţ�\n");
                                        scanf("%104s", str);clrbuf();

                                        long station_number = strtol(str, NULL, 10);
                                        --station_number;
                                        if (station_number < 0)
                                            on_error();
                                        else
                                        {
                                            int j = 0;
                                            for (BusStop *jt = pt->value.root; jt->hou != NULL; jt = jt->hou)
                                            {
                                                if (j == station_number)
                                                {
                                                    buschain_remove(jt);
                                                }
                                                ++j;
                                            }
                                            printf("\n");
                                        }
                                        break;
                                    }
                                    case 2://2.*����һ��վ��*
                                    {
                                        printf("��(>__<) �롫���ĸ�վ�������µ�վ�㣿\n���ڿ�ͷ������0Ŷ\n\t");
                                        fflush(stdout);
                                        scanf("%104s", str);clrbuf();
                                        long newstation_number = strtol(str, NULL, 10);
                                        if (newstation_number < 0)
                                            on_error();
                                        else
                                        {
                                            int j = 0;
                                            for (BusStop *jt = pt->value.root; jt->hou != NULL; jt = jt->hou)
                                            {
                                                if (j == newstation_number)
                                                {
                                                    char newstation_name[100];
                                                    printf("��������վ�������\n");
                                                    scanf("%99s", newstation_name);clrbuf();
                                                    buschain_insert(jt, newstation_name);
                                                }
                                                ++j;
                                            }
                                            if (j < newstation_number)
                                            {
                                                printf("ԭվ�㲻���ڣ�����ʧ��\n");
                                                fflush(stdout);
                                            } else
                                            {
                                                printf("�����ɹ�\n");
                                                fflush(stdout);
                                            }
                                        }
                                        break;
                                    }
                                    case 3://3.*�޸�һ��վ��*
                                    {
                                        printf("��(>__<) �롫�޸��ĸ�վ�㣿\n�޸����������0Ŷ\n\t");
                                        scanf("%104s", str);clrbuf();
                                        long changestation_number = strtol(str, NULL, 10);
                                        if (changestation_number < 0)
                                            on_error();
                                        else
                                        {
                                            char changestation_name[100];
                                            printf("��������վ�������\n");
                                            int j = 0;
                                            for (BusStop *jt = pt->value.root; jt->hou != NULL; jt = jt->hou)
                                            {
                                                if (j == changestation_number)
                                                {
                                                    scanf("%99s", changestation_name);clrbuf();
                                                    strcpy(jt->value, changestation_name);
//                                                    buschain_remove(jt);
//                                                    buschain_insert(jt, changestation_name);
                                                }
                                                ++j;
                                            }
                                            if (j < changestation_number)
                                            {
                                                printf("ԭվ�㲻���ڣ��޸�ʧ��\n");
                                                fflush(stdout);
                                            } else
                                            {
                                                printf("�����ɹ�\n");
                                                fflush(stdout);
                                            }
                                        }
                                        break;
                                    }
                                    case 4:
                                    {
                                        cont = 0;
                                        break;
                                    }
                                    default:
                                        on_error();
                                }
                                int j = 0;
                                printf("���º��·���ǣ�\n");
                                for (BusStop *jt = pt->value.root->hou; jt != NULL; jt = jt->hou)
                                {
                                    ++j;
                                    printf("%d:%s", j, jt->value);
                                    if (jt->hou != NULL)
                                    {
                                        printf("->");
                                    }
                                }
                                printf("\n");
                            }
                        }
                    } else
                    {
                        on_error();
                    }

                } else
                {
                    on_error();
                }
                break;
            case 8:
                printf("�Ƿ񱣴����ݣ� 1.��\t2.��\n");
                fflush(stdout);
                int new_number;
                scanf("%104s", str);clrbuf();
                new_number = strtol(str, NULL, 10);
                if (new_number == 1)
                {

                    printf("�������ļ���\n");
                    fflush(stdout);
                    char new_file[100];
                    scanf("%99s", new_file);clrbuf();
                    data_save(d, new_file);
                    printf("�����ѱ�������Ϊ%s���ļ�\n", new_file);
                    fflush(stdout);
                    return 0;
                } else if (new_number == 2)
                {
                    printf("����δ����");
                    fflush(stdout);
                    return 0;
                } else
                {
                    on_error();
                }
                break;

            default:
                on_error();
                fflush(stdout);
                break;
        }
    }
    // ����ֻ����while���˳�(return 0;)�����Բ���Ҫ�ڽ�βreturn
    // return 0;
}


void on_error()
{
    //printf("��úõضԴ���ϵͳ����Ȼ�ᱻ�滵��Ӵ\n");
    printf("*************FBI WARING**************\n"
           "*������Ҳ��ǰ�?                    *\n"
           "*Ҳ���������������˭д�����ģ�     *\n"
           "*����������Ĺ������������ʵ���� *\n"
           "*************************************\n"
           "#��#\t#��#\t#��#\t#��#\t#��#\t#��#\n"
           "#ϲ#\t#��#\t#��#\t#��#\t#Ϊ#\t#��#\n"
           "#��#\t#��#\t#Ҫ#\t#��#\t#��#\t#��#\n"
           "#ҵ#\t#��#\t#��#\t#��#\t2@ZFN\n");
    fflush(stdout);
}

void clrbuf()
{
    char t;
    do{
        t = getchar();
    }while(t != '\n' && t != EOF);
}