//
// Created by cxh on 2021/11/12.
//

#ifndef ELDER_COMM_FACILITY_H
#define ELDER_COMM_FACILITY_H
typedef struct Facility
{
    int id;
    char name[100];
} Facility;

typedef struct FacilityList
{
    Facility* head;
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
void facility_list_push(FacilityList* p, char* name)
{
    if (p->size == 0)
    {
        p->head = malloc(sizeof(Facility));
        ++p->size;
    }
    else
    {
        ++p->size;
        p->head = realloc(p->head, sizeof(Facility) * p->size);
    }
    p->head[p->size - 1].id = p->size;
    memcpy(p->head[p->size - 1].name, name, strlen(name) * sizeof(char));
}

///获取列表中第in个设施（从零开始数）
Facility  facility_list_at(FacilityList p, int in)
{
    Facility r = { -1, "fuck!" };
    if (in >= p.size) return r;
    else return p.head[in];
}
#endif ELDER_COMM_ FACILITY_H
