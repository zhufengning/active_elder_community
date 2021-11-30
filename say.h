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

#endif //ELDER_COMM_SAY_H
