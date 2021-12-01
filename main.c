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

//array--代表数组

void on_error();
void clrbuf();

int main()
{
    char str[105];
    srand(time(NULL));
    printf("您是否想观看我们的宣传动画？\n\t1.观看\n\t2.取消\n");
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
        printf("注意事项：\n"
               "\t1.请不要输入长度超过99的字符串（如果你硬要这么做，可以，程序不会崩溃，但您超出的输入会被忽略。）\n"
               "\t2.请不要输入含有空格的名字（如果你硬要这么做，可以，程序不会崩溃，也不会影响后续输入，但您第一个空格起的字符会被忽略）\n"
               "如果您已仔细阅读本须知，请输入1\n");
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
        printf("您是否需要读取已保存的数据？\n"
               "\t1.是\n"
               "\t2.否\n");
        fflush(stdout);
        scanf("%104s", str);clrbuf();
        a = strtol(str, NULL, 10);

        char array[105];
        if (a == 1)
        {
            printf("请输入文件名：\n");
            fflush(stdout);
            scanf("%104s", array);clrbuf();
            d = data_from_file(array);
            if (d.error != 0)
            {
                printf("文件加载失败\n");
                on_error();
                fflush(stdout);
                continue;
            } else
            {
                break;
            }

        } else if (a == 2)
        {
            printf("请继续！ \n");
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
            printf("输入1继续使用本系统，输入其他数字保存并退出\n");
            fflush(stdout);
            long array;
            scanf("%104s", str);clrbuf();
            array = strtol(str, NULL, 10);
            if (array == 1)
            {
                printf("********************************\n    欢迎进入活力长者社区后台系统系统    \n********************************\n请确保在管理员的监督下使用本系统，否则将被视为非法操作\n");
                printf(
                        "*亲，请输入数字*\n"
                        "\t1.选择*会员管理*\n"
                        "\t2.选择*房屋管理*\n"
                        "\t3.选择*入住管理*\n"
                        "\t4.选择*场馆设施管理*\n"
                        "\t5.选择*服务人员管理*\n"
                        "\t6.选择*问题反映*\n"
                        "\t7.选择*班车线路管理*\n"
                        "\t8.保存数据及退出系统：\n");
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
            printf("********************************\n    欢迎进入活力长者社区系统    \n********************************\n");
            printf(
                    "*亲，请输入数字*\n"
                    "\t1.选择*会员管理*\n"
                    "\t2.选择*房屋管理*\n"
                    "\t3.选择*入住管理*\n"
                    "\t4.选择*场馆设施管理*\n"
                    "\t5.选择*服务人员管理*\n"
                    "\t6.选择*问题反映*\n"
                    "\t7.选择*班车线路管理*\n"
                    "\t8.保存数据及退出系统：\n");
            say_sentence();
            fflush(stdout);

            scanf("%104s", str);clrbuf();
            the_n = strtol(str, NULL, 10);
        }

        long n;
        switch (the_n)
        {
            case 1: //会员管理
                printf(
                        "您下一步想要干什么？\n"
                        "请输入相应数字：\n"
                        "\t1.选择*新建会员*\n"
                        "\t2.选择*查询会员*\n"
                        "\t3.选择*会员的删除与修改*\n"
                        "\t4.选择*返回上一级*\n");
                fflush(stdout);
                scanf("%104s", str);clrbuf();
                n = strtol(str, NULL, 10);
                if (n == 4)
                {

                } else
                {
                    if (n == 1)//1.选择*新建会员
                    {
                        char name[100] = "";
                        printf("输入会员名字：\n");
                        fflush(stdout);
                        scanf("%99s", name);clrbuf();
                        int new_id = people_list_push(&d.people_list, name);
                        printf("操作成功，您的会员ID为：%d\n", new_id);
                        fflush(stdout);
                    }
                    if (n == 2)//2.选择*查询会员*
                    {
                        printf("请的选择查询的方式\n"
                               "\t1.按ID查询\n"
                               "\t2.按名字查询\n"
                               "\t3.输出所有会员\n");
                        fflush(stdout);
                        scanf("%104s", str);clrbuf();
                        n = strtol(str, NULL, 10);
                        if (n == 1)
                        {
                            long ID;
                            printf("请输入您查询的ID:\n");
                            fflush(stdout);
                            scanf("%104s", str);clrbuf();
                            ID = strtol(str, NULL, 10);
                            int *ans_list = people_find_by_id(d.people_list, ID);
                            if (ans_list[0] == 0)
                            {
                                printf("该用户不存在\n");
                                fflush(stdout);
                            } else if(ans_list[0] == 1)
                            {
                                printf("用户ID:%ld\n姓名:%s\n", ID, people_list_at(d.people_list, ans_list[1])->name);
                            } else
                            {
                                printf("致命错误：ID重复！\n正在为您重建列表\n请注意，您不应该手动编辑数据文件\n");
                                pl_rebuild(&d.people_list);
                                //pl,hl,sl,fl
                                for (int i = 0; i < d.people_list.size; ++i)
                                    printf("用户ID:%d\n姓名:%s\n", people_list_at(d.people_list, i)->id, people_list_at(d.people_list, i)->name);
                                fflush(stdout);
                            }
                        } else if (n == 2)
                        {
                            char name[100];
                            int xiabiao;
                            printf("请输入需要查询的名字：\n");
                            fflush(stdout);
                            scanf("%99s", name);clrbuf();
                            xiabiao = people_find_by_name(d.people_list, name);
                            if (xiabiao < 0)
                            {
                                printf("该用户不存在\n");
                                fflush(stdout);
                            } else
                            {
                                printf("用户ID:%d\n姓名:%99s\n", people_list_at(d.people_list, xiabiao)->id, name);
                                fflush(stdout);
                            }
                        } else if (n == 3)
                        {
                            while (1)
                            {
                                for (int i = 0; i < d.people_list.size; i++)
                                {
                                    printf("第%d个用户\n\tID:%d\n\t姓名:%s\n", i + 1, people_list_at(d.people_list, i)->id,
                                           people_list_at(d.people_list, i)->name);
                                    fflush(stdout);
                                }
                                printf("您是否要再看一遍？1.确认\t2.取消\n");
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
                                    printf("输入错误，我猜您不想看了\n");
                                    fflush(stdout);
                                }
                            }
                        } else
                        {
                            on_error();
                        }
                    } else if (n == 3)//会员的删除与修改
                    {
                        printf("请输入会员ID:\n");
                        fflush(stdout);
                        //  根据编号选择要修改的会员
                        long xiabiao, ID;

                        scanf("%104s", str);clrbuf();
                        ID = strtol(str, NULL, 10);
                        xiabiao = people_find_by_id(d.people_list, ID);
                        if (xiabiao < 0)
                        {
                            printf("该用户不存在\n");
                            fflush(stdout);
                        } else
                        {
                            printf("用户ID:%d\n姓名:%s\n", people_list_at(d.people_list, xiabiao)->id,
                                   people_list_at(d.people_list, xiabiao)->name);
                            printf("请选择您的操作? 1.修改\t2.删除\t3.取消\n");
                            fflush(stdout);
                            int confirm;
                            scanf("%104s", str);clrbuf();
                            confirm = strtol(str, NULL, 10);
                            if (confirm == 1)
                            {
                                char new_name[100];
                                printf("请输入新的姓名\n");
                                fflush(stdout);
                                scanf("%99s", new_name);clrbuf();
                                strcpy(people_list_at(d.people_list, xiabiao)->name, new_name);
                                printf("操作成功，已重命名为%s\n", new_name);
                            } else if (confirm == 2)
                            {
                                people_list_delete(&d.people_list, xiabiao);
                                printf("删除成功\n");
                                fflush(stdout);
                            } else if (confirm == 3)
                            {
                                printf("取消成功\n");
                                fflush(stdout);
                            } else
                            {
                                printf("输入错误，我猜您不想改了\n");
                                on_error();
                                fflush(stdout);
                            }
                        }
                    }
                }
                break;

            case 2://选择*房屋管理*

                printf("您下一步想要干什么？\n"
                       "请输入相应数字：\n"
                       "\t1.选择*查看房屋基本情况*\n"
                       "\t2.选择*会员购买房屋办理*\n"
                       "\t3.选择*查询会员名下的房屋*\n"
                       "\t4.选择*返回上一级*\n");
                fflush(stdout);
                scanf("%104s", str);clrbuf();
                n = strtol(str, NULL, 10);
                if (n == 1)//1.选择*查看房屋基本情况*
                {
                    printf("我们的房屋都有权威机构的认证！请您放心！\n");
                    fflush(stdout);
                }
                if (n == 2)//2.选择*购买房屋*
                {
                    printf("购房者是否已经成为会员？\n"
                           "\t1.是\n"
                           "\t2.否\n");
                    fflush(stdout);
                    scanf("%104s", str);clrbuf();
                    n = strtol(str, NULL, 10);
                    if (n == 1)
                    {
                        printf("请输入会员ID：\n");
                        fflush(stdout);
                        int people_id;
                        scanf("%104s", str);clrbuf();
                        people_id = strtol(str, NULL, 10);
                        int xiabiao = people_find_by_id(d.people_list, people_id);
                        if (xiabiao < 0)
                        {
                            printf("该ID对应的会员不存在\n");
                            fflush(stdout);
                        } else
                        {
                            char name[100];
                            strcpy(name, people_list_at(d.people_list, xiabiao)->name);
                            printf("欢迎您，尊敬的会员:%s\n", name);
                            printf("您可以开始选择房屋了\n"
                                   "请输入您购买的房屋的名字！（名字请参见宣传手册）\n");
                            fflush(stdout);
                            char house_name[100];
                            scanf("%99s", house_name);clrbuf();
                            house_list_push(&d.house_list, house_name, people_id);
                            int new_id = house_list_push(&d.house_list, house_name, people_id);
                            printf("操作成功，感谢您的购买\n"
                                   "您的新房屋ID为%d\n", new_id);
                            fflush(stdout);
                            //TODO 您的新房屋的ID是：
                        }
                    } else if (n == 2)
                    {
                        printf("您还不是会员！\n"
                               "请返回首页注册会员以办理房屋购买！\n");
                        fflush(stdout);
                    } else
                    {
                        on_error();
                    }
                } else if (n == 3)//3.选择*查询房屋*
                {
                    printf("请输入您的ID\n");
                    fflush(stdout);
                    int people_id;
                    scanf("%104s", str);clrbuf();
                    people_id = strtol(str, NULL, 10);
                    int xiabiao = people_find_by_id(d.people_list, people_id);
                    if (xiabiao < 0)
                    {
                        printf("该ID对应的会员不存在\n");
                        fflush(stdout);
                    } else
                    {
                        for (int i = 0; i < d.house_list.size; i++)
                        {
                            int ID;

                            if (house_list_at(d.house_list, i)->owner == ID)
                            {
                                printf("第%d间房屋\n\tID:%d\n\t姓名:%s\n", i + 1, house_list_at(d.house_list, i)->id,
                                       house_list_at(d.house_list, i)->name);
                                fflush(stdout);
                            }
                        }
                    }
                }
                break;

            case 3://选择*入住管理*

                printf("您是否已经购买房屋？\n"
                       "\t1.是\n"
                       "\t2.否\n");
                fflush(stdout);

                scanf("%104s", str);clrbuf();
                n = strtol(str, NULL, 10);

                if (n == 1)//已购买房屋
                {
                    printf("请输入您的会员ID\n");
                    int people_id;
                    fflush(stdout);
                    scanf("%104s", str);clrbuf();
                    people_id = strtol(str, NULL, 10);
                    int xiabiao = people_find_by_id(d.people_list, people_id);
                    if (xiabiao < 0)
                    {
                        printf("该ID对应的会员不存在\n");
                        fflush(stdout);
                    } else
                    {
                        printf("请输入您名下房产的ID\n");
                        fflush(stdout);
                        int house_id;
                        scanf("%104s", str);clrbuf();
                        house_id = strtol(str, NULL, 10);
                        int xiabiao = house_find_by_id(d.house_list, house_id);
                        if (xiabiao < 0)
                        {
                            printf("该房屋不存在\n");
                            fflush(stdout);
                        } else
                        {
                            int is_his = 1;
                            for (int i = 0; i < d.house_list.size; i++)
                            {
                                if (house_list_at(d.house_list, i)->owner != people_id)
                                {
                                    printf("这根本就不是您的房子( ^ω^)\n");
                                    fflush(stdout);
                                    is_his = 0;
                                    break;
                                }
                            }// TODO 只有在拥有专属服务人员的情况下才能入住房屋
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
                                printf("您还没有专属服务人员\n"
                                       "本公司提供优质的专属服务\n"
                                       "时刻保障您的财产安全\n"
                                       "请先选择您的服务人员以享受我们的服务\n");
                                fflush(stdout);
                                continue;
                            }
                            printf("%d号服务人员%s竭诚为您服务\n", servant_list_at(d.servant_list, servant_xiabiao)->id,
                                   servant_list_at(d.servant_list, servant_xiabiao)->name);
                            printf("您将更新房屋的入住信息\n"
                                   "\t1.*本人入住*\n"
                                   "\t2.*出租*\n"
                                   "\t3.*空置*: \n");
                            fflush(stdout);
                            scanf("%104s", str);clrbuf();
                            n = strtol(str, NULL, 10);
                            if (n == 1)
                            {
                                house_list_at(d.house_list, xiabiao)->type = 1;
                                printf("欢迎入住\n");
                                fflush(stdout);
                            } else if (n == 2)
                            {
                                printf("请输入您希望出租对象的ID\n");
                                fflush(stdout);
                                int rent_id, xiabiao;
                                scanf("%104s", str);clrbuf();
                                rent_id = strtol(str, NULL, 10);
                                xiabiao = people_find_by_id(d.people_list, rent_id);
                                if (xiabiao < 0)
                                {
                                    printf("该用户不存在\n");
                                    fflush(stdout);
                                } else
                                {
                                    house_list_at(d.house_list, xiabiao)->type = 2;
                                    house_list_at(d.house_list, xiabiao)->tenant = rent_id;
                                    printf("操作成功，您的房屋信息已更改为出租中，出租对象的ID为%d\n", rent_id);
                                    fflush(stdout);
                                }
                            } else if (n == 3)
                            {
                                house_list_at(d.house_list, xiabiao)->type = 0;
                                printf("操作成功，您的ID为%d的房屋信息已更改为闲置中\n", house_id);
                                fflush(stdout);
                            } else
                            {
                                on_error();
                            }
                        }
                    }
                } else if (n == 2)//在是否购买房屋中选择否
                {
                    printf("滚去买\n");
                    fflush(stdout);
                } else
                {
                    on_error();
                }
                break;
            case 4://4.选择*场馆设施管理*

                printf("请选择您的操作：\n"
                       "\t1.*用户：申请使用娱乐设施*\n"
                       "\t2.*管理人员：管理娱乐设施*\n");
                fflush(stdout);
                scanf("%104s", str);clrbuf();
                n = strtol(str, NULL, 10);
                if (n == 1)
                {
                    printf("您想要使用申请娱乐设施吗？\n"
                           "1.是\n"
                           "2.否\n");
                    fflush(stdout);
                    scanf("%104s", str);clrbuf();
                    n = strtol(str, NULL, 10);
                    if (n == 1)
                    {
                        printf("您想要申请使用什么娱乐设施？\n"
                               "请输入娱乐设施的名字\n");
                        fflush(stdout);
                        char f_name[100];
                        scanf("%99s", f_name);clrbuf();
                        int xiabiao = facility_find_by_name(d.facility_list, f_name);
                        if (xiabiao < 0)
                        {
                            printf("该娱乐设施不存在，如有需要请先申请\n");
                        } else
                        {
                            printf("使用成功\n");
                        }
                    }//TODO 陈骁恒的工作（输入，查找并判断是否有该娱乐设施，如果有则输出使用成功，否则输出无次设施，如有需要，请先申请）
                } else if (n == 2)
                {
                    printf("您想要对娱乐设施进行哪项操作？\n"
                           "\t1.查询\n"
                           "\t2.添加\n"
                           "\t3.修改或删除\n");
                    fflush(stdout);
                    int confirm_number;
                    scanf("%104s", str);clrbuf();
                    confirm_number = strtol(str, NULL, 10);
                    if (confirm_number == 1)//1.查询设施
                    {
                        printf("您想以哪种方式查询娱乐设施？\n"
                               "\t1.按ID查询\n"
                               "\t2.按名称查询\n"
                               "\t3.输出所有设施\n"
                               "注意：输入其它数字将返回上一级\n");
                        fflush(stdout);
                        int c_number;
                        scanf("%104s", str);clrbuf();
                        c_number = strtol(str, NULL, 10);
                        if (c_number == 1)//1.按ID查询
                        {
                            printf("请输入您想查询的娱乐设施ID\n");
                            fflush(stdout);
                            int f_id;
                            scanf("%104s", str);clrbuf();
                            f_id = strtol(str, NULL, 10);
                            int xiabiao = facility_find_by_id(d.facility_list, f_id);
                            if (xiabiao < 0)
                            {
                                printf("该ID对应的娱乐设施不存在\n");
                                fflush(stdout);
                            } else
                            {
                                Facility *t = facility_list_at(d.facility_list, xiabiao);
                                printf("设施ID:%d\t设施名称:%s\n", t->id, t->name);
                                fflush(stdout);
                            }
                        } else if (c_number == 2)//2.按名称查询
                        {
                            printf("请输入您想查询的娱乐设施名称\n");
                            fflush(stdout);
                            char f_name[100];
                            scanf("%99s", f_name);clrbuf();
                            printf("下面是查询结果\n");
                            fflush(stdout);
                            for (int i = 0; i < d.facility_list.size; i++)
                            {
                                if (strcmp(facility_list_at(d.facility_list, i)->name, f_name) == 0)
                                {
                                    Facility *t = facility_list_at(d.facility_list, i);
                                    printf("设施ID:%d\t设施名称:%s\n", t->id, t->name);
                                    fflush(stdout);
                                }
                            }
                            printf("查询完毕，以上为所有查询结果\n");
                            fflush(stdout);
                        } else if (c_number == 3)//3.输出所有设施
                        {
                            for (int i = 0; i < d.facility_list.size; i++)
                            {
                                Facility *t = facility_list_at(d.facility_list, i);
                                printf("设施ID:%d\t设施名称:%s\n", t->id, t->name);
                                fflush(stdout);
                            }
                        } else
                        {
                            on_error();
                        }
                    } else if (confirm_number == 2)//2.添加娱乐设施
                    {
                        char f_name[100];
                        printf("请输入您想要添加的娱乐设施的名称\n");
                        fflush(stdout);
                        scanf("%99s", f_name);clrbuf();
                        int new_id = facility_list_push(&d.facility_list, f_name);
                        printf("已成功添加名为%s的设施,其ID为%d\n", f_name, new_id);
                    } else if (confirm_number == 3)//3.修改或删除
                    {
                        printf("请输入设施ID:\n");
                        fflush(stdout);
                        int xiabiao, ID;
                        scanf("%104s", str);clrbuf();
                        ID = strtol(str, NULL, 10);
                        xiabiao = facility_find_by_id(d.facility_list, ID);
                        if (xiabiao < 0)
                        {
                            printf("该设施不存在\n");
                        } else
                        {
                            printf("设施ID:%d\n名称:%s\n", facility_list_at(d.facility_list, xiabiao)->id,
                                   facility_list_at(d.facility_list, xiabiao)->name);
                            printf("请选择您的操作? 1.修改\t2.删除\t3.取消\n");
                            fflush(stdout);
                            int confirm;
                            scanf("%104s", str);clrbuf();
                            confirm = strtol(str, NULL, 10);
                            if (confirm == 1)
                            {
                                char new_name[100];
                                printf("请输入新的设施名称\n");
                                fflush(stdout);
                                scanf("%99s", new_name);clrbuf();
                                strcpy(facility_list_at(d.facility_list, xiabiao)->name, new_name);
                                printf("操作成功，设施已重命名为%s\n", new_name);
                            } else if (confirm == 2)
                            {
                                facility_list_delete(&d.facility_list, xiabiao);
                                printf("删除成功\n");
                                fflush(stdout);
                            } else if (confirm == 3)
                            {

                            } else
                            {
                                printf("输入错误，我猜您不想改了\n");
                                on_error();
                            }
                        }
                    } else
                    {
                        on_error();
                    }
                }
                break;
            case 5://5.选择*服务人员管理*

                printf("请选择您的操作：\n"
                       "1.编辑服务人员信息\n"
                       "2.修改用户的服务人员\n");
                fflush(stdout);
                char name2[100];
                if (n == 1)
                {
                    printf("您下一步想干什么？\n"
                           "1.*查询服务人员信息*\n"
                           "2.*注册服务人员*\n"
                           "3.*修改服务人员信息*\n"
                           "4.*删除服务人员*\n"
                           "5.*点错了*\n");
                    fflush(stdout);
                    scanf("%104s", str);clrbuf();
                    n = strtol(str, NULL, 10);
                    if (n == 1)
                    {

                    } else if (n == 2)
                    {
                        printf("请输入您的姓名：\n");
                        fflush(stdout);
                        scanf("%99s", name2);clrbuf();
                        int new_id = servant_list_push(&d.servant_list, name2);
                        printf("注册成功，您的ID为%d", new_id);
                    } else if (n == 3)
                    {
                        printf("请输入您的ID：\n");
                        fflush(stdout);
                        int s_id;

                        scanf("%104s", str);clrbuf();
                        s_id = strtol(str, NULL, 10);
                        int xiabiao = servant_find_by_id(d.servant_list, s_id);
                        if (xiabiao < 0)
                        {
                            printf("该服务人员不存在\n");
                            fflush(stdout);
                        } else
                        {
                            char new_name[100];
                            printf("请输入新的名称\n");
                            fflush(stdout);
                            scanf("%99s", new_name);clrbuf();
                            strcpy(facility_list_at(d.facility_list, xiabiao)->name, new_name);
                            printf("操作成功，ID为%d的服务人员已重命名为%s\n", s_id, new_name);
                        }
                    } else if (n == 4)
                    {
                        printf("请输入您的姓名：\n");
                        fflush(stdout);
                        char your_name[100];
                        scanf("%99s", your_name);clrbuf();
                        int xiabiao = servant_find_by_name(d.servant_list, your_name);
                        if (xiabiao < 0)
                        {
                            printf("该服务人员不存在\n");
                            fflush(stdout);
                        } else
                        {
                            facility_list_delete(&d.facility_list, xiabiao);
                            printf("删除成功\n");
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
                    printf("请选择您的操作\n"
                           "\t1.查询您的服务人员\n"
                           "\t2.修改您的服务人员\n"
                           "\t3.删除您的服务人员\n"
                           "\t4.退出\n");
                    scanf("%104s", str);clrbuf();
                    long x = strtol(str, NULL, 0);
                    switch (x)
                    {
                        case 1://1.查询您的服务人员
                        {
                            //for()
                            break;
                        }
                        case 2://2.修改您的服务人员
                        {
                            break;
                        }
                        case 3://删除您的服务人员
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
            case 6://6.选择*问题反映*

                printf("登陆 https://www.icourse163.org/learn/NEU-1002745019 获得更多帮助\n"
                       "添加客服微信：川酱今天吃什么：zhangyichuan_33获取一对一帮助\n");
                fflush(stdout);
                break;
            case 7:

                printf("您想进行什么操作？\n"
                       "1.查看班车路线\n"
                       "2.添加班车路线\n"
                       "3.删除班车路线\n"
                       "4.修改班车路线\n"
                );
                fflush(stdout);
                scanf("%104s", str);clrbuf();
                n = strtol(str, NULL, 10);
                if (n == 1)//1.查看班车路线
                {
                    printf("1.*查看某条班车路线*\n"
                           "2.*查看全部路线*\n");
                    fflush(stdout);
                    scanf("%104s", str);clrbuf();
                    long c_number = strtol(str, NULL, 10);
                    if (c_number == 1)
                    {
                        printf("你要查看第几条的班车路线？（不清楚的话可以输入-1返回并查询全部路线）\n");
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
                            printf("第%d条线路：", i);
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
                } else if (n == 2)//2.添加班车路线
                {
                    printf("请输入站点数量：\n");
                    fflush(stdout);
                    scanf("%104s", str);clrbuf();
                    n = strtol(str, NULL, 10);
                    printf("请输入站点名字（以空格分隔）：\n");
                    fflush(stdout); // TODO 陈骁恒，这里根据输入的数量循环读入站点名字
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
                } else if (n == 3)//3.删除班车路线
                {
                    printf("请问您要删除第几条线路\n\t"
                           "（不清楚的话可以输入-1来返回并通过查询功能查看线路列表哦）\n");
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
                                printf("该线路已删除\n");
                                break;
                            }
                        }
                        if (i < d_number)
                        {
                            printf("删除失败，该路线不存在\n");
                        }
                    } else
                        on_error();
                } else if (n == 4)//4.修改班车路线
                {
                    printf("请问您要修改第几条线路\n"
                           "（不清楚的话可以输入-1来返回并通过查询功能查看线路列表哦）");
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
                            printf("没有这条线路\n");
                        }//大括号打上
                        else
                        {
                            int cont = 1;
                            while (cont)
                            {
                                //让他先输入操作，再输入第几站
                                printf("请选择您的操作：\n"
                                       "1.*删除一个站点*\n"
                                       "2.*插入一个站点*\n"
                                       "3.*修改一个站点*\n"
                                       "4.*结束修改*\n");
                                fflush(stdout);
                                scanf("%104s", str);clrbuf();
                                n = strtol(str, NULL, 10);
                                switch (n)
                                {
                                    case 1://1.*删除一个站点
                                    {
                                        printf("请输入您想要删除的站点号：\n");
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
                                    case 2://2.*插入一个站点*
                                    {
                                        printf("您(>__<) 想～在哪个站点后插入新的站点？\n插在开头请输入0哦\n\t");
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
                                                    printf("请输入新站点的名称\n");
                                                    scanf("%99s", newstation_name);clrbuf();
                                                    buschain_insert(jt, newstation_name);
                                                }
                                                ++j;
                                            }
                                            if (j < newstation_number)
                                            {
                                                printf("原站点不存在，插入失败\n");
                                                fflush(stdout);
                                            } else
                                            {
                                                printf("操作成功\n");
                                                fflush(stdout);
                                            }
                                        }
                                        break;
                                    }
                                    case 3://3.*修改一个站点*
                                    {
                                        printf("您(>__<) 想～修改哪个站点？\n修改起点请输入0哦\n\t");
                                        scanf("%104s", str);clrbuf();
                                        long changestation_number = strtol(str, NULL, 10);
                                        if (changestation_number < 0)
                                            on_error();
                                        else
                                        {
                                            char changestation_name[100];
                                            printf("请输入新站点的名称\n");
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
                                                printf("原站点不存在，修改失败\n");
                                                fflush(stdout);
                                            } else
                                            {
                                                printf("操作成功\n");
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
                                printf("更新后的路线是：\n");
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
                printf("是否保存数据？ 1.是\t2.否\n");
                fflush(stdout);
                int new_number;
                scanf("%104s", str);clrbuf();
                new_number = strtol(str, NULL, 10);
                if (new_number == 1)
                {

                    printf("请输入文件名\n");
                    fflush(stdout);
                    char new_file[100];
                    scanf("%99s", new_file);clrbuf();
                    data_save(d, new_file);
                    printf("数据已保存至名为%s的文件\n", new_file);
                    fflush(stdout);
                    return 0;
                } else if (new_number == 2)
                {
                    printf("数据未保存");
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
    // 程序只会在while中退出(return 0;)，所以不需要在结尾return
    // return 0;
}


void on_error()
{
    //printf("请好好地对待本系统，不然会被玩坏的哟\n");
    printf("*************FBI WARING**************\n"
           "*你故意找茬是吧?                    *\n"
           "*也不看看这个代码是谁写出来的！     *\n"
           "*跟我宁丰猪的狗斗，你有这个实力吗？ *\n"
           "*************************************\n"
           "#丰#\t#宁#\t#我#\t#真#\t#的#\t#好#\n"
           "#喜#\t#欢#\t#你#\t#啊#\t#为#\t#了#\n"
           "#你#\t#我#\t#要#\t#在#\t#大#\t#作#\n"
           "#业#\t#里#\t#发#\t#病#\t2@ZFN\n");
    fflush(stdout);
}

void clrbuf()
{
    char t;
    do{
        t = getchar();
    }while(t != '\n' && t != EOF);
}