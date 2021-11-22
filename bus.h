//
// Created by zfn on 2021/11/22.
//

#ifndef ELDER_COMM_BUS_H
#define ELDER_COMM_BUS_H

/// 本文件的其余注释都没有卵用，请只看这里
/// 有关班车的结构全是链表
/// BusStop是一个车站，只有名字，结点形式
/// BusChain是一条路线
/// BusChainNode是路线的链表结点形式
/// BusChainList是多条线路的集合
/// BusChain和BusChainList都有create,insert,remove的操作
/// BusChain有查找操作

typedef struct BusStop//链表的一个节点
{
    struct BusStop *hou;//指向下一项的指针
    char *value;//这个节点保存的值
} BusStop;

typedef struct BusChain//链表本表
{
    BusStop *root;//根，假节点，根的后一个节点才是第一个节点
} BusChain;

BusChain buschain_create(void)//创建并初始化一个链表
{
    BusChain t;
    t.root = malloc(sizeof(BusStop));//初始化一个根
    t.root->hou = NULL;
    return t;
}

void buschain_insert(BusStop *p, char *v)//在节点p后面插入v
{
    if (p == NULL) return;//不能对NULL操作，保险
    BusStop *t = malloc(sizeof(BusStop));//为新的节点分配内存
    t->value = v;//设置值
    //一个插入过程
    t->hou = p->hou;//这一项的下一项设置为前一项的下一项
    p->hou = t;//前一项的下一项设置为这一项
}

void buschain_remove(BusStop *p)//删除p之后的节点
{
    BusStop *t = p->hou;//先记录下要删的节点的地址，free用
    p->hou = t->hou;//让链子跨过要删除的节点
    free(t);//free掉没用的节点
}

//查找，虽然不用讲，但有这么个函数方便演示，
BusStop *buschain_find(BusChain c, char *v)//返回的是查找结果的前一个节点
{
    for (BusStop *it = c.root; it->hou != NULL; it = it->hou)
        if (strcmp(it->hou->value, v) == 0)
            return it;

    return NULL;
}

typedef struct BusChainNode//链表的一个节点
{
    struct BusChainNode *hou;//指向下一项的指针
    BusChain value;//这个节点保存的值
} BusChainNode;

typedef struct BusChainList//链表本表
{
    BusChainNode *root;//根，假节点，根的后一个节点才是第一个节点
} BusChainList;

BusChainList buschainlist_chain_create(void)//创建并初始化一个链表
{
    BusChainList t;
    t.root = malloc(sizeof(BusChainNode));//初始化一个根
    t.root->hou = NULL;
    return t;
}

void buschainlist_insert(BusChainNode *p, BusChain v)//在节点p后面插入v
{
    if (p == NULL) return;//不能对NULL操作，保险
    BusChainNode *t = malloc(sizeof(BusChainNode));//为新的节点分配内存
    t->value = v;//设置值
    //一个插入过程
    t->hou = p->hou;//这一项的下一项设置为前一项的下一项
    p->hou = t;//前一项的下一项设置为这一项
}

void buschainlist_remove(BusChainNode *p)//删除p之后的节点
{
    BusChainNode *t = p->hou;//先记录下要删的节点的地址，free用
    p->hou = t->hou;//让链子跨过要删除的节点
    free(t);//free掉没用的节点
}

#endif //ELDER_COMM_BUS_H
