//
// Created by zfn on 2021/11/3.
//

/* People是用链表写的，其他结构是写的变长数组，别问，问就是想尝试多种写法！！！ */

#ifndef ELDER_COMM_PEOPLE_H
#define ELDER_COMM_PEOPLE_H
typedef struct People
{
    int id;
    char name[100];
} People;

typedef struct PeopleNode
{
    struct PeopleNode *hou;
    People v;
} PeopleNode;

typedef struct PeopleList
{
    PeopleNode *root;
    int size;
} PeopleList;

/// 新建一个社区会员列表
PeopleList people_list_new(void)
{
    PeopleList t;
    t.root = NULL;
    t.size = 0;
    return t;
}

/// 往一个会员列表中插入一个新会员并分配id
void people_list_push(PeopleList *p, char *name)
{
    p->size += 1;
    PeopleNode *new_people = (PeopleNode *) calloc(1, sizeof(PeopleNode));
    new_people->v.id = p->size;
    strcpy(new_people->v.name, name);
    if (p->root == NULL)
    {
        p->root = new_people;
    } else
    {
        PeopleNode *tail = p->root;
        while (tail->hou != NULL) tail = tail->hou;
        tail->hou = new_people;
    }
}

/// 加载数据时使用
void people_list_load(PeopleList *p, int id, char *name)
{
    p->size += 1;
    PeopleNode *new_people = (PeopleNode *) calloc(1, sizeof(PeopleNode));
    new_people->v.id = id;
    strcpy(new_people->v.name, name);
    if (p->root == NULL)
    {
        p->root = new_people;
    } else
    {
        PeopleNode *tail = p->root;
        while (tail->hou != NULL) tail = tail->hou;
        tail->hou = new_people;
    }
}

/// 删除一个会员
void people_list_delete(PeopleList *pl, int v)
{
    int p = 0;
    PeopleNode *pt = pl->root;
    while (pt->hou != NULL)
    {
        if (p + 1 == v) break;
        if (p == v)
        {
            PeopleNode *tmp = pl->root;
            pl->root = pl->root->hou;
            pl->size -= 1;
            free(tmp);
            return;
        }
        ++p;
        pt = pt->hou;
    }
    if (p + 1 == v)
    {
        PeopleNode *tmp = pt->hou;
        pt->hou = pt->hou->hou;
        free(tmp);
        pl->size -= 1;
    }
}

/// 按id查找会员
int people_find_by_id(PeopleList pl, int id)
{
    PeopleNode *pt = pl.root;
    int r = 0;
    while (pt != NULL)
    {
        if (pt->v.id == id)
        {
            break;
        } else
        {
            pt = pt->hou;
            ++r;
        }
    }
    if (pt != NULL) return r;
    else return -1;
}

/// 按名字查找会员
int people_find_by_name(PeopleList pl, char *name)
{
    PeopleNode *pt = pl.root;
    int r = 0;
    while (pt != NULL)
    {
        if (strcmp(pt->v.name, name) == 0)
        {
            break;
        } else
        {
            pt = pt->hou;
            ++r;
        }
    }
    if (pt != NULL) return r;
    else return -1;
}

///获取列表中第in个会员（从零开始数）
People *people_list_at(PeopleList pl, int v)
{
    static People r = {-1, "fuck!"};
    int p = 0;
    PeopleNode *pt = pl.root;
    while (pt->hou != NULL)
    {
        ++p;
        pt = pt->hou;
        if (p == v) break;
    }
    if (p == v)
    {
        return &pt->v;
    } else
    {
        return &r;
    }
}

#endif //ELDER_COMM_PEOPLE_H
