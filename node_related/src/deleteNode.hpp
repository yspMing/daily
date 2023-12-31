#pragma once
#include "common.hpp"

void DeleteNode(listNode **pListHead, listNode* pToBeDeleted)
{
    if(pToBeDeleted->next != nullptr)
    {
        listNode *pNext = pToBeDeleted->next;
        pToBeDeleted->val = pNext->val;
        pToBeDeleted->next = pNext->next;
        delete pNext;
        pNext = nullptr;
    }
    else if(*pListHead != pToBeDeleted)
    {
        listNode *tmp = *pListHead;
        while(tmp->next != pToBeDeleted)
        {
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
    else
    {
        delete *pListHead;
        *pListHead = nullptr;
        pToBeDeleted = nullptr;
    }
}