#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* People是用链表写的，其他结构是写的变长数组，别问，问就是想尝试多种写法！！！ */

#include "people.h"
#include "facility.h"
#include "servant.h"
#include "house.h"

// 然而bus也是用的链表，还是二维链表
#include "bus.h"

#include "storage.h"

//sz--代表数组
//readme里的代码规范形同虚设了是吧--zfn
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

    printf("系统加载中。。。\n");
    fflush(stdout);
    for (int i = 1; i <= 3e8; ++i);
    printf("本系统由最优秀的工程师经过多年研发，倾力打造，只求给您最完美的体验。。\n");
    for (int i = 1; i <= 5e8; ++i);
    fflush(stdout);
    printf("3..");
    fflush(stdout);
    for (int i = 1; i <= 5e8; ++i);
    printf("2..");
    fflush(stdout);
    for (int i = 1; i <= 5e8; ++i);
    printf("1..\n");
    fflush(stdout);
    for (int i = 1; i <= 5e8; ++i);
    Data d = data_new();
    int a;
    while (1)
    {
        printf("您是否需要读取已保存的数据？\n"
               "1.是\n"
               "2.否\n");
        fflush(stdout);
        scanf("%d", &a);
        char sz[100];
        if (a == 1)
        {
            printf("请输入文件名：\n");
            scanf("%s", sz);
            d = data_from_file(sz);
            if (d.error != 0)
            {
                printf("文件加载失败\n");
                continue;
            } else
            {
                break;
            }

        } else if (a == 2)
        {
            printf("请继续！ \n");
            break;
        }
    }
    int fst_time = 1;
    while (1)
    {

        int n;
        if (!fst_time)
        {
            printf("输入1继续使用本系统，输入其他数字保存并退出\n");
            fflush(stdout);
            int sz;
            scanf("%d", &sz);
            if (sz == 1)
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
                scanf("%d", &n);
            } else
            {
                n = 8;
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
            fflush(stdout);
            scanf("%d", &n);
        }


        if (n == 1) //会员管理
        {
            printf(
                    "您下一步想要干什么？\n"
                    "请输入相应数字：\n"
                    "\t1.选择*新建会员*\n"
                    "\t2.选择*查询会员*\n"
                    "\t3.选择*会员的删除与修改*\n"
                    "\t4.选择*返回上一级*\n");
            fflush(stdout);
            scanf("%d", &n);
            if (n == 4)
            {

            } else
            {
                if (n == 1)//1.选择*新建会员
                {
                    char name[100];
                    printf("输入会员名字：\n");
                    fflush(stdout);
                    scanf("%s", name);
                    people_list_push(&d.people_list, name);
                }
                if (n == 2)//2.选择*查询会员*
                {
                    printf("请的选择查询的方式\n"
                           "1.按ID查询\n"
                           "2.按名字查询\n"
                           "3.输出所有会员\n");
                    fflush(stdout);
                    scanf("%d", &n);
                    if (n == 1)
                    {
                        int ID, xiabiao;
                        printf("请输入您查询的ID:\n");
                        fflush(stdout);
                        scanf("%d", &ID);
                        xiabiao = people_find_by_id(d.people_list, ID);
                        if (xiabiao < 0)
                        {
                            printf("该用户不存在\n");
                        } else
                        {
                            printf("用户ID:%d\n姓名:%s\n", ID, people_list_at(d.people_list, xiabiao)->name);
                        }
                    }
                    else if (n == 2)
                    {
                        char name[100];
                        int xiabiao;
                        printf("请输入需要查询的名字：\n");
                        fflush(stdout);
                        scanf("", name);
                        xiabiao = people_find_by_name(d.people_list, name);
                        if (xiabiao < 0)
                        {
                            printf("该用户不存在\n");
                        } else
                        {
                            printf("用户ID:%d\n姓名:%s\n", people_list_at(d.people_list, xiabiao)->id, name);
                        }
                    }
                    else if (n == 3)
                    {
                        while (1)
                        {
                            for (int i = 0; i < d.people_list.size; i++)
                            {
                                printf("第%d个用户\n\tID:%d\n\t姓名:%s\n", i + 1, people_list_at(d.people_list, i)->id,
                                       people_list_at(d.people_list, i)->name);
                            }
                            printf("您是否要再看一遍？1.确认\t2.取消\n");
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
                                printf("输入错误，我猜您不想看了\n");
                            }
                        }
                    }
                } else if (n == 3)//会员的删除与修改
                {
                    printf("请输入会员ID:\n");
                    fflush(stdout);
                    //  根据编号选择要修改的会员
                    int xiabiao, ID, name;
                    scanf("%d\n", ID);
                    xiabiao = people_find_by_id(d.people_list, ID);
                    if (xiabiao < 0)
                    {
                        printf("该用户不存在\n");
                    } else
                    {
                        printf("用户ID:%d\n姓名:%s\n", people_list_at(d.people_list, xiabiao)->id, name);
                        printf("是否确认修改? 1.确认\t2.取消\n");//TODO 这里少了个删除
                        int confirm;
                        scanf("%d\n", &confirm);
                        if (confirm == 2)
                        {

                        } else if (confirm == 1)
                        {
                            int new_name;
                            printf("请输入新的姓名\n");
                            scanf("%d\n", new_name);
                            strcpy(people_list_at(d.people_list, xiabiao)->name, new_name);
                        } else
                        {
                            printf("输入错误，我猜您不想改了\n");
                        }
                    }
                }
            }
        } else if (n == 2)//选择*房屋管理*
        {
            printf("您下一步想要干什么？\n"
                   "请输入相应数字：\n"
                   "\t1.选择*查看房屋基本情况*\n"
                   "\t2.选择*会员购买房屋办理*\n"
                   "\t3.选择*查询会员名下的房屋*\n"
                   "\t4.选择*返回上一级*\n");
            fflush(stdout);
            scanf("%d", &n);
            if (n == 1)//1.选择*查看房屋基本情况*
            {
                printf("我们的房屋都有权威机构的认证！请您放心！\n");
                fflush(stdout);
            }
            if (n == 2)//2.选择*购买房屋*
            {
                printf("购房者是否已经成为会员？\n"
                       "1.是\n"
                       "2.否\n");
                fflush(stdout);
                scanf("%d", &n);
                if (n == 1)
                {
                    printf("请输入您的ID：\n");
                    fflush(stdout);
                    int people_id;
                    scanf("%d", &people_id);
                    int xiabiao = people_find_by_id(d.people_list, people_id);
                    if (xiabiao < 0)
                    {
                        printf("该ID对应的会员不存在\n");
                    } else
                    {
                        char name[100];
                        strcpy(name, people_list_at(d.people_list, xiabiao)->name);
                        printf("欢迎您，尊敬的会员:%s\n", name);
                        printf("您可以开始选择房屋了\n"
                               "请输入您购买的房屋的名字！（名字请参见宣传手册）\n");
                        fflush(stdout);
                        char house_name[100];
                        scanf("%s", house_name);
                        house_list_push(&d.house_list, house_name, people_id);
                        printf("操作成功，感谢您的购买\n");
                    }
                }
                else if (n == 2)
                {
                    printf("您还不是会员！\n"
                           "请返回首页注册会员以办理房屋购买！\n");
                    fflush(stdout);
                }
            } else if (n == 3)//3.选择*查询房屋*
            {
                int ID;
                printf("请输入您的ID\n");
                fflush(stdout);
                int people_id;
                scanf("%d", &people_id);
                int xiabiao = people_find_by_id(d.people_list, people_id);
                if (xiabiao < 0)
                {
                    printf("该ID对应的会员不存在\n");
                } else
                {
                    for (int i = 0; i < d.house_list.size; i++)
                    {
                        if (house_list_at(d.house_list, i)->owner == ID)
                        {
                            printf("第%d间房屋\n\tID:%d\n\t姓名:%s\n", i + 1, house_list_at(d.house_list, i)->id,
                                   house_list_at(d.house_list, i)->name);
                        }
                    }
                }
            }

        } else if (n == 3)//选择*入住管理*
        {
            printf("您是否已经购买房屋？\n"
                   "1.是\n"
                   "2.否\n");
            fflush(stdout);
            scanf("%d", &n);
            if (n == 1)
            {
                printf("请输入您房屋的ID\n");
                fflush(stdout);
                int house_id;
                scanf("%d", &house_id);
                int xiabiao = house_find_by_id(d.house_list, house_id);
                if (xiabiao < 0)
                {
                    printf("该房屋不存在\n");
                    continue;
                }
                // TODO 只有在拥有专属服务人员的情况下才能入住房屋
                printf("您将更新房屋的入住信息\n"
                       "1.*本人入住*\n"
                       "2.*出租*\n"
                       "3.*空置*: \n");
                fflush(stdout);
                scanf("%d", &n);
                if (n == 1)
                {
                    house_list_at(d.house_list, xiabiao)->type = 1;
                    printf("欢迎入住\n");
                } else if (n == 2)
                {
                    printf("请输入您希望出租对象的ID\n");
                    fflush(stdout);
                    int rent_id, xiabiao;
                    scanf("%d", &rent_id);
                    xiabiao = people_find_by_id(d.people_list, rent_id);
                    if (xiabiao < 0)
                    {
                        printf("该用户不存在\n");
                    } else
                    {
                        house_list_at(d.house_list, xiabiao)->type = 2;
                        house_list_at(d.house_list, xiabiao)->tenant = rent_id;
                        printf("操作成功，您的房屋信息已更改为出租中，出租对象的ID为%d\n", rent_id);
                    }
                }
                else if (n == 3)
                {
                    house_list_at(d.house_list, xiabiao)->type = 0;
                    printf("操作成功，您的ID为%d的房屋信息已更改为闲置中\n", house_id);
                }
            } else if (n == 2)//在是否购买房屋中选择否
            {
            }
        } else if (n == 4)//4.选择*场馆设施管理*
        {
            printf("请选择您的身份：\n"
                   "1.*我是用户*\n"
                   "2.*我是管理人员*\n");
            fflush(stdout);
            scanf("%d", &n);
            if (n == 1)
            {
                printf("您想要使用申请娱乐设施吗？\n"
                       "1.是\n"
                       "2.否\n");
                fflush(stdout);
                scanf("%d", &n);
                if (n == 1)
                {
                    printf("您想要申请使用什么娱乐设施？\n"
                           "请输入娱乐设施的名字\n");
                    fflush(stdout);
                }//TODO 陈骁恒的工作（输入，查找并判断是否有该娱乐设施，如果有则输出使用成功，否则输出无次设施，如有需要，请先申请）
            }
            if (n == 2)
            {
                printf("您想要申请使用什么娱乐设施？\n"
                       "请输入娱乐设施的名字\n");
                fflush(stdout);
            }//TODO 陈骁恒的工作
        } else if (n == 5)//5.选择*服务人员管理*
        {
            printf("请选择您的身份：\n"
                   "1.服务人员或工作人员\n"
                   "2.用户\n");
            fflush(stdout);
            char name2[100];
            if (n == 1)
            {
                printf("您下一步想干什么？\n"
                       "1.*注册服务人员*\n"
                       "2.*修改服务人员信息*\n"
                       "3.*删除服务人员*\n"
                       "4.*点错了*\n");
                fflush(stdout);
                scanf("%d", &n);
                if (n == 1)
                {
                    printf("请输入您的姓名：\n");
                    fflush(stdout);
                    scanf("%s", name2);
                }

                    // TODO 陈骁恒的工作
                else if (n == 2)
                {
                    printf("请输入您的姓名：\n");
                    fflush(stdout);
                } else if (n == 3)
                {
                    printf("请输入您的姓名：\n");
                    fflush(stdout);
                }
                    // TODO 陈骁恒的工作
                    //见servant.h
                else if (n == 4)
                {}
            }
        } else if (n == 6)//6.选择*问题反映*
        {
            printf("登陆 https://www.icourse163.org/learn/NEU-1002745019 获得更多帮助\n"
                   "添加客服微信：川酱今天吃什么：zhangyichuan_33获取一对一帮助\n");
        } else if (n == 7)
        {
            printf("您想进行什么操作？\n"
                   "1.查看班车路线\n"
                   "2.添加班车路线\n"
                   "3.删除班车路线\n"
                   "4.修改班车路线\n"
            );
            fflush(stdout);
            scanf("%d", n);
            if (n == 1)
            {
                printf("1.*查看某条班车路线*\n"
                       "2.*查看全部路线*\n");
                fflush(stdout);
            }
            if (n == 2)
            {
                printf("请输入站点数量：\n");
                fflush(stdout);
                scanf("%d", &n);

                printf("请输入站点名字：\n");
                fflush(stdout); // TODO 陈晓恒，这里根据输入的数量循环读入站点名字
            }

            if (n == 3)
            {
                printf("");//TODO 陈骁恒的WORK，输出目前有的线路
                fflush(stdout);
                printf("请问您要删除第几条线路\n");
                fflush(stdout);
                scanf("%d", &n);
            }
            if (n == 4)
            {
                printf("");//TODO 陈骁恒的WORK，输出目前有的线路(带编号）
                fflush(stdout);
                printf("请问您要修改第几条线路\n");
                fflush(stdout);
                scanf("%d", &n);
                while (1)
                {
                    printf("您选择的是%d,n\n"
                           "您想要：\n"
                           "1.*删除*\n"
                           "2.*插入*\n"
                           "3.*修改*\n");
                    fflush(stdout);
                    scanf("%d", &n);
                    // TODO cxh
                    printf("您是否选择继续修改当前线路？\n"
                           "1.退出\n"
                           "2.继续\n");
                    fflush(stdout);
                    int flag;
                    scanf("%d", &flag);
                    if (flag == 1)
                    {
                        break;
                    }
                }

            }
        }//TODO 这里有很多陈骁恒的工作
        else if (n == 8)
        {
            // TODO 陈骁恒的工作 询问是否保存数据、保存文件名
            printf("是否保存数据？ 1.是\t2.否\n");
            fflush(stdout);
            int new_number;
            scanf("%d", &new_number);
            if (new_number == 1)
            {

                printf("请输入文件名\n");
                fflush(stdout);
                char new_file[100];
                scanf("%s", new_file);
                data_save(d, new_file);
                printf("数据已保存至名为%s的文件\n", new_file);
                fflush(stdout);
            } else
            {
                printf("数据未保存");
                fflush(stdout);
            }

            break;
        }
    }
    return 0;
}
