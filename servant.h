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

///新建一个社区服务人员列表
ServantList servant_list_new(void)
{
    ServantList t;
    t.head = NULL;
    t.size = 0;
    return t;
}

///往一个服务人员列表中插入一个新的服务人员并分配id
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
    strcpy(p->head[p->size - 1].name, name);
}

void servant_list_load(ServantList* p, Servant v)
{
    if (p->size == 0)
    {
        p->head = calloc(1, sizeof(Servant));
        ++p->size;
    }
    else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(Servant) * p->size);
    }
    p->head[p->size - 1] = v;
}

///获取列表中第in个服务人员（从零开始数）
Servant servant_list_at(ServantList p, int in)
{
    Servant r = { -1, "fuck!", -1 };
    if (in >= p.size) return r;
    else return p.head[in];
}
#endif //ELDER_COMM_SERVANT_H
