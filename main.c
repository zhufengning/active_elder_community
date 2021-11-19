#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "people.h"
#include "facility.h"
#include "servant.h"
#include "house.h"
#include "storage.h"

int main() {
    int a;
    printf ("您是否需要读取已保存的数据？"
            "1.是"
            "2.否");
    scanf ("%d",&a);
    char sz[100];
    if(a==1){scanf ("%s",sz);}
    if(a==2){printf ("请继续！");}
    // TODO 陈骁恒的工作

    int back = 0;
    do {
        back = 0;
        int n;
        char sz2[100];
        printf("********************************\n    欢迎进入活力长者社区系统    \n********************************\n");
        printf(
                "*亲，请输入数字*\n"
                "\t1.选择*会员管理*\n"
                "\t2.选择*房屋管理*\n"
                "\t3.选择*入住管理*\n"
                "\t4.选择*场馆设施管理*\n"
                "\t5.选择*班车路线管理*\n"
                "\t6.选择*问题反映*：");
        scanf("%d", &n);


        if (n == 1) {
            printf(
                    "您下一步想要干什么？\n"
                    "请输入相应数字：\n"
                    "\t1.选择*新建会员*\n"
                    "\t2.选择*查询会员*\n"
                    "\t3.选择*会员的删除与修改*\n"
                    "\t4.选择*返回上一级*");
            scanf("%d", &n);
            char name[100];
            if (n == 4) {
                back = 1;
            } else {
                if (n == 1) {
                    scanf("%s", name);
                }
                if (n == 2) {
                    scanf("%s", name);
                    // TODO 陈骁恒的工作
                }
                if (n == 3) {
                    // TODO 陈骁恒的工作
                }

            }
        } else if (n == 2) {
            printf("您下一步想要干什么？\n"
                   "请输入相应数字：\n"
                   "\t1.选择*查看房屋基本情况*\n"
                   "\t2.选择*购买房屋*\n"
                   "\t3.选择*返回上一级*");
            scanf("%d", &n);
            if (n == 1) { printf("我们的房屋都有权威机构的认证！请您放心！"); }
            if (n == 2) {
                printf("您是否已经成为会员？"
                       "1.是"
                       "2.否");
                scanf("%d", &n);
                if (n == 1) {
                    printf("您可以开始选择房屋了\n"
                           "您想选择哪一个房屋？\n"
                           "请输入房屋名字！");
                    scanf("%s", sz2);
                }
                // TODO 陈骁恒的工作}
                if (n == 2) {
                    printf("您还不是会员！\n"
                           "请返回首页注册会员以购买房屋！");
                    back = 1;
                }
            }

        }

    } while (back);




    PeopleList l = people_list_new();
    people_list_push(&l, "haha");
    printf("%d:%s\n", people_list_at(l, 0).id, people_list_at(l, 0).name);
    return 0;
}
