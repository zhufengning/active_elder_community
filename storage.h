//
// Created by zfn on 2021/11/14.
//

#ifndef ELDER_COMM_STORAGE_H
#define ELDER_COMM_STORAGE_H

#include "cJSON.h"
#include "cJSON.c"

/// 一个变量，存有整个社区的所有数据
typedef struct Data
{
    PeopleList people_list;
    HouseList house_list;
    ServantList servant_list;
    FacilityList facility_list;
    BusChainList buschain_list;
    int error;
} Data;

/// 新建一个DATA
Data data_new()
{
    Data t;
    t.people_list = people_list_new();
    t.house_list = house_list_new();
    t.servant_list = servant_list_new();
    t.facility_list = facility_list_new();
    t.buschain_list = buschainlist_chain_create();
    t.error = 0;
    return t;
}

/// 从json文件中载入数据
Data data_from_file(char *path)
{
    Data ret = data_new();
    FILE *f = fopen(path, "rb");
    if (f == NULL)
    {
        ret.error = -1;
        return ret;
    }
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);  /* same as rewind(f); */
    char *string = malloc(fsize + 1);
    fread(string, 1, fsize, f);
    fclose(f);
    string[fsize] = 0;
    cJSON *json = cJSON_Parse(string);
    if (json == NULL)
    {
        ret.error = -1;
        return ret;
    }
    {
        cJSON *pp = cJSON_GetObjectItem(json, "people_list");
        cJSON_GetArrayItem(pp, 0);
        PeopleList *pl = &ret.people_list;

        for (int i = 0; i < cJSON_GetArraySize(pp); ++i)
        {
            cJSON *t = cJSON_GetArrayItem(pp, i);
            cJSON *t2 = cJSON_GetObjectItem(t, "id");
            cJSON *t3 = cJSON_GetObjectItem(t, "name");
            people_list_load(pl, t2->valueint, t3->valuestring);
        }
    }

    {
        cJSON *pp = cJSON_GetObjectItem(json, "house_list");
        HouseList *pl = &ret.house_list;

        for (int i = 0; i < cJSON_GetArraySize(pp); ++i)
        {
            House new_house;
            cJSON *t = cJSON_GetArrayItem(pp, i);
            cJSON *t2 = cJSON_GetObjectItem(t, "id");
            cJSON *t3 = cJSON_GetObjectItem(t, "name");
            cJSON *t5 = cJSON_GetObjectItem(t, "owner");
            new_house.id = t2->valueint;
            new_house.owner = t5->valueint;
            strcpy(new_house.name, t3->valuestring);
            house_list_load(pl, new_house);
        }
    }

    {
        cJSON *pp = cJSON_GetObjectItem(json, "servant_list");
        ServantList *pl = &ret.servant_list;

        for (int i = 0; i < cJSON_GetArraySize(pp); ++i)
        {
            Servant new_servant;
            cJSON *t = cJSON_GetArrayItem(pp, i);
            cJSON *t2 = cJSON_GetObjectItem(t, "id");
            cJSON *t3 = cJSON_GetObjectItem(t, "name");
            cJSON *t4 = cJSON_GetObjectItem(t, "target_id");
            new_servant.id = t2->valueint;
            new_servant.target_id = t4->valueint;
            strcpy(new_servant.name, t3->valuestring);
            servant_list_load(pl, new_servant);
        }
    }
    {
        cJSON *pp = cJSON_GetObjectItem(json, "facility_list");
        FacilityList *pl = &ret.facility_list;

        for (int i = 0; i < cJSON_GetArraySize(pp); ++i)
        {
            Facility new_facility;
            cJSON *t = cJSON_GetArrayItem(pp, i);
            cJSON *t2 = cJSON_GetObjectItem(t, "id");
            cJSON *t3 = cJSON_GetObjectItem(t, "name");
            new_facility.id = t2->valueint;
            strcpy(new_facility.name, t3->valuestring);
            facility_list_load(pl, new_facility);
        }
    }
    {
        cJSON *pp = cJSON_GetObjectItem(json, "buschain_list");
        BusChainList *bcl = &ret.buschain_list;

        for (int i = cJSON_GetArraySize(pp) - 1; i >= 0; --i)
        {
            cJSON *t = cJSON_GetArrayItem(pp, i);
            BusChain bc = buschain_create();
            for (int j = cJSON_GetArraySize(t) - 1; j >= 0; --j)
            {
                cJSON *t2 = cJSON_GetArrayItem(t, j);
                buschain_insert(bc.root, t2->valuestring);
            }
            buschainlist_insert(bcl->root, bc);
        }
    }
    return ret;
}

