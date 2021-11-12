//
// Created by hbl on 2021/11/12
//

#ifndef ELDER_COMM_SERVANT_H
#define ELDER_COMM_SERVANT_H
typedef struct Servant
{
    int id;
    char name[100];
    int  target_id;
} Servant;

typedef struct ServantList
{
    Servant* head;
    int size;
} ServantList;

///新建一个社区会员列表
ServantList servant_list_new(void)
{
    ServantList t;
    t.head = NULL;
    t.size = 0;
    return t;
}

///往一个会员列表中插入一个新会员并分配id
void servant_list_push(ServantList* p, char* name)
{
    if (p->size == 0)
    {
        p->head = calloc(1, sizeof(People));
        ++p->size;
    }
    else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(Servant) * p->size);
    }
    p->head[p->size - 1].id = p->size;
    memcpy(p->head[p->size - 1].name, name, strlen(name) * sizeof(char));
}

///获取列表中第in个会员（从零开始数）
Servant servant_list_at(ServantList p, int in)
{
    Servant r = { -1, "fuck!", -1 };
    if (in >= p.size) return r;
    else return p.head[in];
}
#endif ELDER_COMM_SERVANT_H
