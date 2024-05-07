#include <iostream>
#include "common.hpp"
using namespace std;

namespace node_related{

// Function to reverse a linked list and return the new head
listNode* reverseLinkedList(listNode* head) {
    listNode* prev = NULL;
    listNode* current = head;
    listNode* next = NULL;

    while (current != NULL) {
        next = current->next;  // Store next
        current->next = prev;  // Reverse current listNode's pointer
        prev = current;        // Move pointers one position ahead
        current = next;
    }
    return prev;  // New head
}

// Function to divide and reverse the linked list
listNode* divideAndReverse(listNode* head, int N, int M) {
    listNode* current = head;
    listNode* prevTail = NULL;
    listNode* newHead = NULL;

    for (int m = 0; m < M; ++m) {
        listNode* partHead = current;
        listNode* partTail = current;

        // Move to the end of the current part
        for (int n = 1; n < N && current; ++n) {
            current = current->next;
        }

        // Prepare for the next part
        if (current) {
            listNode* nextPart = current->next;
            current->next = NULL;  // Break the link
            current = nextPart;    // Move current to the start of the next part
        }

        // Reverse the current part
        listNode* reversedPartHead = reverseLinkedList(partHead);

        // If this is the first part, it will become the new head of the final list
        if (m == 0) newHead = reversedPartHead;

        // Link the previous part with the reversed current part
        if (prevTail) prevTail->next = reversedPartHead;

        // Update the previous part's tail for the next iteration
        prevTail = partTail;
    }

    return newHead;  // Return the head of the newly arranged list
}

// Helper function to print the list
void printList(listNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main Function
int mainGPT() {
    int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

    listNode* head = constructLinkedList(arr, 15);

    int N = 5;  // Number of listNodes in each part
    int M = 3;  // Number of parts

    listNode* newHead = divideAndReverse(head, N, M);
    printList(newHead);

    // Free the allocated memory (not shown here, but should be done in real scenarios)
    destroyLinkedList(newHead);
    return 0;
}

}