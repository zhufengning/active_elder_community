//
// Created by cxh on 2021/11/12.
//

/* People是用链表写的，其他结构是写的变长数组，别问，问就是想尝试多种写法！！！ */

#ifndef ELDER_COMM_FACILITY_H
#define ELDER_COMM_FACILITY_H
typedef struct Facility
{
    int id;
    char name[100];
} Facility;

typedef struct FacilityList
{
    Facility *head;
    int size;
} FacilityList;

///新建一个社区设施列表
FacilityList facility_list_new(void)
{
    FacilityList t;
    t.head = NULL;
    t.size = 0;
    return t;
}

///往一个设施列表中插入一个新设施并分配id
void facility_list_push(FacilityList *p, char *name)
{
    if (p->size == 0)
    {
        p->head = malloc(sizeof(Facility));
        ++p->size;
    } else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(Facility) * p->size);
    }
    p->head[p->size - 1].id = p->size;
    strcpy(p->head[p->size - 1].name, name);
}

/// 加载数据时使用
void facility_list_load(FacilityList *p, Facility v)
{
    if (p->size == 0)
    {
        p->head = malloc(sizeof(Facility));
        ++p->size;
    } else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(Facility) * p->size);
    }
    p->head[p->size - 1] = v;
}

/// 获取列表中第in个设施（从零开始数）
Facility *facility_list_at(FacilityList p, int in)
{
    static Facility r = {-1, "fuck!"};
    if (in >= p.size) return &r;
    else return &p.head[in];
}

/// 删除一个设施
void facility_list_delete(FacilityList *pl, int v)
{
    if (v >= pl->size) return;
    for (int i = v; i < pl->size - 1; ++i)
    {
        pl->head[i] = pl->head[i + 1];
    }
    pl->size -= 1;
}

/// 按id查找设施
int facility_find_by_id(FacilityList pl, int id)
{
    for (int i = 0; i < pl.size; ++i)
    {
        if (pl.head[i].id == id) return i;
    }
    return -1;
}

/// 按名字查找设施
int facility_find_by_name(FacilityList pl, char *name)
{
    for (int i = 0; i < pl.size; ++i)
    {
        if (strcmp(pl.head[i].name, name) == 0) return i;
    }
    return -1;
}

#endif //ELDER_COMM_FACILITY_H
