/******************************************
 * This file should be encoded with GB2312*
 ******************************************/
//
// Created by cxh on 2021/11/12.
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
    int size, maxid;
} PeopleList;

/// 新建一个社区会员列表
PeopleList people_list_new(void)
{
    PeopleList t;
    t.head = NULL;
    t.size = 0;
    t.maxid = 0;
    return t;
}

/// 往一个会员列表中插入一个新会员并分配id
int people_list_push(PeopleList *p, char *name)
{
    ++p->maxid;
    if (p->size == 0)
    {
        p->head = malloc(sizeof(People));
        ++p->size;
    } else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(People) * p->size);
    }
    p->head[p->size - 1].id = p->maxid;
    strcpy(p->head[p->size - 1].name, name);
    return p->maxid;
}

/// 加载数据时使用
void people_list_load(PeopleList *p, People v)
{
    if (v.id >= p->maxid)
    {
        p->maxid = v.id + 1;
    }
    if (p->size == 0)
    {
        p->head = malloc(sizeof(People));
        ++p->size;
    } else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(People) * p->size);
    }
    p->head[p->size - 1] = v;
}

/// 获取列表中第in个会员（从零开始数）
People *people_list_at(PeopleList p, int in)
{
    static People r = {-1, "fuck!"};
    if (in >= p.size) return &r;
    else return &p.head[in];
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
/// 返回数组a,a[0]表示结果数量,a[1-a[0]]为结果
int* people_find_by_id(PeopleList pl, int id)
{
    int *ret = calloc(1, sizeof(int));
    ret[0] = 0;
    for (int i = 0; i < pl.size; ++i)
    {
        if (pl.head[i].id == id)
        {
            ++ret[0];
            ret = realloc(ret, (ret[0] + 1) * sizeof(int));
            ret[ret[0]] = i;
        }
    }
    return ret;
}

/// 按名字查找会员
/// 返回数组a,a[0]表示结果数量,a[1-a[0]]为结果
int *people_find_by_name(PeopleList pl, char *name)
{
    int *ret = calloc(1, sizeof(int));
    ret[0] = 0;
    for (int i = 0; i < pl.size; ++i)
    {
        if (strcmp(pl.head[i].name, name) == 0)
        {
            ++ret[0];
            ret = realloc(ret, (ret[0] + 1) * sizeof(int));
            ret[ret[0]] = i;
        }
    }
    return ret;
}

/// 重建，确保id不重复
void pl_rebuild(PeopleList *fl)
{
    for (int i = 0; i < fl->size; ++i)
    {
        fl->head[i].id = i + 1;
    }
}
#endif //ELDER_COMM_PEOPLE_H
