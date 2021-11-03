//
// Created by zfn on 2021/11/3.
//

#ifndef ELDER_COMM_PEOPLE_H
#define ELDER_COMM_PEOPLE_H
#include <stdlib.h>
#include <string.h>
typedef struct People
{
    int id;
    char name[100];
} People;

typedef struct PeopleList
{
    People *head;
    int size;
} PeopleList;

///新建一个社区会员列表
PeopleList people_list_new(void)
{
    PeopleList t;
    t.head = NULL;
    t.size = 0;
    return t;
}

///往一个会员列表中插入一个新会员并分配id
void people_list_push(PeopleList *p, char *name)
{
    if (p->size == 0)
    {
        p->head = malloc(sizeof(People));
        ++p->size;
    } else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(People) * p->size);
    }
    p->head[p->size - 1].id = p->size;
    memcpy(p->head[p->size - 1].name, name, strlen(name) * sizeof(char));
}

///获取列表中第in个会员（从零开始数）
People people_list_at(PeopleList p, int in)
{
    People r = {-1, "fuck!"};
    if (in >= p.size) return r;
    else return p.head[in];
}
#endif //ELDER_COMM_PEOPLE_H
