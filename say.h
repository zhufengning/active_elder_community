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
    printf("ϵͳ������");
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
    printf("��ϵͳ��������Ĺ���ʦ");
    fflush(stdout);
    mysleep(0.6);
    printf("���������з����������죬");
    fflush(stdout);
    mysleep(0.6);
    printf("ֻ����������������顣��\n");
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
    printf("�������\n");
}

#endif //ELDER_COMM_SAY_H