/// 保存数据到json文件
void data_save(Data d, char *path)
{
    cJSON *j = cJSON_CreateObject();
    cJSON *pl = cJSON_CreateArray();
    cJSON *hl = cJSON_CreateArray();
    cJSON *sl = cJSON_CreateArray();
    cJSON *fl = cJSON_CreateArray();
    for (int i = 0; i < d.people_list.size; ++i)
    {
        cJSON *pt = cJSON_CreateObject();
        cJSON_AddItemToObject(pt, "id", cJSON_CreateNumber(people_list_at(d.people_list, i)->id));
        cJSON_AddItemToObject(pt, "name", cJSON_CreateString(people_list_at(d.people_list, i)->name));
        cJSON_AddItemToArray(pl, pt);
    }
    cJSON_AddItemToObject(j, "people_list", pl);
    for (int i = 0; i < d.house_list.size; ++i)
    {
        cJSON *ht = cJSON_CreateObject();
        cJSON_AddItemToObject(ht, "id", cJSON_CreateNumber(house_list_at(d.house_list, i)->id));
        cJSON_AddItemToObject(ht, "owner", cJSON_CreateNumber(house_list_at(d.house_list, i)->owner));
        cJSON_AddItemToObject(ht, "name", cJSON_CreateString(house_list_at(d.house_list, i)->name));
        cJSON_AddItemToArray(hl, ht);
    }
    cJSON_AddItemToObject(j, "house_list", hl);
    for (int i = 0; i < d.servant_list.size; ++i)
    {
        cJSON *st = cJSON_CreateObject();
        cJSON_AddItemToObject(st, "id", cJSON_CreateNumber(servant_list_at(d.servant_list, i)->id));
        cJSON_AddItemToObject(st, "target_id", cJSON_CreateNumber(servant_list_at(d.servant_list, i)->target_id));
        cJSON_AddItemToObject(st, "name", cJSON_CreateString(servant_list_at(d.servant_list, i)->name));
        cJSON_AddItemToArray(sl, st);
    }
    cJSON_AddItemToObject(j, "servant_list", sl);
    for (int i = 0; i < d.facility_list.size; ++i)
    {
        cJSON *ft = cJSON_CreateObject();
        cJSON_AddItemToObject(ft, "id", cJSON_CreateNumber(facility_list_at(d.facility_list, i)->id));
        cJSON_AddItemToObject(ft, "name", cJSON_CreateString(facility_list_at(d.facility_list, i)->name));
        cJSON_AddItemToArray(fl, ft);
    }
    cJSON_AddItemToObject(j, "facility_list", fl);

    cJSON *bcl = cJSON_CreateArray();
    {

        for (BusChainNode *it = d.buschain_list.root->hou; it != NULL; it = it->hou)
        {
            cJSON *bc = cJSON_CreateArray();
            for (BusStop *jt = it->value.root->hou; jt != NULL; jt = jt->hou)
            {
                cJSON_AddItemToArray(bc, cJSON_CreateString(jt->value));
            }
            cJSON_AddItemToArray(bcl, bc);
        }
    }

    cJSON_AddItemToObject(j, "buschain_list", bcl);

    //printf("%s\n", cJSON_Print(j));
    FILE *f = fopen(path, "w");
    fprintf(f, "%s", cJSON_Print(j));
    fclose(f);
}

#endif //ELDER_COMM_STORAGE_H
