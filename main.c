#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "people.h"
#include "facility.h"
#include "servant.h"
#include "house.h"
int main() 
{
	int n;
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

	if (n == 1)
	{
		printf(
			"您下一步想要干什么？\n"
            "请输入相应数字：\n"
			"\t1.选择*新建会员*\n"
            "\t2.选择*查询会员*\n"
			"\t3.选择*会员的删除与修改*\n");
	}


	PeopleList l = people_list_new();
	people_list_push(&l, "haha");
	printf("%d:%s\n", people_list_at(l, 0).id, people_list_at(l, 0).name);
	return 0;
}
