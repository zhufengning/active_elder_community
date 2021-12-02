#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* People是用链表写的，其他结构是写的变长数组，别问，问就是想尝试多种写法！！！ */

#include "people.h"
#include "facility.h"
#include "servant.h"
#include "house.h"
#include "say.h"
// 然而bus也是用的链表，还是二维链表
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
            printf("输入1继续使用本系统，输入其他数字保存并退出\n");
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
            case 7:
                bus_manage(&the_variable_that_saves_all_our_data);
                break;
            case 8:
                if (save_and_exit(&the_variable_that_saves_all_our_data))
                    break;
                else return 0;

            default:
                on_error();
                break;
        }
    }
    // 程序只会在while中退出(return 0;)，所以不需要在结尾return
    // return 0;
}
