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
    Data d = data_new();
    int a;
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

    }
    if (a == 2)
    { printf("请继续！ \n"); }
    // TODO 陈骁恒的工作 存取数据的示例在最开头

    while (1)
    {
        int n;
        char sz2[100];
        char sz3[100];
        printf("********************************\n    欢迎进入活力长者社区系统    \n********************************\n");
        printf(
                "*亲，请输入数字*\n"
                "\t1.选择*会员管理*\n"
                "\t2.选择*房屋管理*\n"
                "\t3.选择*入住管理*\n"
                "\t4.选择*场馆设施管理*\n"
                "\t5.选择*服务人员管理*\n"
                "\t6.选择*问题反映*\n"
                "\t7.保存数据及退出系统：\n");
        fflush(stdout);
        scanf("%d", &n);


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
            char name[100];
            if (n == 4)
            {

            } else
            {
                if (n == 1)//1.选择*新建会员
                {
                    printf("输入会员名字：\n");
                    fflush(stdout);
                    scanf("%s", name);
                    people_list_push(&d.people_list, name);
                }
                if (n == 2)//2.选择*查询会员*
                {
                    printf("请的选择查询的方式\n"
                           "1.ID查询\n"
                           "2.按名字查询\n"
                           "3.输出所有会员\n");
                    fflush(stdout);
                    scanf("%d", &n);
                    if (n == 1)
                    {
                        printf("请输入您的ID:\n");
                        fflush(stdout);
                    }
                    // TODO 陈骁恒的工作,调用数组
                    if (n == 2)
                    {
                        printf("请输入您的名字：\n");
                        fflush(stdout);
                        scanf("%s", name);
                    }
                    // TODO 陈骁恒的工作
                    if (n == 3)
                    {}//TODO 陈骁恒的工作,输出所有会员
                }
                if (n == 3)//会员的删除与修改
                {
                    printf("请输出您的ID:\n");
                    fflush(stdout);
                    //  根据编号选择要修改的会员
                    // TODO 陈骁恒的工作 （选择修改的会员之后先输出该会员的信息）
                }

            }
        } else if (n == 2)//选择*房屋管理*
        {
            printf("您下一步想要干什么？\n"
                   "请输入相应数字：\n"
                   "\t1.选择*查看房屋基本情况*\n"
                   "\t2.选择*购买房屋*\n"
                   "\t3.选择*返回上一级*\n");
            fflush(stdout);
            scanf("%d", &n);
            if (n == 1)//1.选择*查看房屋基本情况*
            {
                printf("我们的房屋都有权威机构的认证！请您放心！\n");
                fflush(stdout);
            }
            if (n == 2)//2.选择*购买房屋*
            {
                printf("您是否已经成为会员？\n"
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
                    if (1)
                        // TODO 陈骁恒，查询会员是否存在，不存在就什么都不做（这样会自动会主页）
                    {
                        printf("您可以开始选择房屋了\n"
                               "请输入房屋名字！\n");
                        fflush(stdout);
                        scanf("%s", sz2);
                    }

                }
                    // TODO 陈骁恒的工作
                else if (n == 2)
                {
                    printf("您还不是会员！\n"
                           "请返回首页注册会员以购买房屋！\n");
                    fflush(stdout);
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
                printf("请输入您房屋的名字\n");
                fflush(stdout);
                scanf("%s", sz3);
                // TODO 陈骁恒的工作
                printf("您接下来希望您的房屋？\n"
                       "1.*入住*\n"
                       "2.*出租*\n"
                       "3.*空置*: \n");
                fflush(stdout);
                scanf("%d", &n);
                if (n == 1)
                {}// TODO 陈骁恒的工作
                if (n == 2)
                {}// TODO 陈骁恒的工作
                if (n == 3)
                {}// TODO 陈骁恒的工作
            } else if (n == 2)
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
            fflush(stdout);
        } else if (n == 7)
        {
            // TODO 陈骁恒的工作 询问是否保存数据、保存文件名
            break;
        }
    }
    return 0;
}