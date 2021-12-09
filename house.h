/******************************************
 * This file should be encoded with GB2312*
 ******************************************/
//
// Created by whx on 2021/11/12.
//

#ifndef ELDER_COMM_HOUSE_H
#define ELDER_COMM_HOUSE_H
typedef struct House
{
    int id;
    char name[100];
    int owner, type, tenant; //type: 0.û����ס;1.ҵ����ס;2.�����ס
} House;

typedef struct HouseList
{
    House *head;
    int size, maxid;
} HouseList;

/// �½�һ�������б�
HouseList house_list_new(void)
{
    HouseList t;
    t.head = NULL;
    t.size = 0;
    t.maxid = 0;
    return t;
}

/// ��һ�������б��в���һ���·��ݲ�����id
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

/// ��������ʱʹ��
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

/// ��ȡ�б��е�in�����ݣ����㿪ʼ����
House *house_list_at(HouseList p, int in)
{
    static House r = {-1, "fuck!", -1, -1, -1};
    if (in >= p.size || in < 0) return &r;
    else return &p.head[in];
}

/// ɾ��һ������
void house_list_delete(HouseList *pl, int v)
{
    if (v >= pl->size) return;
    for (int i = v; i < pl->size - 1; ++i)
    {
        pl->head[i] = pl->head[i + 1];
    }
    pl->size -= 1;
}

/// ��id���ҷ���
/// ��������a,a[0]��ʾ�������,a[1-a[0]]Ϊ���
int* house_find_by_id(HouseList pl, int id)
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

/// �����ֲ��ҷ���
/// ��������a,a[0]��ʾ�������,a[1-a[0]]Ϊ���
int* house_find_by_name(HouseList pl, char *name)
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

/// �����ֲ��ҷ���
/// ��������a,a[0]��ʾ�������,a[1-a[0]]Ϊ���
int house_find_by_owner(HouseList pl, int owner)
{
    for (int i = 0; i < pl.size; ++i)
    {
        if (pl.head[i].owner == owner) return i;
    }
    return -1;
}
/// �ؽ���ȷ��id���ظ�
void hl_rebuild(HouseList *hl)
{
    for (int i = 0; i < hl->size; ++i)
    {
        hl->head[i].id = i + 1;
    }
}

#endif //ELDER_COMM_HOUSE_H
