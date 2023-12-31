#pragma once

#include "common.hpp"

class reverseKlist
{
public:
	listNode* reverse(listNode* listHead, int K)
	{
		if (listHead == nullptr)
			return nullptr;
		listNode* prev = nullptr;
		listNode* curr = listHead;
		listNode* tail = nullptr;
		listNode* prevTail = nullptr;
		listNode* Head = nullptr;
		bool finished = false;
		bool findHead = false;
		while (!finished)
		{
			tail = curr;
			for (int i = 0; i < K; i++)
			{
				if (nullptr == curr)
				{
					finished = true;
					break;
				}
				listNode* next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}
			if (!findHead)
			{
				Head = prev;
				findHead = true;
				prev = nullptr;
				prevTail = tail;
				continue;
			}
			
			prevTail->next = prev;
			prevTail = tail;
			prev = nullptr;
		}
		
		return Head;
	}
};

void testReverseKlist()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	listNode* listHead = constructLinkedList(arr, 10);

	reverseKlist s;
	listNode* Head = s.reverse(listHead, 3);

	printLinkedList(Head);

	destroyLinkedList(Head);
}