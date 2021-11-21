#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* People是用链表写的，其他结构是写的变长数组，别问，问就是想尝试多种写法！！！*/

#include "people.h"
#include "facility.h"
#include "servant.h"
#include "house.h"
#include "storage.h"

//sz--代表数组
int main()
{
//    Data d = data_from_file("../a.json");
//    people_list_delete(&d.people_list, 0);
//    servant_list_delete(&d.servant_list, 0);
//    strcpy(people_list_at(d.people_list, 0)->name, "zzz");
//    data_save(d, "../b.json");
//    return 0;
    int a;
    printf("您是否需要读取已保存的数据？"
           "1.是"
           "2.否");
    scanf("%d", &a);
    char sz[100];
    if (a == 1)
    { scanf("%s", sz); }
    if (a == 2)
    { printf("请继续！ \n"); }
    // TODO 陈骁恒的工作

    int back = 0;
    do
    {
        back = 0;
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
                "\t6.选择*问题反映*：");
        scanf("%d", &n);


        if (n == 1)
        {
            printf(
                    "您下一步想要干什么？\n"
                    "请输入相应数字：\n"
                    "\t1.选择*新建会员*\n"
                    "\t2.选择*查询会员*\n"
                    "\t3.选择*会员的删除与修改*\n"
                    "\t4.选择*返回上一级*");
            scanf("%d", &n);
            char name[100];
            if (n == 4)
            {
                back = 1;
            } else
            {
                if (n == 1)
                {
                    scanf("%s", name);
                }
                if (n == 2)
                {
                    scanf("%s", name);
                    // TODO 陈骁恒的工作
                }
                if (n == 3)
                {
                    // TODO 陈骁恒的工作
                }

            }
        } else if (n == 2)
        {
            printf("您下一步想要干什么？\n"
                   "请输入相应数字：\n"
                   "\t1.选择*查看房屋基本情况*\n"
                   "\t2.选择*购买房屋*\n"
                   "\t3.选择*返回上一级*");
            scanf("%d", &n);
            if (n == 1)
            { printf("我们的房屋都有权威机构的认证！请您放心！"); }
            if (n == 2)
            {
                printf("您是否已经成为会员？"
                       "1.是"
                       "2.否");
                scanf("%d", &n);
                if (n == 1)
                {
                    printf("您可以开始选择房屋了\n"
                           "您想选择哪一个房屋？\n"
                           "请输入房屋名字！");
                    scanf("%s", sz2);
                }
                // TODO 陈骁恒的工作}
                if (n == 2)
                {
                    printf("您还不是会员！\n"
                           "请返回首页注册会员以购买房屋！");
                    back = 1;
                }
                if (n == 3)
                {
                    back = 1;
                }
            }
        } else if (n == 3)
        {
            printf("您是否已经购买房屋？"
                   "1.是"
                   "2.否");
            scanf("%d", &n);
            if (n == 1)
            {
                printf("请输入您房屋的名字");
                scanf("%s", sz3);
                // TODO 陈骁恒的工作
                printf ("您接下来希望您的房屋？\n"
                        "1.*入住*\n"
                        "2.*出租*\n"
                        "3.*空置*: ");
                scanf ("%d",n);
                if (n==1){}// TODO 陈骁恒的工作
                if (n==2){}// TODO 陈骁恒的工作
                if (n==3){}// TODO 陈骁恒的工作
            }//sz3是数组
            if (n == 2)
            { back = 1; }
        }else if (n==4){printf ("请选择您的身份：\n"
                                "1.*我是用户*\n"
                                "2.*我是管理人员*");
            scanf ("%d",&n);
            if (n==1){printf ("您想要申请娱乐设施吗？\n"
                              "1.是\n"
                              "2.否");
            scanf ("%d",n);
            if (n==1){printf("您想要申请什么娱乐设施？\n"
                             "1.*\n"
                             "2.*\n"
                             "3.*\n"
                             "4.退出");}//我们有这个功能吗？<-->
                             if (n==4){break;}
            if (n==2){break;}}
            if (n==2){printf ("您想要新建什么娱乐设施？\n"
                              "1.*\n"
                              "2.*\n"
                              "3.*\n"
                              "4.退出");
            scanf ("%d",&n);
            if (n==4){break;}
            //好像这也没有。。。。。。。
            }


        }
        else if (n==5){printf ("请选择您的身份：\n"
                               "1.服务人员或工作人员\n"
                               "2.用户\n");
            char name2[100];
        if (n==1) {printf ("您下一步想干什么？\n"
                           "1.*注册成为服务人员*\n"
                           "2.*修改服务人员信息*\n"
                           "3.*删除服务人员信息*\n"
                           "4.劳资点错了");
        scanf ("%d",n);
        if (n==1){printf ("请输入您的姓名：\n");
        scanf ("%s",name2);}
            // TODO 陈骁恒的工作
        if (n==2){}

        if (n==3){}
        // TODO 陈骁恒的工作
        //见servant.h
        if(n==4){break;}
                 }
        }else if (n==6){printf ("登陆www.hlzzsq.com获得更多帮助\n"
                                "添加客服微信：川酱今天吃什么：zhangyichuan_33获取一对一帮助\n");}



    } while (back);


    PeopleList l = people_list_new();
    people_list_push(&l, "haha");
    printf("%d:%s\n", people_list_at(l, 0)->id, people_list_at(l, 0)->name);
    return 0;
}