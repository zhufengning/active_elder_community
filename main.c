/*******************************************
 * This file should be encoded with GB2312 *
 *******************************************/
/*
 * ��vs 2022��codeblocks20.03��gcc 11��clang 13�¿�ֱ�ӱ��룬���汾���в�ͬ����ɳ��ԡ�
 * ע�⣬����codeblocks����ʱ����ֻ��main.c��ӵ�����(����Щ�궨�壬Ӧ��Ҳ������������ļ���)��
 * �ļ��а��� CMakeLists.txt��ʹ��VS��CLion�����ú�CMake��Qt Creator��֧��CMake��IDE��
 * ֱ�Ӵ�CMakeLists.txt���ڵ��ļ��У����Զ����ú���Ŀ���˺�ֱ�����м��ɡ�
 * ��VSΪ����ѡ���ļ�-��-�ļ��У���������Ŀ�����������У�
 * ����ѡ���ļ�-��-CMake��Ȼ���ڱ���Ŀ���ļ�����ѡ��CMakeLists.txt��
 * ���ʹ�õı������汾���ϣ�Ĭ��ʹ��c89��׼�ģ������ܱ���ʧ�ܣ����ڱ��������м���-std=c99
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "people.h"
#include "facility.h"
#include "servant.h"
#include "house.h"
#include "say.h"
// bus�õ��������Ƕ�ά����
#include "bus.h"
#include "storage.h"
#include "managing.h"

//INPUT_DATA is a string defined in managing.h, used to input string and then convert to an integer
int main()
{
    Data the_variable_that_saves_all_our_data = data_new();
    int fst_time = 1;
    srand(time(NULL));

    ani_play();
    readme();
    open_data(&the_variable_that_saves_all_our_data);

    while (1)
    {
        long the_n;
        if (!fst_time)
        {
            printf("����1����ʹ�ñ�ϵͳ���������������˳���ѡ���Ƿ񱣴�����\n");
            fflush(stdout);
            long cont;
            scanf("%104s", INPUT_DATA);
            clrbuf();
            cont = strtol(INPUT_DATA, NULL, 10);
            if (cont == 1)
            {
                show_menu();
                scanf("%104s", INPUT_DATA);
                clrbuf();
                the_n = strtol(INPUT_DATA, NULL, 10);
            } else the_n = 8;
        } else
        {
            fst_time = 0;
            show_menu();
            scanf("%104s", INPUT_DATA);
            clrbuf();
            the_n = strtol(INPUT_DATA, NULL, 10);
        }
        switch (the_n)
        {
            case 1: //��Ա����
                vip_manage(&the_variable_that_saves_all_our_data);
                break;
            case 2://ѡ��*���ݹ���*
                house_manage(&the_variable_that_saves_all_our_data);
                break;
            case 3://ѡ��*��ס����*
                live_manage(&the_variable_that_saves_all_our_data);
                break;
            case 4://4.ѡ��*������ʩ����*
                facility_manage(&the_variable_that_saves_all_our_data);
                break;
            case 5://5.ѡ��*������Ա����*
                servant_manage(&the_variable_that_saves_all_our_data);
                break;
            case 6://6.ѡ��*���ⷴӳ*
                printf("��½ https://www.icourse163.org/learn/NEU-1002745019 ��ø������\n"
                       "��ӿͷ�΢�ţ����������ʲô��zhangyichuan_33 ��ȡһ��һ����\n");
                fflush(stdout);
                break;
            case 7://7.ѡ��*�೵��·����*
                bus_manage(&the_variable_that_saves_all_our_data);
                break;
            case 8://8.�������ݼ��˳�ϵͳ
                if (save_and_exit(&the_variable_that_saves_all_our_data))
                    break;
                else
                {
                    printf("���س��˳�\n");
                    fflush(stdout);
                    clrbuf();
                    return 0;
                }

            default:
                on_error();
                break;
        }
    }
    // ����ֻ����while���˳�(return 0;)�����Բ���Ҫ�ڽ�βreturn
    // return 0;
}
