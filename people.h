//
// Created by zfn on 2021/11/3.
//

#ifndef ELDER_COMM_PEOPLE_H
#define ELDER_COMM_PEOPLE_H
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

/// 新建一个社区会员列表
PeopleList people_list_new(void)
{
    PeopleList t;
    t.head = NULL;
    t.size = 0;
    return t;
}

/// 往一个会员列表中插入一个新会员并分配id
void people_list_push(PeopleList *p, char *name)
{
    if (p->size == 0)
    {
        p->head = calloc(1, sizeof(People));
        ++p->size;
    } else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(People) * p->size);
    }
    p->head[p->size - 1].id = p->size;
    memcpy(p->head[p->size - 1].name, name, strlen(name) * sizeof(char));
}

/// 加载数据时使用
void people_list_load(PeopleList *p, int id, char *name)
{
    if (p->size == 0)
    {
        p->head = calloc(1, sizeof(People));
        ++p->size;
    } else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(People) * p->size);
    }
    p->head[p->size - 1].id = id;
    strcpy(p->head[p->size - 1].name, name);
}

/// 删除一个会员
void people_list_delete(PeopleList *pl, int v)
{
    if (v >= pl->size) return;
    for (int i = v; i < pl->size - 1; ++i)
    {
        pl->head[i] = pl->head[i + 1];
    }
    pl->size -= 1;
}

/// 按id查找会员
int people_find_by_id(PeopleList pl, int id)
{
    for (int i = 0; i < pl.size; ++i)
    {
        if (pl.head[i].id == id) return i;
    }
    return -1;
}

/// 按名字查找会员
int people_find_by_name(PeopleList pl, char *name)
{
    for (int i = 0; i < pl.size; ++i)
    {
        if (strcmp(pl.head[i].name, name) == 0) return i;
    }
    return -1;
}

///获取列表中第in个会员（从零开始数）
People people_list_at(PeopleList p, int in)
{
    People r = {-1, "fuck!"};
    if (in >= p.size) return r;
    else return p.head[in];
}

#endif //ELDER_COMM_PEOPLE_H
