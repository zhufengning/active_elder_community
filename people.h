//
// Created by zfn on 2021/11/3.
//

/* People��������д�ģ������ṹ��д�ı䳤���飬���ʣ��ʾ����볢�Զ���д�������� */

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
    int size, maxid;
} PeopleList;

/// �½�һ��������Ա�б�
PeopleList people_list_new(void)
{
    PeopleList t;
    t.root = NULL;
    t.size = 0;
    t.maxid = 0;
    return t;
}

/// ��һ����Ա�б��в���һ���»�Ա������id
int people_list_push(PeopleList *p, char *name)
{
    p->size += 1;
    PeopleNode *new_people = (PeopleNode *) calloc(1, sizeof(PeopleNode));
    new_people->v.id = p->maxid + 1;
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
    p->maxid += 1;
    return new_people->v.id;
}

/// ��������ʱʹ��
void people_list_load(PeopleList *p, int id, char *name)
{
    p->size += 1;
    PeopleNode *new_people = (PeopleNode *) calloc(1, sizeof(PeopleNode));
    new_people->v.id = id;
    if (id >= p->maxid)
    {
        p->maxid = id + 1;
    }
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

/// ɾ��һ����Ա
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

/// ��id���һ�Ա
int* people_find_by_id(PeopleList pl, int id)
{
    int *ret = calloc(1, sizeof(int));
    ret[0] = 0;
    PeopleNode *pt = pl.root;
    int r = 0;
    while (pt != NULL)
    {
        if (pt->v.id == id)
        {
            ++ret[0];
            ret = realloc(ret, (ret[0] + 1) * sizeof(int));
            ret[ret[0]] = r;
        }
        pt = pt->hou;
        ++r;
    }
    return ret;
}

/// �����ֲ��һ�Ա
int *people_find_by_name(PeopleList pl, char *name)
{
    int *ret = calloc(1, sizeof(int));
    ret[0] = 0;
    PeopleNode *pt = pl.root;
    int r = 0;
    while (pt != NULL)
    {
        if (strcmp(pt->v.name, name) == 0)
        {
            ++ret[0];
            ret = realloc(ret, (ret[0] + 1) * sizeof(int));
            ret[ret[0]] = r;
        }
        pt = pt->hou;
        ++r;
    }
    return ret;
}

///��ȡ�б��е�in����Ա�����㿪ʼ����
People *people_list_at(PeopleList pl, int v)
{
    static People r = {-1, "fuck!"};
    int p = 0;
    PeopleNode *pt = pl.root;
    while (pt->hou != NULL)
    {
        if (p == v) break;
        ++p;
        pt = pt->hou;
    }
    if (p == v)
    {
        return &pt->v;
    } else
    {
        return &r;
    }
}

void pl_rebuild(PeopleList *pl)
{
    int i = 0;
    for (PeopleNode *it = pl->root; it != NULL; it = it->hou)
    {
        ++i;
        it->v.id = i;
    }
}

#endif //ELDER_COMM_PEOPLE_H
