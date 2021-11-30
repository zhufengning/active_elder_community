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


void say_sentence()
{
    const static char a[][1005] = {
            "����񡢱����ɣ����κδ�\n\t���������������졤������������������ ",
            "�������������գ�����ͭȸӭ����\n\t���������顶�����졤������������ ",
            "��ϴ�գ���������¥\n\t������ͥ�ޡ������ϡ���ϴ�ա� ",
            "������ģ����������ջ���\n\t������������ˮ����ͷ���Ѿƶ�б�ա� ",
            "��������У�����������\n\t�������ᡶ�ϸ��� ",
    };
    int p = rand() % (sizeof(a) / sizeof(char[1005]));
    printf("%s\n", a[p]);
    fflush(stdout);
}
#endif //ELDER_COMM_SAY_H
