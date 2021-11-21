//
// Created by hbl on 2021/11/12
//

/* People是用链表写的，其他结构是写的变长数组，别问，问就是想尝试多种写法！！！*/

#ifndef ELDER_COMM_SERVANT_H
#define ELDER_COMM_SERVANT_H
typedef struct Servant
{
    int id;
    char name[100];
    int target_id;
} Servant;

typedef struct ServantList
{
    Servant *head;
    int size;
} ServantList;

/// 新建一个社区服务人员列表
ServantList servant_list_new(void)
{
    ServantList t;
    t.head = NULL;
    t.size = 0;
    return t;
}

/// 往一个服务人员列表中插入一个新的服务人员并分配id
void servant_list_push(ServantList *p, char *name)
{
    if (p->size == 0)
    {
        p->head = calloc(1, sizeof(People));
        ++p->size;
    } else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(Servant) * p->size);
    }
    p->head[p->size - 1].id = p->size;
    strcpy(p->head[p->size - 1].name, name);
}

/// 加载数据时使用
void servant_list_load(ServantList *p, Servant v)
{
    if (p->size == 0)
    {
        p->head = calloc(1, sizeof(Servant));
        ++p->size;
    } else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(Servant) * p->size);
    }
    p->head[p->size - 1] = v;
}

///获取列表中第in个服务人员（从零开始数）
Servant *servant_list_at(ServantList p, int in)
{
    static Servant r = {-1, "fuck!", -1};
    if (in >= p.size) return &r;
    else return &p.head[in];
}

/// 删除一个服务人员
void servant_list_delete(ServantList *pl, int v)
{
    if (v >= pl->size) return;
    for (int i = v; i < pl->size - 1; ++i)
    {
        pl->head[i] = pl->head[i + 1];
    }
    pl->size -= 1;
}

/// 按id查找服务人员
int servant_find_by_id(ServantList pl, int id)
{
    for (int i = 0; i < pl.size; ++i)
    {
        if (pl.head[i].id == id) return i;
    }
    return -1;
}

/// 按名字查找服务人员
int servant_find_by_name(ServantList pl, char *name)
{
    for (int i = 0; i < pl.size; ++i)
    {
        if (strcmp(pl.head[i].name, name) == 0) return i;
    }
    return -1;
}

#endif //ELDER_COMM_SERVANT_H
