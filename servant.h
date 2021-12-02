//
// Created by hbl on 2021/11/12
//

/* People��������д�ģ������ṹ��д�ı䳤���飬���ʣ��ʾ����볢�Զ���д�������� */

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
    int size, maxid;
} ServantList;

/// �½�һ������������Ա�б�
ServantList servant_list_new(void)
{
    ServantList t;
    t.head = NULL;
    t.size = 0;
    t.maxid = 0;
    return t;
}

/// ��һ��������Ա�б��в���һ���µķ�����Ա������id
int servant_list_push(ServantList *p, char *name)
{
    ++p->maxid;
    if (p->size == 0)
    {
        p->head = calloc(1, sizeof(Servant));
        ++p->size;
    } else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(Servant) * p->size);
    }
    p->head[p->size - 1].id = p->size;
    strcpy(p->head[p->size - 1].name, name);
    p->head[p->size - 1].target_id = -1;
    return p->maxid;
}

/// ��������ʱʹ��
void servant_list_load(ServantList *p, Servant v)
{
    if (v.id >= p->maxid)
    {
        p->maxid = v.id + 1;
    }
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

///��ȡ�б��е�in��������Ա�����㿪ʼ����
Servant *servant_list_at(ServantList p, int in)
{
    static Servant r = {-1, "fuck!", -1};
    if (in >= p.size) return &r;
    else return &p.head[in];
}

/// ɾ��һ��������Ա
void servant_list_delete(ServantList *pl, int v)
{
    if (v >= pl->size) return;
    for (int i = v; i < pl->size - 1; ++i)
    {
        pl->head[i] = pl->head[i + 1];
    }
    pl->size -= 1;
}

/// ��id���ҷ�����Ա
int *servant_find_by_id(ServantList pl, int id)
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

/// �����ֲ��ҷ�����Ա
int *servant_find_by_name(ServantList pl, char *name)
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

void sl_rebuild(ServantList *sl)
{
    for (int i = 0; i < sl->size; ++i)
    {
        sl->head[i].id = i + 1;
    }
}
#endif //ELDER_COMM_SERVANT_H
