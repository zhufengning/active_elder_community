//
// Created by 11549 on 2021/11/30.
//

#ifndef ELDER_COMM_SAY_H
#define ELDER_COMM_SAY_H

#include <stdio.h>
#include <time.h>

void mysleep(double t)
{
    clock_t st = clock();
    while ((double) (clock() - st) / CLOCKS_PER_SEC < t);
}

void play_ani()
{
    printf("系统加载中");
    fflush(stdout);
    mysleep(0.6);
    printf(".");
    fflush(stdout);
    mysleep(0.6);
    printf(".");
    fflush(stdout);
    mysleep(0.6);
    printf(".\n");
    fflush(stdout);
    mysleep(0.6);
    printf("本系统由最优秀的工程师");
    fflush(stdout);
    mysleep(0.6);
    printf("经过多年研发，倾力打造，");
    fflush(stdout);
    mysleep(0.6);
    printf("只求给您最完美的体验。。\n");
    mysleep(0.6);
    fflush(stdout);
    printf("3..");
    fflush(stdout);
    mysleep(0.6);
    printf("2..");
    fflush(stdout);
    mysleep(0.6);
    printf("1..\n");
    fflush(stdout);
    mysleep(0.6);
    printf("加载完成\n");
}


void say_sentence()
{
    const static char a[][1005] = {
            "想翠竹、碧梧风采，旧游何处\n\t——张宁《满江红·题碧梧翠竹送李阳春》 ",
            "回首昭阳离落日，伤心铜雀迎秋月\n\t——文天祥《满江红·代王夫人作》 ",
            "梳洗罢，独倚望江楼\n\t——温庭筠《望江南·梳洗罢》 ",
            "吾生如寄，尚想三径菊花丛\n\t——杨炎正《水调歌头·把酒对斜日》 ",
            "昨日入城市，归来泪满巾\n\t——张俞《蚕妇》 ",
    };
    int p = rand() % (sizeof(a) / sizeof(char[1005]));
    printf("%s\n", a[p]);
    fflush(stdout);
}
#endif //ELDER_COMM_SAY_H
