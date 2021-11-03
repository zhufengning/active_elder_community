//
// Created by zfn on 2021/11/3.
//

#ifndef OLD_COMM_PEOPLE_H
#define OLD_COMM_PEOPLE_H

typedef struct People
{
    int id;
    char name[100];
} People;

typedef struct PeopleList
{
    People *head;
    int size;
} PeopleList;

#endif //OLD_COMM_PEOPLE_H
