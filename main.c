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

	printf(
		"亲，请输入数字\n"
		"\t输入1选择会员管理\n"
		"\t输入2选择房屋管理\n"
		"\t输入3选择入住管理\n"
		"\t输入4选择场馆设施管理\n"
		"\t输入5选择班车路线管理\n"
		"\t输入6选择问题反映：");
	scanf("%d", &n);

	if (n == 1)
	{
		printf(
			"您下一步想要干什么？\n"
			"\t输入1选择新建会员\n"
            "\t输入2选择查询会员\n"
			"\t输入3选择会员的删除与修改\n");
	}


	PeopleList l = people_list_new();
	people_list_push(&l, "haha");
	printf("%d:%s\n", people_list_at(l, 0).id, people_list_at(l, 0).name);
	return 0;
}
