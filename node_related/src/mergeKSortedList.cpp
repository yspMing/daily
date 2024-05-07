#include <iostream>
#include <queue>
#include <vector>
#include "common.hpp"

using std::priority_queue;
using std::vector;

namespace node_related{

class mergeKSortedList
{
public:
	/*
	 * merge K sorted lists
	 * eg: list1: 1->3->5
	 *     list2: 2->4->6
	 * merge result: 1->2->3->4->5->6
	*/
	listNode* merge(listNode** lists, int listLen)
	{
		listNode* dummyHead = new listNode();
		listNode* currNode = dummyHead;
		while (true)
		{
			listNode* minNode = nullptr;
			int minPointer = -1;
			for (int i = 0; i < listLen; i++)
			{
				if (lists[i] == nullptr) {
					continue;
				}
				if (minNode == nullptr || lists[i]->val < minNode->val) {
					minNode = lists[i];
					minPointer = i;
				}
			}
			if (minNode == nullptr) {
				break;
			}
			else
			{
				lists[minPointer] = minNode->next;
				currNode->next = minNode;
				currNode = currNode->next;
				minNode = nullptr;
			}
		}
		listNode* ans = dummyHead->next;
		delete dummyHead;
		return ans;
	}

	/*
	 * merge K sorted lists
	 * eg: list1: 1->3->5
	 *     list2: 2->4->6
	 * merge result: 1->2->3->4->5->6
	*/
	listNode* mergeWithMinHead(listNode** lists, int listLen)
	{
		listNode* dummyHead = new listNode();
		listNode* currNode = dummyHead;
		struct cmp
		{
			bool operator()(listNode* a, listNode* b)
			{
				return a->val > b->val;
			}
		};
		priority_queue<listNode*, vector<listNode*>, cmp >q;

		listNode** lp = lists;
		for (int i = 0; i < listLen; i++)
		{
			if (*lp)
			{
				q.push(*lp);
			}
			lp++;
		}
		while (!q.empty())
		{
			currNode->next = q.top();
			currNode = currNode->next;
			q.pop();
			if (currNode->next) {
				q.push(currNode->next);
			}
		}
		listNode* ans = dummyHead->next;
		delete dummyHead;
		return ans;
	}
};


void testKMergedLists()
{
	/*
	 *initialize test lists
	*/
	listNode** lists = new listNode * [2];
	lists[0] = new listNode(1);
	lists[0]->next = new listNode(3);
	lists[0]->next->next = new listNode(5);
	
	lists[1] = new listNode(2);
	lists[1]->next = new listNode(4);
	lists[1]->next->next = new listNode(6);

	mergeKSortedList s;
	listNode* ans = s.mergeWithMinHead(lists, 2);
	listNode* tmp = ans;
	while (tmp)
	{
		std::cout << tmp->val<<" ";
		tmp = tmp->next;
	}

	/*
	 * delete lists
	*/
	while (ans) {
		tmp = ans->next;
		delete ans;
		ans = tmp;
	}
}

}