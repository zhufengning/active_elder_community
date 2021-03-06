/*******************************************
 * This file should be encoded with GB2312 *
 *******************************************/
/*
 * 在vs 2022，codeblocks20.03，gcc 11，clang 13下可直接编译，若版本略有不同，亦可尝试。
 * 注意，在用codeblocks编译时，请只将main.c添加到工程(加了些宏定义，应该也可以添加所有文件了)。
 * 文件中包含 CMakeLists.txt，使用VS，CLion，配置好CMake的Qt Creator等支持CMake的IDE，
 * 直接打开CMakeLists.txt所在的文件夹，可自动配置好项目，此后直接运行即可。
 * 以VS为例，选择文件-打开-文件夹（而不是项目），即可运行；
 * 或者选择文件-打开-CMake，然后在本项目的文件夹中选择CMakeLists.txt。
 * 如果使用的编译器版本较老（默认使用c89标准的），可能编译失败，请在编译命令中加上-std=c99
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
// bus用的链表，还是二维链表
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
            printf("输入1继续使用本系统，输入其他东西退出并选择是否保存数据\n");
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
            case 1: //会员管理
                vip_manage(&the_variable_that_saves_all_our_data);
                break;
            case 2://选择*房屋管理*
                house_manage(&the_variable_that_saves_all_our_data);
                break;
            case 3://选择*入住管理*
                live_manage(&the_variable_that_saves_all_our_data);
                break;
            case 4://4.选择*场馆设施管理*
                facility_manage(&the_variable_that_saves_all_our_data);
                break;
            case 5://5.选择*服务人员管理*
                servant_manage(&the_variable_that_saves_all_our_data);
                break;
            case 6://6.选择*问题反映*
                printf("登陆 https://www.icourse163.org/learn/NEU-1002745019 获得更多帮助\n"
                       "添加客服微信：川酱今天吃什么：zhangyichuan_33 获取一对一帮助\n");
                fflush(stdout);
                break;
            case 7://7.选择*班车线路管理*
                bus_manage(&the_variable_that_saves_all_our_data);
                break;
            case 8://8.保存数据及退出系统
                if (save_and_exit(&the_variable_that_saves_all_our_data))
                    break;
                else
                {
                    printf("按回车退出\n");
                    fflush(stdout);
                    clrbuf();
                    return 0;
                }

            default:
                on_error();
                break;
        }
    }
    // 程序只会在while中退出(return 0;)，所以不需要在结尾return
    // return 0;
}
