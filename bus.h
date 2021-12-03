/******************************************
 * This file should be encoded with GB2312*
 ******************************************/
//
// Created by zfn on 2021/11/22.
//

#ifndef ELDER_COMM_BUS_H
#define ELDER_COMM_BUS_H

/// ���ļ�������ע�Ͷ�û�����ã���ֻ������
/// �йذ೵�Ľṹȫ������
/// BusStop��һ����վ��ֻ�����֣������ʽ
/// BusChain��һ��·��
/// BusChainNode��·�ߵ���������ʽ
/// BusChainList�Ƕ�����·�ļ���
/// BusChain��BusChainList����create,insert,remove�Ĳ���
/// BusChain�в��Ҳ���

typedef struct BusStop//�����һ���ڵ�
{
    struct BusStop *hou;//ָ����һ���ָ��
    char value[100];//����ڵ㱣���ֵ
} BusStop;

typedef struct BusChain//������
{
    BusStop *root;//�����ٽڵ㣬���ĺ�һ���ڵ���ǵ�һ���ڵ�
} BusChain;

BusChain buschain_create(void)//��������ʼ��һ������
{
    BusChain t;
    t.root = malloc(sizeof(BusStop));//��ʼ��һ����
    t.root->hou = NULL;
    return t;
}

void buschain_insert(BusStop *p, char *v)//�ڽڵ�p�������v
{
    if (p == NULL) return;//���ܶ�NULL����������
    BusStop *t = malloc(sizeof(BusStop));//Ϊ�µĽڵ�����ڴ�
    strcpy(t->value, v);//����ֵ
    //һ���������
    t->hou = p->hou;//��һ�����һ������Ϊǰһ�����һ��
    p->hou = t;//ǰһ�����һ������Ϊ��һ��
}

void buschain_remove(BusStop *p)//ɾ��p֮��Ľڵ�
{
    if (p == NULL) return;
    BusStop *t = p->hou;//�ȼ�¼��Ҫɾ�Ľڵ�ĵ�ַ��free��
    p->hou = t->hou;//�����ӿ��Ҫɾ���Ľڵ�
    free(t);//free��û�õĽڵ�
}

//���ң���Ȼ���ý���������ô������������ʾ��
BusStop *buschain_find(BusChain c, char *v)//���ص��ǲ��ҽ����ǰһ���ڵ�
{
    for (BusStop *it = c.root; it->hou != NULL; it = it->hou)
        if (strcmp(it->hou->value, v) == 0)
            return it;

    return NULL;
}

typedef struct BusChainNode//�����һ���ڵ�
{
    struct BusChainNode *hou;//ָ����һ���ָ��
    BusChain value;//����ڵ㱣���ֵ
} BusChainNode;

typedef struct BusChainList//������
{
    BusChainNode *root;//�����ٽڵ㣬���ĺ�һ���ڵ���ǵ�һ���ڵ�
} BusChainList;

BusChainList buschainlist_chain_create(void)//��������ʼ��һ������
{
    BusChainList t;
    t.root = malloc(sizeof(BusChainNode));//��ʼ��һ����
    t.root->hou = NULL;
    return t;
}

void buschainlist_insert(BusChainNode *p, BusChain v)//�ڽڵ�p�������v
{
    if (p == NULL) return;//���ܶ�NULL����������
    BusChainNode *t = malloc(sizeof(BusChainNode));//Ϊ�µĽڵ�����ڴ�
    t->value = v;//����ֵ
    //һ���������
    t->hou = p->hou;//��һ�����һ������Ϊǰһ�����һ��
    p->hou = t;//ǰһ�����һ������Ϊ��һ��
}

int buschainlist_remove(BusChainNode *p)//ɾ��p֮��Ľڵ�
{
    if (p == NULL) return -1;
    BusChainNode *t = p->hou;//�ȼ�¼��Ҫɾ�Ľڵ�ĵ�ַ��free��
    p->hou = t->hou;//�����ӿ��Ҫɾ���Ľڵ�
    free(t);//free��û�õĽڵ�
    return 1;
}

#endif //ELDER_COMM_BUS_H
