//
// Created by whx on 2021/11/12.
//

#ifndef ELDER_COMM_HOUSE_H
#define ELDER_COMM_HOUSE_H
typedef struct House
{
    int id;
    char name[100];
    int sold, owner;
} House;

typedef struct HouseList
{
    House* head;
    int size;
} HouseList;

///新建一个房屋列表
HouseList house_list_new(void)
{
    HouseList t;
    t.head = NULL;
    t.size = 0;
    return t;
}

///往一个房屋列表中插入一个新房屋并分配id
void house_list_push(HouseList* p, char* name)
{
    if (p->size == 0)
    {
        p->head = calloc(1, sizeof(House));
        ++p->size;
    }
    else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(House) * p->size);
    }
    p->head[p->size - 1].id = p->size;
    memcpy(p->head[p->size - 1].name, name, strlen(name) * sizeof(char));
}

///获取列表中第in个房屋（从零开始数）
House house_list_at(HouseList p, int in)
{
    House r = { -1, "fuck!",-1 };
    if (in >= p.size) return r;
    else return p.head[in];
}
#endif ELDER_COMM_HOUSE_H
