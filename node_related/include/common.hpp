#ifndef _NODE_COMMON_H_
#define _NODE_COMMON_H_

#include <iostream>

namespace node_related{

typedef struct listNode {
	int val;
	listNode* next;
	listNode(int x = 0) :val(x), next(nullptr) {}
}listNode;

inline listNode* constructLinkedList(int* arr, int length)
{
	if (length < 1)
		return nullptr;
	listNode* head = new listNode(arr[0]);
	listNode* curr = head;
	for (int i = 1; i < length; i++)
	{
		curr->next = new listNode(arr[i]);
		curr = curr->next;
	}
	std::cout << "construct a linked list of " << length << " nodes." << std::endl;
	return head;
}

inline void destroyLinkedList(listNode* listHead)
{
	listNode* curr = listHead;
	int count = 0;
	while (nullptr != curr)
	{
		listNode* next = curr->next;
		delete curr;
		count++;
		curr = next;
	}
	std::cout << "destroy a linked list of " << count << " nodes." << std::endl;
}

inline void printLinkedList(listNode* listHead)
{
	listNode* curr = listHead;
	while (nullptr != curr)
	{
		std::cout << curr->val << ", ";
		curr = curr->next;
	}
	std::cout << "end."<<std::endl;
}

}

#endif