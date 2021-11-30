//
// Created by whx on 2021/11/12.
//

/* People是用链表写的，其他结构是写的变长数组，别问，问就是想尝试多种写法！！！ */

#ifndef ELDER_COMM_HOUSE_H
#define ELDER_COMM_HOUSE_H
typedef struct House
{
    int id;
    char name[100];
    int owner, type, tenant; //type: 0.没有入住;1.业主入住;2.租客入住
} House;

typedef struct HouseList
{
    House *head;
    int size, maxid;
} HouseList;

///新建一个房屋列表
HouseList house_list_new(void)
{
    HouseList t;
    t.head = NULL;
    t.size = 0;
    t.maxid = 0;
    return t;
}

///往一个房屋列表中插入一个新房屋并分配id
int house_list_push(HouseList *p, char *name, int owner)
{
    ++p->maxid;
    if (p->size == 0)
    {
        p->head = calloc(1, sizeof(House));
        ++p->size;
    } else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(House) * p->size);
    }
    p->head[p->size - 1].owner = owner;
    p->head[p->size - 1].id = p->maxid;
    strcpy(p->head[p->size - 1].name, name);
    return p->maxid;
}

/// 加载数据时使用
void house_list_load(HouseList *p, House v)
{
    if (v.id >= p->maxid)
    {
        p->maxid = v.id + 1;
    }
    if (p->size == 0)
    {
        p->head = calloc(1, sizeof(House));
        ++p->size;
    } else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(House) * p->size);
    }
    p->head[p->size - 1] = v;
}

///获取列表中第in个房屋（从零开始数）
House *house_list_at(HouseList p, int in)
{
    static House r = {-1, "fuck!", -1, -1, -1};
    if (in >= p.size || in < 0) return &r;
    else return &p.head[in];
}

/// 删除一个房屋
void house_list_delete(HouseList *pl, int v)
{
    if (v >= pl->size) return;
    for (int i = v; i < pl->size - 1; ++i)
    {
        pl->head[i] = pl->head[i + 1];
    }
    pl->size -= 1;
}

/// 按id查找房屋
int house_find_by_id(HouseList pl, int id)
{
    for (int i = 0; i < pl.size; ++i)
    {
        if (pl.head[i].id == id) return i;
    }
    return -1;
}

/// 按名字查找房屋
int house_find_by_name(HouseList pl, char *name)
{
    for (int i = 0; i < pl.size; ++i)
    {
        if (strcmp(pl.head[i].name, name) == 0) return i;
    }
    return -1;
}

/// 按名字查找房屋
int house_find_by_owner(HouseList pl, int owner)
{
    for (int i = 0; i < pl.size; ++i)
    {
        if (pl.head[i].owner == owner) return i;
    }
    return -1;
}

#endif //ELDER_COMM_HOUSE_H
